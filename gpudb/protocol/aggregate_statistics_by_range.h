/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __AGGREGATE_STATISTICS_BY_RANGE_H__
#define __AGGREGATE_STATISTICS_BY_RANGE_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #aggregateStatisticsByRange(const AggregateStatisticsByRangeRequest&) const}.
     * <p>
     * Divides the given set into bins and calculates statistics of the values
     * of a value-column in each bin.  The bins are based on the values of a
     * given binning-column.  The statistics that may be requested are mean,
     * stdv (standard deviation), variance, skew, kurtosis, sum, min, max,
     * first, last and weighted average. In addition to the requested
     * statistics the count of total samples in each bin is returned. This
     * counts vector is just the histogram of the column used to divide the set
     * members into bins. The weighted average statistic requires a
     * weight_column to be specified in @a options. The weighted average is
     * then defined as the sum of the products of the value column times the
     * weight column divided by the sum of the weight column.
     * <p>
     * There are two methods for binning the set members. In the first, which
     * can be used for numeric valued binning-columns, a min, max and interval
     * are specified. The number of bins, nbins, is the integer upper bound of
     * (max-min)/interval. Values that fall in the range
     * [min+n*interval,min+(n+1)*interval) are placed in the nth bin where n
     * ranges from 0..nbin-2. The final bin is [min+(nbin-1)*interval,max]. In
     * the second method, @a options bin_values specifies a list of binning
     * column values. Binning-columns whose value matches the nth member of the
     * bin_values list are placed in the nth bin. When a list is provided the
     * binning-column must be of type string or int.
     * <p>
     * NOTE:  The Kinetica instance being accessed must be running a CUDA
     * (GPU-based) build to service this request.
     */
    struct AggregateStatisticsByRangeRequest
    {

        /**
         * Constructs an AggregateStatisticsByRangeRequest object with default
         * parameter values.
         */
        AggregateStatisticsByRangeRequest() :
            tableName(std::string()),
            selectExpression(std::string()),
            columnName(std::string()),
            valueColumnName(std::string()),
            stats(std::string()),
            start(double()),
            end(double()),
            interval(double()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an AggregateStatisticsByRangeRequest object with the
         * specified parameters.
         * 
         * @param[in] tableName_  Name of the table on which the
         *                        ranged-statistics operation will be
         *                        performed.
         * @param[in] selectExpression_  For a non-empty expression statistics
         *                               are calculated for those records for
         *                               which the expression is true.
         * @param[in] columnName_  Name of the binning-column used to divide
         *                         the set samples into bins.
         * @param[in] valueColumnName_  Name of the value-column for which
         *                              statistics are to be computed.
         * @param[in] stats_  A string of comma separated list of the
         *                    statistics to calculate, e.g. 'sum,mean'.
         *                    Available statistics: mean, stdv (standard
         *                    deviation), variance, skew, kurtosis, sum.
         * @param[in] start_  The lower bound of the binning-column.
         * @param[in] end_  The upper bound of the binning-column.
         * @param[in] interval_  The interval of a bin. Set members fall into
         *                       bin i if the binning-column falls in the range
         *                       [start+interval*i, start+interval*(i+1)).
         * @param[in] options_  Map of optional parameters:
         *                      <ul>
         *                              <li>
         *                      gpudb::aggregate_statistics_by_range_additional_column_names:
         *                      A list of comma separated value-column names
         *                      over which statistics can be accumulated along
         *                      with the primary value_column.
         *                              <li>
         *                      gpudb::aggregate_statistics_by_range_bin_values:
         *                      A list of comma separated binning-column
         *                      values. Values that match the nth bin_values
         *                      value are placed in the nth bin.
         *                              <li>
         *                      gpudb::aggregate_statistics_by_range_weight_column_name:
         *                      Name of the column used as weighting column for
         *                      the weighted_average statistic.
         *                              <li>
         *                      gpudb::aggregate_statistics_by_range_order_column_name:
         *                      Name of the column used for candlestick
         *                      charting techniques.
         *                      </ul>
         * 
         */
        AggregateStatisticsByRangeRequest(const std::string& tableName_, const std::string& selectExpression_, const std::string& columnName_, const std::string& valueColumnName_, const std::string& stats_, const double start_, const double end_, const double interval_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            selectExpression( selectExpression_ ),
            columnName( columnName_ ),
            valueColumnName( valueColumnName_ ),
            stats( stats_ ),
            start( start_ ),
            end( end_ ),
            interval( interval_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::string selectExpression;
        std::string columnName;
        std::string valueColumnName;
        std::string stats;
        double start;
        double end;
        double interval;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AggregateStatisticsByRangeRequest>
    {
        static void encode(Encoder& e, const gpudb::AggregateStatisticsByRangeRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.selectExpression);
            ::avro::encode(e, v.columnName);
            ::avro::encode(e, v.valueColumnName);
            ::avro::encode(e, v.stats);
            ::avro::encode(e, v.start);
            ::avro::encode(e, v.end);
            ::avro::encode(e, v.interval);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AggregateStatisticsByRangeRequest& v)
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
                            ::avro::decode(d, v.selectExpression);
                            break;

                        case 2:
                            ::avro::decode(d, v.columnName);
                            break;

                        case 3:
                            ::avro::decode(d, v.valueColumnName);
                            break;

                        case 4:
                            ::avro::decode(d, v.stats);
                            break;

                        case 5:
                            ::avro::decode(d, v.start);
                            break;

                        case 6:
                            ::avro::decode(d, v.end);
                            break;

                        case 7:
                            ::avro::decode(d, v.interval);
                            break;

                        case 8:
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
                ::avro::decode(d, v.selectExpression);
                ::avro::decode(d, v.columnName);
                ::avro::decode(d, v.valueColumnName);
                ::avro::decode(d, v.stats);
                ::avro::decode(d, v.start);
                ::avro::decode(d, v.end);
                ::avro::decode(d, v.interval);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #aggregateStatisticsByRange(const AggregateStatisticsByRangeRequest&) const}.
     * <p>
     * Divides the given set into bins and calculates statistics of the values
     * of a value-column in each bin.  The bins are based on the values of a
     * given binning-column.  The statistics that may be requested are mean,
     * stdv (standard deviation), variance, skew, kurtosis, sum, min, max,
     * first, last and weighted average. In addition to the requested
     * statistics the count of total samples in each bin is returned. This
     * counts vector is just the histogram of the column used to divide the set
     * members into bins. The weighted average statistic requires a
     * weight_column to be specified in @a options. The weighted average is
     * then defined as the sum of the products of the value column times the
     * weight column divided by the sum of the weight column.
     * <p>
     * There are two methods for binning the set members. In the first, which
     * can be used for numeric valued binning-columns, a min, max and interval
     * are specified. The number of bins, nbins, is the integer upper bound of
     * (max-min)/interval. Values that fall in the range
     * [min+n*interval,min+(n+1)*interval) are placed in the nth bin where n
     * ranges from 0..nbin-2. The final bin is [min+(nbin-1)*interval,max]. In
     * the second method, @a options bin_values specifies a list of binning
     * column values. Binning-columns whose value matches the nth member of the
     * bin_values list are placed in the nth bin. When a list is provided the
     * binning-column must be of type string or int.
     * <p>
     * NOTE:  The Kinetica instance being accessed must be running a CUDA
     * (GPU-based) build to service this request.
     */
    struct AggregateStatisticsByRangeResponse
    {

        /**
         * Constructs an AggregateStatisticsByRangeResponse object with default
         * parameter values.
         */
        AggregateStatisticsByRangeResponse() :
            stats(std::map<std::string, std::vector<double> >()),
            info(std::map<std::string, std::string>())
        {
        }

        std::map<std::string, std::vector<double> > stats;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AggregateStatisticsByRangeResponse>
    {
        static void encode(Encoder& e, const gpudb::AggregateStatisticsByRangeResponse& v)
        {
            ::avro::encode(e, v.stats);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::AggregateStatisticsByRangeResponse& v)
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

                        case 1:
                            ::avro::decode(d, v.info);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.stats);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
