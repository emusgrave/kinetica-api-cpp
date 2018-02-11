/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __COLLECT_STATISTICS_H__
#define __COLLECT_STATISTICS_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #collectStatistics(const CollectStatisticsRequest&) const}.
     * <p>
     * Collect the requested statistics of the given column(s) in a given
     * table.
     */
    struct CollectStatisticsRequest
    {

        /**
         * Constructs a CollectStatisticsRequest object with default parameter
         * values.
         */
        CollectStatisticsRequest() :
            tableName(std::string()),
            columnNames(std::vector<std::string>()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a CollectStatisticsRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Name of the table on which the statistics
         *                        operation will be performed.
         * @param[in] columnNames_  List of one or more column names.
         * @param[in] options_  Optional parameters.
         * 
         */
        CollectStatisticsRequest(const std::string& tableName_, const std::vector<std::string>& columnNames_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            columnNames( columnNames_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::vector<std::string> columnNames;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::CollectStatisticsRequest>
    {
        static void encode(Encoder& e, const gpudb::CollectStatisticsRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.columnNames);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::CollectStatisticsRequest& v)
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
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #collectStatistics(const CollectStatisticsRequest&) const}.
     * <p>
     * Collect the requested statistics of the given column(s) in a given
     * table.
     */
    struct CollectStatisticsResponse
    {

        /**
         * Constructs a CollectStatisticsResponse object with default parameter
         * values.
         */
        CollectStatisticsResponse() :
            tableName(std::string()),
            columnNames(std::vector<std::string>())
        {
        }

        std::string tableName;
        std::vector<std::string> columnNames;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::CollectStatisticsResponse>
    {
        static void encode(Encoder& e, const gpudb::CollectStatisticsResponse& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.columnNames);
        }

        static void decode(Decoder& d, gpudb::CollectStatisticsResponse& v)
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

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.tableName);
                ::avro::decode(d, v.columnNames);
            }
        }
    };
}

#endif
