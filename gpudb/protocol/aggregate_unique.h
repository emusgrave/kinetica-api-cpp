/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __AGGREGATE_UNIQUE_H__
#define __AGGREGATE_UNIQUE_H__

#include "../GenericRecord.hpp"

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #aggregateUniqueRaw(const AggregateUniqueRequest&) const}.
     * <p>
     * Returns all the unique values from a particular column
     * (specified by @a columnName) of a particular table or view
     * (specified by @a tableName). If @a columnName is a numeric column,
     * the values will be in @a binaryEncodedResponse. Otherwise if
     * @a columnName is a string column, the values will be in
     * @a jsonEncodedResponse.  The results can be paged via @a offset
     * and @a limit parameters.
     * <p>
     * Columns marked as <a href="../../../concepts/types/#data-handling"
     * target="_top">store-only</a>
     * are unable to be used with this function.
     * <p>
     * To get the first 10 unique values sorted in descending order @a options
     * would be::
     * <p>
     * {"limit":"10","sort_order":"descending"}.
     * <p>
     * The response is returned as a dynamic schema. For details see:
     * <a href="../../../api/concepts/#dynamic-schemas" target="_top">dynamic
     * schemas documentation</a>.
     * <p>
     * If a @a result_table name is specified in the
     * @a options, the results are stored in a new table with that name--no
     * results are returned in the response.  Both the table name and resulting
     * column
     * name must adhere to
     * <a href="../../../concepts/tables/#table" target="_top">standard naming
     * conventions</a>;
     * any column expression will need to be aliased.  If the source table's
     * <a href="../../../concepts/tables/#shard-keys" target="_top">shard
     * key</a> is used as the
     * @a columnName, the result table will be sharded, in all other cases it
     * will be replicated.  Sorting will properly function only if the result
     * table is
     * replicated or if there is only one processing node and should not be
     * relied upon
     * in other cases.  Not available if the value of @a columnName is an
     * unrestricted-length string.
     */
    struct AggregateUniqueRequest
    {

        /**
         * Constructs an AggregateUniqueRequest object with default parameter
         * values.
         */
        AggregateUniqueRequest() :
            tableName(std::string()),
            columnName(std::string()),
            offset(int64_t()),
            limit(int64_t()),
            encoding(std::string("binary")),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an AggregateUniqueRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Name of an existing table or view on which
         *                        the operation will be performed, in
         *                        [schema_name.]table_name format, using
         *                        standard <a
         *                        href="../../../concepts/tables/#table-name-resolution"
         *                        target="_top">name resolution rules</a>.
         * @param[in] columnName_  Name of the column or an expression
         *                         containing one or more column names on which
         *                         the unique function would be applied.
         * @param[in] offset_  A positive integer indicating the number of
         *                     initial results to skip (this can be useful for
         *                     paging through the results).  The minimum
         *                     allowed value is 0. The maximum allowed value is
         *                     MAX_INT.
         * @param[in] limit_  A positive integer indicating the maximum number
         *                    of results to be returned. Or END_OF_SET (-9999)
         *                    to indicate that the max number of results should
         *                    be returned.  The number of records returned will
         *                    never exceed the server's own limit, defined by
         *                    the <a href="../../../config/#general"
         *                    target="_top">max_get_records_size</a> parameter
         *                    in the server configuration.  Use @a
         *                    hasMoreRecords to see if more records exist in
         *                    the result to be fetched, and @a offset & @a
         *                    limit to request subsequent pages of results.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::aggregate_unique_create_temp_table: If
         *                      @a true, a unique temporary table name will be
         *                      generated in the sys_temp schema and used in
         *                      place of @a result_table. If @a
         *                      result_table_persist is @a false (or
         *                      unspecified), then this is always allowed even
         *                      if the caller does not have permission to
         *                      create tables. The generated name is returned
         *                      in @a qualified_result_table_name.
         *                      <ul>
         *                              <li> gpudb::aggregate_unique_true
         *                              <li> gpudb::aggregate_unique_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::aggregate_unique_false.
         *                              <li>
         *                      gpudb::aggregate_unique_collection_name:
         *                      [DEPRECATED--please specify the containing
         *                      schema as part of @a result_table and use
         *                      /create/schema to create the schema if
         *                      non-existent]  Name of a schema which is to
         *                      contain the table specified in @a result_table.
         *                      If the schema provided is non-existent, it will
         *                      be automatically created.
         *                              <li>
         *                      gpudb::aggregate_unique_expression: Optional
         *                      filter expression to apply to the table.
         *                              <li>
         *                      gpudb::aggregate_unique_sort_order: String
         *                      indicating how the returned values should be
         *                      sorted.
         *                      <ul>
         *                              <li> gpudb::aggregate_unique_ascending
         *                              <li> gpudb::aggregate_unique_descending
         *                      </ul>
         *                      The default value is
         *                      gpudb::aggregate_unique_ascending.
         *                              <li>
         *                      gpudb::aggregate_unique_result_table: The name
         *                      of the table used to store the results, in
         *                      [schema_name.]table_name format, using standard
         *                      <a
         *                      href="../../../concepts/tables/#table-name-resolution"
         *                      target="_top">name resolution rules</a> and
         *                      meeting <a
         *                      href="../../../concepts/tables/#table-naming-criteria"
         *                      target="_top">table naming criteria</a>.  If
         *                      present, no results are returned in the
         *                      response.  Not available if @a columnName is an
         *                      unrestricted-length string.
         *                              <li>
         *                      gpudb::aggregate_unique_result_table_persist:
         *                      If @a true, then the result table specified in
         *                      @a result_table will be persisted and will not
         *                      expire unless a @a ttl is specified.   If @a
         *                      false, then the result table will be an
         *                      in-memory table and will expire unless a @a ttl
         *                      is specified otherwise.
         *                      <ul>
         *                              <li> gpudb::aggregate_unique_true
         *                              <li> gpudb::aggregate_unique_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::aggregate_unique_false.
         *                              <li>
         *                      gpudb::aggregate_unique_result_table_force_replicated:
         *                      Force the result table to be replicated
         *                      (ignores any sharding). Must be used in
         *                      combination with the @a result_table option.
         *                      <ul>
         *                              <li> gpudb::aggregate_unique_true
         *                              <li> gpudb::aggregate_unique_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::aggregate_unique_false.
         *                              <li>
         *                      gpudb::aggregate_unique_result_table_generate_pk:
         *                      If @a true then set a primary key for the
         *                      result table. Must be used in combination with
         *                      the @a result_table option.
         *                      <ul>
         *                              <li> gpudb::aggregate_unique_true
         *                              <li> gpudb::aggregate_unique_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::aggregate_unique_false.
         *                              <li> gpudb::aggregate_unique_ttl: Sets
         *                      the <a href="../../../concepts/ttl/"
         *                      target="_top">TTL</a> of the table specified in
         *                      @a result_table.
         *                              <li>
         *                      gpudb::aggregate_unique_chunk_size: Indicates
         *                      the number of records per chunk to be used for
         *                      the result table. Must be used in combination
         *                      with the @a result_table option.
         *                              <li> gpudb::aggregate_unique_view_id:
         *                      ID of view of which the result table will be a
         *                      member.  The default value is ''.
         *                      </ul>
         * 
         */
        AggregateUniqueRequest(const std::string& tableName_, const std::string& columnName_, const int64_t offset_, const int64_t limit_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            columnName( columnName_ ),
            offset( offset_ ),
            limit( limit_ ),
            encoding( "binary" ),
            options( options_ )
        {
        }

        /**
         * Constructs an AggregateUniqueRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Name of an existing table or view on which
         *                        the operation will be performed, in
         *                        [schema_name.]table_name format, using
         *                        standard <a
         *                        href="../../../concepts/tables/#table-name-resolution"
         *                        target="_top">name resolution rules</a>.
         * @param[in] columnName_  Name of the column or an expression
         *                         containing one or more column names on which
         *                         the unique function would be applied.
         * @param[in] offset_  A positive integer indicating the number of
         *                     initial results to skip (this can be useful for
         *                     paging through the results).  The minimum
         *                     allowed value is 0. The maximum allowed value is
         *                     MAX_INT.
         * @param[in] limit_  A positive integer indicating the maximum number
         *                    of results to be returned. Or END_OF_SET (-9999)
         *                    to indicate that the max number of results should
         *                    be returned.  The number of records returned will
         *                    never exceed the server's own limit, defined by
         *                    the <a href="../../../config/#general"
         *                    target="_top">max_get_records_size</a> parameter
         *                    in the server configuration.  Use @a
         *                    hasMoreRecords to see if more records exist in
         *                    the result to be fetched, and @a offset & @a
         *                    limit to request subsequent pages of results.
         * @param[in] encoding_  Specifies the encoding for returned records.
         *                       <ul>
         *                               <li> gpudb::aggregate_unique_binary:
         *                       Indicates that the returned records should be
         *                       binary encoded.
         *                               <li> gpudb::aggregate_unique_json:
         *                       Indicates that the returned records should be
         *                       json encoded.
         *                       </ul>
         *                       The default value is
         *                       gpudb::aggregate_unique_binary.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::aggregate_unique_create_temp_table: If
         *                      @a true, a unique temporary table name will be
         *                      generated in the sys_temp schema and used in
         *                      place of @a result_table. If @a
         *                      result_table_persist is @a false (or
         *                      unspecified), then this is always allowed even
         *                      if the caller does not have permission to
         *                      create tables. The generated name is returned
         *                      in @a qualified_result_table_name.
         *                      <ul>
         *                              <li> gpudb::aggregate_unique_true
         *                              <li> gpudb::aggregate_unique_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::aggregate_unique_false.
         *                              <li>
         *                      gpudb::aggregate_unique_collection_name:
         *                      [DEPRECATED--please specify the containing
         *                      schema as part of @a result_table and use
         *                      /create/schema to create the schema if
         *                      non-existent]  Name of a schema which is to
         *                      contain the table specified in @a result_table.
         *                      If the schema provided is non-existent, it will
         *                      be automatically created.
         *                              <li>
         *                      gpudb::aggregate_unique_expression: Optional
         *                      filter expression to apply to the table.
         *                              <li>
         *                      gpudb::aggregate_unique_sort_order: String
         *                      indicating how the returned values should be
         *                      sorted.
         *                      <ul>
         *                              <li> gpudb::aggregate_unique_ascending
         *                              <li> gpudb::aggregate_unique_descending
         *                      </ul>
         *                      The default value is
         *                      gpudb::aggregate_unique_ascending.
         *                              <li>
         *                      gpudb::aggregate_unique_result_table: The name
         *                      of the table used to store the results, in
         *                      [schema_name.]table_name format, using standard
         *                      <a
         *                      href="../../../concepts/tables/#table-name-resolution"
         *                      target="_top">name resolution rules</a> and
         *                      meeting <a
         *                      href="../../../concepts/tables/#table-naming-criteria"
         *                      target="_top">table naming criteria</a>.  If
         *                      present, no results are returned in the
         *                      response.  Not available if @a columnName is an
         *                      unrestricted-length string.
         *                              <li>
         *                      gpudb::aggregate_unique_result_table_persist:
         *                      If @a true, then the result table specified in
         *                      @a result_table will be persisted and will not
         *                      expire unless a @a ttl is specified.   If @a
         *                      false, then the result table will be an
         *                      in-memory table and will expire unless a @a ttl
         *                      is specified otherwise.
         *                      <ul>
         *                              <li> gpudb::aggregate_unique_true
         *                              <li> gpudb::aggregate_unique_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::aggregate_unique_false.
         *                              <li>
         *                      gpudb::aggregate_unique_result_table_force_replicated:
         *                      Force the result table to be replicated
         *                      (ignores any sharding). Must be used in
         *                      combination with the @a result_table option.
         *                      <ul>
         *                              <li> gpudb::aggregate_unique_true
         *                              <li> gpudb::aggregate_unique_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::aggregate_unique_false.
         *                              <li>
         *                      gpudb::aggregate_unique_result_table_generate_pk:
         *                      If @a true then set a primary key for the
         *                      result table. Must be used in combination with
         *                      the @a result_table option.
         *                      <ul>
         *                              <li> gpudb::aggregate_unique_true
         *                              <li> gpudb::aggregate_unique_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::aggregate_unique_false.
         *                              <li> gpudb::aggregate_unique_ttl: Sets
         *                      the <a href="../../../concepts/ttl/"
         *                      target="_top">TTL</a> of the table specified in
         *                      @a result_table.
         *                              <li>
         *                      gpudb::aggregate_unique_chunk_size: Indicates
         *                      the number of records per chunk to be used for
         *                      the result table. Must be used in combination
         *                      with the @a result_table option.
         *                              <li> gpudb::aggregate_unique_view_id:
         *                      ID of view of which the result table will be a
         *                      member.  The default value is ''.
         *                      </ul>
         * 
         */
        AggregateUniqueRequest(const std::string& tableName_, const std::string& columnName_, const int64_t offset_, const int64_t limit_, const std::string& encoding_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            columnName( columnName_ ),
            offset( offset_ ),
            limit( limit_ ),
            encoding( encoding_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::string columnName;
        int64_t offset;
        int64_t limit;
        std::string encoding;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AggregateUniqueRequest>
    {
        static void encode(Encoder& e, const gpudb::AggregateUniqueRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.columnName);
            ::avro::encode(e, v.offset);
            ::avro::encode(e, v.limit);
            ::avro::encode(e, v.encoding);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AggregateUniqueRequest& v)
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
                            ::avro::decode(d, v.columnName);
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
                ::avro::decode(d, v.columnName);
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
     * #aggregateUniqueRaw(const AggregateUniqueRequest&) const}.
     * <p>
     * Returns all the unique values from a particular column
     * (specified by @a columnName) of a particular table or view
     * (specified by @a tableName). If @a columnName is a numeric column,
     * the values will be in @a binaryEncodedResponse. Otherwise if
     * @a columnName is a string column, the values will be in
     * @a jsonEncodedResponse.  The results can be paged via @a offset
     * and @a limit parameters.
     * <p>
     * Columns marked as <a href="../../../concepts/types/#data-handling"
     * target="_top">store-only</a>
     * are unable to be used with this function.
     * <p>
     * To get the first 10 unique values sorted in descending order @a options
     * would be::
     * <p>
     * {"limit":"10","sort_order":"descending"}.
     * <p>
     * The response is returned as a dynamic schema. For details see:
     * <a href="../../../api/concepts/#dynamic-schemas" target="_top">dynamic
     * schemas documentation</a>.
     * <p>
     * If a @a result_table name is specified in the
     * @a options, the results are stored in a new table with that name--no
     * results are returned in the response.  Both the table name and resulting
     * column
     * name must adhere to
     * <a href="../../../concepts/tables/#table" target="_top">standard naming
     * conventions</a>;
     * any column expression will need to be aliased.  If the source table's
     * <a href="../../../concepts/tables/#shard-keys" target="_top">shard
     * key</a> is used as the
     * @a columnName, the result table will be sharded, in all other cases it
     * will be replicated.  Sorting will properly function only if the result
     * table is
     * replicated or if there is only one processing node and should not be
     * relied upon
     * in other cases.  Not available if the value of @a columnName is an
     * unrestricted-length string.
     */
    struct RawAggregateUniqueResponse
    {

        /**
         * Constructs a RawAggregateUniqueResponse object with default
         * parameter values.
         */
        RawAggregateUniqueResponse() :
            tableName(std::string()),
            responseSchemaStr(std::string()),
            binaryEncodedResponse(std::vector<uint8_t>()),
            jsonEncodedResponse(std::string()),
            hasMoreRecords(bool()),
            info(std::map<std::string, std::string>())
        {
        }

        std::string tableName;
        std::string responseSchemaStr;
        std::vector<uint8_t> binaryEncodedResponse;
        std::string jsonEncodedResponse;
        bool hasMoreRecords;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::RawAggregateUniqueResponse>
    {
        static void encode(Encoder& e, const gpudb::RawAggregateUniqueResponse& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.responseSchemaStr);
            ::avro::encode(e, v.binaryEncodedResponse);
            ::avro::encode(e, v.jsonEncodedResponse);
            ::avro::encode(e, v.hasMoreRecords);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::RawAggregateUniqueResponse& v)
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
                            ::avro::decode(d, v.hasMoreRecords);
                            break;

                        case 5:
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
     * #aggregateUnique(const AggregateUniqueRequest&) const}.
     * <p>
     * Returns all the unique values from a particular column
     * (specified by @a columnName) of a particular table or view
     * (specified by @a tableName). If @a columnName is a numeric column,
     * the values will be in @a binaryEncodedResponse. Otherwise if
     * @a columnName is a string column, the values will be in
     * @a jsonEncodedResponse.  The results can be paged via @a offset
     * and @a limit parameters.
     * <p>
     * Columns marked as <a href="../../../concepts/types/#data-handling"
     * target="_top">store-only</a>
     * are unable to be used with this function.
     * <p>
     * To get the first 10 unique values sorted in descending order @a options
     * would be::
     * <p>
     * {"limit":"10","sort_order":"descending"}.
     * <p>
     * The response is returned as a dynamic schema. For details see:
     * <a href="../../../api/concepts/#dynamic-schemas" target="_top">dynamic
     * schemas documentation</a>.
     * <p>
     * If a @a result_table name is specified in the
     * @a options, the results are stored in a new table with that name--no
     * results are returned in the response.  Both the table name and resulting
     * column
     * name must adhere to
     * <a href="../../../concepts/tables/#table" target="_top">standard naming
     * conventions</a>;
     * any column expression will need to be aliased.  If the source table's
     * <a href="../../../concepts/tables/#shard-keys" target="_top">shard
     * key</a> is used as the
     * @a columnName, the result table will be sharded, in all other cases it
     * will be replicated.  Sorting will properly function only if the result
     * table is
     * replicated or if there is only one processing node and should not be
     * relied upon
     * in other cases.  Not available if the value of @a columnName is an
     * unrestricted-length string.
     */
    struct AggregateUniqueResponse
    {

        /**
         * Constructs an AggregateUniqueResponse object with default parameter
         * values.
         */
        AggregateUniqueResponse() :
            tableName(std::string()),
            responseSchemaStr(std::string()),
            data(std::vector<gpudb::GenericRecord>()),
            hasMoreRecords(bool()),
            info(std::map<std::string, std::string>()),
            dataTypePtr((gpudb::Type*)NULL)
        {
        }

        std::string tableName;
        std::string responseSchemaStr;
        std::vector<gpudb::GenericRecord> data;
        bool hasMoreRecords;
        std::map<std::string, std::string> info;
        gpudb_type_ptr_t dataTypePtr;
    };
}

#endif
