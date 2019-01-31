/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __GET_VECTORTILE_H__
#define __GET_VECTORTILE_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #getVectortile(const GetVectortileRequest&) const}.
     * <p>
     * @private
     */
    struct GetVectortileRequest
    {

        /**
         * @private
         * Constructs a GetVectortileRequest object with default parameter
         * values.
         */
        GetVectortileRequest() :
            tableNames(std::vector<std::string>()),
            columnNames(std::vector<std::string>()),
            layers(std::map<std::string, std::vector<std::string> >()),
            tileX(int32_t()),
            tileY(int32_t()),
            zoom(int32_t()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * @private
         * Constructs a GetVectortileRequest object with the specified
         * parameters.
         * 
         * @param[in] tableNames_
         * @param[in] columnNames_
         * @param[in] layers_
         * @param[in] tileX_
         * @param[in] tileY_
         * @param[in] zoom_
         * @param[in] options_
         * 
         */
        GetVectortileRequest(const std::vector<std::string>& tableNames_, const std::vector<std::string>& columnNames_, const std::map<std::string, std::vector<std::string> >& layers_, const int32_t tileX_, const int32_t tileY_, const int32_t zoom_, const std::map<std::string, std::string>& options_):
            tableNames( tableNames_ ),
            columnNames( columnNames_ ),
            layers( layers_ ),
            tileX( tileX_ ),
            tileY( tileY_ ),
            zoom( zoom_ ),
            options( options_ )
        {
        }

        std::vector<std::string> tableNames;
        std::vector<std::string> columnNames;
        std::map<std::string, std::vector<std::string> > layers;
        int32_t tileX;
        int32_t tileY;
        int32_t zoom;
        std::map<std::string, std::string> options;
    };
}

    /**
     * @private
     */

namespace avro
{
    template<> struct codec_traits<gpudb::GetVectortileRequest>
    {
        static void encode(Encoder& e, const gpudb::GetVectortileRequest& v)
        {
            ::avro::encode(e, v.tableNames);
            ::avro::encode(e, v.columnNames);
            ::avro::encode(e, v.layers);
            ::avro::encode(e, v.tileX);
            ::avro::encode(e, v.tileY);
            ::avro::encode(e, v.zoom);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::GetVectortileRequest& v)
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
                            ::avro::decode(d, v.columnNames);
                            break;

                        case 2:
                            ::avro::decode(d, v.layers);
                            break;

                        case 3:
                            ::avro::decode(d, v.tileX);
                            break;

                        case 4:
                            ::avro::decode(d, v.tileY);
                            break;

                        case 5:
                            ::avro::decode(d, v.zoom);
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
                ::avro::decode(d, v.tableNames);
                ::avro::decode(d, v.columnNames);
                ::avro::decode(d, v.layers);
                ::avro::decode(d, v.tileX);
                ::avro::decode(d, v.tileY);
                ::avro::decode(d, v.zoom);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #getVectortile(const GetVectortileRequest&) const}.
     * <p>
     * @private
     */
    struct GetVectortileResponse
    {

        /**
         * @private
         * Constructs a GetVectortileResponse object with default parameter
         * values.
         */
        GetVectortileResponse() :
            encodedData(std::string()),
            info(std::map<std::string, std::string>())
        {
        }

        std::string encodedData;
        std::map<std::string, std::string> info;
    };
}

    /**
     * @private
     */

namespace avro
{
    template<> struct codec_traits<gpudb::GetVectortileResponse>
    {
        static void encode(Encoder& e, const gpudb::GetVectortileResponse& v)
        {
            ::avro::encode(e, v.encodedData);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::GetVectortileResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.encodedData);
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
                ::avro::decode(d, v.encodedData);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
