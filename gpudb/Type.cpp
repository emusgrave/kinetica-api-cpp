#include "gpudb/Type.hpp"

#include "gpudb/GPUdb.hpp"

#include <algorithm> // for sort and set_symmetric_difference
#include <sstream>   // for istringstream

#include <boost/algorithm/string.hpp> // starts_with and to_lower_copy
#include <boost/lexical_cast.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/unordered_set.hpp>

namespace gpudb
{
    Type::Column::Column(const std::string& name, const ColumnType type, const std::string& property1, const std::string& property2, const std::string& property3) :
        m_name(name),
        m_type(type),
        m_isNullable(false)
    {
        if (!property1.empty())
        {
            m_properties.push_back(property1);

            if (!property2.empty())
            {
                m_properties.push_back(property2);

                if (!property3.empty())
                {
                    m_properties.push_back(property3);
                }
            }
        }

        initialize();
    }

    Type::Column::Column(const std::string& name, const ColumnType type, const std::vector<std::string>& properties) :
        m_name(name),
        m_type(type),
        m_isNullable(false),
        m_properties(properties)
    {
        initialize();
    }

    const std::string& Type::Column::getName() const
    {
        return m_name;
    }

    Type::Column::ColumnType Type::Column::getType() const
    {
        return m_type;
    }

    std::string Type::Column::getTypeName() const
    {
        switch ( m_type )
        {
            case ColumnType::BYTES:    return "bytes";
            case ColumnType::DOUBLE:   return "double";
            case ColumnType::FLOAT:    return "float";
            case ColumnType::INT:      return "int";
            case ColumnType::LONG:     return "long";
            case ColumnType::STRING:   return "string";
            default:                   return "unknown";
        }
    }

    bool Type::Column::isNullable() const
    {
        return m_isNullable;
    }

    bool Type::Column::isArray() const
    {
        for (const std::string& prop : m_properties)
            if (boost::starts_with(prop, ColumnProperty::ARRAY))
                return true;
        
        return false;
    }

    std::string Type::Column::getArrayType() const
    {
        for (const std::string& prop : m_properties)
            if (boost::starts_with(prop, ColumnProperty::ARRAY))
            {
                int open_index = prop.find('(');
                int close_index = prop.find(')');
                if ((open_index >=0 ) && (close_index > open_index))
                {
                    int comma_index = prop.find(',', open_index);
                    if ((comma_index > open_index) && (comma_index < close_index))
                        close_index = comma_index;
                    std::string sub_type = boost::to_lower_copy(prop.substr(open_index + 1, close_index - open_index - 1));
                    if (boost::starts_with(sub_type, "bool"))
                        return gpudb::create_type_boolean;
                    else if (boost::starts_with(sub_type, "int"))
                        return "int";
                    else
                        return sub_type;
                }
            }

        return std::string();
    }

    const std::vector<std::string>& Type::Column::getProperties() const
    {
        return m_properties;
    }

    bool Type::Column::isVector() const
    {
        for (const std::string& prop : m_properties)
            if (boost::starts_with(prop, ColumnProperty::VECTOR))
                return true;
        
        return false;
    }

    int Type::Column::getVectorDimensions() const
    {
        for (const std::string& prop : m_properties)
            if (boost::starts_with(prop, ColumnProperty::VECTOR))
            {
                int open_index = prop.find('(');
                int close_index = prop.find(')');
                if ((open_index >=0 ) && (close_index > open_index))
                {
                    int dims;
                    std::istringstream ss(prop.substr(open_index + 1, close_index - open_index - 1));
                    if (!(ss >> dims).fail())
                        return dims;
                }
            }

        return -1;
    }

    // Return whether this column has the given property
    bool Type::Column::hasProperty( std::string property ) const
    {
        return ( std::find( m_properties.begin(), m_properties.end(), property )
                 != m_properties.end() );
    }

    void Type::Column::initialize()
    {
        if (m_name.empty())
        {
            throw std::invalid_argument("Name must not be empty.");
        }

        switch (m_type)
        {
            case BYTES:
            case DOUBLE:
            case FLOAT:
            case INT:
            case LONG:
            case STRING:
                break;

            default:
                throw std::invalid_argument("Column " + m_name + " must be of type BYTES, DOUBLE, FLOAT, INT, LONG or STRING.");
        }

        for (std::vector<std::string>::const_iterator it = m_properties.begin(); it != m_properties.end(); ++it)
        {
            if (it->empty())
            {
                throw std::invalid_argument("Properties must not be empty.");
            }

            if (!m_isNullable && *it == ColumnProperty::NULLABLE)
            {
                m_isNullable = true;
            }
        }

        // Sort the properties; will be useful later
        std::sort( m_properties.begin(), m_properties.end() );
    }  // end initialize


