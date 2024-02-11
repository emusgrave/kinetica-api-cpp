/*
 *  This file was autogenerated by the Kinetica schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __GET_RECORDS_BY_COLUMN_H__
#define __GET_RECORDS_BY_COLUMN_H__

#include "../GenericRecord.hpp"

namespace gpudb
{
    /**
     * A set of parameters for @ref
     * GPUdb::getRecordsByColumn(const GetRecordsByColumnRequest&) const
     * "GPUdb::getRecordsByColumn".
     *
     * For a given table, retrieves the values from the requested column(s).
     * Maps of column name to the array of values as well as the column data
     * type are returned. This endpoint supports pagination with the @ref
     * offset and @ref limit parameters.
     *
     * <a href="../../../concepts/window/" target="_top">Window functions</a>,
     * which can perform operations like moving averages, are available through
     * this endpoint as well as @ref
     * GPUdb::createProjection(const CreateProjectionRequest&) const
     * "GPUdb::createProjection".
     *
     * When using pagination, if the table (or the underlying table in the case
     * of a view) is modified (records are inserted, updated, or deleted)
     * during a call to the endpoint, the records or values retrieved may
     * differ between calls based on the type of the update, e.g., the
     * contiguity across pages cannot be relied upon.
     *
     * If @ref tableName is empty, selection is performed against a single-row
     * virtual table.  This can be useful in executing temporal (<a
     * href="../../../concepts/expressions/#date-time-functions"
     * target="_top">NOW()</a>), identity (<a
     * href="../../../concepts/expressions/#user-security-functions"
     * target="_top">USER()</a>), or constant-based functions (<a
     * href="../../../concepts/expressions/#scalar-functions"
     * target="_top">GEODIST(-77.11, 38.88, -71.06, 42.36)</a>).
     *
     * The response is returned as a dynamic schema. For details see: <a
     * href="../../../api/concepts/#dynamic-schemas" target="_top">dynamic
     * schemas documentation</a>.
     */
    struct GetRecordsByColumnRequest
    {
        /**
         * Constructs a GetRecordsByColumnRequest object with default
         * parameters.
         */
        GetRecordsByColumnRequest() :
            tableName(std::string()),
            columnNames(std::vector<std::string>()),
            offset(int64_t()),
            limit(int64_t()),
            encoding(std::string("binary")),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a GetRecordsByColumnRequest object with the specified
         * parameters.
         *
         * @param[in] tableName_  Name of the table or view on which this
         *                        operation will be performed, in
         *                        [schema_name.]table_name format, using
         *                        standard <a
         *                        href="../../../concepts/tables/#table-name-resolution"
         *                        target="_top">name resolution rules</a>.  An
         *                        empty table name retrieves one record from a
         *                        single-row virtual table, where columns
         *                        specified should be constants or constant
         *                        expressions.
         * @param[in] columnNames_  The list of column values to retrieve.
         * @param[in] offset_  A positive integer indicating the number of
         *                     initial results to skip (this can be useful for
         *                     paging through the results). The default value
         *                     is 0. The minimum allowed value is 0. The
         *                     maximum allowed value is MAX_INT.
         * @param[in] limit_  A positive integer indicating the maximum number
         *                    of results to be returned, or END_OF_SET (-9999)
         *                    to indicate that the maximum number of results
         *                    allowed by the server should be returned.  The
         *                    number of records returned will never exceed the
         *                    server's own limit, defined by the <a
         *                    href="../../../config/#config-main-general"
         *                    target="_top">max_get_records_size</a> parameter
         *                    in the server configuration. Use @ref
         *                    gpudb::RawGetRecordsByColumnResponse::hasMoreRecords
         *                    "hasMoreRecords" to see if more records exist in
         *                    the result to be fetched, and @a offset_ & @a
         *                    limit_ to request subsequent pages of results.
         *                    The default value is -9999.
         * @param[in] options_  <ul>
         *                          <li>@ref
         *                              gpudb::get_records_by_column_expression
         *                              "get_records_by_column_expression":
         *                              Optional filter expression to apply to
         *                              the table.
         *                          <li>@ref
         *                              gpudb::get_records_by_column_sort_by
         *                              "get_records_by_column_sort_by":
         *                              Optional column that the data should be
         *                              sorted by. Used in conjunction with
         *                              @ref
         *                              gpudb::get_records_by_column_sort_order
         *                              "sort_order". The @ref
         *                              gpudb::get_records_by_column_order_by
         *                              "order_by" option can be used in lieu
         *                              of @ref
         *                              gpudb::get_records_by_column_sort_by
         *                              "sort_by" / @ref
         *                              gpudb::get_records_by_column_sort_order
         *                              "sort_order". The default value is ''.
         *                          <li>@ref
         *                              gpudb::get_records_by_column_sort_order
         *                              "get_records_by_column_sort_order":
         *                              String indicating how the returned
         *                              values should be sorted - @ref
         *                              gpudb::get_records_by_column_ascending
         *                              "ascending" or @ref
         *                              gpudb::get_records_by_column_descending
         *                              "descending". If @ref
         *                              gpudb::get_records_by_column_sort_order
         *                              "sort_order" is provided, @ref
         *                              gpudb::get_records_by_column_sort_by
         *                              "sort_by" has to be provided.
         *                              Supported values:
         *                              <ul>
         *                                  <li>@ref
         *                                      gpudb::get_records_by_column_ascending
         *                                      "get_records_by_column_ascending"
         *                                  <li>@ref
         *                                      gpudb::get_records_by_column_descending
         *                                      "get_records_by_column_descending"
         *                              </ul>
         *                              The default value is @ref
         *                              gpudb::get_records_by_column_ascending
         *                              "get_records_by_column_ascending".
         *                          <li>@ref
         *                              gpudb::get_records_by_column_order_by
         *                              "get_records_by_column_order_by":
         *                              Comma-separated list of the columns to
         *                              be sorted by as well as the sort
         *                              direction, e.g., 'timestamp asc, x
         *                              desc'. The default value is ''.
         *                          <li>@ref
         *                              gpudb::get_records_by_column_convert_wkts_to_wkbs
         *                              "get_records_by_column_convert_wkts_to_wkbs":
         *                              If @ref
         *                              gpudb::get_records_by_column_true
         *                              "true", then WKT string columns will be
         *                              returned as WKB bytes.
         *                              Supported values:
         *                              <ul>
         *                                  <li>@ref
         *                                      gpudb::get_records_by_column_true
         *                                      "get_records_by_column_true"
         *                                  <li>@ref
         *                                      gpudb::get_records_by_column_false
         *                                      "get_records_by_column_false"
         *                              </ul>
         *                              The default value is @ref
         *                              gpudb::get_records_by_column_false
         *                              "get_records_by_column_false".
         *                      </ul>
         *                      The default value is an empty map.
         */
        GetRecordsByColumnRequest(const std::string& tableName_, const std::vector<std::string>& columnNames_, const int64_t offset_, const int64_t limit_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            columnNames( columnNames_ ),
            offset( offset_ ),
            limit( limit_ ),
            encoding( "binary" ),
            options( options_ )
        {
        }

        /**
         * Constructs a GetRecordsByColumnRequest object with the specified
         * parameters.
         *
         * @param[in] tableName_  Name of the table or view on which this
         *                        operation will be performed, in
         *                        [schema_name.]table_name format, using
         *                        standard <a
         *                        href="../../../concepts/tables/#table-name-resolution"
         *                        target="_top">name resolution rules</a>.  An
         *                        empty table name retrieves one record from a
         *                        single-row virtual table, where columns
         *                        specified should be constants or constant
         *                        expressions.
         * @param[in] columnNames_  The list of column values to retrieve.
         * @param[in] offset_  A positive integer indicating the number of
         *                     initial results to skip (this can be useful for
         *                     paging through the results). The default value
         *                     is 0. The minimum allowed value is 0. The
         *                     maximum allowed value is MAX_INT.
         * @param[in] limit_  A positive integer indicating the maximum number
         *                    of results to be returned, or END_OF_SET (-9999)
         *                    to indicate that the maximum number of results
         *                    allowed by the server should be returned.  The
         *                    number of records returned will never exceed the
         *                    server's own limit, defined by the <a
         *                    href="../../../config/#config-main-general"
         *                    target="_top">max_get_records_size</a> parameter
         *                    in the server configuration. Use @ref
         *                    gpudb::RawGetRecordsByColumnResponse::hasMoreRecords
         *                    "hasMoreRecords" to see if more records exist in
         *                    the result to be fetched, and @a offset_ & @a
         *                    limit_ to request subsequent pages of results.
         *                    The default value is -9999.
         * @param[in] encoding_  Specifies the encoding for returned records;
         *                       either @ref
         *                       gpudb::get_records_by_column_binary "binary"
         *                       or @ref gpudb::get_records_by_column_json
         *                       "json".
         *                       Supported values:
         *                       <ul>
         *                           <li>@ref
         *                               gpudb::get_records_by_column_binary
         *                               "get_records_by_column_binary"
         *                           <li>@ref gpudb::get_records_by_column_json
         *                               "get_records_by_column_json"
         *                       </ul>
         *                       The default value is @ref
         *                       gpudb::get_records_by_column_binary
         *                       "get_records_by_column_binary".
         * @param[in] options_  <ul>
         *                          <li>@ref
         *                              gpudb::get_records_by_column_expression
         *                              "get_records_by_column_expression":
         *                              Optional filter expression to apply to
         *                              the table.
         *                          <li>@ref
         *                              gpudb::get_records_by_column_sort_by
         *                              "get_records_by_column_sort_by":
         *                              Optional column that the data should be
         *                              sorted by. Used in conjunction with
         *                              @ref
         *                              gpudb::get_records_by_column_sort_order
         *                              "sort_order". The @ref
         *                              gpudb::get_records_by_column_order_by
         *                              "order_by" option can be used in lieu
         *                              of @ref
         *                              gpudb::get_records_by_column_sort_by
         *                              "sort_by" / @ref
         *                              gpudb::get_records_by_column_sort_order
         *                              "sort_order". The default value is ''.
         *                          <li>@ref
         *                              gpudb::get_records_by_column_sort_order
         *                              "get_records_by_column_sort_order":
         *                              String indicating how the returned
         *                              values should be sorted - @ref
         *                              gpudb::get_records_by_column_ascending
         *                              "ascending" or @ref
         *                              gpudb::get_records_by_column_descending
         *                              "descending". If @ref
         *                              gpudb::get_records_by_column_sort_order
         *                              "sort_order" is provided, @ref
         *                              gpudb::get_records_by_column_sort_by
         *                              "sort_by" has to be provided.
         *                              Supported values:
         *                              <ul>
         *                                  <li>@ref
         *                                      gpudb::get_records_by_column_ascending
         *                                      "get_records_by_column_ascending"
         *                                  <li>@ref
         *                                      gpudb::get_records_by_column_descending
         *                                      "get_records_by_column_descending"
         *                              </ul>
         *                              The default value is @ref
         *                              gpudb::get_records_by_column_ascending
         *                              "get_records_by_column_ascending".
         *                          <li>@ref
         *                              gpudb::get_records_by_column_order_by
         *                              "get_records_by_column_order_by":
         *                              Comma-separated list of the columns to
         *                              be sorted by as well as the sort
         *                              direction, e.g., 'timestamp asc, x
         *                              desc'. The default value is ''.
         *                          <li>@ref
         *                              gpudb::get_records_by_column_convert_wkts_to_wkbs
         *                              "get_records_by_column_convert_wkts_to_wkbs":
         *                              If @ref
         *                              gpudb::get_records_by_column_true
         *                              "true", then WKT string columns will be
         *                              returned as WKB bytes.
         *                              Supported values:
         *                              <ul>
         *                                  <li>@ref
         *                                      gpudb::get_records_by_column_true
         *                                      "get_records_by_column_true"
         *                                  <li>@ref
         *                                      gpudb::get_records_by_column_false
         *                                      "get_records_by_column_false"
         *                              </ul>
         *                              The default value is @ref
         *                              gpudb::get_records_by_column_false
         *                              "get_records_by_column_false".
         *                      </ul>
         *                      The default value is an empty map.
         */
        GetRecordsByColumnRequest(const std::string& tableName_, const std::vector<std::string>& columnNames_, const int64_t offset_, const int64_t limit_, const std::string& encoding_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            columnNames( columnNames_ ),
            offset( offset_ ),
            limit( limit_ ),
            encoding( encoding_ ),
            options( options_ )
        {
        }

        /**
         * Name of the table or view on which this operation will be performed,
         * in [ schema_name.\ ]table_name format, using standard <a
         * href="../../../concepts/tables/#table-name-resolution"
         * target="_top">name resolution rules</a>.  An empty table name
         * retrieves one record from a single-row virtual table, where columns
         * specified should be constants or constant expressions.
         */
        std::string tableName;

        /**
         * The list of column values to retrieve.
         */
        std::vector<std::string> columnNames;

        /**
         * A positive integer indicating the number of initial results to skip
         * (this can be useful for paging through the results). The default
         * value is 0. The minimum allowed value is 0. The maximum allowed
         * value is MAX_INT.
         */
        int64_t offset;

        /**
         * A positive integer indicating the maximum number of results to be
         * returned, or END_OF_SET (-9999) to indicate that the maximum number
         * of results allowed by the server should be returned.  The number of
         * records returned will never exceed the server's own limit, defined
         * by the <a href="../../../config/#config-main-general"
         * target="_top">max_get_records_size</a> parameter in the server
         * configuration. Use @ref
         * gpudb::RawGetRecordsByColumnResponse::hasMoreRecords
         * "hasMoreRecords" to see if more records exist in the result to be
         * fetched, and @ref offset & @ref limit to request subsequent pages of
         * results. The default value is -9999.
         */
        int64_t limit;

        /**
         * Specifies the encoding for returned records; either @ref
         * gpudb::get_records_by_column_binary "binary" or @ref
         * gpudb::get_records_by_column_json "json".
         * Supported values:
         * <ul>
         *     <li>@ref gpudb::get_records_by_column_binary
         *         "get_records_by_column_binary"
         *     <li>@ref gpudb::get_records_by_column_json
         *         "get_records_by_column_json"
         * </ul>
         * The default value is @ref gpudb::get_records_by_column_binary
         * "get_records_by_column_binary".
         */
        std::string encoding;

        /**
         * <ul>
         *     <li>@ref gpudb::get_records_by_column_expression
         *         "get_records_by_column_expression": Optional filter
         *         expression to apply to the table.
         *     <li>@ref gpudb::get_records_by_column_sort_by
         *         "get_records_by_column_sort_by": Optional column that the
         *         data should be sorted by. Used in conjunction with @ref
         *         gpudb::get_records_by_column_sort_order "sort_order". The
         *         @ref gpudb::get_records_by_column_order_by "order_by" option
         *         can be used in lieu of @ref
         *         gpudb::get_records_by_column_sort_by "sort_by" / @ref
         *         gpudb::get_records_by_column_sort_order "sort_order". The
         *         default value is ''.
         *     <li>@ref gpudb::get_records_by_column_sort_order
         *         "get_records_by_column_sort_order": String indicating how
         *         the returned values should be sorted - @ref
         *         gpudb::get_records_by_column_ascending "ascending" or @ref
         *         gpudb::get_records_by_column_descending "descending". If
         *         @ref gpudb::get_records_by_column_sort_order "sort_order" is
         *         provided, @ref gpudb::get_records_by_column_sort_by
         *         "sort_by" has to be provided.
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::get_records_by_column_ascending
         *                 "get_records_by_column_ascending"
         *             <li>@ref gpudb::get_records_by_column_descending
         *                 "get_records_by_column_descending"
         *         </ul>
         *         The default value is @ref
         *         gpudb::get_records_by_column_ascending
         *         "get_records_by_column_ascending".
         *     <li>@ref gpudb::get_records_by_column_order_by
         *         "get_records_by_column_order_by": Comma-separated list of
         *         the columns to be sorted by as well as the sort direction,
         *         e.g., 'timestamp asc, x desc'. The default value is ''.
         *     <li>@ref gpudb::get_records_by_column_convert_wkts_to_wkbs
         *         "get_records_by_column_convert_wkts_to_wkbs": If @ref
         *         gpudb::get_records_by_column_true "true", then WKT string
         *         columns will be returned as WKB bytes.
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::get_records_by_column_true
         *                 "get_records_by_column_true"
         *             <li>@ref gpudb::get_records_by_column_false
         *                 "get_records_by_column_false"
         *         </ul>
         *         The default value is @ref gpudb::get_records_by_column_false
         *         "get_records_by_column_false".
         * </ul>
         * The default value is an empty map.
         */
        std::map<std::string, std::string> options;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::GetRecordsByColumnRequest>
    {
        static void encode(Encoder& e, const gpudb::GetRecordsByColumnRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.columnNames);
            ::avro::encode(e, v.offset);
            ::avro::encode(e, v.limit);
            ::avro::encode(e, v.encoding);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::GetRecordsByColumnRequest& v)
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
                            ::avro::decode(d, v.columnNames);
                            break;

                        case 2:
                            ::avro::decode(d, v.offset);
                            break;

                        case 3:
                            ::avro::decode(d, v.limit);
                            break;

                        case 4:
                            ::avro::decode(d, v.encoding);
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
                ::avro::decode(d, v.columnNames);
                ::avro::decode(d, v.offset);
                ::avro::decode(d, v.limit);
                ::avro::decode(d, v.encoding);
                ::avro::decode(d, v.options);
            }
        }
    };
} // end namespace avro

