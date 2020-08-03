/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __DELETE_RECORDS_H__
#define __DELETE_RECORDS_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #deleteRecords(const DeleteRecordsRequest&) const}.
     * <p>
     * Deletes record(s) matching the provided criteria from the given table.
     * The record selection criteria can either be one or more  @a expressions
     * (matching multiple records), a single record identified by @a record_id
     * options, or all records when using @a delete_all_records.  Note that the
     * three selection criteria are mutually exclusive.  This operation cannot
     * be run on a view.  The operation is synchronous meaning that a response
     * will not be available until the request is completely processed and all
     * the matching records are deleted.
     */
    struct DeleteRecordsRequest
    {

        /**
         * Constructs a DeleteRecordsRequest object with default parameter
         * values.
         */
        DeleteRecordsRequest() :
            tableName(std::string()),
            expressions(std::vector<std::string>()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a DeleteRecordsRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Name of the table from which to delete
         *                        records, in [schema_name.]table_name format,
         *                        using standard <a
         *                        href="../../concepts/tables.html#table-name-resolution"
         *                        target="_top">name resolution rules</a>. Must
         *                        contain the name of an existing table; not
         *                        applicable to views.
         * @param[in] expressions_  A list of the actual predicates, one for
         *                          each select; format should follow the
         *                          guidelines provided <a
         *                          href="../../concepts/expressions.html"
         *                          target="_top">here</a>. Specifying one or
         *                          more @a expressions is mutually exclusive
         *                          to specifying @a record_id in the @a
         *                          options.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::delete_records_global_expression: An
         *                      optional global expression to reduce the search
         *                      space of the @a expressions.  The default value
         *                      is ''.
         *                              <li> gpudb::delete_records_record_id: A
         *                      record ID identifying a single record, obtained
         *                      at the time of /insert/records or by calling
         *                      /get/records/fromcollection with the
         *                      *return_record_ids* option. This option cannot
         *                      be used to delete records from <a
         *                      href="../../concepts/tables.html#replication"
         *                      target="_top">replicated</a> tables.
         *                              <li>
         *                      gpudb::delete_records_delete_all_records: If
         *                      set to @a true, all records in the table will
         *                      be deleted. If set to @a false, then the option
         *                      is effectively ignored.
         *                      <ul>
         *                              <li> gpudb::delete_records_true
         *                              <li> gpudb::delete_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::delete_records_false.
         *                      </ul>
         * 
         */
        DeleteRecordsRequest(const std::string& tableName_, const std::vector<std::string>& expressions_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            expressions( expressions_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::vector<std::string> expressions;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::DeleteRecordsRequest>
    {
        static void encode(Encoder& e, const gpudb::DeleteRecordsRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.expressions);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::DeleteRecordsRequest& v)
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
                            ::avro::decode(d, v.expressions);
                            break;

                        case 2:
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
                ::avro::decode(d, v.expressions);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #deleteRecords(const DeleteRecordsRequest&) const}.
     * <p>
     * Deletes record(s) matching the provided criteria from the given table.
     * The record selection criteria can either be one or more  @a expressions
     * (matching multiple records), a single record identified by @a record_id
     * options, or all records when using @a delete_all_records.  Note that the
     * three selection criteria are mutually exclusive.  This operation cannot
     * be run on a view.  The operation is synchronous meaning that a response
     * will not be available until the request is completely processed and all
     * the matching records are deleted.
     */
    struct DeleteRecordsResponse
    {

        /**
         * Constructs a DeleteRecordsResponse object with default parameter
         * values.
         */
        DeleteRecordsResponse() :
            countDeleted(int64_t()),
            countsDeleted(std::vector<int64_t>()),
            info(std::map<std::string, std::string>())
        {
        }

        int64_t countDeleted;
        std::vector<int64_t> countsDeleted;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::DeleteRecordsResponse>
    {
        static void encode(Encoder& e, const gpudb::DeleteRecordsResponse& v)
        {
            ::avro::encode(e, v.countDeleted);
            ::avro::encode(e, v.countsDeleted);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::DeleteRecordsResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.countDeleted);
                            break;

                        case 1:
                            ::avro::decode(d, v.countsDeleted);
                            break;

                        case 2:
                            ::avro::decode(d, v.info);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.countDeleted);
                ::avro::decode(d, v.countsDeleted);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
