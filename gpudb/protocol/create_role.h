/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __CREATE_ROLE_H__
#define __CREATE_ROLE_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #createRole(const CreateRoleRequest&) const}.
     * <p>
     * Creates a new role.
     */
    struct CreateRoleRequest
    {

        /**
         * Constructs a CreateRoleRequest object with default parameter values.
         */
        CreateRoleRequest() :
            name(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a CreateRoleRequest object with the specified parameters.
         * 
         * @param[in] name_  Name of the role to be created. Must contain only
         *                   lowercase letters, digits, and underscores, and
         *                   cannot begin with a digit. Must not be the same
         *                   name as an existing user or role.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li> gpudb::create_role_resource_group:
         *                      Name of an existing resource group to associate
         *                      with this user
         *                      </ul>
         * 
         */
        CreateRoleRequest(const std::string& name_, const std::map<std::string, std::string>& options_):
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
    template<> struct codec_traits<gpudb::CreateRoleRequest>
    {
        static void encode(Encoder& e, const gpudb::CreateRoleRequest& v)
        {
            ::avro::encode(e, v.name);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::CreateRoleRequest& v)
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
     * #createRole(const CreateRoleRequest&) const}.
     * <p>
     * Creates a new role.
     */
    struct CreateRoleResponse
    {

        /**
         * Constructs a CreateRoleResponse object with default parameter
         * values.
         */
        CreateRoleResponse() :
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
    template<> struct codec_traits<gpudb::CreateRoleResponse>
    {
        static void encode(Encoder& e, const gpudb::CreateRoleResponse& v)
        {
            ::avro::encode(e, v.name);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::CreateRoleResponse& v)
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
