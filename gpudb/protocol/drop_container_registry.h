/*
 *  This file was autogenerated by the Kinetica schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __DROP_CONTAINER_REGISTRY_H__
#define __DROP_CONTAINER_REGISTRY_H__

namespace gpudb
{
    /** @private */
    struct DropContainerRegistryRequest
    {
        DropContainerRegistryRequest() :
            registryName(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        DropContainerRegistryRequest(const std::string& registryName_, const std::map<std::string, std::string>& options_):
            registryName( registryName_ ),
            options( options_ )
        {
        }

        std::string registryName;
        std::map<std::string, std::string> options;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::DropContainerRegistryRequest>
    {
        static void encode(Encoder& e, const gpudb::DropContainerRegistryRequest& v)
        {
            ::avro::encode(e, v.registryName);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::DropContainerRegistryRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.registryName);
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
                ::avro::decode(d, v.registryName);
                ::avro::decode(d, v.options);
            }
        }
    };
} // end namespace avro

namespace gpudb
{
    /** @private */
    struct DropContainerRegistryResponse
    {
        DropContainerRegistryResponse() :
            registryName(std::string()),
            info(std::map<std::string, std::string>())
        {
        }

        std::string registryName;
        std::map<std::string, std::string> info;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::DropContainerRegistryResponse>
    {
        static void encode(Encoder& e, const gpudb::DropContainerRegistryResponse& v)
        {
            ::avro::encode(e, v.registryName);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::DropContainerRegistryResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.registryName);
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
                ::avro::decode(d, v.registryName);
                ::avro::decode(d, v.info);
            }
        }
    };
} // end namespace avro

#endif // __DROP_CONTAINER_REGISTRY_H__