    /* Check if the given type's columns' data types are compatible
     * (checks primitive types and type-related properties, including nullability).
     * If check_query_compatibility is true, then also check for query
     * related properties, e.g. 'data', 'disk_optimized', 'store_only',
     * and 'text_search'.
     */
    bool Type::Column::isColumnCompatible(const Type::Column &other, bool check_query_compatibility ) const
    {
        // Looking for a 100% match between the columns
        if ( check_query_compatibility )
        {
            return ( (m_name == other.getName())
                && (m_type == other.getType())
                && (m_isNullable == other.isNullable())
                && (m_properties == other.getProperties()) );
        }

        // Check if the name, primitive data type, and nullability match
        if ( (m_name != other.getName())
             || (m_type != other.getType())
             || (m_isNullable != other.m_isNullable) )
        {
            return false;
        }

        // Check if the data type related properties match; ignore the
        // following properties: date, text_search, store_only, disk_optimized
        // -------------------------------------------------------------------
        // Get the uncommon elements from both the properties
        std::set<std::string> uncommon_properties;
        const std::vector<std::string>& other_props = other.getProperties();
        std::set_symmetric_difference( m_properties.begin(), m_properties.end(),
                                       other_props.begin(),  other_props.end(),
                                       std::inserter( uncommon_properties,
                                                      uncommon_properties.begin() ) );

        // Now erase the properties that we're ignoring
        uncommon_properties.erase( gpudb::ColumnProperty::DATA );
        uncommon_properties.erase( gpudb::ColumnProperty::DISK_OPTIMIZED );
        uncommon_properties.erase( gpudb::ColumnProperty::STORE_ONLY);
        uncommon_properties.erase( gpudb::ColumnProperty::TEXT_SEARCH );

        // If are no more uncommon property, then the columns are compatible
        if ( uncommon_properties.empty() )
            return true;
        return false;
    }  // end isColumnCompatible


    // Overloading == for Column
    bool operator==(const gpudb::Type::Column &lhs, const gpudb::Type::Column &rhs)
    {
        return ( (lhs.m_name == rhs.m_name)
            && (lhs.m_type == rhs.m_type)
            && (lhs.m_isNullable == rhs.m_isNullable)
            && (lhs.m_properties == rhs.m_properties) );
    }

    std::ostream &operator << (std::ostream &os, const gpudb::Type::Column &column)
    {
        os << " ( " << column.getName() << ", " << column.getTypeName() << ", nullable: " << column.m_isNullable;

        if ( !column.m_properties.empty() )
        {
            os << " properties: [";
            std::vector<std::string>::const_iterator iter;
            for ( iter = column.m_properties.begin(); iter != column.m_properties.end(); ++iter )
                os << *iter << ", ";
            os << "]";
        }
        os << " )" << std::endl;
        return os;
    }

    std::ostream &operator << (std::ostream &os, gpudb::Type::Column &column)
    {
        os << " ( " << column.getName() << ", " << column.getTypeName() << ", nullable: " << column.m_isNullable;

        if ( !column.m_properties.empty() )
        {
            os << " properties: [";
            std::vector<std::string>::const_iterator iter;
            for ( iter = column.m_properties.begin(); iter != column.m_properties.end(); ++iter )
                os << *iter << ", ";
            os << "]";
        }
        os << " )" << std::endl;
        return os;
    }



    /* Check if the given type's columns' data types are compatible
     * (checks primitive types and type-related properties, including nullability).
     * If check_query_compatibility is true, then also check for query
     * related properties, e.g. 'data', 'disk_optimized', 'store_only',
     * and 'text_search'.
     */
    bool Type::isTypeCompatible(const Type &other, bool check_query_compatibility ) const
    {
        // Looking for a 100% match between all the columns
        if ( check_query_compatibility )
        {
            return ( m_data->columns == other.m_data->columns );
        }

        // Looking for column name, data type, and data related property compatibility;
        // so, need to ignore 'data', 'text_search', 'disk_optimized', and 'store_only'.
        // -----------------------------------------------------------------------------
        // First check that the number of columns is the same
        if ( m_data->columns.size() != other.m_data->columns.size() )
            return false;

        // Now go through all the columns and check for compatibility
        for ( size_t i = 0; i < m_data->columns.size(); ++i )
        {
            // Bail out at the first mismatch
            if ( !m_data->columns[ i ].isColumnCompatible( other.m_data->columns[ i ] ) )
                return false;
        }
        return true; // all match
    }  // end isTypeCompatible


