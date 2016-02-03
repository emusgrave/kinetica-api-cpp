/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __FILTER_BY_RANGE_H__
#define __FILTER_BY_RANGE_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #filterByRange(FilterByRangeRequest&)}.
     * <p>
     * Calculates which objects from a table have a column that is within the
     * given bounds. An object from the table identified by @a tableName is
     * added to the view @a viewName if its column is within [@a lowerBound, @a
     * upperBound] (inclusive). The operation is synchronous. The response
     * provides a count of the number of objects which passed the bound filter.
     * <p>
     * For track objects, the count reflects how many points fall within the
     * given bounds (which may not include all the track points of any given
     * track).
     */
    struct FilterByRangeRequest
    {

        /**
         * Constructs a FilterByRangeRequest object with default parameter
         * values.
         */
        FilterByRangeRequest() :
            tableName(std::string()),
            viewName(std::string()),
            columnName(std::string()),
            lowerBound(double()),
            upperBound(double()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a FilterByRangeRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName  Name of the table on which the filter by range
         *                       operation will be performed.  Must be a valid
         *                       GPUdb table.
         * @param[in] viewName  If provided, then this will be the name of the
         *                      view containing the results. Must not be an
         *                      already existing collection, table or view.
         *                      Default value is an empty {@link std::string}.
         * @param[in] columnName  Name of a column or an expression of one or
         *                        more columns on which the operation would be
         *                        applied.
         * @param[in] lowerBound  Value of the lower bound (inclusive).
         * @param[in] upperBound  Value of the upper bound (inclusive).
         * @param[in] options  Optional parameters.  Default value is an empty
         *                     {@link std::map}.
         * 
         */
        FilterByRangeRequest(const std::string& tableName, const std::string& viewName, const std::string& columnName, const double lowerBound, const double upperBound, const std::map<std::string, std::string>& options):
            tableName(tableName),
            viewName(viewName),
            columnName(columnName),
            lowerBound(lowerBound),
            upperBound(upperBound),
            options(options)
        {
        }

        std::string tableName;
        std::string viewName;
        std::string columnName;
        double lowerBound;
        double upperBound;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::FilterByRangeRequest>
    {
        static void encode(Encoder& e, const gpudb::FilterByRangeRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.viewName);
            ::avro::encode(e, v.columnName);
            ::avro::encode(e, v.lowerBound);
            ::avro::encode(e, v.upperBound);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::FilterByRangeRequest& v)
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
                            ::avro::decode(d, v.columnName);
                            break;

                        case 3:
                            ::avro::decode(d, v.lowerBound);
                            break;

                        case 4:
                            ::avro::decode(d, v.upperBound);
                            break;

                        case 5:
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
                ::avro::decode(d, v.columnName);
                ::avro::decode(d, v.lowerBound);
                ::avro::decode(d, v.upperBound);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #filterByRange(FilterByRangeRequest&)}.
     * <p>
     * Calculates which objects from a table have a column that is within the
     * given bounds. An object from the table identified by @a tableName is
     * added to the view @a viewName if its column is within [@a lowerBound, @a
     * upperBound] (inclusive). The operation is synchronous. The response
     * provides a count of the number of objects which passed the bound filter.
     * <p>
     * For track objects, the count reflects how many points fall within the
     * given bounds (which may not include all the track points of any given
     * track).
     */
    struct FilterByRangeResponse
    {

        /**
         * Constructs a FilterByRangeResponse object with default parameter
         * values.
         */
        FilterByRangeResponse() :
            count(int64_t())
        {
        }

        int64_t count;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::FilterByRangeResponse>
    {
        static void encode(Encoder& e, const gpudb::FilterByRangeResponse& v)
        {
            ::avro::encode(e, v.count);
        }

        static void decode(Decoder& d, gpudb::FilterByRangeResponse& v)
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
