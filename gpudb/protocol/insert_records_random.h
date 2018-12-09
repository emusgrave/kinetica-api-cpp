/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __INSERT_RECORDS_RANDOM_H__
#define __INSERT_RECORDS_RANDOM_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #insertRecordsRandom(const InsertRecordsRandomRequest&) const}.
     * <p>
     * Generates a specified number of random records and adds them to the
     * given table. There is an optional parameter that allows the user to
     * customize the ranges of the column values. It also allows the user to
     * specify linear profiles for some or all columns in which case linear
     * values are generated rather than random ones. Only individual tables are
     * supported for this operation.
     * <p>
     * This operation is synchronous, meaning that a response will not be
     * returned until all random records are fully available.
     */
    struct InsertRecordsRandomRequest
    {

        /**
         * Constructs an InsertRecordsRandomRequest object with default
         * parameter values.
         */
        InsertRecordsRandomRequest() :
            tableName(std::string()),
            count(int64_t()),
            options(std::map<std::string, std::map<std::string, double> >())
        {
        }

        /**
         * Constructs an InsertRecordsRandomRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Table to which random records will be added.
         *                        Must be an existing table.  Also, must be an
         *                        individual table, not a collection of tables,
         *                        nor a view of a table.
         * @param[in] count_  Number of records to generate.
         * @param[in] options_  Optional parameter to pass in specifications
         *                      for the randomness of the values.  This map is
         *                      different from the *options* parameter of most
         *                      other endpoints in that it is a map of string
         *                      to map of string to doubles, while most others
         *                      are maps of string to string.  In this map, the
         *                      top level keys represent which column's
         *                      parameters are being specified, while the
         *                      internal keys represents which parameter is
         *                      being specified.  These parameters take on
         *                      different meanings depending on the type of the
         *                      column.  Below follows a more detailed
         *                      description of the map:
         *                      <ul>
         *                              <li> gpudb::insert_records_random_seed:
         *                      If provided, the internal random number
         *                      generator will be initialized with the given
         *                      value.  The minimum is 0.  This allows for the
         *                      same set of random numbers to be generated
         *                      across invocation of this endpoint in case the
         *                      user wants to repeat the test.  Since @a
         *                      options, is a map of maps, we need an internal
         *                      map to provide the seed value.  For example, to
         *                      pass 100 as the seed value through this
         *                      parameter, you need something equivalent to:
         *                      'options' = {'seed': { 'value': 100 } }
         *                      <ul>
         *                              <li>
         *                      gpudb::insert_records_random_value: Pass the
         *                      seed value here.
         *                      </ul>
         *                              <li> gpudb::insert_records_random_all:
         *                      This key indicates that the specifications
         *                      relayed in the internal map are to be applied
         *                      to all columns of the records.
         *                      <ul>
         *                              <li> gpudb::insert_records_random_min:
         *                      For numerical columns, the minimum of the
         *                      generated values is set to this value.  Default
         *                      is -99999.  For point, shape, and track
         *                      columns, min for numeric 'x' and 'y' columns
         *                      needs to be within [-180, 180] and [-90, 90],
         *                      respectively. The default minimum possible
         *                      values for these columns in such cases are
         *                      -180.0 and -90.0. For the 'TIMESTAMP' column,
         *                      the default minimum corresponds to Jan 1, 2010.
         *                      For string columns, the minimum length of the
         *                      randomly generated strings is set to this value
         *                      (default is 0). If both minimum and maximum are
         *                      provided, minimum must be less than or equal to
         *                      max. Value needs to be within [0, 200].
         *                      If the min is outside the accepted ranges for
         *                      strings columns and 'x' and 'y' columns for
         *                      point/shape/track, then those parameters will
         *                      not be set; however, an error will not be
         *                      thrown in such a case. It is the responsibility
         *                      of the user to use the @a all parameter
         *                      judiciously.
         *                              <li> gpudb::insert_records_random_max:
         *                      For numerical columns, the maximum of the
         *                      generated values is set to this value. Default
         *                      is 99999. For point, shape, and track columns,
         *                      max for numeric 'x' and 'y' columns needs to be
         *                      within [-180, 180] and [-90, 90], respectively.
         *                      The default minimum possible values for these
         *                      columns in such cases are 180.0 and 90.0.
         *                      For string columns, the maximum length of the
         *                      randomly generated strings is set to this value
         *                      (default is 200). If both minimum and maximum
         *                      are provided, *max* must be greater than or
         *                      equal to *min*. Value needs to be within [0,
         *                      200].
         *                      If the *max* is outside the accepted ranges for
         *                      strings columns and 'x' and 'y' columns for
         *                      point/shape/track, then those parameters will
         *                      not be set; however, an error will not be
         *                      thrown in such a case. It is the responsibility
         *                      of the user to use the @a all parameter
         *                      judiciously.
         *                              <li>
         *                      gpudb::insert_records_random_interval: If
         *                      specified, generate values for all columns
         *                      evenly spaced with the given interval value. If
         *                      a max value is specified for a given column the
         *                      data is randomly generated between min and max
         *                      and decimated down to the interval. If no max
         *                      is provided the data is linerally generated
         *                      starting at the minimum value (instead of
         *                      generating random data). For non-decimated
         *                      string-type columns the interval value is
         *                      ignored. Instead the values are generated
         *                      following the pattern:
         *                      'attrname_creationIndex#', i.e. the column name
         *                      suffixed with an underscore and a running
         *                      counter (starting at 0). For string types with
         *                      limited size (eg char4) the prefix is dropped.
         *                      No nulls will be generated for nullable
         *                      columns.
         *                              <li>
         *                      gpudb::insert_records_random_null_percentage:
         *                      If specified, then generate the given
         *                      percentage of the count as nulls for all
         *                      nullable columns.  This option will be ignored
         *                      for non-nullable columns.  The value must be
         *                      within the range [0, 1.0].  The default value
         *                      is 5% (0.05).
         *                              <li>
         *                      gpudb::insert_records_random_cardinality: If
         *                      specified, limit the randomly generated values
         *                      to a fixed set. Not allowed on a column with
         *                      interval specified, and is not applicable to
         *                      WKT or Track-specific columns. The value must
         *                      be greater than 0. This option is disabled by
         *                      default.
         *                      </ul>
         *                              <li>
         *                      gpudb::insert_records_random_attr_name: Use the
         *                      desired column name in place of @a attr_name,
         *                      and set the following parameters for the column
         *                      specified. This overrides any parameter set by
         *                      @a all.
         *                      <ul>
         *                              <li> gpudb::insert_records_random_min:
         *                      For numerical columns, the minimum of the
         *                      generated values is set to this value.  Default
         *                      is -99999.  For point, shape, and track
         *                      columns, min for numeric 'x' and 'y' columns
         *                      needs to be within [-180, 180] and [-90, 90],
         *                      respectively. The default minimum possible
         *                      values for these columns in such cases are
         *                      -180.0 and -90.0. For the 'TIMESTAMP' column,
         *                      the default minimum corresponds to Jan 1, 2010.
         *                      For string columns, the minimum length of the
         *                      randomly generated strings is set to this value
         *                      (default is 0). If both minimum and maximum are
         *                      provided, minimum must be less than or equal to
         *                      max. Value needs to be within [0, 200].
         *                      If the min is outside the accepted ranges for
         *                      strings columns and 'x' and 'y' columns for
         *                      point/shape/track, then those parameters will
         *                      not be set; however, an error will not be
         *                      thrown in such a case. It is the responsibility
         *                      of the user to use the @a all parameter
         *                      judiciously.
         *                              <li> gpudb::insert_records_random_max:
         *                      For numerical columns, the maximum of the
         *                      generated values is set to this value. Default
         *                      is 99999. For point, shape, and track columns,
         *                      max for numeric 'x' and 'y' columns needs to be
         *                      within [-180, 180] and [-90, 90], respectively.
         *                      The default minimum possible values for these
         *                      columns in such cases are 180.0 and 90.0.
         *                      For string columns, the maximum length of the
         *                      randomly generated strings is set to this value
         *                      (default is 200). If both minimum and maximum
         *                      are provided, *max* must be greater than or
         *                      equal to *min*. Value needs to be within [0,
         *                      200].
         *                      If the *max* is outside the accepted ranges for
         *                      strings columns and 'x' and 'y' columns for
         *                      point/shape/track, then those parameters will
         *                      not be set; however, an error will not be
         *                      thrown in such a case. It is the responsibility
         *                      of the user to use the @a all parameter
         *                      judiciously.
         *                              <li>
         *                      gpudb::insert_records_random_interval: If
         *                      specified, generate values for all columns
         *                      evenly spaced with the given interval value. If
         *                      a max value is specified for a given column the
         *                      data is randomly generated between min and max
         *                      and decimated down to the interval. If no max
         *                      is provided the data is linerally generated
         *                      starting at the minimum value (instead of
         *                      generating random data). For non-decimated
         *                      string-type columns the interval value is
         *                      ignored. Instead the values are generated
         *                      following the pattern:
         *                      'attrname_creationIndex#', i.e. the column name
         *                      suffixed with an underscore and a running
         *                      counter (starting at 0). For string types with
         *                      limited size (eg char4) the prefix is dropped.
         *                      No nulls will be generated for nullable
         *                      columns.
         *                              <li>
         *                      gpudb::insert_records_random_null_percentage:
         *                      If specified and if this column is nullable,
         *                      then generate the given percentage of the count
         *                      as nulls.  This option will result in an error
         *                      if the column is not nullable.  The value must
         *                      be within the range [0, 1.0].  The default
         *                      value is 5% (0.05).
         *                              <li>
         *                      gpudb::insert_records_random_cardinality: If
         *                      specified, limit the randomly generated values
         *                      to a fixed set. Not allowed on a column with
         *                      interval specified, and is not applicable to
         *                      WKT or Track-specific columns. The value must
         *                      be greater than 0. This option is disabled by
         *                      default.
         *                      </ul>
         *                              <li>
         *                      gpudb::insert_records_random_track_length: This
         *                      key-map pair is only valid for track data sets
         *                      (an error is thrown otherwise).  No nulls would
         *                      be generated for nullable columns.
         *                      <ul>
         *                              <li> gpudb::insert_records_random_min:
         *                      Minimum possible length for generated series;
         *                      default is 100 records per series. Must be an
         *                      integral value within the range [1, 500]. If
         *                      both min and max are specified, min must be
         *                      less than or equal to max.
         *                              <li> gpudb::insert_records_random_max:
         *                      Maximum possible length for generated series;
         *                      default is 500 records per series. Must be an
         *                      integral value within the range [1, 500]. If
         *                      both min and max are specified, max must be
         *                      greater than or equal to min.
         *                      </ul>
         *                      </ul>
         * 
         */
        InsertRecordsRandomRequest(const std::string& tableName_, const int64_t count_, const std::map<std::string, std::map<std::string, double> >& options_):
            tableName( tableName_ ),
            count( count_ ),
            options( options_ )
        {
        }

        std::string tableName;
        int64_t count;
        std::map<std::string, std::map<std::string, double> > options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::InsertRecordsRandomRequest>
    {
        static void encode(Encoder& e, const gpudb::InsertRecordsRandomRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.count);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::InsertRecordsRandomRequest& v)
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
                            ::avro::decode(d, v.count);
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
                ::avro::decode(d, v.count);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #insertRecordsRandom(const InsertRecordsRandomRequest&) const}.
     * <p>
     * Generates a specified number of random records and adds them to the
     * given table. There is an optional parameter that allows the user to
     * customize the ranges of the column values. It also allows the user to
     * specify linear profiles for some or all columns in which case linear
     * values are generated rather than random ones. Only individual tables are
     * supported for this operation.
     * <p>
     * This operation is synchronous, meaning that a response will not be
     * returned until all random records are fully available.
     */
    struct InsertRecordsRandomResponse
    {

        /**
         * Constructs an InsertRecordsRandomResponse object with default
         * parameter values.
         */
        InsertRecordsRandomResponse() :
            tableName(std::string()),
            count(int64_t()),
            info(std::map<std::string, std::string>())
        {
        }

        std::string tableName;
        int64_t count;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::InsertRecordsRandomResponse>
    {
        static void encode(Encoder& e, const gpudb::InsertRecordsRandomResponse& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.count);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::InsertRecordsRandomResponse& v)
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
                            ::avro::decode(d, v.count);
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
                ::avro::decode(d, v.tableName);
                ::avro::decode(d, v.count);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
