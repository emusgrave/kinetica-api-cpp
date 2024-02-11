/*
 *  This file was autogenerated by the Kinetica schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __REVOKE_PERMISSION_DIRECTORY_H__
#define __REVOKE_PERMISSION_DIRECTORY_H__

namespace gpudb
{
    /**
     * A set of parameters for @ref
     * GPUdb::revokePermissionDirectory(const RevokePermissionDirectoryRequest&) const
     * "GPUdb::revokePermissionDirectory".
     *
     * Revokes a <a href="../../../tools/kifs/" target="_top">KiFS</a>
     * directory-level permission from a user or role.
     */
    struct RevokePermissionDirectoryRequest
    {
        /**
         * Constructs a RevokePermissionDirectoryRequest object with default
         * parameters.
         */
        RevokePermissionDirectoryRequest() :
            name(std::string()),
            permission(std::string()),
            directoryName(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a RevokePermissionDirectoryRequest object with the
         * specified parameters.
         *
         * @param[in] name_  Name of the user or role from which the permission
         *                   will be revoked. Must be an existing user or role.
         * @param[in] permission_  Permission to revoke from the user or role.
         *                         Supported values:
         *                         <ul>
         *                             <li>@ref
         *                                 gpudb::revoke_permission_directory_directory_read
         *                                 "revoke_permission_directory_directory_read":
         *                                 For files in the directory, access
         *                                 to list files, download files, or
         *                                 use files in server side functions
         *                             <li>@ref
         *                                 gpudb::revoke_permission_directory_directory_write
         *                                 "revoke_permission_directory_directory_write":
         *                                 Access to upload files to, or delete
         *                                 files from, the directory. A user or
         *                                 role with write access automatically
         *                                 has read acceess
         *                         </ul>
         * @param[in] directoryName_  Name of the KiFS directory to which the
         *                            permission revokes access
         * @param[in] options_  Optional parameters. The default value is an
         *                      empty map.
         */
        RevokePermissionDirectoryRequest(const std::string& name_, const std::string& permission_, const std::string& directoryName_, const std::map<std::string, std::string>& options_):
            name( name_ ),
            permission( permission_ ),
            directoryName( directoryName_ ),
            options( options_ )
        {
        }

        /**
         * Name of the user or role from which the permission will be revoked.
         * Must be an existing user or role.
         */
        std::string name;

        /**
         * Permission to revoke from the user or role.
         * Supported values:
         * <ul>
         *     <li>@ref gpudb::revoke_permission_directory_directory_read
         *         "revoke_permission_directory_directory_read": For files in
         *         the directory, access to list files, download files, or use
         *         files in server side functions
         *     <li>@ref gpudb::revoke_permission_directory_directory_write
         *         "revoke_permission_directory_directory_write": Access to
         *         upload files to, or delete files from, the directory. A user
         *         or role with write access automatically has read acceess
         * </ul>
         */
        std::string permission;

        /**
         * Name of the KiFS directory to which the permission revokes access
         */
        std::string directoryName;

        /**
         * Optional parameters. The default value is an empty map.
         */
        std::map<std::string, std::string> options;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::RevokePermissionDirectoryRequest>
    {
        static void encode(Encoder& e, const gpudb::RevokePermissionDirectoryRequest& v)
        {
            ::avro::encode(e, v.name);
            ::avro::encode(e, v.permission);
            ::avro::encode(e, v.directoryName);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::RevokePermissionDirectoryRequest& v)
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
                            ::avro::decode(d, v.directoryName);
                            break;

                        case 3:
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
                ::avro::decode(d, v.directoryName);
                ::avro::decode(d, v.options);
            }
        }
    };
} // end namespace avro

namespace gpudb
{
    /**
     * A set of results returned by @ref
     * GPUdb::revokePermissionDirectory(const RevokePermissionDirectoryRequest&) const
     * "GPUdb::revokePermissionDirectory".
     */
    struct RevokePermissionDirectoryResponse
    {
        /**
         * Constructs a RevokePermissionDirectoryResponse object with default
         * parameters.
         */
        RevokePermissionDirectoryResponse() :
            name(std::string()),
            permission(std::string()),
            directoryName(std::string()),
            info(std::map<std::string, std::string>())
        {
        }

        /**
         * Value of @ref gpudb::RevokePermissionDirectoryRequest::name "name".
         */
        std::string name;

        /**
         * Value of @ref gpudb::RevokePermissionDirectoryRequest::permission
         * "permission".
         */
        std::string permission;

        /**
         * Value of @ref gpudb::RevokePermissionDirectoryRequest::directoryName
         * "directoryName".
         */
        std::string directoryName;

        /**
         * Additional information.
         */
        std::map<std::string, std::string> info;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::RevokePermissionDirectoryResponse>
    {
        static void encode(Encoder& e, const gpudb::RevokePermissionDirectoryResponse& v)
        {
            ::avro::encode(e, v.name);
            ::avro::encode(e, v.permission);
            ::avro::encode(e, v.directoryName);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::RevokePermissionDirectoryResponse& v)
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
                            ::avro::decode(d, v.directoryName);
                            break;

                        case 3:
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
                ::avro::decode(d, v.directoryName);
                ::avro::decode(d, v.info);
            }
        }
    };
} // end namespace avro

#endif // __REVOKE_PERMISSION_DIRECTORY_H__
