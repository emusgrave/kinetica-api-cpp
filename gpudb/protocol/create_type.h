/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __CREATE_TYPE_H__
#define __CREATE_TYPE_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #createType(const CreateTypeRequest&) const}.
     * <p>
     * Creates a new type describing the layout of a table. The type definition
     * is a JSON string describing the fields (i.e. columns) of the type. Each
     * field consists of a name and a data type. Supported data types are:
     * double, float, int, long, string, and bytes. In addition, one or more
     * properties can be specified for each column which customize the memory
     * usage and query availability of that column.  Note that some properties
     * are mutually exclusive--i.e. they cannot be specified for any given
     * column simultaneously.  One example of mutually exclusive properties are
     * @a data and @a store_only.
     * <p>
     * A single <a href="../../concepts/tables.html#primary-keys"
     * target="_top">primary key</a> and/or single <a
     * href="../../concepts/tables.html#shard-keys" target="_top">shard key</a>
     * can be set across one or more columns. If a primary key is specified,
     * then a uniqueness constraint is enforced, in that only a single object
     * can exist with a given primary key column value (or set of values for
     * the key columns, if using a composite primary key). When {@link
     * #insertRecordsRaw(const RawInsertRecordsRequest&) const inserting}
     * data into a table with a primary key, depending on the parameters in the
     * request, incoming objects with primary key values that match existing
     * objects will either overwrite (i.e. update) the existing object or will
     * be skipped and not added into the set.
     * <p>
     * Example of a type definition with some of the parameters::
     * <p>
     *         {"type":"record",
     *         "name":"point",
     *         "fields":[{"name":"msg_id","type":"string"},
     *                         {"name":"x","type":"double"},
     *                         {"name":"y","type":"double"},
     *                         {"name":"TIMESTAMP","type":"double"},
     *                         {"name":"source","type":"string"},
     *                         {"name":"group_id","type":"string"},
     *                         {"name":"OBJECT_ID","type":"string"}]
     *         }
     * <p>
     * Properties::
     * <p>
     *         {"group_id":["store_only"],
     *         "msg_id":["store_only","text_search"]
     *         }
     */
    struct CreateTypeRequest
    {

        /**
         * Constructs a CreateTypeRequest object with default parameter values.
         */
        CreateTypeRequest() :
            typeDefinition(std::string()),
            label(std::string()),
            properties(std::map<std::string, std::vector<std::string> >()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a CreateTypeRequest object with the specified parameters.
         * 
         * @param[in] typeDefinition_  a JSON string describing the columns of
         *                             the type to be registered.
         * @param[in] label_  A user-defined description string which can be
         *                    used to differentiate between tables and types
         *                    with otherwise identical schemas.
         * @param[in] properties_  Each key-value pair specifies the properties
         *                         to use for a given column where the key is
         *                         the column name.  All keys used must be
         *                         relevant column names for the given table.
         *                         Specifying any property overrides the
         *                         default properties for that column (which is
         *                         based on the column's data type).
         *                         <ul>
         *                                 <li> gpudb::create_type_data:
         *                         Default property for all numeric and string
         *                         type columns; makes the column available for
         *                         GPU queries.
         *                                 <li> gpudb::create_type_text_search:
         *                         Valid only for 'string' columns. Enables
         *                         full text search for string columns. Can be
         *                         set independently of @a data and @a
         *                         store_only.
         *                                 <li> gpudb::create_type_store_only:
         *                         Persist the column value but do not make it
         *                         available to queries (e.g. /filter)-i.e. it
         *                         is mutually exclusive to the @a data
         *                         property. Any 'bytes' type column must have
         *                         a @a store_only property. This property
         *                         reduces system memory usage.
         *                                 <li>
         *                         gpudb::create_type_disk_optimized: Works in
         *                         conjunction with the @a data property for
         *                         string columns. This property reduces system
         *                         disk usage by disabling reverse string
         *                         lookups. Queries like /filter,
         *                         /filter/bylist, and /filter/byvalue work as
         *                         usual but /aggregate/unique and
         *                         /aggregate/groupby are not allowed on
         *                         columns with this property.
         *                                 <li> gpudb::create_type_timestamp:
         *                         Valid only for 'long' columns. Indicates
         *                         that this field represents a timestamp and
         *                         will be provided in milliseconds since the
         *                         Unix epoch: 00:00:00 Jan 1 1970.  Dates
         *                         represented by a timestamp must fall between
         *                         the year 1000 and the year 2900.
         *                                 <li> gpudb::create_type_ulong: Valid
         *                         only for 'string' columns.  It represents an
         *                         unsigned long integer data type. The string
         *                         can only be interpreted as an unsigned long
         *                         data type with minimum value of zero, and
         *                         maximum value of 18446744073709551615.
         *                                 <li> gpudb::create_type_uuid: Valid
         *                         only for 'string' columns.  It represents an
         *                         uuid data type. Internally, it is stored as
         *                         an 128-bit ingeger.
         *                                 <li> gpudb::create_type_decimal:
         *                         Valid only for 'string' columns.  It
         *                         represents a SQL type NUMERIC(19, 4) data
         *                         type.  There can be up to 15 digits before
         *                         the decimal point and up to four digits in
         *                         the fractional part.  The value can be
         *                         positive or negative (indicated by a minus
         *                         sign at the beginning).  This property is
         *                         mutually exclusive with the @a text_search
         *                         property.
         *                                 <li> gpudb::create_type_date: Valid
         *                         only for 'string' columns.  Indicates that
         *                         this field represents a date and will be
         *                         provided in the format 'YYYY-MM-DD'.  The
         *                         allowable range is 1000-01-01 through
         *                         2900-01-01.  This property is mutually
         *                         exclusive with the @a text_search property.
         *                                 <li> gpudb::create_type_time: Valid
         *                         only for 'string' columns.  Indicates that
         *                         this field represents a time-of-day and will
         *                         be provided in the format 'HH:MM:SS.mmm'.
         *                         The allowable range is 00:00:00.000 through
         *                         23:59:59.999.  This property is mutually
         *                         exclusive with the @a text_search property.
         *                                 <li> gpudb::create_type_datetime:
         *                         Valid only for 'string' columns.  Indicates
         *                         that this field represents a datetime and
         *                         will be provided in the format 'YYYY-MM-DD
         *                         HH:MM:SS.mmm'.  The allowable range is
         *                         1000-01-01 00:00:00.000 through 2900-01-01
         *                         23:59:59.999.  This property is mutually
         *                         exclusive with the @a text_search property.
         *                                 <li> gpudb::create_type_char1: This
         *                         property provides optimized memory, disk and
         *                         query performance for string columns.
         *                         Strings with this property must be no longer
         *                         than 1 character.
         *                                 <li> gpudb::create_type_char2: This
         *                         property provides optimized memory, disk and
         *                         query performance for string columns.
         *                         Strings with this property must be no longer
         *                         than 2 characters.
         *                                 <li> gpudb::create_type_char4: This
         *                         property provides optimized memory, disk and
         *                         query performance for string columns.
         *                         Strings with this property must be no longer
         *                         than 4 characters.
         *                                 <li> gpudb::create_type_char8: This
         *                         property provides optimized memory, disk and
         *                         query performance for string columns.
         *                         Strings with this property must be no longer
         *                         than 8 characters.
         *                                 <li> gpudb::create_type_char16: This
         *                         property provides optimized memory, disk and
         *                         query performance for string columns.
         *                         Strings with this property must be no longer
         *                         than 16 characters.
         *                                 <li> gpudb::create_type_char32: This
         *                         property provides optimized memory, disk and
         *                         query performance for string columns.
         *                         Strings with this property must be no longer
         *                         than 32 characters.
         *                                 <li> gpudb::create_type_char64: This
         *                         property provides optimized memory, disk and
         *                         query performance for string columns.
         *                         Strings with this property must be no longer
         *                         than 64 characters.
         *                                 <li> gpudb::create_type_char128:
         *                         This property provides optimized memory,
         *                         disk and query performance for string
         *                         columns. Strings with this property must be
         *                         no longer than 128 characters.
         *                                 <li> gpudb::create_type_char256:
         *                         This property provides optimized memory,
         *                         disk and query performance for string
         *                         columns. Strings with this property must be
         *                         no longer than 256 characters.
         *                                 <li> gpudb::create_type_int8: This
         *                         property provides optimized memory and query
         *                         performance for int columns. Ints with this
         *                         property must be between -128 and +127
         *                         (inclusive)
         *                                 <li> gpudb::create_type_int16: This
         *                         property provides optimized memory and query
         *                         performance for int columns. Ints with this
         *                         property must be between -32768 and +32767
         *                         (inclusive)
         *                                 <li> gpudb::create_type_ipv4: This
         *                         property provides optimized memory, disk and
         *                         query performance for string columns
         *                         representing IPv4 addresses (i.e.
         *                         192.168.1.1). Strings with this property
         *                         must be of the form: A.B.C.D where A, B, C
         *                         and D are in the range of 0-255.
         *                                 <li> gpudb::create_type_wkt: Valid
         *                         only for 'string' and 'bytes' columns.
         *                         Indicates that this field contains
         *                         geospatial geometry objects in Well-Known
         *                         Text (WKT) or Well-Known Binary (WKB)
         *                         format.
         *                                 <li> gpudb::create_type_primary_key:
         *                         This property indicates that this column
         *                         will be part of (or the entire) <a
         *                         href="../../concepts/tables.html#primary-keys"
         *                         target="_top">primary key</a>.
         *                                 <li> gpudb::create_type_shard_key:
         *                         This property indicates that this column
         *                         will be part of (or the entire) <a
         *                         href="../../concepts/tables.html#shard-keys"
         *                         target="_top">shard key</a>.
         *                                 <li> gpudb::create_type_nullable:
         *                         This property indicates that this column is
         *                         nullable.  However, setting this property is
         *                         insufficient for making the column nullable.
         *                         The user must declare the type of the column
         *                         as a union between its regular type and
         *                         'null' in the avro schema for the record
         *                         type in @a typeDefinition.  For example, if
         *                         a column is of type integer and is nullable,
         *                         then the entry for the column in the avro
         *                         schema must be: ['int', 'null'].
         *                         The C++, C#, Java, and Python APIs have
         *                         built-in convenience for bypassing setting
         *                         the avro schema by hand.  For those
         *                         languages, one can use this property as
         *                         usual and not have to worry about the avro
         *                         schema for the record.
         *                                 <li> gpudb::create_type_dict: This
         *                         property indicates that this column should
         *                         be <a
         *                         href="../../concepts/dictionary_encoding.html"
         *                         target="_top">dictionary encoded</a>. It can
         *                         only be used in conjunction with restricted
         *                         string (charN), int, long or date columns.
         *                         Dictionary encoding is best for columns
         *                         where the cardinality (the number of unique
         *                         values) is expected to be low. This property
         *                         can save a large amount of memory.
         *                                 <li>
         *                         gpudb::create_type_init_with_now: For
         *                         'date', 'time', 'datetime', or 'timestamp'
         *                         column types, replace empty strings and
         *                         invalid timestamps with 'NOW()' upon insert.
         *                         </ul>
         * @param[in] options_  Optional parameters.
         * 
         */
        CreateTypeRequest(const std::string& typeDefinition_, const std::string& label_, const std::map<std::string, std::vector<std::string> >& properties_, const std::map<std::string, std::string>& options_):
            typeDefinition( typeDefinition_ ),
            label( label_ ),
            properties( properties_ ),
            options( options_ )
        {
        }

        std::string typeDefinition;
        std::string label;
        std::map<std::string, std::vector<std::string> > properties;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::CreateTypeRequest>
    {
        static void encode(Encoder& e, const gpudb::CreateTypeRequest& v)
        {
            ::avro::encode(e, v.typeDefinition);
            ::avro::encode(e, v.label);
            ::avro::encode(e, v.properties);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::CreateTypeRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.typeDefinition);
                            break;

                        case 1:
                            ::avro::decode(d, v.label);
                            break;

                        case 2:
                            ::avro::decode(d, v.properties);
                            break;

                        case 3:
                            ::avro::decode(d, v.options);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.typeDefinition);
                ::avro::decode(d, v.label);
                ::avro::decode(d, v.properties);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #createType(const CreateTypeRequest&) const}.
     * <p>
     * Creates a new type describing the layout of a table. The type definition
     * is a JSON string describing the fields (i.e. columns) of the type. Each
     * field consists of a name and a data type. Supported data types are:
     * double, float, int, long, string, and bytes. In addition, one or more
     * properties can be specified for each column which customize the memory
     * usage and query availability of that column.  Note that some properties
     * are mutually exclusive--i.e. they cannot be specified for any given
     * column simultaneously.  One example of mutually exclusive properties are
     * @a data and @a store_only.
     * <p>
     * A single <a href="../../concepts/tables.html#primary-keys"
     * target="_top">primary key</a> and/or single <a
     * href="../../concepts/tables.html#shard-keys" target="_top">shard key</a>
     * can be set across one or more columns. If a primary key is specified,
     * then a uniqueness constraint is enforced, in that only a single object
     * can exist with a given primary key column value (or set of values for
     * the key columns, if using a composite primary key). When {@link
     * #insertRecordsRaw(const RawInsertRecordsRequest&) const inserting}
     * data into a table with a primary key, depending on the parameters in the
     * request, incoming objects with primary key values that match existing
     * objects will either overwrite (i.e. update) the existing object or will
     * be skipped and not added into the set.
     * <p>
     * Example of a type definition with some of the parameters::
     * <p>
     *         {"type":"record",
     *         "name":"point",
     *         "fields":[{"name":"msg_id","type":"string"},
     *                         {"name":"x","type":"double"},
     *                         {"name":"y","type":"double"},
     *                         {"name":"TIMESTAMP","type":"double"},
     *                         {"name":"source","type":"string"},
     *                         {"name":"group_id","type":"string"},
     *                         {"name":"OBJECT_ID","type":"string"}]
     *         }
     * <p>
     * Properties::
     * <p>
     *         {"group_id":["store_only"],
     *         "msg_id":["store_only","text_search"]
     *         }
     */
    struct CreateTypeResponse
    {

        /**
         * Constructs a CreateTypeResponse object with default parameter
         * values.
         */
        CreateTypeResponse() :
            typeId(std::string()),
            typeDefinition(std::string()),
            label(std::string()),
            properties(std::map<std::string, std::vector<std::string> >()),
            info(std::map<std::string, std::string>())
        {
        }

        std::string typeId;
        std::string typeDefinition;
        std::string label;
        std::map<std::string, std::vector<std::string> > properties;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::CreateTypeResponse>
    {
        static void encode(Encoder& e, const gpudb::CreateTypeResponse& v)
        {
            ::avro::encode(e, v.typeId);
            ::avro::encode(e, v.typeDefinition);
            ::avro::encode(e, v.label);
            ::avro::encode(e, v.properties);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::CreateTypeResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.typeId);
                            break;

                        case 1:
                            ::avro::decode(d, v.typeDefinition);
                            break;

                        case 2:
                            ::avro::decode(d, v.label);
                            break;

                        case 3:
                            ::avro::decode(d, v.properties);
                            break;

                        case 4:
                            ::avro::decode(d, v.info);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.typeId);
                ::avro::decode(d, v.typeDefinition);
                ::avro::decode(d, v.label);
                ::avro::decode(d, v.properties);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