namespace gpudb
{
    /**
     * A set of results returned by @ref
     * GPUdb::getRecordsByColumnRaw(const GetRecordsByColumnRequest&) const
     * "GPUdb::getRecordsByColumnRaw".
     */
    struct RawGetRecordsByColumnResponse
    {
        /**
         * Constructs a RawGetRecordsByColumnResponse object with default
         * parameters.
         */
        RawGetRecordsByColumnResponse() :
            tableName(std::string()),
            responseSchemaStr(std::string()),
            binaryEncodedResponse(std::vector<uint8_t>()),
            jsonEncodedResponse(std::string()),
            totalNumberOfRecords(int64_t()),
            hasMoreRecords(bool()),
            info(std::map<std::string, std::string>())
        {
        }

        /**
         * The same table name as was passed in the parameter list.
         */
        std::string tableName;

        /**
         * Avro schema of @ref binaryEncodedResponse or @ref
         * jsonEncodedResponse.
         */
        std::string responseSchemaStr;

        /**
         * Avro binary encoded response.
         */
        std::vector<uint8_t> binaryEncodedResponse;

        /**
         * Avro JSON encoded response.
         */
        std::string jsonEncodedResponse;

        /**
         * Total/Filtered number of records.
         */
        int64_t totalNumberOfRecords;

