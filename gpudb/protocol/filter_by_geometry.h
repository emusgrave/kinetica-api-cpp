/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __FILTER_BY_GEOMETRY_H__
#define __FILTER_BY_GEOMETRY_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #filterByGeometry(const FilterByGeometryRequest&) const}.
     * <p>
     * Applies a geometry filter against a spatial column named WKT in a given
     * table, collection or view. The filtering geometry is provided by @a
     * inputWkt.
     */
    struct FilterByGeometryRequest
    {

        /**
         * Constructs a FilterByGeometryRequest object with default parameter
         * values.
         */
        FilterByGeometryRequest() :
            tableName(std::string()),
            viewName(std::string()),
            columnName(std::string()),
            inputWkt(std::string()),
            operation(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a FilterByGeometryRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Name of the table on which the filter by
         *                        geometry will be performed.  Must be an
         *                        existing table, collection or view containing
         *                        a column named WKT.
         * @param[in] viewName_  If provided, then this will be the name of the
         *                       view containing the results. Has the same
         *                       naming restrictions as <a
         *                       href="../../concepts/tables.html"
         *                       target="_top">tables</a>.  Default value is an
         *                       empty string.
         * @param[in] columnName_  Name of the column to be used in the filter.
         *                         Must be 'WKT'
         * @param[in] inputWkt_  A geometry in WKT format that will be used to
         *                       filter the objects in @a tableName.  Default
         *                       value is an empty string.
         * @param[in] operation_  The geometric filtering operation to perform
         *                        Values: 'contains', 'crosses', 'disjoint',
         *                        'equals', 'intersects', 'overlaps',
         *                        'touches', 'within'.
         * @param[in] options_  Optional parameters.  Default value is an empty
         *                      std::map.
         * 
         */
        FilterByGeometryRequest(const std::string& tableName_, const std::string& viewName_, const std::string& columnName_, const std::string& inputWkt_, const std::string& operation_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            viewName( viewName_ ),
            columnName( columnName_ ),
            inputWkt( inputWkt_ ),
            operation( operation_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::string viewName;
        std::string columnName;
        std::string inputWkt;
        std::string operation;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::FilterByGeometryRequest>
    {
        static void encode(Encoder& e, const gpudb::FilterByGeometryRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.viewName);
            ::avro::encode(e, v.columnName);
            ::avro::encode(e, v.inputWkt);
            ::avro::encode(e, v.operation);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::FilterByGeometryRequest& v)
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
                            ::avro::decode(d, v.inputWkt);
                            break;

                        case 4:
                            ::avro::decode(d, v.operation);
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
                ::avro::decode(d, v.inputWkt);
                ::avro::decode(d, v.operation);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #filterByGeometry(const FilterByGeometryRequest&) const}.
     * <p>
     * Applies a geometry filter against a spatial column named WKT in a given
     * table, collection or view. The filtering geometry is provided by @a
     * inputWkt.
     */
    struct FilterByGeometryResponse
    {

        /**
         * Constructs a FilterByGeometryResponse object with default parameter
         * values.
         */
        FilterByGeometryResponse() :
            count(int64_t())
        {
        }

        int64_t count;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::FilterByGeometryResponse>
    {
        static void encode(Encoder& e, const gpudb::FilterByGeometryResponse& v)
        {
            ::avro::encode(e, v.count);
        }

        static void decode(Decoder& d, gpudb::FilterByGeometryResponse& v)
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
