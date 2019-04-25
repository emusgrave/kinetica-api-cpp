/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __GET_RECORDS_BY_COLUMN_H__
#define __GET_RECORDS_BY_COLUMN_H__

#include "../GenericRecord.hpp"

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #getRecordsByColumnRaw(const GetRecordsByColumnRequest&) const}.
     * <p>
     * For a given table, retrieves the values from the requested column(s).
     * Maps of column name to the array of values as well as the column data
     * type are returned. This endpoint supports pagination with the @a offset
     * and @a limit parameters.
     * <p>
     * <a href="../../concepts/window.html" target="_top">Window functions</a>,
     * which can perform operations like moving averages, are available through
     * this endpoint as well as {@link
     * #createProjection(const CreateProjectionRequest&) const}.
     * <p>
     * When using pagination, if the table (or the underlying table in the case
     * of a view) is modified (records are inserted, updated, or deleted)
     * during a call to the endpoint, the records or values retrieved may
     * differ between calls based on the type of the update, e.g., the
     * contiguity across pages cannot be relied upon.
     * <p>
     * The response is returned as a dynamic schema. For details see: <a
     * href="../../api/index.html#dynamic-schemas" target="_top">dynamic
     * schemas documentation</a>.
     */
    struct GetRecordsByColumnRequest
    {

        /**
         * Constructs a GetRecordsByColumnRequest object with default parameter
         * values.
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
         * @param[in] tableName_  Name of the table on which this operation
         *                        will be performed. The table cannot be a
         *                        parent set.
         * @param[in] columnNames_  The list of column values to retrieve.
         * @param[in] offset_  A positive integer indicating the number of
         *                     initial results to skip (this can be useful for
         *                     paging through the results).  The minimum
         *                     allowed value is 0. The maximum allowed value is
         *                     MAX_INT.
         * @param[in] limit_  A positive integer indicating the maximum number
         *                    of results to be returned (if not provided the
         *                    default is 10000), or END_OF_SET (-9999) to
         *                    indicate that the maximum number of results
         *                    allowed by the server should be returned.
         * @param[in] options_
         *                      <ul>
         *                              <li>
         *                      gpudb::get_records_by_column_expression:
         *                      Optional filter expression to apply to the
         *                      table.
         *                              <li>
         *                      gpudb::get_records_by_column_sort_by: Optional
         *                      column that the data should be sorted by. Used
         *                      in conjunction with @a sort_order. The @a
         *                      order_by option can be used in lieu of @a
         *                      sort_by / @a sort_order.  The default value is
         *                      ''.
         *                              <li>
         *                      gpudb::get_records_by_column_sort_order: String
         *                      indicating how the returned values should be
         *                      sorted - @a ascending or @a descending. If @a
         *                      sort_order is provided, @a sort_by has to be
         *                      provided.
         *                      <ul>
         *                              <li>
         *                      gpudb::get_records_by_column_ascending
         *                              <li>
         *                      gpudb::get_records_by_column_descending
         *                      </ul>
         *                      The default value is
         *                      gpudb::get_records_by_column_ascending.
         *                              <li>
         *                      gpudb::get_records_by_column_order_by:
         *                      Comma-separated list of the columns to be
         *                      sorted by as well as the sort direction, e.g.,
         *                      'timestamp asc, x desc'.  The default value is
         *                      ''.
         *                              <li>
         *                      gpudb::get_records_by_column_convert_wkts_to_wkbs:
         *                      If true, then WKT string columns will be
         *                      returned as WKB bytes.
         *                      <ul>
         *                              <li> gpudb::get_records_by_column_true
         *                              <li> gpudb::get_records_by_column_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::get_records_by_column_false.
         *                      </ul>
         * 
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
         * @param[in] tableName_  Name of the table on which this operation
         *                        will be performed. The table cannot be a
         *                        parent set.
         * @param[in] columnNames_  The list of column values to retrieve.
         * @param[in] offset_  A positive integer indicating the number of
         *                     initial results to skip (this can be useful for
         *                     paging through the results).  The minimum
         *                     allowed value is 0. The maximum allowed value is
         *                     MAX_INT.
         * @param[in] limit_  A positive integer indicating the maximum number
         *                    of results to be returned (if not provided the
         *                    default is 10000), or END_OF_SET (-9999) to
         *                    indicate that the maximum number of results
         *                    allowed by the server should be returned.
         * @param[in] encoding_  Specifies the encoding for returned records;
         *                       either 'binary' or 'json'.
         *                       <ul>
         *                               <li>
         *                       gpudb::get_records_by_column_binary
         *                               <li> gpudb::get_records_by_column_json
         *                       </ul>
         *                       The default value is
         *                       gpudb::get_records_by_column_binary.
         * @param[in] options_
         *                      <ul>
         *                              <li>
         *                      gpudb::get_records_by_column_expression:
         *                      Optional filter expression to apply to the
         *                      table.
         *                              <li>
         *                      gpudb::get_records_by_column_sort_by: Optional
         *                      column that the data should be sorted by. Used
         *                      in conjunction with @a sort_order. The @a
         *                      order_by option can be used in lieu of @a
         *                      sort_by / @a sort_order.  The default value is
         *                      ''.
         *                              <li>
         *                      gpudb::get_records_by_column_sort_order: String
         *                      indicating how the returned values should be
         *                      sorted - @a ascending or @a descending. If @a
         *                      sort_order is provided, @a sort_by has to be
         *                      provided.
         *                      <ul>
         *                              <li>
         *                      gpudb::get_records_by_column_ascending
         *                              <li>
         *                      gpudb::get_records_by_column_descending
         *                      </ul>
         *                      The default value is
         *                      gpudb::get_records_by_column_ascending.
         *                              <li>
         *                      gpudb::get_records_by_column_order_by:
         *                      Comma-separated list of the columns to be
         *                      sorted by as well as the sort direction, e.g.,
         *                      'timestamp asc, x desc'.  The default value is
         *                      ''.
         *                              <li>
         *                      gpudb::get_records_by_column_convert_wkts_to_wkbs:
         *                      If true, then WKT string columns will be
         *                      returned as WKB bytes.
         *                      <ul>
         *                              <li> gpudb::get_records_by_column_true
         *                              <li> gpudb::get_records_by_column_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::get_records_by_column_false.
         *                      </ul>
         * 
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

        std::string tableName;
        std::vector<std::string> columnNames;
        int64_t offset;
        int64_t limit;
        std::string encoding;
        std::map<std::string, std::string> options;
    };
}

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
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #getRecordsByColumnRaw(const GetRecordsByColumnRequest&) const}.
     * <p>
     * For a given table, retrieves the values from the requested column(s).
     * Maps of column name to the array of values as well as the column data
     * type are returned. This endpoint supports pagination with the @a offset
     * and @a limit parameters.
     * <p>
     * <a href="../../concepts/window.html" target="_top">Window functions</a>,
     * which can perform operations like moving averages, are available through
     * this endpoint as well as {@link
     * #createProjection(const CreateProjectionRequest&) const}.
     * <p>
     * When using pagination, if the table (or the underlying table in the case
     * of a view) is modified (records are inserted, updated, or deleted)
     * during a call to the endpoint, the records or values retrieved may
     * differ between calls based on the type of the update, e.g., the
     * contiguity across pages cannot be relied upon.
     * <p>
     * The response is returned as a dynamic schema. For details see: <a
     * href="../../api/index.html#dynamic-schemas" target="_top">dynamic
     * schemas documentation</a>.
     */
    struct RawGetRecordsByColumnResponse
    {

        /**
         * Constructs a RawGetRecordsByColumnResponse object with default
         * parameter values.
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

        std::string tableName;
        std::string responseSchemaStr;
        std::vector<uint8_t> binaryEncodedResponse;
        std::string jsonEncodedResponse;
        int64_t totalNumberOfRecords;
        bool hasMoreRecords;
        std::map<std::string, std::string> info;
    };
}

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
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #getRecordsByColumn(const GetRecordsByColumnRequest&) const}.
     * <p>
     * For a given table, retrieves the values from the requested column(s).
     * Maps of column name to the array of values as well as the column data
     * type are returned. This endpoint supports pagination with the @a offset
     * and @a limit parameters.
     * <p>
     * <a href="../../concepts/window.html" target="_top">Window functions</a>,
     * which can perform operations like moving averages, are available through
     * this endpoint as well as {@link
     * #createProjection(const CreateProjectionRequest&) const}.
     * <p>
     * When using pagination, if the table (or the underlying table in the case
     * of a view) is modified (records are inserted, updated, or deleted)
     * during a call to the endpoint, the records or values retrieved may
     * differ between calls based on the type of the update, e.g., the
     * contiguity across pages cannot be relied upon.
     * <p>
     * The response is returned as a dynamic schema. For details see: <a
     * href="../../api/index.html#dynamic-schemas" target="_top">dynamic
     * schemas documentation</a>.
     */
    struct GetRecordsByColumnResponse
    {

        /**
         * Constructs a GetRecordsByColumnResponse object with default
         * parameter values.
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

        std::string tableName;
        std::string responseSchemaStr;
        std::vector<gpudb::GenericRecord> data;
        int64_t totalNumberOfRecords;
        bool hasMoreRecords;
        std::map<std::string, std::string> info;
        gpudb_type_ptr_t dataTypePtr;
    };
}

#endif
