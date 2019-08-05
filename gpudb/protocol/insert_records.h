/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __INSERT_RECORDS_H__
#define __INSERT_RECORDS_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #insertRecordsRaw(const RawInsertRecordsRequest&) const}.
     * <p>
     * Adds multiple records to the specified table. The operation is
     * synchronous, meaning that a response will not be returned until all the
     * records are fully inserted and available. The response payload provides
     * the counts of the number of records actually inserted and/or updated,
     * and can provide the unique identifier of each added record.
     * <p>
     * The @a options parameter can be used to customize this function's
     * behavior.
     * <p>
     * The @a update_on_existing_pk option specifies the record collision
     * policy for inserting into a table with a <a
     * href="../../concepts/tables.html#primary-keys" target="_top">primary
     * key</a>, but is ignored if no primary key exists.
     * <p>
     * The @a return_record_ids option indicates that the database should
     * return the unique identifiers of inserted records.
     */
    struct RawInsertRecordsRequest
    {

        /**
         * Constructs a RawInsertRecordsRequest object with default parameter
         * values.
         */
        RawInsertRecordsRequest() :
            tableName(std::string()),
            list(std::vector<std::vector<uint8_t> >()),
            listStr(std::vector<std::string>()),
            listEncoding(std::string("binary")),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a RawInsertRecordsRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Table to which the records are to be added.
         *                        Must be an existing table.
         * @param[in] list_  An array of binary-encoded data for the records to
         *                   be added. All records must be of the same type as
         *                   that of the table. Empty array if @a listEncoding
         *                   is @a json.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::insert_records_update_on_existing_pk:
         *                      Specifies the record collision policy for
         *                      inserting into a table with a <a
         *                      href="../../concepts/tables.html#primary-keys"
         *                      target="_top">primary key</a>.  If set to @a
         *                      true, any existing table record with primary
         *                      key values that match those of a record being
         *                      inserted will be replaced by that new record.
         *                      If set to @a false, any existing table record
         *                      with primary key values that match those of a
         *                      record being inserted will remain unchanged and
         *                      the new record discarded.  If the specified
         *                      table does not have a primary key, then this
         *                      option is ignored.
         *                      <ul>
         *                              <li> gpudb::insert_records_true
         *                              <li> gpudb::insert_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::insert_records_false.
         *                              <li>
         *                      gpudb::insert_records_return_record_ids: If @a
         *                      true then return the internal record id along
         *                      for each inserted record.
         *                      <ul>
         *                              <li> gpudb::insert_records_true
         *                              <li> gpudb::insert_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::insert_records_false.
         *                              <li>
         *                      gpudb::insert_records_truncate_strings: If set
         *                      to {true}@{, any strings which are too long for
         *                      their charN string fields will be truncated to
         *                      fit.  The default value is false.
         *                      <ul>
         *                              <li> gpudb::insert_records_true
         *                              <li> gpudb::insert_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::insert_records_false.
         *                      </ul>
         * 
         */
        RawInsertRecordsRequest(const std::string& tableName_, const std::vector<std::vector<uint8_t> >& list_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            list( list_ ),
            listStr( std::vector<std::string>() ),
            listEncoding( "binary" ),
            options( options_ )
        {
        }

        /**
         * Constructs a RawInsertRecordsRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Table to which the records are to be added.
         *                        Must be an existing table.
         * @param[in] list_  An array of binary-encoded data for the records to
         *                   be added. All records must be of the same type as
         *                   that of the table. Empty array if @a listEncoding
         *                   is @a json.
         * @param[in] listStr_  An array of JSON encoded data for the records
         *                      to be added. All records must be of the same
         *                      type as that of the table. Empty array if @a
         *                      listEncoding is @a binary.
         * @param[in] listEncoding_  The encoding of the records to be
         *                           inserted.
         *                           <ul>
         *                                   <li> gpudb::insert_records_binary
         *                                   <li> gpudb::insert_records_json
         *                           </ul>
         *                           The default value is
         *                           gpudb::insert_records_binary.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::insert_records_update_on_existing_pk:
         *                      Specifies the record collision policy for
         *                      inserting into a table with a <a
         *                      href="../../concepts/tables.html#primary-keys"
         *                      target="_top">primary key</a>.  If set to @a
         *                      true, any existing table record with primary
         *                      key values that match those of a record being
         *                      inserted will be replaced by that new record.
         *                      If set to @a false, any existing table record
         *                      with primary key values that match those of a
         *                      record being inserted will remain unchanged and
         *                      the new record discarded.  If the specified
         *                      table does not have a primary key, then this
         *                      option is ignored.
         *                      <ul>
         *                              <li> gpudb::insert_records_true
         *                              <li> gpudb::insert_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::insert_records_false.
         *                              <li>
         *                      gpudb::insert_records_return_record_ids: If @a
         *                      true then return the internal record id along
         *                      for each inserted record.
         *                      <ul>
         *                              <li> gpudb::insert_records_true
         *                              <li> gpudb::insert_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::insert_records_false.
         *                              <li>
         *                      gpudb::insert_records_truncate_strings: If set
         *                      to {true}@{, any strings which are too long for
         *                      their charN string fields will be truncated to
         *                      fit.  The default value is false.
         *                      <ul>
         *                              <li> gpudb::insert_records_true
         *                              <li> gpudb::insert_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::insert_records_false.
         *                      </ul>
         * 
         */
        RawInsertRecordsRequest(const std::string& tableName_, const std::vector<std::vector<uint8_t> >& list_, const std::vector<std::string>& listStr_, const std::string& listEncoding_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            list( list_ ),
            listStr( listStr_ ),
            listEncoding( listEncoding_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::vector<std::vector<uint8_t> > list;
        std::vector<std::string> listStr;
        std::string listEncoding;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::RawInsertRecordsRequest>
    {
        static void encode(Encoder& e, const gpudb::RawInsertRecordsRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.list);
            ::avro::encode(e, v.listStr);
            ::avro::encode(e, v.listEncoding);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::RawInsertRecordsRequest& v)
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
                            ::avro::decode(d, v.list);
                            break;

                        case 2:
                            ::avro::decode(d, v.listStr);
                            break;

                        case 3:
                            ::avro::decode(d, v.listEncoding);
                            break;

                        case 4:
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
                ::avro::decode(d, v.list);
                ::avro::decode(d, v.listStr);
                ::avro::decode(d, v.listEncoding);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #insertRecordsRaw(const RawInsertRecordsRequest&) const}.
     * <p>
     * Adds multiple records to the specified table. The operation is
     * synchronous, meaning that a response will not be returned until all the
     * records are fully inserted and available. The response payload provides
     * the counts of the number of records actually inserted and/or updated,
     * and can provide the unique identifier of each added record.
     * <p>
     * The @a options parameter can be used to customize this function's
     * behavior.
     * <p>
     * The @a update_on_existing_pk option specifies the record collision
     * policy for inserting into a table with a <a
     * href="../../concepts/tables.html#primary-keys" target="_top">primary
     * key</a>, but is ignored if no primary key exists.
     * <p>
     * The @a return_record_ids option indicates that the database should
     * return the unique identifiers of inserted records.
     * 
     * @param <T>  The type of object being processed.
     * 
     */
    template<typename T> struct InsertRecordsRequest
    {

        /**
         * Constructs an InsertRecordsRequest object with default parameter
         * values.
         */
        InsertRecordsRequest() :
            tableName(std::string()),
            data(std::vector<T>()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an InsertRecordsRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Table to which the records are to be added.
         *                        Must be an existing table.
         * @param[in] data_  An array of binary-encoded data for the records to
         *                   be added. All records must be of the same type as
         *                   that of the table. Empty array if @a listEncoding
         *                   is @a json.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::insert_records_update_on_existing_pk:
         *                      Specifies the record collision policy for
         *                      inserting into a table with a <a
         *                      href="../../concepts/tables.html#primary-keys"
         *                      target="_top">primary key</a>.  If set to @a
         *                      true, any existing table record with primary
         *                      key values that match those of a record being
         *                      inserted will be replaced by that new record.
         *                      If set to @a false, any existing table record
         *                      with primary key values that match those of a
         *                      record being inserted will remain unchanged and
         *                      the new record discarded.  If the specified
         *                      table does not have a primary key, then this
         *                      option is ignored.
         *                      <ul>
         *                              <li> gpudb::insert_records_true
         *                              <li> gpudb::insert_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::insert_records_false.
         *                              <li>
         *                      gpudb::insert_records_return_record_ids: If @a
         *                      true then return the internal record id along
         *                      for each inserted record.
         *                      <ul>
         *                              <li> gpudb::insert_records_true
         *                              <li> gpudb::insert_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::insert_records_false.
         *                              <li>
         *                      gpudb::insert_records_truncate_strings: If set
         *                      to {true}@{, any strings which are too long for
         *                      their charN string fields will be truncated to
         *                      fit.  The default value is false.
         *                      <ul>
         *                              <li> gpudb::insert_records_true
         *                              <li> gpudb::insert_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::insert_records_false.
         *                      </ul>
         * 
         */
        InsertRecordsRequest(const std::string& tableName_, const std::vector<T>& data_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            data( data_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::vector<T> data;
        std::map<std::string, std::string> options;
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #insertRecordsRaw(const RawInsertRecordsRequest&) const}.
     * <p>
     * Adds multiple records to the specified table. The operation is
     * synchronous, meaning that a response will not be returned until all the
     * records are fully inserted and available. The response payload provides
     * the counts of the number of records actually inserted and/or updated,
     * and can provide the unique identifier of each added record.
     * <p>
     * The @a options parameter can be used to customize this function's
     * behavior.
     * <p>
     * The @a update_on_existing_pk option specifies the record collision
     * policy for inserting into a table with a <a
     * href="../../concepts/tables.html#primary-keys" target="_top">primary
     * key</a>, but is ignored if no primary key exists.
     * <p>
     * The @a return_record_ids option indicates that the database should
     * return the unique identifiers of inserted records.
     */
    struct InsertRecordsResponse
    {

        /**
         * Constructs an InsertRecordsResponse object with default parameter
         * values.
         */
        InsertRecordsResponse() :
            recordIds(std::vector<std::string>()),
            countInserted(int32_t()),
            countUpdated(int32_t()),
            info(std::map<std::string, std::string>())
        {
        }

        std::vector<std::string> recordIds;
        int32_t countInserted;
        int32_t countUpdated;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::InsertRecordsResponse>
    {
        static void encode(Encoder& e, const gpudb::InsertRecordsResponse& v)
        {
            ::avro::encode(e, v.recordIds);
            ::avro::encode(e, v.countInserted);
            ::avro::encode(e, v.countUpdated);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::InsertRecordsResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.recordIds);
                            break;

                        case 1:
                            ::avro::decode(d, v.countInserted);
                            break;

                        case 2:
                            ::avro::decode(d, v.countUpdated);
                            break;

                        case 3:
                            ::avro::decode(d, v.info);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.recordIds);
                ::avro::decode(d, v.countInserted);
                ::avro::decode(d, v.countUpdated);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
