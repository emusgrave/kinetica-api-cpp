/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __AGGREGATE_STATISTICS_H__
#define __AGGREGATE_STATISTICS_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #aggregateStatistics(AggregateStatisticsRequest&)}.
     * <p>
     * Calculates the requested statistics of a given column in a given table.
     * The available statistics are count (number of total objects), mean, stdv
     * (standard deviation), variance, skew, kurtosis, sum, min, max,
     * weighted_average, cardinality (unique count) and estimated cardinality.
     * Estimated cardinality is calculated by using the hyperloglog
     * approximation technique. The weighted average statistic requires a
     * weight_attribute to be specified in @a options. The weighted average is
     * then defined as the sum of the products of @a columnName times the
     * weight attribute divided by the sum of the weight attribute. The
     * response includes a list of the statistics requested along with the
     * count of the number of items in the given set.
     */
    struct AggregateStatisticsRequest
    {

        /**
         * Constructs an AggregateStatisticsRequest object with default
         * parameter values.
         */
        AggregateStatisticsRequest() :
            tableName(std::string()),
            columnName(std::string()),
            stats(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an AggregateStatisticsRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName  Name of the table on which the statistics
         *                       operation will be performed.
         * @param[in] columnName  Name of the column for which the statistics
         *                        are to be calculated.
         * @param[in] stats  Comma separated list of the statistics to
         *                   calculate, e.g. "sum,mean".  The allowed values
         *                   are:  ~!~ * MEAN * STDV * VARIANCE * SKEW *
         *                   KURTOSIS * SUM * CARDINALITY *
         *                   ESTIMATED_CARDINALITY~!~
         * @param[in] options  Optional parameters.  Default value is an empty
         *                     {@link std::map}.
         * 
         */
        AggregateStatisticsRequest(const std::string& tableName, const std::string& columnName, const std::string& stats, const std::map<std::string, std::string>& options):
            tableName(tableName),
            columnName(columnName),
            stats(stats),
            options(options)
        {
        }

        std::string tableName;
        std::string columnName;
        std::string stats;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AggregateStatisticsRequest>
    {
        static void encode(Encoder& e, const gpudb::AggregateStatisticsRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.columnName);
            ::avro::encode(e, v.stats);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AggregateStatisticsRequest& v)
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
                            ::avro::decode(d, v.stats);
                            break;

                        case 3:
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
                ::avro::decode(d, v.stats);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #aggregateStatistics(AggregateStatisticsRequest&)}.
     * <p>
     * Calculates the requested statistics of a given column in a given table.
     * The available statistics are count (number of total objects), mean, stdv
     * (standard deviation), variance, skew, kurtosis, sum, min, max,
     * weighted_average, cardinality (unique count) and estimated cardinality.
     * Estimated cardinality is calculated by using the hyperloglog
     * approximation technique. The weighted average statistic requires a
     * weight_attribute to be specified in @a options. The weighted average is
     * then defined as the sum of the products of @a columnName times the
     * weight attribute divided by the sum of the weight attribute. The
     * response includes a list of the statistics requested along with the
     * count of the number of items in the given set.
     */
    struct AggregateStatisticsResponse
    {

        /**
         * Constructs an AggregateStatisticsResponse object with default
         * parameter values.
         */
        AggregateStatisticsResponse() :
            stats(std::map<std::string, double>())
        {
        }

        std::map<std::string, double> stats;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AggregateStatisticsResponse>
    {
        static void encode(Encoder& e, const gpudb::AggregateStatisticsResponse& v)
        {
            ::avro::encode(e, v.stats);
        }

        static void decode(Decoder& d, gpudb::AggregateStatisticsResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.stats);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.stats);
            }
        }
    };
}

#endif
