/*
 *  This file was autogenerated by the Kinetica schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __GRANT_PERMISSION_DATASOURCE_H__
#define __GRANT_PERMISSION_DATASOURCE_H__

namespace gpudb
{
    /**
     * A set of parameters for @ref
     * GPUdb::grantPermissionDatasource(const GrantPermissionDatasourceRequest&) const
     * "GPUdb::grantPermissionDatasource".
     *
     * Grants a <a href="../../../concepts/data_sources/" target="_top">data
     * source</a> permission to a user or role.
     */
    struct GrantPermissionDatasourceRequest
    {
        /**
         * Constructs a GrantPermissionDatasourceRequest object with default
         * parameters.
         */
        GrantPermissionDatasourceRequest() :
            name(std::string()),
            permission(std::string()),
            datasourceName(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a GrantPermissionDatasourceRequest object with the
         * specified parameters.
         *
         * @param[in] name_  Name of the user or role to which the permission
         *                   will be granted. Must be an existing user or role.
         * @param[in] permission_  Permission to grant to the user or role.
         *                         Supported values:
         *                         <ul>
         *                             <li>@ref
         *                                 gpudb::grant_permission_datasource_admin
         *                                 "grant_permission_datasource_admin":
         *                                 Admin access on the given data
         *                                 source
         *                             <li>@ref
         *                                 gpudb::grant_permission_datasource_connect
         *                                 "grant_permission_datasource_connect":
         *                                 Connect access on the given data
         *                                 source
         *                         </ul>
         * @param[in] datasourceName_  Name of the data source on which the
         *                             permission will be granted. Must be an
         *                             existing data source, or an empty string
         *                             to grant permission on all data sources.
         * @param[in] options_  Optional parameters. The default value is an
         *                      empty map.
         */
        GrantPermissionDatasourceRequest(const std::string& name_, const std::string& permission_, const std::string& datasourceName_, const std::map<std::string, std::string>& options_):
            name( name_ ),
            permission( permission_ ),
            datasourceName( datasourceName_ ),
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
         *     <li>@ref gpudb::grant_permission_datasource_admin
         *         "grant_permission_datasource_admin": Admin access on the
         *         given data source
         *     <li>@ref gpudb::grant_permission_datasource_connect
         *         "grant_permission_datasource_connect": Connect access on the
         *         given data source
         * </ul>
         */
        std::string permission;

        /**
         * Name of the data source on which the permission will be granted.
         * Must be an existing data source, or an empty string to grant
         * permission on all data sources.
         */
        std::string datasourceName;

        /**
         * Optional parameters. The default value is an empty map.
         */
        std::map<std::string, std::string> options;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::GrantPermissionDatasourceRequest>
    {
        static void encode(Encoder& e, const gpudb::GrantPermissionDatasourceRequest& v)
        {
            ::avro::encode(e, v.name);
            ::avro::encode(e, v.permission);
            ::avro::encode(e, v.datasourceName);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::GrantPermissionDatasourceRequest& v)
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
                            ::avro::decode(d, v.datasourceName);
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
                ::avro::decode(d, v.datasourceName);
                ::avro::decode(d, v.options);
            }
        }
    };
} // end namespace avro

namespace gpudb
{
    /**
     * A set of results returned by @ref
     * GPUdb::grantPermissionDatasource(const GrantPermissionDatasourceRequest&) const
     * "GPUdb::grantPermissionDatasource".
     */
    struct GrantPermissionDatasourceResponse
    {
        /**
         * Constructs a GrantPermissionDatasourceResponse object with default
         * parameters.
         */
        GrantPermissionDatasourceResponse() :
            name(std::string()),
            permission(std::string()),
            datasourceName(std::string()),
            info(std::map<std::string, std::string>())
        {
        }

        /**
         * Value of @ref gpudb::GrantPermissionDatasourceRequest::name "name".
         */
        std::string name;

        /**
         * Value of @ref gpudb::GrantPermissionDatasourceRequest::permission
         * "permission".
         */
        std::string permission;

        /**
         * Value of @ref
         * gpudb::GrantPermissionDatasourceRequest::datasourceName
         * "datasourceName".
         */
        std::string datasourceName;

        /**
         * Additional information.
         */
        std::map<std::string, std::string> info;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::GrantPermissionDatasourceResponse>
    {
        static void encode(Encoder& e, const gpudb::GrantPermissionDatasourceResponse& v)
        {
            ::avro::encode(e, v.name);
            ::avro::encode(e, v.permission);
            ::avro::encode(e, v.datasourceName);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::GrantPermissionDatasourceResponse& v)
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
                            ::avro::decode(d, v.datasourceName);
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
                ::avro::decode(d, v.datasourceName);
                ::avro::decode(d, v.info);
            }
        }
    };
} // end namespace avro

#endif // __GRANT_PERMISSION_DATASOURCE_H__
