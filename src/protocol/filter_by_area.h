/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __FILTER_BY_AREA_H__
#define __FILTER_BY_AREA_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #filterByArea(FilterByAreaRequest&)}.
     * <p>
     * Calculates which objects from a table are within a named area of
     * interest (NAI/polygon). The operation is synchronous meaning that GPUdb
     * will not return the request until all the matching objects are fully
     * available. The response payload provides the count of the resulting set.
     * A new resultant set (view) which satisfies the input NAI restriction
     * specification is created with the name @a viewName passed in as part of
     * the input.
     */
    struct FilterByAreaRequest
    {

        /**
         * Constructs a FilterByAreaRequest object with default parameter
         * values.
         */
        FilterByAreaRequest() :
            tableName(std::string()),
            viewName(std::string()),
            xColumnName(std::string()),
            xVector(std::vector<double>()),
            yColumnName(std::string()),
            yVector(std::vector<double>()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a FilterByAreaRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName  Name of the table to filter.  This may be the
         *                       name of a collection, a table or a view (when
         *                       chaining queries).  Collections may be
         *                       filtered only if all tables within the
         *                       collection have the same type ID.
         * @param[in] viewName  If provided, then this will be the name of the
         *                      view containing the results. Must not be an
         *                      already existing collection, table or view.
         *                      Default value is an empty {@link std::string}.
         * @param[in] xColumnName  Name of the column containing the x values
         *                         to be filtered.
         * @param[in] xVector  List of x coordinates of the vertices of the
         *                     polygon representing the area to be filtered.
         * @param[in] yColumnName  Name of the column containing the y values
         *                         to be filtered.
         * @param[in] yVector  List of y coordinates of the vertices of the
         *                     polygon representing the area to be filtered.
         * @param[in] options  Optional parameters.  Default value is an empty
         *                     {@link std::map}.
         * 
         */
        FilterByAreaRequest(const std::string& tableName, const std::string& viewName, const std::string& xColumnName, const std::vector<double>& xVector, const std::string& yColumnName, const std::vector<double>& yVector, const std::map<std::string, std::string>& options):
            tableName(tableName),
            viewName(viewName),
            xColumnName(xColumnName),
            xVector(xVector),
            yColumnName(yColumnName),
            yVector(yVector),
            options(options)
        {
        }

        std::string tableName;
        std::string viewName;
        std::string xColumnName;
        std::vector<double> xVector;
        std::string yColumnName;
        std::vector<double> yVector;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::FilterByAreaRequest>
    {
        static void encode(Encoder& e, const gpudb::FilterByAreaRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.viewName);
            ::avro::encode(e, v.xColumnName);
            ::avro::encode(e, v.xVector);
            ::avro::encode(e, v.yColumnName);
            ::avro::encode(e, v.yVector);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::FilterByAreaRequest& v)
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
                            ::avro::decode(d, v.viewName);
                            break;

                        case 2:
                            ::avro::decode(d, v.xColumnName);
                            break;

                        case 3:
                            ::avro::decode(d, v.xVector);
                            break;

                        case 4:
                            ::avro::decode(d, v.yColumnName);
                            break;

                        case 5:
                            ::avro::decode(d, v.yVector);
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
                ::avro::decode(d, v.viewName);
                ::avro::decode(d, v.xColumnName);
                ::avro::decode(d, v.xVector);
                ::avro::decode(d, v.yColumnName);
                ::avro::decode(d, v.yVector);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #filterByArea(FilterByAreaRequest&)}.
     * <p>
     * Calculates which objects from a table are within a named area of
     * interest (NAI/polygon). The operation is synchronous meaning that GPUdb
     * will not return the request until all the matching objects are fully
     * available. The response payload provides the count of the resulting set.
     * A new resultant set (view) which satisfies the input NAI restriction
     * specification is created with the name @a viewName passed in as part of
     * the input.
     */
    struct FilterByAreaResponse
    {

        /**
         * Constructs a FilterByAreaResponse object with default parameter
         * values.
         */
        FilterByAreaResponse() :
            count(int64_t())
        {
        }

        int64_t count;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::FilterByAreaResponse>
    {
        static void encode(Encoder& e, const gpudb::FilterByAreaResponse& v)
        {
            ::avro::encode(e, v.count);
        }

        static void decode(Decoder& d, gpudb::FilterByAreaResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.count);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.count);
            }
        }
    };
}

#endif