        /**
         * Too many records. Returned a partial set.
         */
        bool hasMoreRecords;

        /**
         * Additional information.
         */
        std::map<std::string, std::string> info;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::RawGetRecordsByColumnResponse>
    {
        static void encode(Encoder& e, const gpudb::RawGetRecordsByColumnResponse& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.responseSchemaStr);
            ::avro::encode(e, v.binaryEncodedResponse);
            ::avro::encode(e, v.jsonEncodedResponse);
            ::avro::encode(e, v.totalNumberOfRecords);
            ::avro::encode(e, v.hasMoreRecords);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::RawGetRecordsByColumnResponse& v)
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
                            ::avro::decode(d, v.responseSchemaStr);
                            break;

                        case 2:
                            ::avro::decode(d, v.binaryEncodedResponse);
                            break;

                        case 3:
                            ::avro::decode(d, v.jsonEncodedResponse);
                            break;

                        case 4:
                            ::avro::decode(d, v.totalNumberOfRecords);
                            break;

                        case 5:
                            ::avro::decode(d, v.hasMoreRecords);
                            break;

                        case 6:
                            ::avro::decode(d, v.info);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.tableName);
                ::avro::decode(d, v.responseSchemaStr);
                ::avro::decode(d, v.binaryEncodedResponse);
                ::avro::decode(d, v.jsonEncodedResponse);
                ::avro::decode(d, v.totalNumberOfRecords);
                ::avro::decode(d, v.hasMoreRecords);
                ::avro::decode(d, v.info);
            }
        }
    };
} // end namespace avro