    Type Type::fromTable(const GPUdb& gpudb, const std::string& tableName)
    {
        ShowTableResponse response;
        std::map<std::string, std::string> options;
        gpudb.showTable(tableName, options, response);
        size_t typeIdCount = response.typeIds.size();

        if (typeIdCount == 0)
        {
            throw GPUdbException("Table " + tableName + " does not exist.");
        }

        if (typeIdCount > 1)
        {
            const std::string& typeId = response.typeIds[0];

            for (size_t i = 1; i < typeIdCount; ++i)
            {
                if (response.typeIds[i] != typeId)
                {
                    throw GPUdbException("Table " + tableName + " is not homogeneous.");
                }
            }
        }

        return Type( response.typeLabels[0], response.typeSchemas[0], response.properties[0] );
    }

    Type Type::fromType(const GPUdb& gpudb, const std::string& typeId)
    {
        ShowTypesResponse response;
        std::map<std::string, std::string> options;
        gpudb.showTypes(typeId, "", options);

        if (response.typeIds.empty())
        {
            throw GPUdbException("Type " + typeId + " does not exist.");
        }

        return Type( response.labels[0], response.typeSchemas[0], response.properties[0] );
    }

    Type::Type(const std::vector<Type::Column>& columns) :
        m_data(boost::make_shared<TypeData>())
    {
        m_data->columns = columns;
        initialize();
        createSchema();
    }

    Type::Type(const std::string& label, const std::vector<Type::Column>& columns) :
        m_data(boost::make_shared<TypeData>())
    {
        m_data->label = label;
        m_data->columns = columns;
        initialize();
        createSchema();
    }

    Type::Type(const std::string& typeSchema) :
        m_data(boost::make_shared<TypeData>())
    {
        std::map<std::string, std::vector<std::string> > properties;
        createFromSchema(typeSchema, properties);
        createSchema();
    }

    Type::Type(const std::string& label, const std::string& typeSchema, const std::map<std::string, std::vector<std::string> >& properties) :
        m_data(boost::make_shared<TypeData>())
    {
        m_data->label = label;
        createFromSchema(typeSchema, properties);
        createSchema();
    }

    const std::string& Type::getLabel() const
    {
        return m_data->label;
    }

    const std::vector<Type::Column>& Type::getColumns() const
    {
        return m_data->columns;
    }

    const Type::Column& Type::getColumn(const size_t index) const
    {
        return m_data->columns.at(index);
    }

    const Type::Column& Type::getColumn(const std::string& name) const
    {
        return m_data->columns[getColumnIndex(name)];
    }

    size_t Type::getColumnCount() const
    {
        return m_data->columns.size();
    }

    size_t Type::getColumnIndex(const std::string& name) const
    {
        std::map<std::string, size_t>::const_iterator column = m_data->columnMap.find(name);

        if (column == m_data->columnMap.end())
        {
            throw std::out_of_range("Column " + name + " does not exist.");
        }

        return column->second;
    }

    bool Type::hasColumn(const std::string& name) const
    {
        return m_data->columnMap.find(name) != m_data->columnMap.end();
    }

    const ::avro::ValidSchema& Type::getSchema() const
    {
        return m_data->schema;
    }

    std::string Type::create(const GPUdb& gpudb) const
    {
        boost::property_tree::ptree root;
        root.put("type", "record");
        root.put("name", "type_name");
        boost::property_tree::ptree fields;
        std::map<std::string, std::vector<std::string> > properties;

        for (std::vector<Type::Column>::const_iterator it = m_data->columns.begin(); it != m_data->columns.end(); ++it)
        {
            boost::property_tree::ptree field;
            const std::string& columnName = it->getName();
            field.put("name", columnName);
            std::string columnTypeString;

            switch (it->getType())
            {
                case Column::BYTES:
                    columnTypeString = "bytes";
                    break;

                case Column::DOUBLE:
                    columnTypeString = "double";
                    break;

                case Column::FLOAT:
                    columnTypeString = "float";
                    break;

                case Column::INT:
                    columnTypeString = "int";
                    break;

                case Column::LONG:
                    columnTypeString = "long";
                    break;

                case Column::STRING:
                    columnTypeString = "string";
                    break;
            }

            if (it->isNullable())
            {
                boost::property_tree::ptree fieldArray;
                fieldArray.push_back(std::make_pair("", boost::property_tree::ptree(columnTypeString)));
                fieldArray.push_back(std::make_pair("", boost::property_tree::ptree("null")));
                field.add_child("type", fieldArray);
            }
            else
            {
                field.put("type", columnTypeString);
            }

            fields.push_back(std::make_pair("", field));

            if (!it->getProperties().empty())
            {
                properties[columnName] = it->getProperties();
            }
        }

        root.add_child("fields", fields);
        std::ostringstream schemaStream;
        boost::property_tree::write_json(schemaStream, root);

        CreateTypeResponse response;
        return gpudb.createType(schemaStream.str(), m_data->label, properties, std::map<std::string, std::string>(), response).typeId;
    }

