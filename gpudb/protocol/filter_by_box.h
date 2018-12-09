/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __FILTER_BY_BOX_H__
#define __FILTER_BY_BOX_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #filterByBox(const FilterByBoxRequest&) const}.
     * <p>
     * Calculates how many objects within the given table lie in a rectangular
     * box. The operation is synchronous, meaning that a response will not be
     * returned until all the objects are fully available. The response payload
     * provides the count of the resulting set. A new resultant set which
     * satisfies the input NAI restriction specification is also created when a
     * @a viewName is passed in as part of the input payload.
     */
    struct FilterByBoxRequest
    {

        /**
         * Constructs a FilterByBoxRequest object with default parameter
         * values.
         */
        FilterByBoxRequest() :
            tableName(std::string()),
            viewName(std::string()),
            xColumnName(std::string()),
            minX(double()),
            maxX(double()),
            yColumnName(std::string()),
            minY(double()),
            maxY(double()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a FilterByBoxRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Name of the table on which the bounding box
         *                        operation will be performed. Must be an
         *                        existing table.
         * @param[in] viewName_  Optional name of the result view that will be
         *                       created containing the results of the query.
         *                       Has the same naming restrictions as <a
         *                       href="../../concepts/tables.html"
         *                       target="_top">tables</a>.
         * @param[in] xColumnName_  Name of the column on which to perform the
         *                          bounding box query. Must be a valid numeric
         *                          column.
         * @param[in] minX_  Lower bound for the column chosen by @a
         *                   xColumnName.  Must be less than or equal to @a
         *                   maxX.
         * @param[in] maxX_  Upper bound for @a xColumnName.  Must be greater
         *                   than or equal to @a minX.
         * @param[in] yColumnName_  Name of a column on which to perform the
         *                          bounding box query. Must be a valid numeric
         *                          column.
         * @param[in] minY_  Lower bound for @a yColumnName. Must be less than
         *                   or equal to @a maxY.
         * @param[in] maxY_  Upper bound for @a yColumnName. Must be greater
         *                   than or equal to @a minY.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::filter_by_box_collection_name: Name of a
         *                      collection which is to contain the newly
         *                      created view. If the collection provided is
         *                      non-existent, the collection will be
         *                      automatically created. If empty, then the newly
         *                      created view will be top-level.
         *                      </ul>
         * 
         */
        FilterByBoxRequest(const std::string& tableName_, const std::string& viewName_, const std::string& xColumnName_, const double minX_, const double maxX_, const std::string& yColumnName_, const double minY_, const double maxY_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            viewName( viewName_ ),
            xColumnName( xColumnName_ ),
            minX( minX_ ),
            maxX( maxX_ ),
            yColumnName( yColumnName_ ),
            minY( minY_ ),
            maxY( maxY_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::string viewName;
        std::string xColumnName;
        double minX;
        double maxX;
        std::string yColumnName;
        double minY;
        double maxY;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::FilterByBoxRequest>
    {
        static void encode(Encoder& e, const gpudb::FilterByBoxRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.viewName);
            ::avro::encode(e, v.xColumnName);
            ::avro::encode(e, v.minX);
            ::avro::encode(e, v.maxX);
            ::avro::encode(e, v.yColumnName);
            ::avro::encode(e, v.minY);
            ::avro::encode(e, v.maxY);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::FilterByBoxRequest& v)
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
                            ::avro::decode(d, v.minX);
                            break;

                        case 4:
                            ::avro::decode(d, v.maxX);
                            break;

                        case 5:
                            ::avro::decode(d, v.yColumnName);
                            break;

                        case 6:
                            ::avro::decode(d, v.minY);
                            break;

                        case 7:
                            ::avro::decode(d, v.maxY);
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
                ::avro::decode(d, v.viewName);
                ::avro::decode(d, v.xColumnName);
                ::avro::decode(d, v.minX);
                ::avro::decode(d, v.maxX);
                ::avro::decode(d, v.yColumnName);
                ::avro::decode(d, v.minY);
                ::avro::decode(d, v.maxY);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #filterByBox(const FilterByBoxRequest&) const}.
     * <p>
     * Calculates how many objects within the given table lie in a rectangular
     * box. The operation is synchronous, meaning that a response will not be
     * returned until all the objects are fully available. The response payload
     * provides the count of the resulting set. A new resultant set which
     * satisfies the input NAI restriction specification is also created when a
     * @a viewName is passed in as part of the input payload.
     */
    struct FilterByBoxResponse
    {

        /**
         * Constructs a FilterByBoxResponse object with default parameter
         * values.
         */
        FilterByBoxResponse() :
            count(int64_t()),
            info(std::map<std::string, std::string>())
        {
        }

        int64_t count;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::FilterByBoxResponse>
    {
        static void encode(Encoder& e, const gpudb::FilterByBoxResponse& v)
        {
            ::avro::encode(e, v.count);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::FilterByBoxResponse& v)
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
                ::avro::decode(d, v.count);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
