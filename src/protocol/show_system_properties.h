/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __SHOW_SYSTEM_PROPERTIES_H__
#define __SHOW_SYSTEM_PROPERTIES_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #showSystemProperties(ShowSystemPropertiesRequest&)}.
     * <p>
     * Returns server configuration and version related information to the
     * caller. The GPUdb Admin tool uses it to present server related
     * information to the user.
     */
    struct ShowSystemPropertiesRequest
    {

        /**
         * Constructs a ShowSystemPropertiesRequest object with default
         * parameter values.
         */
        ShowSystemPropertiesRequest() :
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a ShowSystemPropertiesRequest object with the specified
         * parameters.
         * 
         * @param[in] options  Optional parameters, currently unused.  Default
         *                     value is an empty {@link std::map}.
         * 
         */
        ShowSystemPropertiesRequest(const std::map<std::string, std::string>& options):
            options(options)
        {
        }

        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::ShowSystemPropertiesRequest>
    {
        static void encode(Encoder& e, const gpudb::ShowSystemPropertiesRequest& v)
        {
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::ShowSystemPropertiesRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.options);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #showSystemProperties(ShowSystemPropertiesRequest&)}.
     * <p>
     * Returns server configuration and version related information to the
     * caller. The GPUdb Admin tool uses it to present server related
     * information to the user.
     */
    struct ShowSystemPropertiesResponse
    {

        /**
         * Constructs a ShowSystemPropertiesResponse object with default
         * parameter values.
         */
        ShowSystemPropertiesResponse() :
            propertyMap(std::map<std::string, std::string>())
        {
        }

        std::map<std::string, std::string> propertyMap;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::ShowSystemPropertiesResponse>
    {
        static void encode(Encoder& e, const gpudb::ShowSystemPropertiesResponse& v)
        {
            ::avro::encode(e, v.propertyMap);
        }

        static void decode(Decoder& d, gpudb::ShowSystemPropertiesResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.propertyMap);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.propertyMap);
            }
        }
    };
}

#endif