    Type::Type()
    {
    }

    void Type::initialize()
    {
        size_t columnCount = m_data->columns.size();

        if (columnCount == 0)
        {
            throw std::invalid_argument("At least one column must be specified.");
        }

        for (size_t i = 0; i < columnCount; ++i)
        {
            const std::string& columnName = m_data->columns[i].getName();

            if (m_data->columnMap.find(columnName) != m_data->columnMap.end())
            {
                throw std::invalid_argument("Duplicate column name " + columnName + " specified.");
            }

            m_data->columnMap[columnName] = i;
        }
    }

    void Type::createFromSchema(const std::string& typeSchema, const std::map<std::string, std::vector<std::string> >& properties)
    {
        std::stringstream schemaStream(typeSchema);
        boost::property_tree::ptree root;

        try
        {
            boost::property_tree::read_json(schemaStream, root);
        }
        catch (const std::exception& ex)
        {
            throw std::invalid_argument("Schema is invalid: " + std::string(ex.what()));
        }

        boost::optional<std::string> rootType = root.get_optional<std::string>("type");

        if (!rootType || *rootType != "record")
        {
            throw std::invalid_argument("Schema must be of type record.");
        }

        boost::optional<boost::property_tree::ptree&> fields = root.get_child_optional("fields");

        if (!fields || fields->empty())
        {
            throw std::invalid_argument("Schema has no fields.");
        }

        for (boost::property_tree::ptree::const_iterator field = fields->begin(); field != fields->end(); ++field)
        {
            if (!field->first.empty() || field->second.empty())
            {
                throw std::invalid_argument("Schema has invalid field.");
            }

            boost::optional<std::string> fieldName = field->second.get_optional<std::string>("name");

            if (!fieldName || fieldName->empty())
            {
                throw std::invalid_argument("Schema has unnamed field.");
            }

            if (m_data->columnMap.find(*fieldName) != m_data->columnMap.end())
            {
                throw std::invalid_argument("Duplicate field name " + *fieldName + ".");
            }

            boost::optional<std::string> fieldType = field->second.get_optional<std::string>("type");
            bool isNullable = false;

            if (!fieldType)
            {
                throw std::invalid_argument("Field " + *fieldName + " has no type.");
            }

            if (fieldType->empty())
            {
                boost::optional<const boost::property_tree::ptree&> fieldTypeArray = field->second.get_child_optional("type");

                for (boost::property_tree::ptree::const_iterator fieldTypeElement = fieldTypeArray->begin();
                     fieldTypeElement != fieldTypeArray->end(); ++fieldTypeElement)
                {
                    bool valid = false;

                    if (fieldTypeElement->first.empty())
                    {
                        boost::optional<std::string> fieldTypeElementString = fieldTypeElement->second.get_value_optional<std::string>();

                        if (fieldTypeElementString && !fieldTypeElementString->empty())
                        {
                            if (!fieldType->empty() && *fieldTypeElementString == "null")
                            {
                                valid = true;
                                isNullable = true;
                            }
                            else if (fieldType->empty())
                            {
                                fieldType = fieldTypeElementString;
                                valid = true;
                            }
                        }
                    }

                    if (!valid)
                    {
                        throw std::invalid_argument("Field " + *fieldName + " has invalid type.");
                    }
                }

                if (fieldType->empty())
                {
                    throw std::invalid_argument("Field " + *fieldName + " has invalid type.");
                }
            }

            Column::ColumnType columnType;

            if (*fieldType == "bytes")
            {
                columnType = Column::BYTES;
            }
            else if (*fieldType == "double")
            {
                columnType = Column::DOUBLE;
            }
            else if (*fieldType == "float")
            {
                columnType = Column::FLOAT;
            }
            else if (*fieldType == "int")
            {
                columnType = Column::INT;
            }
            else if (*fieldType == "long")
            {
                columnType = Column::LONG;
            }
            else if (*fieldType == "string")
            {
                columnType = Column::STRING;
            }
            else
            {
                throw std::invalid_argument("Field " + *fieldName + " must be of type bytes, double, float, int, long or string.");
            }

            std::map<std::string, std::vector<std::string> >::const_iterator columnPropertiesIterator = properties.find(*fieldName);

            if (columnPropertiesIterator == properties.end())
            {
                if (isNullable)
                {
                    std::vector<std::string> columnProperties;
                    columnProperties.push_back(ColumnProperty::NULLABLE);
                    m_data->columns.push_back(Column(*fieldName, columnType, columnProperties));
                }
                else
                {
                    m_data->columns.push_back(Column(*fieldName, columnType));
                }
            }
            else
            {
                const std::vector<std::string>& columnProperties = columnPropertiesIterator->second;

                if (isNullable)
                {
                    if (std::find(columnProperties.begin(), columnProperties.end(), ColumnProperty::NULLABLE) == columnProperties.end())
                    {
                        std::vector<std::string> newColumnProperties(columnProperties);
                        newColumnProperties.push_back(ColumnProperty::NULLABLE);
                        m_data->columns.push_back(Column(*fieldName, columnType, newColumnProperties));
                    }
                    else
                    {
                        m_data->columns.push_back(Column(*fieldName, columnType, columnProperties));
                    }
                }
                else
                {
                    m_data->columns.push_back(Column(*fieldName, columnType, columnProperties));
                }
            }

            m_data->columnMap[*fieldName] = m_data->columns.size() - 1;
        }
    }

