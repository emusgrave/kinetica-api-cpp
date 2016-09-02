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
     * This operation is synchronous, meaning that GPUdb will not return until
     * all random records are fully available.
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
         * @param[in] tableName  Table to which random records will be added.
         *                       Must be an existing table.  Also, must be an
         *                       individual table, not a collection of tables,
         *                       nor a view of a table.
         * @param[in] count  Number of records to generate.
         * @param[in] options  Optional parameter to pass in specifications for
         *                     the randomness of the values.  This map is
         *                     different from the *options* parameter of most
         *                     other endpoints in that it is a map of string to
         *                     map of string to doubles, while most others are
         *                     maps of string to string.  In this map, the top
         *                     level keys represent which column's parameters
         *                     are being specified, while the internal keys
         *                     represents which parameter is being specified.
         *                     The parameters that can be specified are: *min*,
         *                     *max*, and *interval*.  These parameters take on
         *                     different meanings depending on the type of the
         *                     column.  Below follows a more detailed
         *                     description of the map:  Default value is an
         *                     empty std::map.
         * <ul>
         *     <li>all: This key indicates that the specifications relayed in the internal map are to be applied to all columns of the records.  
         *     <li>attr_name: Set the following parameters for the column specified by the key. This overrides any parameter set by @a all.  
         *     <li>track_length: This key-map pair is only valid for track type data sets (GPUdb throws an error otherwise).  
         * </ul>
         * 
         */
        InsertRecordsRandomRequest(const std::string& tableName, const int64_t count, const std::map<std::string, std::map<std::string, double> >& options):
            tableName(tableName),
            count(count),
            options(options)
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
     * This operation is synchronous, meaning that GPUdb will not return until
     * all random records are fully available.
     */
    struct InsertRecordsRandomResponse
    {

        /**
         * Constructs an InsertRecordsRandomResponse object with default
         * parameter values.
         */
        InsertRecordsRandomResponse() :
            tableName(std::string()),
            count(int64_t())
        {
        }

        std::string tableName;
        int64_t count;
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

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.tableName);
                ::avro::decode(d, v.count);
            }
        }
    };
}

#endif
