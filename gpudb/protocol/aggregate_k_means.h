/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __AGGREGATE_K_MEANS_H__
#define __AGGREGATE_K_MEANS_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #aggregateKMeans(const AggregateKMeansRequest&) const}.
     * <p>
     * This endpoint runs the k-means algorithm - a heuristic algorithm that
     * attempts to do k-means clustering.  An ideal k-means clustering
     * algorithm selects k points such that the sum of the mean squared
     * distances of each member of the set to the nearest of the k points is
     * minimized.  The k-means algorithm however does not necessarily produce
     * such an ideal cluster.   It begins with a randomly selected set of k
     * points and then refines the location of the points iteratively and
     * settles to a local minimum.  Various parameters and options are provided
     * to control the heuristic search.
     * <p>
     * NOTE:  The Kinetica instance being accessed must be running a CUDA
     * (GPU-based) build to service this request.
     */
    struct AggregateKMeansRequest
    {

        /**
         * Constructs an AggregateKMeansRequest object with default parameter
         * values.
         */
        AggregateKMeansRequest() :
            tableName(std::string()),
            columnNames(std::vector<std::string>()),
            k(int32_t()),
            tolerance(double()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an AggregateKMeansRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Name of the table on which the operation will
         *                        be performed. Must be an existing table or
         *                        collection.
         * @param[in] columnNames_  List of column names on which the operation
         *                          would be performed. If n columns are
         *                          provided then each of the k result points
         *                          will have n dimensions corresponding to the
         *                          n columns.
         * @param[in] k_  The number of mean points to be determined by the
         *                algorithm.
         * @param[in] tolerance_  Stop iterating when the distances between
         *                        successive points is less than the given
         *                        tolerance.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li> gpudb::aggregate_k_means_whiten:
         *                      When set to 1 each of the columns is first
         *                      normalized by its stdv - default is not to
         *                      whiten.
         *                              <li>
         *                      gpudb::aggregate_k_means_max_iters: Number of
         *                      times to try to hit the tolerance limit before
         *                      giving up - default is 10.
         *                              <li>
         *                      gpudb::aggregate_k_means_num_tries: Number of
         *                      times to run the k-means algorithm with a
         *                      different randomly selected starting points -
         *                      helps avoid local minimum. Default is 1.
         *                      </ul>
         * 
         */
        AggregateKMeansRequest(const std::string& tableName_, const std::vector<std::string>& columnNames_, const int32_t k_, const double tolerance_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            columnNames( columnNames_ ),
            k( k_ ),
            tolerance( tolerance_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::vector<std::string> columnNames;
        int32_t k;
        double tolerance;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AggregateKMeansRequest>
    {
        static void encode(Encoder& e, const gpudb::AggregateKMeansRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.columnNames);
            ::avro::encode(e, v.k);
            ::avro::encode(e, v.tolerance);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AggregateKMeansRequest& v)
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
                            ::avro::decode(d, v.k);
                            break;

                        case 3:
                            ::avro::decode(d, v.tolerance);
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
                ::avro::decode(d, v.columnNames);
                ::avro::decode(d, v.k);
                ::avro::decode(d, v.tolerance);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #aggregateKMeans(const AggregateKMeansRequest&) const}.
     * <p>
     * This endpoint runs the k-means algorithm - a heuristic algorithm that
     * attempts to do k-means clustering.  An ideal k-means clustering
     * algorithm selects k points such that the sum of the mean squared
     * distances of each member of the set to the nearest of the k points is
     * minimized.  The k-means algorithm however does not necessarily produce
     * such an ideal cluster.   It begins with a randomly selected set of k
     * points and then refines the location of the points iteratively and
     * settles to a local minimum.  Various parameters and options are provided
     * to control the heuristic search.
     * <p>
     * NOTE:  The Kinetica instance being accessed must be running a CUDA
     * (GPU-based) build to service this request.
     */
    struct AggregateKMeansResponse
    {

        /**
         * Constructs an AggregateKMeansResponse object with default parameter
         * values.
         */
        AggregateKMeansResponse() :
            means(std::vector<std::vector<double> >()),
            counts(std::vector<int64_t>()),
            rmsDists(std::vector<double>()),
            count(int64_t()),
            rmsDist(double()),
            tolerance(double()),
            numIters(int32_t()),
            info(std::map<std::string, std::string>())
        {
        }

        std::vector<std::vector<double> > means;
        std::vector<int64_t> counts;
        std::vector<double> rmsDists;
        int64_t count;
        double rmsDist;
        double tolerance;
        int32_t numIters;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AggregateKMeansResponse>
    {
        static void encode(Encoder& e, const gpudb::AggregateKMeansResponse& v)
        {
            ::avro::encode(e, v.means);
            ::avro::encode(e, v.counts);
            ::avro::encode(e, v.rmsDists);
            ::avro::encode(e, v.count);
            ::avro::encode(e, v.rmsDist);
            ::avro::encode(e, v.tolerance);
            ::avro::encode(e, v.numIters);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::AggregateKMeansResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.means);
                            break;

                        case 1:
                            ::avro::decode(d, v.counts);
                            break;

                        case 2:
                            ::avro::decode(d, v.rmsDists);
                            break;

                        case 3:
                            ::avro::decode(d, v.count);
                            break;

                        case 4:
                            ::avro::decode(d, v.rmsDist);
                            break;

                        case 5:
                            ::avro::decode(d, v.tolerance);
                            break;

                        case 6:
                            ::avro::decode(d, v.numIters);
                            break;

                        case 7:
                            ::avro::decode(d, v.info);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.means);
                ::avro::decode(d, v.counts);
                ::avro::decode(d, v.rmsDists);
                ::avro::decode(d, v.count);
                ::avro::decode(d, v.rmsDist);
                ::avro::decode(d, v.tolerance);
                ::avro::decode(d, v.numIters);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
