/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __DELETE_USER_H__
#define __DELETE_USER_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #deleteUser(const DeleteUserRequest&) const}.
     * <p>
     * Deletes an existing user.
     */
    struct DeleteUserRequest
    {

        /**
         * Constructs a DeleteUserRequest object with default parameter values.
         */
        DeleteUserRequest() :
            name(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a DeleteUserRequest object with the specified parameters.
         * 
         * @param[in] name  Name of the user to be deleted. Must be an existing
         *                  user.
         * @param[in] options  Optional parameters.
         * 
         */
        DeleteUserRequest(const std::string& name, const std::map<std::string, std::string>& options):
            name(name),
            options(options)
        {
        }

        std::string name;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::DeleteUserRequest>
    {
        static void encode(Encoder& e, const gpudb::DeleteUserRequest& v)
        {
            ::avro::encode(e, v.name);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::DeleteUserRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.name);
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
                ::avro::decode(d, v.name);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #deleteUser(const DeleteUserRequest&) const}.
     * <p>
     * Deletes an existing user.
     */
    struct DeleteUserResponse
    {

        /**
         * Constructs a DeleteUserResponse object with default parameter
         * values.
         */
        DeleteUserResponse() :
            name(std::string())
        {
        }

        std::string name;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::DeleteUserResponse>
    {
        static void encode(Encoder& e, const gpudb::DeleteUserResponse& v)
        {
            ::avro::encode(e, v.name);
        }

        static void decode(Decoder& d, gpudb::DeleteUserResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.name);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.name);
            }
        }
    };
}

#endif