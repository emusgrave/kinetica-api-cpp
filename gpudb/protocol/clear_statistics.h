/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __CLEAR_STATISTICS_H__
#define __CLEAR_STATISTICS_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #clearStatistics(const ClearStatisticsRequest&) const}.
     * <p>
     * Clears (drops) one or all column statistics of a tables.
     */
    struct ClearStatisticsRequest
    {

        /**
         * Constructs a ClearStatisticsRequest object with default parameter
         * values.
         */
        ClearStatisticsRequest() :
            tableName(std::string()),
            columnName(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a ClearStatisticsRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Name of the table to clear the statistics.
         *                        Must be an existing table.
         * @param[in] columnName_  Name of the column to be cleared. Must be an
         *                         existing table. Empty string clears all
         *                         available statistics of the table.
         * @param[in] options_  Optional parameters.
         * 
         */
        ClearStatisticsRequest(const std::string& tableName_, const std::string& columnName_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            columnName( columnName_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::string columnName;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::ClearStatisticsRequest>
    {
        static void encode(Encoder& e, const gpudb::ClearStatisticsRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.columnName);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::ClearStatisticsRequest& v)
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
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #clearStatistics(const ClearStatisticsRequest&) const}.
     * <p>
     * Clears (drops) one or all column statistics of a tables.
     */
    struct ClearStatisticsResponse
    {

        /**
         * Constructs a ClearStatisticsResponse object with default parameter
         * values.
         */
        ClearStatisticsResponse() :
            tableName(std::string()),
            columnName(std::string())
        {
        }

        std::string tableName;
        std::string columnName;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::ClearStatisticsResponse>
    {
        static void encode(Encoder& e, const gpudb::ClearStatisticsResponse& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.columnName);
        }

        static void decode(Decoder& d, gpudb::ClearStatisticsResponse& v)
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

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.tableName);
                ::avro::decode(d, v.columnName);
            }
        }
    };
}

#endif
