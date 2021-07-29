/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __ALTER_VIDEO_H__
#define __ALTER_VIDEO_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #alterVideo(const AlterVideoRequest&) const}.
     * <p>
     * Alters a video.
     */
    struct AlterVideoRequest
    {

        /**
         * Constructs an AlterVideoRequest object with default parameter
         * values.
         */
        AlterVideoRequest() :
            path(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an AlterVideoRequest object with the specified
         * parameters.
         * 
         * @param[in] path_  Fully-qualified <a href="../../../tools/kifs/"
         *                   target="_top">KiFS</a> path to the video to be
         *                   altered.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li> gpudb::alter_video_ttl: Sets the
         *                      <a href="../../../concepts/ttl/"
         *                      target="_top">TTL</a> of the video.
         *                      </ul>
         * 
         */
        AlterVideoRequest(const std::string& path_, const std::map<std::string, std::string>& options_):
            path( path_ ),
            options( options_ )
        {
        }

        std::string path;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AlterVideoRequest>
    {
        static void encode(Encoder& e, const gpudb::AlterVideoRequest& v)
        {
            ::avro::encode(e, v.path);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AlterVideoRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.path);
                            break;

                        case 1:
                            ::avro::decode(d, v.options);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.path);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #alterVideo(const AlterVideoRequest&) const}.
     * <p>
     * Alters a video.
     */
    struct AlterVideoResponse
    {

        /**
         * Constructs an AlterVideoResponse object with default parameter
         * values.
         */
        AlterVideoResponse() :
            path(std::string()),
            info(std::map<std::string, std::string>())
        {
        }

        std::string path;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AlterVideoResponse>
    {
        static void encode(Encoder& e, const gpudb::AlterVideoResponse& v)
        {
            ::avro::encode(e, v.path);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::AlterVideoResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.path);
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
                ::avro::decode(d, v.path);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif