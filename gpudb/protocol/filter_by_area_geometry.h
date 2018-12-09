/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __FILTER_BY_AREA_GEOMETRY_H__
#define __FILTER_BY_AREA_GEOMETRY_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #filterByAreaGeometry(const FilterByAreaGeometryRequest&) const}.
     * <p>
     * Calculates which geospatial geometry objects from a table intersect a
     * named area of interest (NAI/polygon). The operation is synchronous,
     * meaning that a response will not be returned until all the matching
     * objects are fully available. The response payload provides the count of
     * the resulting set. A new resultant set (view) which satisfies the input
     * NAI restriction specification is created with the name @a viewName
     * passed in as part of the input.
     */
    struct FilterByAreaGeometryRequest
    {

        /**
         * Constructs a FilterByAreaGeometryRequest object with default
         * parameter values.
         */
        FilterByAreaGeometryRequest() :
            tableName(std::string()),
            viewName(std::string()),
            columnName(std::string()),
            xVector(std::vector<double>()),
            yVector(std::vector<double>()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a FilterByAreaGeometryRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Name of the table to filter.  This may be the
         *                        name of a collection, a table, or a view
         *                        (when chaining queries).  If filtering a
         *                        collection, all child tables where the filter
         *                        expression is valid will be filtered; the
         *                        filtered result tables will then be placed in
         *                        a collection specified by @a viewName.
         * @param[in] viewName_  If provided, then this will be the name of the
         *                       view containing the results. Must not be an
         *                       already existing collection, table or view.
         * @param[in] columnName_  Name of the geospatial geometry column to be
         *                         filtered.
         * @param[in] xVector_  List of x coordinates of the vertices of the
         *                      polygon representing the area to be filtered.
         * @param[in] yVector_  List of y coordinates of the vertices of the
         *                      polygon representing the area to be filtered.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::filter_by_area_geometry_collection_name:
         *                      Name of a collection which is to contain the
         *                      newly created view. If the collection provided
         *                      is non-existent, the collection will be
         *                      automatically created. If empty, then the newly
         *                      created view will be top-level.
         *                      </ul>
         * 
         */
        FilterByAreaGeometryRequest(const std::string& tableName_, const std::string& viewName_, const std::string& columnName_, const std::vector<double>& xVector_, const std::vector<double>& yVector_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            viewName( viewName_ ),
            columnName( columnName_ ),
            xVector( xVector_ ),
            yVector( yVector_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::string viewName;
        std::string columnName;
        std::vector<double> xVector;
        std::vector<double> yVector;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::FilterByAreaGeometryRequest>
    {
        static void encode(Encoder& e, const gpudb::FilterByAreaGeometryRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.viewName);
            ::avro::encode(e, v.columnName);
            ::avro::encode(e, v.xVector);
            ::avro::encode(e, v.yVector);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::FilterByAreaGeometryRequest& v)
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
                            ::avro::decode(d, v.xVector);
                            break;

                        case 4:
                            ::avro::decode(d, v.yVector);
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
                ::avro::decode(d, v.xVector);
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
     * #filterByAreaGeometry(const FilterByAreaGeometryRequest&) const}.
     * <p>
     * Calculates which geospatial geometry objects from a table intersect a
     * named area of interest (NAI/polygon). The operation is synchronous,
     * meaning that a response will not be returned until all the matching
     * objects are fully available. The response payload provides the count of
     * the resulting set. A new resultant set (view) which satisfies the input
     * NAI restriction specification is created with the name @a viewName
     * passed in as part of the input.
     */
    struct FilterByAreaGeometryResponse
    {

        /**
         * Constructs a FilterByAreaGeometryResponse object with default
         * parameter values.
         */
        FilterByAreaGeometryResponse() :
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
    template<> struct codec_traits<gpudb::FilterByAreaGeometryResponse>
    {
        static void encode(Encoder& e, const gpudb::FilterByAreaGeometryResponse& v)
        {
            ::avro::encode(e, v.count);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::FilterByAreaGeometryResponse& v)
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
