/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __AGGREGATE_UNPIVOT_H__
#define __AGGREGATE_UNPIVOT_H__

#include "../GenericRecord.hpp"

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #aggregateUnpivotRaw(const AggregateUnpivotRequest&) const}.
     * <p>
     * Rotate the column values into rows values.
     * <p>
     * For unpivot details and examples, see <a
     * href="../../concepts/unpivot.html" target="_top">Unpivot</a>.  For
     * limitations, see <a href="../../concepts/unpivot.html#limitations"
     * target="_top">Unpivot Limitations</a>.
     * <p>
     * Unpivot is used to normalize tables that are built for cross tabular
     * reporting purposes. The unpivot operator rotates the column values for
     * all the pivoted columns. A variable column, value column and all columns
     * from the source table except the unpivot columns are projected into the
     * result table. The variable column and value columns in the result table
     * indicate the pivoted column name and values respectively.
     * <p>
     * The response is returned as a dynamic schema. For details see: <a
     * href="../../api/index.html#dynamic-schemas" target="_top">dynamic
     * schemas documentation</a>.
     */
    struct AggregateUnpivotRequest
    {

        /**
         * Constructs an AggregateUnpivotRequest object with default parameter
         * values.
         */
        AggregateUnpivotRequest() :
            tableName(std::string()),
            columnNames(std::vector<std::string>()),
            variableColumnName(std::string()),
            valueColumnName(std::string()),
            pivotedColumns(std::vector<std::string>()),
            encoding(std::string("binary")),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an AggregateUnpivotRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Name of the table on which the operation will
         *                        be performed. Must be an existing table/view.
         * @param[in] columnNames_  List of column names or expressions. A
         *                          wildcard '*' can be used to include all the
         *                          non-pivoted columns from the source table.
         * @param[in] variableColumnName_  Specifies the variable/parameter
         *                                 column name.
         * @param[in] valueColumnName_  Specifies the value column name.
         * @param[in] pivotedColumns_  List of one or more values typically the
         *                             column names of the input table. All the
         *                             columns in the source table must have
         *                             the same data type.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::aggregate_unpivot_collection_name: Name
         *                      of a collection which is to contain the table
         *                      specified in @a result_table. If the collection
         *                      provided is non-existent, the collection will
         *                      be automatically created. If empty, then the
         *                      table will be a top-level table.
         *                              <li>
         *                      gpudb::aggregate_unpivot_result_table: The name
         *                      of the table used to store the results. Has the
         *                      same naming restrictions as <a
         *                      href="../../concepts/tables.html"
         *                      target="_top">tables</a>. If present, no
         *                      results are returned in the response.
         *                              <li>
         *                      gpudb::aggregate_unpivot_result_table_persist:
         *                      If @a true, then the result table specified in
         *                      @a result_table will be persisted and will not
         *                      expire unless a @a ttl is specified.   If @a
         *                      false, then the result table will be an
         *                      in-memory table and will expire unless a @a ttl
         *                      is specified otherwise.
         *                      <ul>
         *                              <li> gpudb::aggregate_unpivot_true
         *                              <li> gpudb::aggregate_unpivot_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::aggregate_unpivot_false.
         *                              <li>
         *                      gpudb::aggregate_unpivot_expression: Filter
         *                      expression to apply to the table prior to
         *                      unpivot processing.
         *                              <li> gpudb::aggregate_unpivot_order_by:
         *                      Comma-separated list of the columns to be
         *                      sorted by; e.g. 'timestamp asc, x desc'.  The
         *                      columns specified must be present in input
         *                      table.  If any alias is given for any column
         *                      name, the alias must be used, rather than the
         *                      original column name.
         *                              <li>
         *                      gpudb::aggregate_unpivot_chunk_size: Indicates
         *                      the chunk size to be used for the result table.
         *                      Must be used in combination with the @a
         *                      result_table option.
         *                              <li> gpudb::aggregate_unpivot_limit:
         *                      The number of records to keep.
         *                              <li> gpudb::aggregate_unpivot_ttl: Sets
         *                      the <a href="../../concepts/ttl.html"
         *                      target="_top">TTL</a> of the table specified in
         *                      @a result_table.
         *                              <li> gpudb::aggregate_unpivot_view_id:
         *                      view this result table is part of
         *                              <li>
         *                      gpudb::aggregate_unpivot_materialize_on_gpu: If
         *                      @a true then the output columns will be cached
         *                      on the GPU.
         *                      <ul>
         *                              <li> gpudb::aggregate_unpivot_true
         *                              <li> gpudb::aggregate_unpivot_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::aggregate_unpivot_false.
         *                              <li>
         *                      gpudb::aggregate_unpivot_create_indexes:
         *                      Comma-separated list of columns on which to
         *                      create indexes on the table specified in @a
         *                      result_table. The columns specified must be
         *                      present in output column names.  If any alias
         *                      is given for any column name, the alias must be
         *                      used, rather than the original column name.
         *                              <li>
         *                      gpudb::aggregate_unpivot_result_table_force_replicated:
         *                      Force the result table to be replicated
         *                      (ignores any sharding). Must be used in
         *                      combination with the @a result_table option.
         *                      <ul>
         *                              <li> gpudb::aggregate_unpivot_true
         *                              <li> gpudb::aggregate_unpivot_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::aggregate_unpivot_false.
         *                      </ul>
         * 
         */
        AggregateUnpivotRequest(const std::string& tableName_, const std::vector<std::string>& columnNames_, const std::string& variableColumnName_, const std::string& valueColumnName_, const std::vector<std::string>& pivotedColumns_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            columnNames( columnNames_ ),
            variableColumnName( variableColumnName_ ),
            valueColumnName( valueColumnName_ ),
            pivotedColumns( pivotedColumns_ ),
            encoding( "binary" ),
            options( options_ )
        {
        }

        /**
         * Constructs an AggregateUnpivotRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Name of the table on which the operation will
         *                        be performed. Must be an existing table/view.
         * @param[in] columnNames_  List of column names or expressions. A
         *                          wildcard '*' can be used to include all the
         *                          non-pivoted columns from the source table.
         * @param[in] variableColumnName_  Specifies the variable/parameter
         *                                 column name.
         * @param[in] valueColumnName_  Specifies the value column name.
         * @param[in] pivotedColumns_  List of one or more values typically the
         *                             column names of the input table. All the
         *                             columns in the source table must have
         *                             the same data type.
         * @param[in] encoding_  Specifies the encoding for returned records.
         *                       <ul>
         *                               <li> gpudb::aggregate_unpivot_binary:
         *                       Indicates that the returned records should be
         *                       binary encoded.
         *                               <li> gpudb::aggregate_unpivot_json:
         *                       Indicates that the returned records should be
         *                       json encoded.
         *                       </ul>
         *                       The default value is
         *                       gpudb::aggregate_unpivot_binary.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::aggregate_unpivot_collection_name: Name
         *                      of a collection which is to contain the table
         *                      specified in @a result_table. If the collection
         *                      provided is non-existent, the collection will
         *                      be automatically created. If empty, then the
         *                      table will be a top-level table.
         *                              <li>
         *                      gpudb::aggregate_unpivot_result_table: The name
         *                      of the table used to store the results. Has the
         *                      same naming restrictions as <a
         *                      href="../../concepts/tables.html"
         *                      target="_top">tables</a>. If present, no
         *                      results are returned in the response.
         *                              <li>
         *                      gpudb::aggregate_unpivot_result_table_persist:
         *                      If @a true, then the result table specified in
         *                      @a result_table will be persisted and will not
         *                      expire unless a @a ttl is specified.   If @a
         *                      false, then the result table will be an
         *                      in-memory table and will expire unless a @a ttl
         *                      is specified otherwise.
         *                      <ul>
         *                              <li> gpudb::aggregate_unpivot_true
         *                              <li> gpudb::aggregate_unpivot_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::aggregate_unpivot_false.
         *                              <li>
         *                      gpudb::aggregate_unpivot_expression: Filter
         *                      expression to apply to the table prior to
         *                      unpivot processing.
         *                              <li> gpudb::aggregate_unpivot_order_by:
         *                      Comma-separated list of the columns to be
         *                      sorted by; e.g. 'timestamp asc, x desc'.  The
         *                      columns specified must be present in input
         *                      table.  If any alias is given for any column
         *                      name, the alias must be used, rather than the
         *                      original column name.
         *                              <li>
         *                      gpudb::aggregate_unpivot_chunk_size: Indicates
         *                      the chunk size to be used for the result table.
         *                      Must be used in combination with the @a
         *                      result_table option.
         *                              <li> gpudb::aggregate_unpivot_limit:
         *                      The number of records to keep.
         *                              <li> gpudb::aggregate_unpivot_ttl: Sets
         *                      the <a href="../../concepts/ttl.html"
         *                      target="_top">TTL</a> of the table specified in
         *                      @a result_table.
         *                              <li> gpudb::aggregate_unpivot_view_id:
         *                      view this result table is part of
         *                              <li>
         *                      gpudb::aggregate_unpivot_materialize_on_gpu: If
         *                      @a true then the output columns will be cached
         *                      on the GPU.
         *                      <ul>
         *                              <li> gpudb::aggregate_unpivot_true
         *                              <li> gpudb::aggregate_unpivot_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::aggregate_unpivot_false.
         *                              <li>
         *                      gpudb::aggregate_unpivot_create_indexes:
         *                      Comma-separated list of columns on which to
         *                      create indexes on the table specified in @a
         *                      result_table. The columns specified must be
         *                      present in output column names.  If any alias
         *                      is given for any column name, the alias must be
         *                      used, rather than the original column name.
         *                              <li>
         *                      gpudb::aggregate_unpivot_result_table_force_replicated:
         *                      Force the result table to be replicated
         *                      (ignores any sharding). Must be used in
         *                      combination with the @a result_table option.
         *                      <ul>
         *                              <li> gpudb::aggregate_unpivot_true
         *                              <li> gpudb::aggregate_unpivot_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::aggregate_unpivot_false.
         *                      </ul>
         * 
         */
        AggregateUnpivotRequest(const std::string& tableName_, const std::vector<std::string>& columnNames_, const std::string& variableColumnName_, const std::string& valueColumnName_, const std::vector<std::string>& pivotedColumns_, const std::string& encoding_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            columnNames( columnNames_ ),
            variableColumnName( variableColumnName_ ),
            valueColumnName( valueColumnName_ ),
            pivotedColumns( pivotedColumns_ ),
            encoding( encoding_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::vector<std::string> columnNames;
        std::string variableColumnName;
        std::string valueColumnName;
        std::vector<std::string> pivotedColumns;
        std::string encoding;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AggregateUnpivotRequest>
    {
        static void encode(Encoder& e, const gpudb::AggregateUnpivotRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.columnNames);
            ::avro::encode(e, v.variableColumnName);
            ::avro::encode(e, v.valueColumnName);
            ::avro::encode(e, v.pivotedColumns);
            ::avro::encode(e, v.encoding);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AggregateUnpivotRequest& v)
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
                            ::avro::decode(d, v.variableColumnName);
                            break;

                        case 3:
                            ::avro::decode(d, v.valueColumnName);
                            break;

                        case 4:
                            ::avro::decode(d, v.pivotedColumns);
                            break;

                        case 5:
                            ::avro::decode(d, v.encoding);
                            break;

                        case 6:
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
                ::avro::decode(d, v.variableColumnName);
                ::avro::decode(d, v.valueColumnName);
                ::avro::decode(d, v.pivotedColumns);
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
     * #aggregateUnpivotRaw(const AggregateUnpivotRequest&) const}.
     * <p>
     * Rotate the column values into rows values.
     * <p>
     * For unpivot details and examples, see <a
     * href="../../concepts/unpivot.html" target="_top">Unpivot</a>.  For
     * limitations, see <a href="../../concepts/unpivot.html#limitations"
     * target="_top">Unpivot Limitations</a>.
     * <p>
     * Unpivot is used to normalize tables that are built for cross tabular
     * reporting purposes. The unpivot operator rotates the column values for
     * all the pivoted columns. A variable column, value column and all columns
     * from the source table except the unpivot columns are projected into the
     * result table. The variable column and value columns in the result table
     * indicate the pivoted column name and values respectively.
     * <p>
     * The response is returned as a dynamic schema. For details see: <a
     * href="../../api/index.html#dynamic-schemas" target="_top">dynamic
     * schemas documentation</a>.
     */
    struct RawAggregateUnpivotResponse
    {

        /**
         * Constructs a RawAggregateUnpivotResponse object with default
         * parameter values.
         */
        RawAggregateUnpivotResponse() :
            tableName(std::string()),
            responseSchemaStr(std::string()),
            binaryEncodedResponse(std::vector<uint8_t>()),
            jsonEncodedResponse(std::string()),
            totalNumberOfRecords(int64_t()),
            hasMoreRecords(bool())
        {
        }

        std::string tableName;
        std::string responseSchemaStr;
        std::vector<uint8_t> binaryEncodedResponse;
        std::string jsonEncodedResponse;
        int64_t totalNumberOfRecords;
        bool hasMoreRecords;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::RawAggregateUnpivotResponse>
    {
        static void encode(Encoder& e, const gpudb::RawAggregateUnpivotResponse& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.responseSchemaStr);
            ::avro::encode(e, v.binaryEncodedResponse);
            ::avro::encode(e, v.jsonEncodedResponse);
            ::avro::encode(e, v.totalNumberOfRecords);
            ::avro::encode(e, v.hasMoreRecords);
        }

        static void decode(Decoder& d, gpudb::RawAggregateUnpivotResponse& v)
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
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #aggregateUnpivot(const AggregateUnpivotRequest&) const}.
     * <p>
     * Rotate the column values into rows values.
     * <p>
     * For unpivot details and examples, see <a
     * href="../../concepts/unpivot.html" target="_top">Unpivot</a>.  For
     * limitations, see <a href="../../concepts/unpivot.html#limitations"
     * target="_top">Unpivot Limitations</a>.
     * <p>
     * Unpivot is used to normalize tables that are built for cross tabular
     * reporting purposes. The unpivot operator rotates the column values for
     * all the pivoted columns. A variable column, value column and all columns
     * from the source table except the unpivot columns are projected into the
     * result table. The variable column and value columns in the result table
     * indicate the pivoted column name and values respectively.
     * <p>
     * The response is returned as a dynamic schema. For details see: <a
     * href="../../api/index.html#dynamic-schemas" target="_top">dynamic
     * schemas documentation</a>.
     */
    struct AggregateUnpivotResponse
    {

        /**
         * Constructs an AggregateUnpivotResponse object with default parameter
         * values.
         */
        AggregateUnpivotResponse() :
            tableName(std::string()),
            responseSchemaStr(std::string()),
            data(std::vector<gpudb::GenericRecord>()),
            totalNumberOfRecords(int64_t()),
            hasMoreRecords(bool())
        {
        }

        std::string tableName;
        std::string responseSchemaStr;
        std::vector<gpudb::GenericRecord> data;
        int64_t totalNumberOfRecords;
        bool hasMoreRecords;
    };
}

#endif
