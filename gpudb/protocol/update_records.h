/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __UPDATE_RECORDS_H__
#define __UPDATE_RECORDS_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #updateRecordsRaw(const RawUpdateRecordsRequest&) const}.
     * <p>
     * Runs multiple predicate-based updates in a single call.  With the
     * list of given expressions, any matching record's column values will be
     * updated
     * as provided in @a newValuesMaps.  There is also an optional 'upsert'
     * capability where if a particular predicate doesn't match any existing
     * record,
     * then a new record can be inserted.
     * <p>
     * Note that this operation can only be run on an original table and not on
     * a
     * result view.
     * <p>
     * This operation can update primary key values.  By default only
     * 'pure primary key' predicates are allowed when updating primary key
     * values. If
     * the primary key for a table is the column 'attr1', then the operation
     * will only
     * accept predicates of the form: "attr1 == 'foo'" if the attr1 column is
     * being
     * updated.  For a composite primary key (e.g. columns 'attr1' and 'attr2')
     * then
     * this operation will only accept predicates of the form:
     * "(attr1 == 'foo') and (attr2 == 'bar')".  Meaning, all primary key
     * columns
     * must appear in an equality predicate in the expressions.  Furthermore
     * each
     * 'pure primary key' predicate must be unique within a given request.
     * These
     * restrictions can be removed by utilizing some available options through
     * @a options.
     * <p>
     * The @a update_on_existing_pk option specifies the record
     * collision policy for tables with a <a
     * href="../../concepts/tables.html#primary-keys" target="_top">primary
     * key</a>, and
     * is ignored on tables with no primary key.
     */
    struct RawUpdateRecordsRequest
    {

        /**
         * Constructs a RawUpdateRecordsRequest object with default parameter
         * values.
         */
        RawUpdateRecordsRequest() :
            tableName(std::string()),
            expressions(std::vector<std::string>()),
            newValuesMaps(std::vector<std::map<std::string, boost::optional<std::string> > >()),
            recordsToInsert(std::vector<std::vector<uint8_t> >()),
            recordsToInsertStr(std::vector<std::string>()),
            recordEncoding(std::string("binary")),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a RawUpdateRecordsRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Name of table to be updated, in
         *                        [schema_name.]table_name format, using
         *                        standard <a
         *                        href="../../concepts/tables.html#table-name-resolution"
         *                        target="_top">name resolution rules</a>.
         *                        Must be a currently existing table and not a
         *                        view.
         * @param[in] expressions_  A list of the actual predicates, one for
         *                          each update; format should follow the
         *                          guidelines /filter.
         * @param[in] newValuesMaps_  List of new values for the matching
         *                            records.  Each element is a map with
         *                            (key, value) pairs where the keys are the
         *                            names of the columns whose values are to
         *                            be updated; the values are the new
         *                            values.  The number of elements in the
         *                            list should match the length of @a
         *                            expressions.
         * @param[in] recordsToInsert_  An *optional* list of new binary-avro
         *                              encoded records to insert, one for each
         *                              update.  If one of @a expressions does
         *                              not yield a matching record to be
         *                              updated, then the corresponding element
         *                              from this list will be added to the
         *                              table.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::update_records_global_expression: An
         *                      optional global expression to reduce the search
         *                      space of the predicates listed in @a
         *                      expressions.  The default value is ''.
         *                              <li>
         *                      gpudb::update_records_bypass_safety_checks:
         *                      When set to @a true, all predicates are
         *                      available for primary key updates.  Keep in
         *                      mind that it is possible to destroy data in
         *                      this case, since a single predicate may match
         *                      multiple objects (potentially all of records of
         *                      a table), and then updating all of those
         *                      records to have the same primary key will, due
         *                      to the primary key uniqueness constraints,
         *                      effectively delete all but one of those updated
         *                      records.
         *                      <ul>
         *                              <li> gpudb::update_records_true
         *                              <li> gpudb::update_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::update_records_false.
         *                              <li>
         *                      gpudb::update_records_update_on_existing_pk:
         *                      Specifies the record collision policy for
         *                      tables with a <a
         *                      href="../../concepts/tables.html#primary-keys"
         *                      target="_top">primary key</a> when updating
         *                      columns of the <a
         *                      href="../../concepts/tables.html#primary-keys"
         *                      target="_top">primary key</a> or inserting new
         *                      records.  If @a true, existing records with
         *                      primary key values that match those of a record
         *                      being updated or inserted will be replaced by
         *                      the updated and new records.  If @a false,
         *                      existing records with matching primary key
         *                      values will remain unchanged, and the updated
         *                      or new records with primary key values that
         *                      match those of existing records will be
         *                      discarded.  If the specified table does not
         *                      have a primary key, then this option has no
         *                      effect.
         *                      <ul>
         *                              <li> gpudb::update_records_true:
         *                      Overwrite existing records when updated and
         *                      inserted records have the same primary keys
         *                              <li> gpudb::update_records_false:
         *                      Discard updated and inserted records when the
         *                      same primary keys already exist
         *                      </ul>
         *                      The default value is
         *                      gpudb::update_records_false.
         *                              <li>
         *                      gpudb::update_records_update_partition: Force
         *                      qualifying records to be deleted and reinserted
         *                      so their partition membership will be
         *                      reevaluated.
         *                      <ul>
         *                              <li> gpudb::update_records_true
         *                              <li> gpudb::update_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::update_records_false.
         *                              <li>
         *                      gpudb::update_records_truncate_strings: If set
         *                      to @a true, any strings which are too long for
         *                      their charN string fields will be truncated to
         *                      fit.
         *                      <ul>
         *                              <li> gpudb::update_records_true
         *                              <li> gpudb::update_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::update_records_false.
         *                              <li>
         *                      gpudb::update_records_use_expressions_in_new_values_maps:
         *                      When set to @a true, all new values in @a
         *                      newValuesMaps are considered as expression
         *                      values. When set to @a false, all new values in
         *                      @a newValuesMaps are considered as constants.
         *                      NOTE:  When @a true, string constants will need
         *                      to be quoted to avoid being evaluated as
         *                      expressions.
         *                      <ul>
         *                              <li> gpudb::update_records_true
         *                              <li> gpudb::update_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::update_records_false.
         *                              <li> gpudb::update_records_record_id:
         *                      ID of a single record to be updated (returned
         *                      in the call to /insert/records or
         *                      /get/records/fromcollection).
         *                      </ul>
         * 
         */
        RawUpdateRecordsRequest(const std::string& tableName_, const std::vector<std::string>& expressions_, const std::vector<std::map<std::string, boost::optional<std::string> > >& newValuesMaps_, const std::vector<std::vector<uint8_t> >& recordsToInsert_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            expressions( expressions_ ),
            newValuesMaps( newValuesMaps_ ),
            recordsToInsert( recordsToInsert_ ),
            recordsToInsertStr( std::vector<std::string>() ),
            recordEncoding( "binary" ),
            options( options_ )
        {
        }

        /**
         * Constructs a RawUpdateRecordsRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Name of table to be updated, in
         *                        [schema_name.]table_name format, using
         *                        standard <a
         *                        href="../../concepts/tables.html#table-name-resolution"
         *                        target="_top">name resolution rules</a>.
         *                        Must be a currently existing table and not a
         *                        view.
         * @param[in] expressions_  A list of the actual predicates, one for
         *                          each update; format should follow the
         *                          guidelines /filter.
         * @param[in] newValuesMaps_  List of new values for the matching
         *                            records.  Each element is a map with
         *                            (key, value) pairs where the keys are the
         *                            names of the columns whose values are to
         *                            be updated; the values are the new
         *                            values.  The number of elements in the
         *                            list should match the length of @a
         *                            expressions.
         * @param[in] recordsToInsert_  An *optional* list of new binary-avro
         *                              encoded records to insert, one for each
         *                              update.  If one of @a expressions does
         *                              not yield a matching record to be
         *                              updated, then the corresponding element
         *                              from this list will be added to the
         *                              table.
         * @param[in] recordsToInsertStr_  An optional list of new json-avro
         *                                 encoded objects to insert, one for
         *                                 each update, to be added to the set
         *                                 if the particular update did not
         *                                 affect any objects.
         * @param[in] recordEncoding_  Identifies which of @a recordsToInsert
         *                             and @a recordsToInsertStr should be
         *                             used.
         *                             <ul>
         *                                     <li>
         *                             gpudb::update_records_binary
         *                                     <li> gpudb::update_records_json
         *                             </ul>
         *                             The default value is
         *                             gpudb::update_records_binary.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::update_records_global_expression: An
         *                      optional global expression to reduce the search
         *                      space of the predicates listed in @a
         *                      expressions.  The default value is ''.
         *                              <li>
         *                      gpudb::update_records_bypass_safety_checks:
         *                      When set to @a true, all predicates are
         *                      available for primary key updates.  Keep in
         *                      mind that it is possible to destroy data in
         *                      this case, since a single predicate may match
         *                      multiple objects (potentially all of records of
         *                      a table), and then updating all of those
         *                      records to have the same primary key will, due
         *                      to the primary key uniqueness constraints,
         *                      effectively delete all but one of those updated
         *                      records.
         *                      <ul>
         *                              <li> gpudb::update_records_true
         *                              <li> gpudb::update_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::update_records_false.
         *                              <li>
         *                      gpudb::update_records_update_on_existing_pk:
         *                      Specifies the record collision policy for
         *                      tables with a <a
         *                      href="../../concepts/tables.html#primary-keys"
         *                      target="_top">primary key</a> when updating
         *                      columns of the <a
         *                      href="../../concepts/tables.html#primary-keys"
         *                      target="_top">primary key</a> or inserting new
         *                      records.  If @a true, existing records with
         *                      primary key values that match those of a record
         *                      being updated or inserted will be replaced by
         *                      the updated and new records.  If @a false,
         *                      existing records with matching primary key
         *                      values will remain unchanged, and the updated
         *                      or new records with primary key values that
         *                      match those of existing records will be
         *                      discarded.  If the specified table does not
         *                      have a primary key, then this option has no
         *                      effect.
         *                      <ul>
         *                              <li> gpudb::update_records_true:
         *                      Overwrite existing records when updated and
         *                      inserted records have the same primary keys
         *                              <li> gpudb::update_records_false:
         *                      Discard updated and inserted records when the
         *                      same primary keys already exist
         *                      </ul>
         *                      The default value is
         *                      gpudb::update_records_false.
         *                              <li>
         *                      gpudb::update_records_update_partition: Force
         *                      qualifying records to be deleted and reinserted
         *                      so their partition membership will be
         *                      reevaluated.
         *                      <ul>
         *                              <li> gpudb::update_records_true
         *                              <li> gpudb::update_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::update_records_false.
         *                              <li>
         *                      gpudb::update_records_truncate_strings: If set
         *                      to @a true, any strings which are too long for
         *                      their charN string fields will be truncated to
         *                      fit.
         *                      <ul>
         *                              <li> gpudb::update_records_true
         *                              <li> gpudb::update_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::update_records_false.
         *                              <li>
         *                      gpudb::update_records_use_expressions_in_new_values_maps:
         *                      When set to @a true, all new values in @a
         *                      newValuesMaps are considered as expression
         *                      values. When set to @a false, all new values in
         *                      @a newValuesMaps are considered as constants.
         *                      NOTE:  When @a true, string constants will need
         *                      to be quoted to avoid being evaluated as
         *                      expressions.
         *                      <ul>
         *                              <li> gpudb::update_records_true
         *                              <li> gpudb::update_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::update_records_false.
         *                              <li> gpudb::update_records_record_id:
         *                      ID of a single record to be updated (returned
         *                      in the call to /insert/records or
         *                      /get/records/fromcollection).
         *                      </ul>
         * 
         */
        RawUpdateRecordsRequest(const std::string& tableName_, const std::vector<std::string>& expressions_, const std::vector<std::map<std::string, boost::optional<std::string> > >& newValuesMaps_, const std::vector<std::vector<uint8_t> >& recordsToInsert_, const std::vector<std::string>& recordsToInsertStr_, const std::string& recordEncoding_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            expressions( expressions_ ),
            newValuesMaps( newValuesMaps_ ),
            recordsToInsert( recordsToInsert_ ),
            recordsToInsertStr( recordsToInsertStr_ ),
            recordEncoding( recordEncoding_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::vector<std::string> expressions;
        std::vector<std::map<std::string, boost::optional<std::string> > > newValuesMaps;
        std::vector<std::vector<uint8_t> > recordsToInsert;
        std::vector<std::string> recordsToInsertStr;
        std::string recordEncoding;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::RawUpdateRecordsRequest>
    {
        static void encode(Encoder& e, const gpudb::RawUpdateRecordsRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.expressions);
            ::avro::encode(e, v.newValuesMaps);
            ::avro::encode(e, v.recordsToInsert);
            ::avro::encode(e, v.recordsToInsertStr);
            ::avro::encode(e, v.recordEncoding);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::RawUpdateRecordsRequest& v)
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
                            ::avro::decode(d, v.newValuesMaps);
                            break;

                        case 3:
                            ::avro::decode(d, v.recordsToInsert);
                            break;

                        case 4:
                            ::avro::decode(d, v.recordsToInsertStr);
                            break;

                        case 5:
                            ::avro::decode(d, v.recordEncoding);
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
                ::avro::decode(d, v.expressions);
                ::avro::decode(d, v.newValuesMaps);
                ::avro::decode(d, v.recordsToInsert);
                ::avro::decode(d, v.recordsToInsertStr);
                ::avro::decode(d, v.recordEncoding);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #updateRecordsRaw(const RawUpdateRecordsRequest&) const}.
     * <p>
     * Runs multiple predicate-based updates in a single call.  With the
     * list of given expressions, any matching record's column values will be
     * updated
     * as provided in @a newValuesMaps.  There is also an optional 'upsert'
     * capability where if a particular predicate doesn't match any existing
     * record,
     * then a new record can be inserted.
     * <p>
     * Note that this operation can only be run on an original table and not on
     * a
     * result view.
     * <p>
     * This operation can update primary key values.  By default only
     * 'pure primary key' predicates are allowed when updating primary key
     * values. If
     * the primary key for a table is the column 'attr1', then the operation
     * will only
     * accept predicates of the form: "attr1 == 'foo'" if the attr1 column is
     * being
     * updated.  For a composite primary key (e.g. columns 'attr1' and 'attr2')
     * then
     * this operation will only accept predicates of the form:
     * "(attr1 == 'foo') and (attr2 == 'bar')".  Meaning, all primary key
     * columns
     * must appear in an equality predicate in the expressions.  Furthermore
     * each
     * 'pure primary key' predicate must be unique within a given request.
     * These
     * restrictions can be removed by utilizing some available options through
     * @a options.
     * <p>
     * The @a update_on_existing_pk option specifies the record
     * collision policy for tables with a <a
     * href="../../concepts/tables.html#primary-keys" target="_top">primary
     * key</a>, and
     * is ignored on tables with no primary key.
     * 
     * @param <T>  The type of object being processed.
     * 
     */
    template<typename T> struct UpdateRecordsRequest
    {

        /**
         * Constructs an UpdateRecordsRequest object with default parameter
         * values.
         */
        UpdateRecordsRequest() :
            tableName(std::string()),
            expressions(std::vector<std::string>()),
            newValuesMaps(std::vector<std::map<std::string, boost::optional<std::string> > >()),
            data(std::vector<T>()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an UpdateRecordsRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Name of table to be updated, in
         *                        [schema_name.]table_name format, using
         *                        standard <a
         *                        href="../../concepts/tables.html#table-name-resolution"
         *                        target="_top">name resolution rules</a>.
         *                        Must be a currently existing table and not a
         *                        view.
         * @param[in] expressions_  A list of the actual predicates, one for
         *                          each update; format should follow the
         *                          guidelines /filter.
         * @param[in] newValuesMaps_  List of new values for the matching
         *                            records.  Each element is a map with
         *                            (key, value) pairs where the keys are the
         *                            names of the columns whose values are to
         *                            be updated; the values are the new
         *                            values.  The number of elements in the
         *                            list should match the length of @a
         *                            expressions.
         * @param[in] data_  An *optional* list of new binary-avro encoded
         *                   records to insert, one for each update.  If one of
         *                   @a expressions does not yield a matching record to
         *                   be updated, then the corresponding element from
         *                   this list will be added to the table.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::update_records_global_expression: An
         *                      optional global expression to reduce the search
         *                      space of the predicates listed in @a
         *                      expressions.  The default value is ''.
         *                              <li>
         *                      gpudb::update_records_bypass_safety_checks:
         *                      When set to @a true, all predicates are
         *                      available for primary key updates.  Keep in
         *                      mind that it is possible to destroy data in
         *                      this case, since a single predicate may match
         *                      multiple objects (potentially all of records of
         *                      a table), and then updating all of those
         *                      records to have the same primary key will, due
         *                      to the primary key uniqueness constraints,
         *                      effectively delete all but one of those updated
         *                      records.
         *                      <ul>
         *                              <li> gpudb::update_records_true
         *                              <li> gpudb::update_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::update_records_false.
         *                              <li>
         *                      gpudb::update_records_update_on_existing_pk:
         *                      Specifies the record collision policy for
         *                      tables with a <a
         *                      href="../../concepts/tables.html#primary-keys"
         *                      target="_top">primary key</a> when updating
         *                      columns of the <a
         *                      href="../../concepts/tables.html#primary-keys"
         *                      target="_top">primary key</a> or inserting new
         *                      records.  If @a true, existing records with
         *                      primary key values that match those of a record
         *                      being updated or inserted will be replaced by
         *                      the updated and new records.  If @a false,
         *                      existing records with matching primary key
         *                      values will remain unchanged, and the updated
         *                      or new records with primary key values that
         *                      match those of existing records will be
         *                      discarded.  If the specified table does not
         *                      have a primary key, then this option has no
         *                      effect.
         *                      <ul>
         *                              <li> gpudb::update_records_true:
         *                      Overwrite existing records when updated and
         *                      inserted records have the same primary keys
         *                              <li> gpudb::update_records_false:
         *                      Discard updated and inserted records when the
         *                      same primary keys already exist
         *                      </ul>
         *                      The default value is
         *                      gpudb::update_records_false.
         *                              <li>
         *                      gpudb::update_records_update_partition: Force
         *                      qualifying records to be deleted and reinserted
         *                      so their partition membership will be
         *                      reevaluated.
         *                      <ul>
         *                              <li> gpudb::update_records_true
         *                              <li> gpudb::update_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::update_records_false.
         *                              <li>
         *                      gpudb::update_records_truncate_strings: If set
         *                      to @a true, any strings which are too long for
         *                      their charN string fields will be truncated to
         *                      fit.
         *                      <ul>
         *                              <li> gpudb::update_records_true
         *                              <li> gpudb::update_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::update_records_false.
         *                              <li>
         *                      gpudb::update_records_use_expressions_in_new_values_maps:
         *                      When set to @a true, all new values in @a
         *                      newValuesMaps are considered as expression
         *                      values. When set to @a false, all new values in
         *                      @a newValuesMaps are considered as constants.
         *                      NOTE:  When @a true, string constants will need
         *                      to be quoted to avoid being evaluated as
         *                      expressions.
         *                      <ul>
         *                              <li> gpudb::update_records_true
         *                              <li> gpudb::update_records_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::update_records_false.
         *                              <li> gpudb::update_records_record_id:
         *                      ID of a single record to be updated (returned
         *                      in the call to /insert/records or
         *                      /get/records/fromcollection).
         *                      </ul>
         * 
         */
        UpdateRecordsRequest(const std::string& tableName_, const std::vector<std::string>& expressions_, const std::vector<std::map<std::string, boost::optional<std::string> > >& newValuesMaps_, const std::vector<T>& data_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            expressions( expressions_ ),
            newValuesMaps( newValuesMaps_ ),
            data( data_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::vector<std::string> expressions;
        std::vector<std::map<std::string, boost::optional<std::string> > > newValuesMaps;
        std::vector<T> data;
        std::map<std::string, std::string> options;
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #updateRecordsRaw(const RawUpdateRecordsRequest&) const}.
     * <p>
     * Runs multiple predicate-based updates in a single call.  With the
     * list of given expressions, any matching record's column values will be
     * updated
     * as provided in @a newValuesMaps.  There is also an optional 'upsert'
     * capability where if a particular predicate doesn't match any existing
     * record,
     * then a new record can be inserted.
     * <p>
     * Note that this operation can only be run on an original table and not on
     * a
     * result view.
     * <p>
     * This operation can update primary key values.  By default only
     * 'pure primary key' predicates are allowed when updating primary key
     * values. If
     * the primary key for a table is the column 'attr1', then the operation
     * will only
     * accept predicates of the form: "attr1 == 'foo'" if the attr1 column is
     * being
     * updated.  For a composite primary key (e.g. columns 'attr1' and 'attr2')
     * then
     * this operation will only accept predicates of the form:
     * "(attr1 == 'foo') and (attr2 == 'bar')".  Meaning, all primary key
     * columns
     * must appear in an equality predicate in the expressions.  Furthermore
     * each
     * 'pure primary key' predicate must be unique within a given request.
     * These
     * restrictions can be removed by utilizing some available options through
     * @a options.
     * <p>
     * The @a update_on_existing_pk option specifies the record
     * collision policy for tables with a <a
     * href="../../concepts/tables.html#primary-keys" target="_top">primary
     * key</a>, and
     * is ignored on tables with no primary key.
     */
    struct UpdateRecordsResponse
    {

        /**
         * Constructs an UpdateRecordsResponse object with default parameter
         * values.
         */
        UpdateRecordsResponse() :
            countUpdated(int64_t()),
            countsUpdated(std::vector<int64_t>()),
            countInserted(int64_t()),
            countsInserted(std::vector<int64_t>()),
            info(std::map<std::string, std::string>())
        {
        }

        int64_t countUpdated;
        std::vector<int64_t> countsUpdated;
        int64_t countInserted;
        std::vector<int64_t> countsInserted;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::UpdateRecordsResponse>
    {
        static void encode(Encoder& e, const gpudb::UpdateRecordsResponse& v)
        {
            ::avro::encode(e, v.countUpdated);
            ::avro::encode(e, v.countsUpdated);
            ::avro::encode(e, v.countInserted);
            ::avro::encode(e, v.countsInserted);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::UpdateRecordsResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.countUpdated);
                            break;

                        case 1:
                            ::avro::decode(d, v.countsUpdated);
                            break;

                        case 2:
                            ::avro::decode(d, v.countInserted);
                            break;

                        case 3:
                            ::avro::decode(d, v.countsInserted);
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
                ::avro::decode(d, v.countUpdated);
                ::avro::decode(d, v.countsUpdated);
                ::avro::decode(d, v.countInserted);
                ::avro::decode(d, v.countsInserted);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
