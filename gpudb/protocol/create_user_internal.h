/*
 *  This file was autogenerated by the Kinetica schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __CREATE_USER_INTERNAL_H__
#define __CREATE_USER_INTERNAL_H__

namespace gpudb
{
    /**
     * A set of parameters for @ref
     * GPUdb::createUserInternal(const CreateUserInternalRequest&) const
     * "GPUdb::createUserInternal".
     *
     * Creates a new internal user (a user whose credentials are managed by the
     * database system).
     */
    struct CreateUserInternalRequest
    {
        /**
         * Constructs a CreateUserInternalRequest object with default
         * parameters.
         */
        CreateUserInternalRequest() :
            name(std::string()),
            password(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a CreateUserInternalRequest object with the specified
         * parameters.
         *
         * @param[in] name_  Name of the user to be created. Must contain only
         *                   lowercase letters, digits, and underscores, and
         *                   cannot begin with a digit. Must not be the same
         *                   name as an existing user or role.
         * @param[in] password_  Initial password of the user to be created.
         *                       May be an empty string for no password.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                          <li>@ref
         *                              gpudb::create_user_internal_resource_group
         *                              "create_user_internal_resource_group":
         *                              Name of an existing resource group to
         *                              associate with this user
         *                          <li>@ref
         *                              gpudb::create_user_internal_default_schema
         *                              "create_user_internal_default_schema":
         *                              Default schema to associate with this
         *                              user
         *                          <li>@ref
         *                              gpudb::create_user_internal_create_home_directory
         *                              "create_user_internal_create_home_directory":
         *                              When @ref
         *                              gpudb::create_user_internal_true
         *                              "true", a home directory in KiFS is
         *                              created for this user.
         *                              Supported values:
         *                              <ul>
         *                                  <li>@ref
         *                                      gpudb::create_user_internal_true
         *                                      "create_user_internal_true"
         *                                  <li>@ref
         *                                      gpudb::create_user_internal_false
         *                                      "create_user_internal_false"
         *                              </ul>
         *                              The default value is @ref
         *                              gpudb::create_user_internal_true
         *                              "create_user_internal_true".
         *                          <li>@ref
         *                              gpudb::create_user_internal_directory_data_limit
         *                              "create_user_internal_directory_data_limit":
         *                              The maximum capacity to apply to the
         *                              created directory if @ref
         *                              gpudb::create_user_internal_create_home_directory
         *                              "create_home_directory" is @ref
         *                              gpudb::create_user_internal_true
         *                              "true". Set to -1 to indicate no upper
         *                              limit. If empty, the system default
         *                              limit is applied.
         *                      </ul>
         *                      The default value is an empty map.
         */
        CreateUserInternalRequest(const std::string& name_, const std::string& password_, const std::map<std::string, std::string>& options_):
            name( name_ ),
            password( password_ ),
            options( options_ )
        {
        }

        /**
         * Name of the user to be created. Must contain only lowercase letters,
         * digits, and underscores, and cannot begin with a digit. Must not be
         * the same name as an existing user or role.
         */
        std::string name;

        /**
         * Initial password of the user to be created. May be an empty string
         * for no password.
         */
        std::string password;

        /**
         * Optional parameters.
         * <ul>
         *     <li>@ref gpudb::create_user_internal_resource_group
         *         "create_user_internal_resource_group": Name of an existing
         *         resource group to associate with this user
         *     <li>@ref gpudb::create_user_internal_default_schema
         *         "create_user_internal_default_schema": Default schema to
         *         associate with this user
         *     <li>@ref gpudb::create_user_internal_create_home_directory
         *         "create_user_internal_create_home_directory": When @ref
         *         gpudb::create_user_internal_true "true", a home directory in
         *         KiFS is created for this user.
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::create_user_internal_true
         *                 "create_user_internal_true"
         *             <li>@ref gpudb::create_user_internal_false
         *                 "create_user_internal_false"
         *         </ul>
         *         The default value is @ref gpudb::create_user_internal_true
         *         "create_user_internal_true".
         *     <li>@ref gpudb::create_user_internal_directory_data_limit
         *         "create_user_internal_directory_data_limit": The maximum
         *         capacity to apply to the created directory if @ref
         *         gpudb::create_user_internal_create_home_directory
         *         "create_home_directory" is @ref
         *         gpudb::create_user_internal_true "true". Set to -1 to
         *         indicate no upper limit. If empty, the system default limit
         *         is applied.
         * </ul>
         * The default value is an empty map.
         */
        std::map<std::string, std::string> options;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::CreateUserInternalRequest>
    {
        static void encode(Encoder& e, const gpudb::CreateUserInternalRequest& v)
        {
            ::avro::encode(e, v.name);
            ::avro::encode(e, v.password);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::CreateUserInternalRequest& v)
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
                            ::avro::decode(d, v.password);
                            break;

                        case 2:
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
                ::avro::decode(d, v.password);
                ::avro::decode(d, v.options);
            }
        }
    };
} // end namespace avro

namespace gpudb
{
    /**
     * A set of results returned by @ref
     * GPUdb::createUserInternal(const CreateUserInternalRequest&) const
     * "GPUdb::createUserInternal".
     */
    struct CreateUserInternalResponse
    {
        /**
         * Constructs a CreateUserInternalResponse object with default
         * parameters.
         */
        CreateUserInternalResponse() :
            name(std::string()),
            info(std::map<std::string, std::string>())
        {
        }

        /**
         * Value of @ref gpudb::CreateUserInternalRequest::name "name".
         */
        std::string name;

        /**
         * Additional information. The default value is an empty map.
         */
        std::map<std::string, std::string> info;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::CreateUserInternalResponse>
    {
        static void encode(Encoder& e, const gpudb::CreateUserInternalResponse& v)
        {
            ::avro::encode(e, v.name);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::CreateUserInternalResponse& v)
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
} // end namespace avro

#endif // __CREATE_USER_INTERNAL_H__
