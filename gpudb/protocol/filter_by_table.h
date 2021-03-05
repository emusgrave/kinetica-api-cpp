/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __FILTER_BY_TABLE_H__
#define __FILTER_BY_TABLE_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #filterByTable(const FilterByTableRequest&) const}.
     * <p>
     * Filters objects in one table based on objects in another table. The
     * user must specify matching column types from the two tables (i.e. the
     * target
     * table from which objects will be filtered and the source table based on
     * which
     * the filter will be created); the column names need not be the same. If a
     * @a viewName is specified, then the filtered objects will then be put in
     * a
     * newly created view. The operation is synchronous, meaning that a
     * response will
     * not be returned until all objects are fully available in the result
     * view. The
     * return value contains the count (i.e. the size) of the resulting view.
     */
    struct FilterByTableRequest
    {

        /**
         * Constructs a FilterByTableRequest object with default parameter
         * values.
         */
        FilterByTableRequest() :
            tableName(std::string()),
            viewName(std::string()),
            columnName(std::string()),
            sourceTableName(std::string()),
            sourceTableColumnName(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a FilterByTableRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Name of the table whose data will be
         *                        filtered, in [schema_name.]table_name format,
         *                        using standard <a
         *                        href="../../../concepts/tables/#table-name-resolution"
         *                        target="_top">name resolution rules</a>.
         *                        Must be an existing table.
         * @param[in] viewName_  If provided, then this will be the name of the
         *                       view containing the results, in
         *                       [schema_name.]view_name format, using standard
         *                       <a
         *                       href="../../../concepts/tables/#table-name-resolution"
         *                       target="_top">name resolution rules</a> and
         *                       meeting <a
         *                       href="../../../concepts/tables/#table-naming-criteria"
         *                       target="_top">table naming criteria</a>.  Must
         *                       not be an already existing table or view.
         * @param[in] columnName_  Name of the column by whose value the data
         *                         will be filtered from the table designated
         *                         by @a tableName.
         * @param[in] sourceTableName_  Name of the table whose data will be
         *                              compared against in the table called @a
         *                              tableName, in [schema_name.]table_name
         *                              format, using standard <a
         *                              href="../../../concepts/tables/#table-name-resolution"
         *                              target="_top">name resolution
         *                              rules</a>.  Must be an existing table.
         * @param[in] sourceTableColumnName_  Name of the column in the @a
         *                                    sourceTableName whose values will
         *                                    be used as the filter for table
         *                                    @a tableName. Must be a
         *                                    geospatial geometry column if in
         *                                    'spatial' mode; otherwise, Must
         *                                    match the type of the @a
         *                                    columnName.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::filter_by_table_collection_name:
         *                      [DEPRECATED--please specify the containing
         *                      schema for the view as part of @a viewName and
         *                      use /create/schema to create the schema if
         *                      non-existent]  Name of a schema for the newly
         *                      created view. If the schema is non-existent, it
         *                      will be automatically created.
         *                              <li>
         *                      gpudb::filter_by_table_filter_mode: String
         *                      indicating the filter mode, either @a in_table
         *                      or @a not_in_table.
         *                      <ul>
         *                              <li> gpudb::filter_by_table_in_table
         *                              <li>
         *                      gpudb::filter_by_table_not_in_table
         *                      </ul>
         *                      The default value is
         *                      gpudb::filter_by_table_in_table.
         *                              <li> gpudb::filter_by_table_mode: Mode
         *                      - should be either @a spatial or @a normal.
         *                      <ul>
         *                              <li> gpudb::filter_by_table_normal
         *                              <li> gpudb::filter_by_table_spatial
         *                      </ul>
         *                      The default value is
         *                      gpudb::filter_by_table_normal.
         *                              <li> gpudb::filter_by_table_buffer:
         *                      Buffer size, in meters. Only relevant for @a
         *                      spatial mode.  The default value is '0'.
         *                              <li>
         *                      gpudb::filter_by_table_buffer_method: Method
         *                      used to buffer polygons.  Only relevant for @a
         *                      spatial mode.
         *                      <ul>
         *                              <li> gpudb::filter_by_table_normal
         *                              <li> gpudb::filter_by_table_geos: Use
         *                      geos 1 edge per corner algorithm
         *                      </ul>
         *                      The default value is
         *                      gpudb::filter_by_table_normal.
         *                              <li>
         *                      gpudb::filter_by_table_max_partition_size:
         *                      Maximum number of points in a partition. Only
         *                      relevant for @a spatial mode.  The default
         *                      value is '0'.
         *                              <li>
         *                      gpudb::filter_by_table_max_partition_score:
         *                      Maximum number of points * edges in a
         *                      partition. Only relevant for @a spatial mode.
         *                      The default value is '8000000'.
         *                              <li>
         *                      gpudb::filter_by_table_x_column_name: Name of
         *                      column containing x value of point being
         *                      filtered in @a spatial mode.  The default value
         *                      is 'x'.
         *                              <li>
         *                      gpudb::filter_by_table_y_column_name: Name of
         *                      column containing y value of point being
         *                      filtered in @a spatial mode.  The default value
         *                      is 'y'.
         *                      </ul>
         * 
         */
        FilterByTableRequest(const std::string& tableName_, const std::string& viewName_, const std::string& columnName_, const std::string& sourceTableName_, const std::string& sourceTableColumnName_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            viewName( viewName_ ),
            columnName( columnName_ ),
            sourceTableName( sourceTableName_ ),
            sourceTableColumnName( sourceTableColumnName_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::string viewName;
        std::string columnName;
        std::string sourceTableName;
        std::string sourceTableColumnName;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::FilterByTableRequest>
    {
        static void encode(Encoder& e, const gpudb::FilterByTableRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.viewName);
            ::avro::encode(e, v.columnName);
            ::avro::encode(e, v.sourceTableName);
            ::avro::encode(e, v.sourceTableColumnName);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::FilterByTableRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.tableName);
                            break;

                        case 1:
                            ::avro::decode(d, v.viewName);
                            break;

                        case 2:
                            ::avro::decode(d, v.columnName);
                            break;

                        case 3:
                            ::avro::decode(d, v.sourceTableName);
                            break;

                        case 4:
                            ::avro::decode(d, v.sourceTableColumnName);
                            break;

                        case 5:
                            ::avro::decode(d, v.options);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.tableName);
                ::avro::decode(d, v.viewName);
                ::avro::decode(d, v.columnName);
                ::avro::decode(d, v.sourceTableName);
                ::avro::decode(d, v.sourceTableColumnName);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #filterByTable(const FilterByTableRequest&) const}.
     * <p>
     * Filters objects in one table based on objects in another table. The
     * user must specify matching column types from the two tables (i.e. the
     * target
     * table from which objects will be filtered and the source table based on
     * which
     * the filter will be created); the column names need not be the same. If a
     * @a viewName is specified, then the filtered objects will then be put in
     * a
     * newly created view. The operation is synchronous, meaning that a
     * response will
     * not be returned until all objects are fully available in the result
     * view. The
     * return value contains the count (i.e. the size) of the resulting view.
     */
    struct FilterByTableResponse
    {

        /**
         * Constructs a FilterByTableResponse object with default parameter
         * values.
         */
        FilterByTableResponse() :
            count(int64_t()),
            info(std::map<std::string, std::string>())
        {
        }

        int64_t count;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::FilterByTableResponse>
    {
        static void encode(Encoder& e, const gpudb::FilterByTableResponse& v)
        {
            ::avro::encode(e, v.count);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::FilterByTableResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.count);
                            break;

                        case 1:
                            ::avro::decode(d, v.info);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.count);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
