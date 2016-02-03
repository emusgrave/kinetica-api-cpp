/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __VISUALIZE_IMAGE_HEATMAP_H__
#define __VISUALIZE_IMAGE_HEATMAP_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #visualizeImageHeatmap(VisualizeImageHeatmapRequest&)}.
     * <p>
     * Generates rasterized heatmap image tiles for an area of interest using
     * the given tables and the provided parameters.
     * <p>
     * All color values must be in the format RRGGBB or AARRGGBB (to specify
     * the alpha value).
     * <p>

     * The heatmap image is contained in the @a imageData field.
     */
    struct VisualizeImageHeatmapRequest
    {

        /**
         * Constructs a VisualizeImageHeatmapRequest object with default
         * parameter values.
         */
        VisualizeImageHeatmapRequest() :
            tableNames(std::vector<std::string>()),
            xColumnName(std::string()),
            yColumnName(std::string()),
            valueColumnName(std::string()),
            minX(double()),
            maxX(double()),
            minY(double()),
            maxY(double()),
            width(int32_t()),
            height(int32_t()),
            projection(std::string()),
            colormap(std::string()),
            blurRadius(int32_t()),
            bgColor(int64_t()),
            gradientStartColor(int64_t()),
            gradientEndColor(int64_t()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a VisualizeImageHeatmapRequest object with the specified
         * parameters.
         * 
         * @param[in] tableNames  Name of the table containing the data for the
         *                        various layers to be rendered.
         * @param[in] xColumnName  Name of the column containing the x
         *                         coordinates.
         * @param[in] yColumnName  Name of the column containing the y
         *                         coordinates.
         * @param[in] valueColumnName
         * @param[in] minX  Lower bound for the x values.
         * @param[in] maxX  Upper bound for the x values.
         * @param[in] minY  Lower bound for the y values.
         * @param[in] maxY  Upper bound for the y values.
         * @param[in] width  Width of the generated image.
         * @param[in] height  Height of the generated image.
         * @param[in] projection  Spatial Reference System (i.e. EPSG Code).
         *                        Default value is 'PLATE_CARREE'. The allowed
         *                        values are:  ~!~ * EPSG:4326 * PLATE_CARREE *
         *                        _900913 * EPSG:900913 * _102100 * EPSG:102100
         *                        * _3857 * EPSG:3857 * WEB_MERCATOR~!~
         * @param[in] colormap  Colormap for the heat map.  Default value is
         *                      'none'.
         * @param[in] blurRadius  Blurring radius for the heat map.  Default
         *                        value is '5'. The minimum allowed value is 1.
         *                        The maximum allowed value is 32.
         * @param[in] bgColor  Background color of the generated image.
         * @param[in] gradientStartColor  User defined gradient start color for
         *                                the heat map.  Default value is
         *                                'FFFFFF'.
         * @param[in] gradientEndColor  User defined gradient end color for the
         *                              heat map.  Default value is 'FF0000'.
         * @param[in] options  Optional parameters.  Default value is an empty
         *                     {@link std::map}.
         * 
         */
        VisualizeImageHeatmapRequest(const std::vector<std::string>& tableNames, const std::string& xColumnName, const std::string& yColumnName, const std::string& valueColumnName, const double minX, const double maxX, const double minY, const double maxY, const int32_t width, const int32_t height, const std::string& projection, const std::string& colormap, const int32_t blurRadius, const int64_t bgColor, const int64_t gradientStartColor, const int64_t gradientEndColor, const std::map<std::string, std::string>& options):
            tableNames(tableNames),
            xColumnName(xColumnName),
            yColumnName(yColumnName),
            valueColumnName(valueColumnName),
            minX(minX),
            maxX(maxX),
            minY(minY),
            maxY(maxY),
            width(width),
            height(height),
            projection(projection),
            colormap(colormap),
            blurRadius(blurRadius),
            bgColor(bgColor),
            gradientStartColor(gradientStartColor),
            gradientEndColor(gradientEndColor),
            options(options)
        {
        }

        std::vector<std::string> tableNames;
        std::string xColumnName;
        std::string yColumnName;
        std::string valueColumnName;
        double minX;
        double maxX;
        double minY;
        double maxY;
        int32_t width;
        int32_t height;
        std::string projection;
        std::string colormap;
        int32_t blurRadius;
        int64_t bgColor;
        int64_t gradientStartColor;
        int64_t gradientEndColor;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::VisualizeImageHeatmapRequest>
    {
        static void encode(Encoder& e, const gpudb::VisualizeImageHeatmapRequest& v)
        {
            ::avro::encode(e, v.tableNames);
            ::avro::encode(e, v.xColumnName);
            ::avro::encode(e, v.yColumnName);
            ::avro::encode(e, v.valueColumnName);
            ::avro::encode(e, v.minX);
            ::avro::encode(e, v.maxX);
            ::avro::encode(e, v.minY);
            ::avro::encode(e, v.maxY);
            ::avro::encode(e, v.width);
            ::avro::encode(e, v.height);
            ::avro::encode(e, v.projection);
            ::avro::encode(e, v.colormap);
            ::avro::encode(e, v.blurRadius);
            ::avro::encode(e, v.bgColor);
            ::avro::encode(e, v.gradientStartColor);
            ::avro::encode(e, v.gradientEndColor);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::VisualizeImageHeatmapRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.tableNames);
                            break;

                        case 1:
                            ::avro::decode(d, v.xColumnName);
                            break;

                        case 2:
                            ::avro::decode(d, v.yColumnName);
                            break;

                        case 3:
                            ::avro::decode(d, v.valueColumnName);
                            break;

                        case 4:
                            ::avro::decode(d, v.minX);
                            break;

                        case 5:
                            ::avro::decode(d, v.maxX);
                            break;

                        case 6:
                            ::avro::decode(d, v.minY);
                            break;

                        case 7:
                            ::avro::decode(d, v.maxY);
                            break;

                        case 8:
                            ::avro::decode(d, v.width);
                            break;

                        case 9:
                            ::avro::decode(d, v.height);
                            break;

                        case 10:
                            ::avro::decode(d, v.projection);
                            break;

                        case 11:
                            ::avro::decode(d, v.colormap);
                            break;

                        case 12:
                            ::avro::decode(d, v.blurRadius);
                            break;

                        case 13:
                            ::avro::decode(d, v.bgColor);
                            break;

                        case 14:
                            ::avro::decode(d, v.gradientStartColor);
                            break;

                        case 15:
                            ::avro::decode(d, v.gradientEndColor);
                            break;

                        case 16:
                            ::avro::decode(d, v.options);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.tableNames);
                ::avro::decode(d, v.xColumnName);
                ::avro::decode(d, v.yColumnName);
                ::avro::decode(d, v.valueColumnName);
                ::avro::decode(d, v.minX);
                ::avro::decode(d, v.maxX);
                ::avro::decode(d, v.minY);
                ::avro::decode(d, v.maxY);
                ::avro::decode(d, v.width);
                ::avro::decode(d, v.height);
                ::avro::decode(d, v.projection);
                ::avro::decode(d, v.colormap);
                ::avro::decode(d, v.blurRadius);
                ::avro::decode(d, v.bgColor);
                ::avro::decode(d, v.gradientStartColor);
                ::avro::decode(d, v.gradientEndColor);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #visualizeImageHeatmap(VisualizeImageHeatmapRequest&)}.
     * <p>
     * Generates rasterized heatmap image tiles for an area of interest using
     * the given tables and the provided parameters.
     * <p>
     * All color values must be in the format RRGGBB or AARRGGBB (to specify
     * the alpha value).
     * <p>

     * The heatmap image is contained in the @a imageData field.
     */
    struct VisualizeImageHeatmapResponse
    {

        /**
         * Constructs a VisualizeImageHeatmapResponse object with default
         * parameter values.
         */
        VisualizeImageHeatmapResponse() :
            width(int32_t()),
            height(int32_t()),
            bgColor(int64_t()),
            imageData(std::vector<uint8_t>())
        {
        }

        int32_t width;
        int32_t height;
        int64_t bgColor;
        std::vector<uint8_t> imageData;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::VisualizeImageHeatmapResponse>
    {
        static void encode(Encoder& e, const gpudb::VisualizeImageHeatmapResponse& v)
        {
            ::avro::encode(e, v.width);
            ::avro::encode(e, v.height);
            ::avro::encode(e, v.bgColor);
            ::avro::encode(e, v.imageData);
        }

        static void decode(Decoder& d, gpudb::VisualizeImageHeatmapResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.width);
                            break;

                        case 1:
                            ::avro::decode(d, v.height);
                            break;

                        case 2:
                            ::avro::decode(d, v.bgColor);
                            break;

                        case 3:
                            ::avro::decode(d, v.imageData);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.width);
                ::avro::decode(d, v.height);
                ::avro::decode(d, v.bgColor);
                ::avro::decode(d, v.imageData);
            }
        }
    };
}

#endif
