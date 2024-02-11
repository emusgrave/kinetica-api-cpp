/*
 *  This file was autogenerated by the Kinetica schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __GRANT_PERMISSION_SYSTEM_H__
#define __GRANT_PERMISSION_SYSTEM_H__

namespace gpudb
{
    /**
     * A set of parameters for @ref
     * GPUdb::grantPermissionSystem(const GrantPermissionSystemRequest&) const
     * "GPUdb::grantPermissionSystem".
     *
     * Grants a system-level permission to a user or role.
     */
    struct GrantPermissionSystemRequest
    {
        /**
         * Constructs a GrantPermissionSystemRequest object with default
         * parameters.
         */
        GrantPermissionSystemRequest() :
            name(std::string()),
            permission(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a GrantPermissionSystemRequest object with the specified
         * parameters.
         *
         * @param[in] name_  Name of the user or role to which the permission
         *                   will be granted. Must be an existing user or role.
         * @param[in] permission_  Permission to grant to the user or role.
         *                         Supported values:
         *                         <ul>
         *                             <li>@ref
         *                                 gpudb::grant_permission_system_system_admin
         *                                 "grant_permission_system_system_admin":
         *                                 Full access to all data and system
         *                                 functions.
         *                             <li>@ref
         *                                 gpudb::grant_permission_system_system_user_admin
         *                                 "grant_permission_system_system_user_admin":
         *                                 Access to administer users and roles
         *                                 that do not have system_admin
         *                                 permission.
         *                             <li>@ref
         *                                 gpudb::grant_permission_system_system_write
         *                                 "grant_permission_system_system_write":
         *                                 Read and write access to all tables.
         *                             <li>@ref
         *                                 gpudb::grant_permission_system_system_read
         *                                 "grant_permission_system_system_read":
         *                                 Read-only access to all tables.
         *                         </ul>
         * @param[in] options_  Optional parameters. The default value is an
         *                      empty map.
         */
        GrantPermissionSystemRequest(const std::string& name_, const std::string& permission_, const std::map<std::string, std::string>& options_):
            name( name_ ),
            permission( permission_ ),
            options( options_ )
        {
        }

        /**
         * Name of the user or role to which the permission will be granted.
         * Must be an existing user or role.
         */
        std::string name;

        /**
         * Permission to grant to the user or role.
         * Supported values:
         * <ul>
         *     <li>@ref gpudb::grant_permission_system_system_admin
         *         "grant_permission_system_system_admin": Full access to all
         *         data and system functions.
         *     <li>@ref gpudb::grant_permission_system_system_user_admin
         *         "grant_permission_system_system_user_admin": Access to
         *         administer users and roles that do not have system_admin
         *         permission.
         *     <li>@ref gpudb::grant_permission_system_system_write
         *         "grant_permission_system_system_write": Read and write
         *         access to all tables.
         *     <li>@ref gpudb::grant_permission_system_system_read
         *         "grant_permission_system_system_read": Read-only access to
         *         all tables.
         * </ul>
         */
        std::string permission;

        /**
         * Optional parameters. The default value is an empty map.
         */
        std::map<std::string, std::string> options;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::GrantPermissionSystemRequest>
    {
        static void encode(Encoder& e, const gpudb::GrantPermissionSystemRequest& v)
        {
            ::avro::encode(e, v.name);
            ::avro::encode(e, v.permission);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::GrantPermissionSystemRequest& v)
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
                            ::avro::decode(d, v.permission);
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
                ::avro::decode(d, v.permission);
                ::avro::decode(d, v.options);
            }
        }
    };
} // end namespace avro

namespace gpudb
{
    /**
     * A set of results returned by @ref
     * GPUdb::grantPermissionSystem(const GrantPermissionSystemRequest&) const
     * "GPUdb::grantPermissionSystem".
     */
    struct GrantPermissionSystemResponse
    {
        /**
         * Constructs a GrantPermissionSystemResponse object with default
         * parameters.
         */
        GrantPermissionSystemResponse() :
            name(std::string()),
            permission(std::string()),
            info(std::map<std::string, std::string>())
        {
        }

        /**
         * Value of @ref gpudb::GrantPermissionSystemRequest::name "name".
         */
        std::string name;

        /**
         * Value of @ref gpudb::GrantPermissionSystemRequest::permission
         * "permission".
         */
        std::string permission;

        /**
         * Additional information.
         */
        std::map<std::string, std::string> info;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::GrantPermissionSystemResponse>
    {
        static void encode(Encoder& e, const gpudb::GrantPermissionSystemResponse& v)
        {
            ::avro::encode(e, v.name);
            ::avro::encode(e, v.permission);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::GrantPermissionSystemResponse& v)
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
                            ::avro::decode(d, v.permission);
                            break;

                        case 2:
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
                ::avro::decode(d, v.permission);
                ::avro::decode(d, v.info);
            }
        }
    };
} // end namespace avro

#endif // __GRANT_PERMISSION_SYSTEM_H__
