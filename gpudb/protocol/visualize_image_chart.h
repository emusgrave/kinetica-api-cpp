/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __VISUALIZE_IMAGE_CHART_H__
#define __VISUALIZE_IMAGE_CHART_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #visualizeImageChart(const VisualizeImageChartRequest&) const}.
     * <p>
     * Scatter plot is the only plot type currently supported. A non-numeric
     * column can be specified as x or y column and jitters can be added to
     * them to avoid excessive overlapping. All color values must be in the
     * format RRGGBB or AARRGGBB (to specify the alpha value).
     * The image is contained in the @a imageData field.
     */
    struct VisualizeImageChartRequest
    {

        /**
         * Constructs a VisualizeImageChartRequest object with default
         * parameter values.
         */
        VisualizeImageChartRequest() :
            tableName(std::string()),
            xColumnNames(std::vector<std::string>()),
            yColumnNames(std::vector<std::string>()),
            minX(double()),
            maxX(double()),
            minY(double()),
            maxY(double()),
            width(int32_t()),
            height(int32_t()),
            bgColor(std::string()),
            styleOptions(std::map<std::string, std::vector<std::string> >()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a VisualizeImageChartRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Name of the table containing the data to be
         *                        drawn as a chart.
         * @param[in] xColumnNames_  Names of the columns containing the data
         *                           mapped to the x axis of a chart.
         * @param[in] yColumnNames_  Names of the columns containing the data
         *                           mapped to the y axis of a chart.
         * @param[in] minX_  Lower bound for the x column values. For
         *                   non-numeric x column, each x column item is mapped
         *                   to an integral value starting from 0.
         * @param[in] maxX_  Upper bound for the x column values. For
         *                   non-numeric x column, each x column item is mapped
         *                   to an integral value starting from 0.
         * @param[in] minY_  Lower bound for the y column values. For
         *                   non-numeric y column, each y column item is mapped
         *                   to an integral value starting from 0.
         * @param[in] maxY_  Upper bound for the y column values. For
         *                   non-numeric y column, each y column item is mapped
         *                   to an integral value starting from 0.
         * @param[in] width_  Width of the generated image in pixels.
         * @param[in] height_  Height of the generated image in pixels.
         * @param[in] bgColor_  Background color of the generated image.
         * @param[in] styleOptions_  Rendering style options for a chart.
         *                           <ul>
         *                                   <li>
         *                           gpudb::visualize_image_chart_pointcolor:
         *                           The color of points in the plot
         *                           represented as a hexadecimal number.  The
         *                           default value is '0000FF'.
         *                                   <li>
         *                           gpudb::visualize_image_chart_pointsize:
         *                           The size of points in the plot represented
         *                           as number of pixels.  The default value is
         *                           '3'.
         *                                   <li>
         *                           gpudb::visualize_image_chart_pointshape:
         *                           The shape of points in the plot.
         *                           <ul>
         *                                   <li>
         *                           gpudb::visualize_image_chart_none
         *                                   <li>
         *                           gpudb::visualize_image_chart_circle
         *                                   <li>
         *                           gpudb::visualize_image_chart_square
         *                                   <li>
         *                           gpudb::visualize_image_chart_diamond
         *                                   <li>
         *                           gpudb::visualize_image_chart_hollowcircle
         *                                   <li>
         *                           gpudb::visualize_image_chart_hollowsquare
         *                                   <li>
         *                           gpudb::visualize_image_chart_hollowdiamond
         *                           </ul>
         *                           The default value is
         *                           gpudb::visualize_image_chart_square.
         *                                   <li>
         *                           gpudb::visualize_image_chart_cb_pointcolors:
         *                           Point color class break information
         *                           consisting of three entries: class-break
         *                           attribute, class-break values/ranges, and
         *                           point color values. This option overrides
         *                           the pointcolor option if both are
         *                           provided. Class-break ranges are
         *                           represented in the form of "min:max".
         *                           Class-break values/ranges and point color
         *                           values are separated by cb_delimiter, e.g.
         *                           {"price", "20:30;30:40;40:50",
         *                           "0xFF0000;0x00FF00;0x0000FF"}.
         *                                   <li>
         *                           gpudb::visualize_image_chart_cb_pointsizes:
         *                           Point size class break information
         *                           consisting of three entries: class-break
         *                           attribute, class-break values/ranges, and
         *                           point size values. This option overrides
         *                           the pointsize option if both are provided.
         *                           Class-break ranges are represented in the
         *                           form of "min:max". Class-break
         *                           values/ranges and point size values are
         *                           separated by cb_delimiter, e.g. {"states",
         *                           "NY;TX;CA", "3;5;7"}.
         *                                   <li>
         *                           gpudb::visualize_image_chart_cb_pointshapes:
         *                           Point shape class break information
         *                           consisting of three entries: class-break
         *                           attribute, class-break values/ranges, and
         *                           point shape names. This option overrides
         *                           the pointshape option if both are
         *                           provided. Class-break ranges are
         *                           represented in the form of "min:max".
         *                           Class-break values/ranges and point shape
         *                           names are separated by cb_delimiter, e.g.
         *                           {"states", "NY;TX;CA",
         *                           "circle;square;diamond"}.
         *                                   <li>
         *                           gpudb::visualize_image_chart_cb_delimiter:
         *                           A character or string which separates
         *                           per-class values in a class-break style
         *                           option string.  The default value is ';'.
         *                                   <li>
         *                           gpudb::visualize_image_chart_x_order_by:
         *                           An expression or aggregate expression by
         *                           which non-numeric x column values are
         *                           sorted, e.g. "avg(price) descending".
         *                                   <li>
         *                           gpudb::visualize_image_chart_y_order_by:
         *                           An expression or aggregate expression by
         *                           which non-numeric y column values are
         *                           sorted, e.g. "avg(price)", which defaults
         *                           to "avg(price) ascending".
         *                                   <li>
         *                           gpudb::visualize_image_chart_scale_type_x:
         *                           Type of x axis scale.
         *                           <ul>
         *                                   <li>
         *                           gpudb::visualize_image_chart_none: No
         *                           scale is applied to the x axis.
         *                                   <li>
         *                           gpudb::visualize_image_chart_log: A
         *                           base-10 log scale is applied to the x
         *                           axis.
         *                           </ul>
         *                           The default value is
         *                           gpudb::visualize_image_chart_none.
         *                                   <li>
         *                           gpudb::visualize_image_chart_scale_type_y:
         *                           Type of y axis scale.
         *                           <ul>
         *                                   <li>
         *                           gpudb::visualize_image_chart_none: No
         *                           scale is applied to the y axis.
         *                                   <li>
         *                           gpudb::visualize_image_chart_log: A
         *                           base-10 log scale is applied to the y
         *                           axis.
         *                           </ul>
         *                           The default value is
         *                           gpudb::visualize_image_chart_none.
         *                                   <li>
         *                           gpudb::visualize_image_chart_min_max_scaled:
         *                           If this options is set to "false", this
         *                           endpoint expects request's min/max values
         *                           are not yet scaled. They will be scaled
         *                           according to scale_type_x or scale_type_y
         *                           for response. If this options is set to
         *                           "true", this endpoint expects request's
         *                           min/max values are already scaled
         *                           according to scale_type_x/scale_type_y.
         *                           Response's min/max values will be equal to
         *                           request's min/max values.  The default
         *                           value is 'false'.
         *                                   <li>
         *                           gpudb::visualize_image_chart_jitter_x:
         *                           Amplitude of horizontal jitter applied to
         *                           non-numeric x column values.  The default
         *                           value is '0.0'.
         *                                   <li>
         *                           gpudb::visualize_image_chart_jitter_y:
         *                           Amplitude of vertical jitter applied to
         *                           non-numeric y column values.  The default
         *                           value is '0.0'.
         *                                   <li>
         *                           gpudb::visualize_image_chart_plot_all: If
         *                           this options is set to "true", all
         *                           non-numeric column values are plotted
         *                           ignoring min_x, max_x, min_y and max_y
         *                           parameters.  The default value is 'false'.
         *                           </ul>
         * @param[in] options_  Optional parameters.
         * 
         */
        VisualizeImageChartRequest(const std::string& tableName_, const std::vector<std::string>& xColumnNames_, const std::vector<std::string>& yColumnNames_, const double minX_, const double maxX_, const double minY_, const double maxY_, const int32_t width_, const int32_t height_, const std::string& bgColor_, const std::map<std::string, std::vector<std::string> >& styleOptions_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            xColumnNames( xColumnNames_ ),
            yColumnNames( yColumnNames_ ),
            minX( minX_ ),
            maxX( maxX_ ),
            minY( minY_ ),
            maxY( maxY_ ),
            width( width_ ),
            height( height_ ),
            bgColor( bgColor_ ),
            styleOptions( styleOptions_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::vector<std::string> xColumnNames;
        std::vector<std::string> yColumnNames;
        double minX;
        double maxX;
        double minY;
        double maxY;
        int32_t width;
        int32_t height;
        std::string bgColor;
        std::map<std::string, std::vector<std::string> > styleOptions;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::VisualizeImageChartRequest>
    {
        static void encode(Encoder& e, const gpudb::VisualizeImageChartRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.xColumnNames);
            ::avro::encode(e, v.yColumnNames);
            ::avro::encode(e, v.minX);
            ::avro::encode(e, v.maxX);
            ::avro::encode(e, v.minY);
            ::avro::encode(e, v.maxY);
            ::avro::encode(e, v.width);
            ::avro::encode(e, v.height);
            ::avro::encode(e, v.bgColor);
            ::avro::encode(e, v.styleOptions);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::VisualizeImageChartRequest& v)
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
                            ::avro::decode(d, v.xColumnNames);
                            break;

                        case 2:
                            ::avro::decode(d, v.yColumnNames);
                            break;

                        case 3:
                            ::avro::decode(d, v.minX);
                            break;

                        case 4:
                            ::avro::decode(d, v.maxX);
                            break;

                        case 5:
                            ::avro::decode(d, v.minY);
                            break;

                        case 6:
                            ::avro::decode(d, v.maxY);
                            break;

                        case 7:
                            ::avro::decode(d, v.width);
                            break;

                        case 8:
                            ::avro::decode(d, v.height);
                            break;

                        case 9:
                            ::avro::decode(d, v.bgColor);
                            break;

                        case 10:
                            ::avro::decode(d, v.styleOptions);
                            break;

                        case 11:
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
                ::avro::decode(d, v.xColumnNames);
                ::avro::decode(d, v.yColumnNames);
                ::avro::decode(d, v.minX);
                ::avro::decode(d, v.maxX);
                ::avro::decode(d, v.minY);
                ::avro::decode(d, v.maxY);
                ::avro::decode(d, v.width);
                ::avro::decode(d, v.height);
                ::avro::decode(d, v.bgColor);
                ::avro::decode(d, v.styleOptions);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #visualizeImageChart(const VisualizeImageChartRequest&) const}.
     * <p>
     * Scatter plot is the only plot type currently supported. A non-numeric
     * column can be specified as x or y column and jitters can be added to
     * them to avoid excessive overlapping. All color values must be in the
     * format RRGGBB or AARRGGBB (to specify the alpha value).
     * The image is contained in the @a imageData field.
     */
    struct VisualizeImageChartResponse
    {

        /**
         * Constructs a VisualizeImageChartResponse object with default
         * parameter values.
         */
        VisualizeImageChartResponse() :
            minX(double()),
            maxX(double()),
            minY(double()),
            maxY(double()),
            width(int32_t()),
            height(int32_t()),
            bgColor(std::string()),
            imageData(std::vector<uint8_t>()),
            axesInfo(std::map<std::string, std::vector<std::string> >()),
            info(std::map<std::string, std::string>())
        {
        }

        double minX;
        double maxX;
        double minY;
        double maxY;
        int32_t width;
        int32_t height;
        std::string bgColor;
        std::vector<uint8_t> imageData;
        std::map<std::string, std::vector<std::string> > axesInfo;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::VisualizeImageChartResponse>
    {
        static void encode(Encoder& e, const gpudb::VisualizeImageChartResponse& v)
        {
            ::avro::encode(e, v.minX);
            ::avro::encode(e, v.maxX);
            ::avro::encode(e, v.minY);
            ::avro::encode(e, v.maxY);
            ::avro::encode(e, v.width);
            ::avro::encode(e, v.height);
            ::avro::encode(e, v.bgColor);
            ::avro::encode(e, v.imageData);
            ::avro::encode(e, v.axesInfo);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::VisualizeImageChartResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.minX);
                            break;

                        case 1:
                            ::avro::decode(d, v.maxX);
                            break;

                        case 2:
                            ::avro::decode(d, v.minY);
                            break;

                        case 3:
                            ::avro::decode(d, v.maxY);
                            break;

                        case 4:
                            ::avro::decode(d, v.width);
                            break;

                        case 5:
                            ::avro::decode(d, v.height);
                            break;

                        case 6:
                            ::avro::decode(d, v.bgColor);
                            break;

                        case 7:
                            ::avro::decode(d, v.imageData);
                            break;

                        case 8:
                            ::avro::decode(d, v.axesInfo);
                            break;

                        case 9:
                            ::avro::decode(d, v.info);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.minX);
                ::avro::decode(d, v.maxX);
                ::avro::decode(d, v.minY);
                ::avro::decode(d, v.maxY);
                ::avro::decode(d, v.width);
                ::avro::decode(d, v.height);
                ::avro::decode(d, v.bgColor);
                ::avro::decode(d, v.imageData);
                ::avro::decode(d, v.axesInfo);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