namespace gpudb
{
    /**
     * A set of results returned by @ref
     * GPUdb::getRecordsByColumn(const GetRecordsByColumnRequest&) const
     * "GPUdb::getRecordsByColumn".
     */
    struct GetRecordsByColumnResponse
    {
        /**
         * Constructs a GetRecordsByColumnResponse object with default
         * parameters.
         */
        GetRecordsByColumnResponse() :
            tableName(std::string()),
            responseSchemaStr(std::string()),
            data(std::vector<gpudb::GenericRecord>()),
            totalNumberOfRecords(int64_t()),
            hasMoreRecords(bool()),
            info(std::map<std::string, std::string>()),
            dataTypePtr((gpudb::Type*)NULL)
        {
        }

        /**
         * The same table name as was passed in the parameter list.
         */
        std::string tableName;

        /**
         * Avro schema of @ref data or @a jsonEncodedResponse.
         */
        std::string responseSchemaStr;

        /**
         * Avro binary encoded response.
         */
        std::vector<gpudb::GenericRecord> data;

        /**
         * Total/Filtered number of records.
         */
        int64_t totalNumberOfRecords;

        /**
         * Too many records. Returned a partial set.
         */
        bool hasMoreRecords;

        /**
         * Additional information.
         */
        std::map<std::string, std::string> info;

        gpudb_type_ptr_t dataTypePtr;
    };
} // end namespace gpudb

#endif // __GET_RECORDS_BY_COLUMN_H__
