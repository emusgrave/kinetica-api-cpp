/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __AGGREGATE_CONVEX_HULL_H__
#define __AGGREGATE_CONVEX_HULL_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #aggregateConvexHull(AggregateConvexHullRequest&)}.
     * <p>
     * Calculates and returns the convex hull for the values in a table
     * specified by @a tableName.
     */
    struct AggregateConvexHullRequest
    {

        /**
         * Constructs an AggregateConvexHullRequest object with default
         * parameter values.
         */
        AggregateConvexHullRequest() :
            tableName(std::string()),
            xColumnName(std::string()),
            yColumnName(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an AggregateConvexHullRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName  Name of Table on which the operation will be
         *                       performed. Must be a valid table in GPUdb.  It
         *                       can not be a collection.
         * @param[in] xColumnName  Name of the column containing the x
         *                         coordinates of the points for the operation
         *                         being performed.
         * @param[in] yColumnName  Name of the column containing the y
         *                         coordinates of the points for the operation
         *                         being performed.
         * @param[in] options  Optional parameters.  Default value is an empty
         *                     {@link std::map}.
         * 
         */
        AggregateConvexHullRequest(const std::string& tableName, const std::string& xColumnName, const std::string& yColumnName, const std::map<std::string, std::string>& options):
            tableName(tableName),
            xColumnName(xColumnName),
            yColumnName(yColumnName),
            options(options)
        {
        }

        std::string tableName;
        std::string xColumnName;
        std::string yColumnName;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AggregateConvexHullRequest>
    {
        static void encode(Encoder& e, const gpudb::AggregateConvexHullRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.xColumnName);
            ::avro::encode(e, v.yColumnName);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AggregateConvexHullRequest& v)
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
                            ::avro::decode(d, v.xColumnName);
                            break;

                        case 2:
                            ::avro::decode(d, v.yColumnName);
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
                ::avro::decode(d, v.xColumnName);
                ::avro::decode(d, v.yColumnName);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #aggregateConvexHull(AggregateConvexHullRequest&)}.
     * <p>
     * Calculates and returns the convex hull for the values in a table
     * specified by @a tableName.
     */
    struct AggregateConvexHullResponse
    {

        /**
         * Constructs an AggregateConvexHullResponse object with default
         * parameter values.
         */
        AggregateConvexHullResponse() :
            xVector(std::vector<double>()),
            yVector(std::vector<double>()),
            count(int32_t()),
            isValid(bool())
        {
        }

        std::vector<double> xVector;
        std::vector<double> yVector;
        int32_t count;
        bool isValid;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AggregateConvexHullResponse>
    {
        static void encode(Encoder& e, const gpudb::AggregateConvexHullResponse& v)
        {
            ::avro::encode(e, v.xVector);
            ::avro::encode(e, v.yVector);
            ::avro::encode(e, v.count);
            ::avro::encode(e, v.isValid);
        }

        static void decode(Decoder& d, gpudb::AggregateConvexHullResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.xVector);
                            break;

                        case 1:
                            ::avro::decode(d, v.yVector);
                            break;

                        case 2:
                            ::avro::decode(d, v.count);
                            break;

                        case 3:
                            ::avro::decode(d, v.isValid);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.xVector);
                ::avro::decode(d, v.yVector);
                ::avro::decode(d, v.count);
                ::avro::decode(d, v.isValid);
            }
        }
    };
}

#endif
