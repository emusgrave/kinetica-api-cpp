/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __DELETE_ROLE_H__
#define __DELETE_ROLE_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #deleteRole(const DeleteRoleRequest&) const}.
     * <p>
     * Deletes an existing role.
     */
    struct DeleteRoleRequest
    {

        /**
         * Constructs a DeleteRoleRequest object with default parameter values.
         */
        DeleteRoleRequest() :
            name(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a DeleteRoleRequest object with the specified parameters.
         * 
         * @param[in] name_  Name of the role to be deleted. Must be an
         *                   existing role.
         * @param[in] options_  Optional parameters.
         * 
         */
        DeleteRoleRequest(const std::string& name_, const std::map<std::string, std::string>& options_):
            name( name_ ),
            options( options_ )
        {
        }

        std::string name;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::DeleteRoleRequest>
    {
        static void encode(Encoder& e, const gpudb::DeleteRoleRequest& v)
        {
            ::avro::encode(e, v.name);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::DeleteRoleRequest& v)
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
     * #deleteRole(const DeleteRoleRequest&) const}.
     * <p>
     * Deletes an existing role.
     */
    struct DeleteRoleResponse
    {

        /**
         * Constructs a DeleteRoleResponse object with default parameter
         * values.
         */
        DeleteRoleResponse() :
            name(std::string()),
            info(std::map<std::string, std::string>())
        {
        }

        std::string name;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::DeleteRoleResponse>
    {
        static void encode(Encoder& e, const gpudb::DeleteRoleResponse& v)
        {
            ::avro::encode(e, v.name);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::DeleteRoleResponse& v)
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
                            ::avro::decode(d, v.info);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.name);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