    void Type::createSchema()
    {
        ::avro::RecordSchema recordSchema("type_name");
        std::vector<std::string> fields;
        boost::unordered_set<std::string> fieldNames;
        const std::vector<Type::Column>& columns = m_data->columns;
        const std::map<std::string, size_t>& columnMap = m_data->columnMap;
        size_t columnCount = columns.size();

        for (size_t i = 0; i < columnCount; ++i)
        {
            const Type::Column& column = columns[i];
            std::string baseFieldName = column.getName();

            for (size_t j = 0; j < baseFieldName.size(); ++j)
            {
                char c = baseFieldName[j];

                if (!(j > 0 && c >= '0' && c <= '9')
                        && !(c >= 'A' && c <= 'Z')
                        && !(c >= 'a' && c <= 'z')
                        && c != '_')
                {
                    baseFieldName[j] = '_';
                }
            }

            std::string fieldName;

            for (size_t n = 1; ; ++n)
            {
                fieldName = baseFieldName + (n > 1 ? "_" + boost::lexical_cast<std::string>(n) : "");
                std::map<std::string, size_t>::const_iterator columnIndex = columnMap.find(fieldName);

                if ((columnIndex == columnMap.end() || columnIndex->second == i)
                    && (fieldNames.find(fieldName) == fieldNames.end()))
                {
                    break;
                }
            }

            fields.push_back(fieldName);
            fieldNames.insert(fieldName);
            boost::scoped_ptr< ::avro::Schema> fieldSchema;

            switch (columns[i].getType())
            {
                case Column::BYTES:
                    fieldSchema.reset(new ::avro::BytesSchema());
                    break;

                case Column::DOUBLE:
                    fieldSchema.reset(new ::avro::DoubleSchema());
                    break;

                case Column::FLOAT:
                    fieldSchema.reset(new ::avro::FloatSchema());
                    break;

                case Column::INT:
                    fieldSchema.reset(new ::avro::IntSchema());
                    break;

                case Column::LONG:
                    fieldSchema.reset(new ::avro::LongSchema());
                    break;

                case Column::STRING:
                    fieldSchema.reset(new ::avro::StringSchema());
                    break;
            }

            if (column.isNullable())
            {
                ::avro::UnionSchema fieldUnionSchema;
                fieldUnionSchema.addType(*fieldSchema);
                fieldUnionSchema.addType(::avro::NullSchema());
                recordSchema.addField(fieldName, fieldUnionSchema);
            }
            else
            {
                recordSchema.addField(fieldName, *fieldSchema);
            }
        }

        m_data->schema.setSchema(recordSchema);
    }   // end createSchema


    std::ostream &operator << (std::ostream  &os, gpudb::Type &type)
    {
        os << "[ ";
        std::vector<Type::Column>::const_iterator iter;
        for ( iter = type.m_data->columns.begin();
              iter != type.m_data->columns.end(); ++ iter )
        {
            os << *iter;
        }
        os << " ]" << std::endl;
        return os;
    }

    std::ostream &operator << (std::ostream  &os, const gpudb::Type &type)
    {
        os << "[ ";
        std::vector<Type::Column>::const_iterator iter;
        for ( iter = type.m_data->columns.begin();
              iter != type.m_data->columns.end(); ++ iter )
        {
            os << *iter;
        }
        os << " ]" << std::endl;
        return os;
    }
    
    
}   // end namespace gpudb
