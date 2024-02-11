/*
 *  This file was autogenerated by the Kinetica schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __FILTER_BY_TABLE_H__
#define __FILTER_BY_TABLE_H__

namespace gpudb
{
    /**
     * A set of parameters for @ref
     * GPUdb::filterByTable(const FilterByTableRequest&) const
     * "GPUdb::filterByTable".
     *
     * Filters objects in one table based on objects in another table. The user
     * must specify matching column types from the two tables (i.e. the target
     * table from which objects will be filtered and the source table based on
     * which the filter will be created); the column names need not be the
     * same. If a @ref viewName is specified, then the filtered objects will
     * then be put in a newly created view. The operation is synchronous,
     * meaning that a response will not be returned until all objects are fully
     * available in the result view. The return value contains the count (i.e.
     * the size) of the resulting view.
     */
    struct FilterByTableRequest
    {
        /**
         * Constructs a FilterByTableRequest object with default parameters.
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
         *                       not be an already existing table or view. The
         *                       default value is ''.
         * @param[in] columnName_  Name of the column by whose value the data
         *                         will be filtered from the table designated
         *                         by @a tableName_.
         * @param[in] sourceTableName_  Name of the table whose data will be
         *                              compared against in the table called @a
         *                              tableName_, in [schema_name.]table_name
         *                              format, using standard <a
         *                              href="../../../concepts/tables/#table-name-resolution"
         *                              target="_top">name resolution
         *                              rules</a>.  Must be an existing table.
         * @param[in] sourceTableColumnName_  Name of the column in the @a
         *                                    sourceTableName_ whose values
         *                                    will be used as the filter for
         *                                    table @a tableName_. Must be a
         *                                    geospatial geometry column if in
         *                                    'spatial' mode; otherwise, Must
         *                                    match the type of the @a
         *                                    columnName_.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                          <li>@ref
         *                              gpudb::filter_by_table_create_temp_table
         *                              "filter_by_table_create_temp_table": If
         *                              @ref gpudb::filter_by_table_true
         *                              "true", a unique temporary table name
         *                              will be generated in the sys_temp
         *                              schema and used in place of @a
         *                              viewName_. This is always allowed even
         *                              if the caller does not have permission
         *                              to create tables. The generated name is
         *                              returned in @ref
         *                              gpudb::filter_by_table_qualified_view_name
         *                              "qualified_view_name".
         *                              Supported values:
         *                              <ul>
         *                                  <li>@ref
         *                                      gpudb::filter_by_table_true
         *                                      "filter_by_table_true"
         *                                  <li>@ref
         *                                      gpudb::filter_by_table_false
         *                                      "filter_by_table_false"
         *                              </ul>
         *                              The default value is @ref
         *                              gpudb::filter_by_table_false
         *                              "filter_by_table_false".
         *                          <li>@ref
         *                              gpudb::filter_by_table_collection_name
         *                              "filter_by_table_collection_name":
         *                              [DEPRECATED--please specify the
         *                              containing schema for the view as part
         *                              of @a viewName_ and use @ref
         *                              GPUdb::createSchema(const CreateSchemaRequest&) const
         *                              "GPUdb::createSchema" to create the
         *                              schema if non-existent]  Name of a
         *                              schema for the newly created view. If
         *                              the schema is non-existent, it will be
         *                              automatically created.
         *                          <li>@ref gpudb::filter_by_table_filter_mode
         *                              "filter_by_table_filter_mode": String
         *                              indicating the filter mode, either @ref
         *                              gpudb::filter_by_table_in_table
         *                              "in_table" or @ref
         *                              gpudb::filter_by_table_not_in_table
         *                              "not_in_table".
         *                              Supported values:
         *                              <ul>
         *                                  <li>@ref
         *                                      gpudb::filter_by_table_in_table
         *                                      "filter_by_table_in_table"
         *                                  <li>@ref
         *                                      gpudb::filter_by_table_not_in_table
         *                                      "filter_by_table_not_in_table"
         *                              </ul>
         *                              The default value is @ref
         *                              gpudb::filter_by_table_in_table
         *                              "filter_by_table_in_table".
         *                          <li>@ref gpudb::filter_by_table_mode
         *                              "filter_by_table_mode": Mode - should
         *                              be either @ref
         *                              gpudb::filter_by_table_spatial
         *                              "spatial" or @ref
         *                              gpudb::filter_by_table_normal "normal".
         *                              Supported values:
         *                              <ul>
         *                                  <li>@ref
         *                                      gpudb::filter_by_table_normal
         *                                      "filter_by_table_normal"
         *                                  <li>@ref
         *                                      gpudb::filter_by_table_spatial
         *                                      "filter_by_table_spatial"
         *                              </ul>
         *                              The default value is @ref
         *                              gpudb::filter_by_table_normal
         *                              "filter_by_table_normal".
         *                          <li>@ref gpudb::filter_by_table_buffer
         *                              "filter_by_table_buffer": Buffer size,
         *                              in meters. Only relevant for @ref
         *                              gpudb::filter_by_table_spatial
         *                              "spatial" mode. The default value is
         *                              '0'.
         *                          <li>@ref
         *                              gpudb::filter_by_table_buffer_method
         *                              "filter_by_table_buffer_method": Method
         *                              used to buffer polygons.  Only relevant
         *                              for @ref gpudb::filter_by_table_spatial
         *                              "spatial" mode.
         *                              Supported values:
         *                              <ul>
         *                                  <li>@ref
         *                                      gpudb::filter_by_table_normal
         *                                      "filter_by_table_normal"
         *                                  <li>@ref
         *                                      gpudb::filter_by_table_geos
         *                                      "filter_by_table_geos": Use
         *                                      geos 1 edge per corner
         *                                      algorithm
         *                              </ul>
         *                              The default value is @ref
         *                              gpudb::filter_by_table_normal
         *                              "filter_by_table_normal".
         *                          <li>@ref
         *                              gpudb::filter_by_table_max_partition_size
         *                              "filter_by_table_max_partition_size":
         *                              Maximum number of points in a
         *                              partition. Only relevant for @ref
         *                              gpudb::filter_by_table_spatial
         *                              "spatial" mode. The default value is
         *                              '0'.
         *                          <li>@ref
         *                              gpudb::filter_by_table_max_partition_score
         *                              "filter_by_table_max_partition_score":
         *                              Maximum number of points * edges in a
         *                              partition. Only relevant for @ref
         *                              gpudb::filter_by_table_spatial
         *                              "spatial" mode. The default value is
         *                              '8000000'.
         *                          <li>@ref
         *                              gpudb::filter_by_table_x_column_name
         *                              "filter_by_table_x_column_name": Name
         *                              of column containing x value of point
         *                              being filtered in @ref
         *                              gpudb::filter_by_table_spatial
         *                              "spatial" mode. The default value is
         *                              'x'.
         *                          <li>@ref
         *                              gpudb::filter_by_table_y_column_name
         *                              "filter_by_table_y_column_name": Name
         *                              of column containing y value of point
         *                              being filtered in @ref
         *                              gpudb::filter_by_table_spatial
         *                              "spatial" mode. The default value is
         *                              'y'.
         *                      </ul>
         *                      The default value is an empty map.
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

        /**
         * Name of the table whose data will be filtered, in [ schema_name.\
         * ]table_name format, using standard <a
         * href="../../../concepts/tables/#table-name-resolution"
         * target="_top">name resolution rules</a>.  Must be an existing table.
         */
        std::string tableName;

        /**
         * If provided, then this will be the name of the view containing the
         * results, in [ schema_name.\ ]view_name format, using standard <a
         * href="../../../concepts/tables/#table-name-resolution"
         * target="_top">name resolution rules</a> and meeting <a
         * href="../../../concepts/tables/#table-naming-criteria"
         * target="_top">table naming criteria</a>.  Must not be an already
         * existing table or view. The default value is ''.
         */
        std::string viewName;

        /**
         * Name of the column by whose value the data will be filtered from the
         * table designated by @ref tableName.
         */
        std::string columnName;

        /**
         * Name of the table whose data will be compared against in the table
         * called @ref tableName, in [ schema_name.\ ]table_name format, using
         * standard <a href="../../../concepts/tables/#table-name-resolution"
         * target="_top">name resolution rules</a>.  Must be an existing table.
         */
        std::string sourceTableName;

        /**
         * Name of the column in the @ref sourceTableName whose values will be
         * used as the filter for table @ref tableName. Must be a geospatial
         * geometry column if in 'spatial' mode; otherwise, Must match the type
         * of the @ref columnName.
         */
        std::string sourceTableColumnName;

        /**
         * Optional parameters.
         * <ul>
         *     <li>@ref gpudb::filter_by_table_create_temp_table
         *         "filter_by_table_create_temp_table": If @ref
         *         gpudb::filter_by_table_true "true", a unique temporary table
         *         name will be generated in the sys_temp schema and used in
         *         place of @ref viewName. This is always allowed even if the
         *         caller does not have permission to create tables. The
         *         generated name is returned in @ref
         *         gpudb::filter_by_table_qualified_view_name
         *         "qualified_view_name".
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::filter_by_table_true
         *                 "filter_by_table_true"
         *             <li>@ref gpudb::filter_by_table_false
         *                 "filter_by_table_false"
         *         </ul>
         *         The default value is @ref gpudb::filter_by_table_false
         *         "filter_by_table_false".
         *     <li>@ref gpudb::filter_by_table_collection_name
         *         "filter_by_table_collection_name": [DEPRECATED--please
         *         specify the containing schema for the view as part of @ref
         *         viewName and use @ref
         *         GPUdb::createSchema(const CreateSchemaRequest&) const
         *         "GPUdb::createSchema" to create the schema if non-existent]
         *         Name of a schema for the newly created view. If the schema
         *         is non-existent, it will be automatically created.
         *     <li>@ref gpudb::filter_by_table_filter_mode
         *         "filter_by_table_filter_mode": String indicating the filter
         *         mode, either @ref gpudb::filter_by_table_in_table "in_table"
         *         or @ref gpudb::filter_by_table_not_in_table "not_in_table".
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::filter_by_table_in_table
         *                 "filter_by_table_in_table"
         *             <li>@ref gpudb::filter_by_table_not_in_table
         *                 "filter_by_table_not_in_table"
         *         </ul>
         *         The default value is @ref gpudb::filter_by_table_in_table
         *         "filter_by_table_in_table".
         *     <li>@ref gpudb::filter_by_table_mode "filter_by_table_mode":
         *         Mode - should be either @ref gpudb::filter_by_table_spatial
         *         "spatial" or @ref gpudb::filter_by_table_normal "normal".
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::filter_by_table_normal
         *                 "filter_by_table_normal"
         *             <li>@ref gpudb::filter_by_table_spatial
         *                 "filter_by_table_spatial"
         *         </ul>
         *         The default value is @ref gpudb::filter_by_table_normal
         *         "filter_by_table_normal".
         *     <li>@ref gpudb::filter_by_table_buffer "filter_by_table_buffer":
         *         Buffer size, in meters. Only relevant for @ref
         *         gpudb::filter_by_table_spatial "spatial" mode. The default
         *         value is '0'.
         *     <li>@ref gpudb::filter_by_table_buffer_method
         *         "filter_by_table_buffer_method": Method used to buffer
         *         polygons.  Only relevant for @ref
         *         gpudb::filter_by_table_spatial "spatial" mode.
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::filter_by_table_normal
         *                 "filter_by_table_normal"
         *             <li>@ref gpudb::filter_by_table_geos
         *                 "filter_by_table_geos": Use geos 1 edge per corner
         *                 algorithm
         *         </ul>
         *         The default value is @ref gpudb::filter_by_table_normal
         *         "filter_by_table_normal".
         *     <li>@ref gpudb::filter_by_table_max_partition_size
         *         "filter_by_table_max_partition_size": Maximum number of
         *         points in a partition. Only relevant for @ref
         *         gpudb::filter_by_table_spatial "spatial" mode. The default
         *         value is '0'.
         *     <li>@ref gpudb::filter_by_table_max_partition_score
         *         "filter_by_table_max_partition_score": Maximum number of
         *         points * edges in a partition. Only relevant for @ref
         *         gpudb::filter_by_table_spatial "spatial" mode. The default
         *         value is '8000000'.
         *     <li>@ref gpudb::filter_by_table_x_column_name
         *         "filter_by_table_x_column_name": Name of column containing x
         *         value of point being filtered in @ref
         *         gpudb::filter_by_table_spatial "spatial" mode. The default
         *         value is 'x'.
         *     <li>@ref gpudb::filter_by_table_y_column_name
         *         "filter_by_table_y_column_name": Name of column containing y
         *         value of point being filtered in @ref
         *         gpudb::filter_by_table_spatial "spatial" mode. The default
         *         value is 'y'.
         * </ul>
         * The default value is an empty map.
         */
        std::map<std::string, std::string> options;
    };
} // end namespace gpudb

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
} // end namespace avro

namespace gpudb
{
    /**
     * A set of results returned by @ref
     * GPUdb::filterByTable(const FilterByTableRequest&) const
     * "GPUdb::filterByTable".
     */
    struct FilterByTableResponse
    {
        /**
         * Constructs a FilterByTableResponse object with default parameters.
         */
        FilterByTableResponse() :
            count(int64_t()),
            info(std::map<std::string, std::string>())
        {
        }

        /**
         * The number of records in @ref gpudb::FilterByTableRequest::tableName
         * "tableName" that have @ref gpudb::FilterByTableRequest::columnName
         * "columnName" values matching @ref
         * gpudb::FilterByTableRequest::sourceTableColumnName
         * "sourceTableColumnName" values in @ref
         * gpudb::FilterByTableRequest::sourceTableName "sourceTableName".
         */
        int64_t count;

        /**
         * Additional information.
         * <ul>
         *     <li>@ref gpudb::filter_by_table_qualified_view_name
         *         "filter_by_table_qualified_view_name": The fully qualified
         *         name of the view (i.e. including the schema)
         * </ul>
         * The default value is an empty map.
         */
        std::map<std::string, std::string> info;
    };
} // end namespace gpudb

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
} // end namespace avro

#endif // __FILTER_BY_TABLE_H__
