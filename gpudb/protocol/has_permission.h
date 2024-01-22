/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __HAS_PERMISSION_H__
#define __HAS_PERMISSION_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #hasPermission(const HasPermissionRequest&) const}.
     * <p>
     * Checks if the specified user has the specified permission on the
     * specified object.
     */
    struct HasPermissionRequest
    {

        /**
         * Constructs a HasPermissionRequest object with default parameter
         * values.
         */
        HasPermissionRequest() :
            principal(std::string()),
            object(std::string()),
            objectType(std::string()),
            permission(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a HasPermissionRequest object with the specified
         * parameters.
         * 
         * @param[in] principal_  Name of the user for which the permission is
         *                        being checked. Must be an existing user. If
         *                        blank, will use the current user.
         * @param[in] object_  Name of object to check for the requested
         *                     permission.  It is recommended to use a
         *                     fully-qualified name when possible.
         * @param[in] objectType_  The type of object being checked
         *                         <ul>
         *                                 <li> gpudb::has_permission_context:
         *                         Context
         *                                 <li>
         *                         gpudb::has_permission_credential: Credential
         *                                 <li> gpudb::has_permission_datasink:
         *                         Data Sink
         *                                 <li>
         *                         gpudb::has_permission_datasource: Data
         *                         Source
         *                                 <li>
         *                         gpudb::has_permission_directory: KiFS File
         *                         Directory
         *                                 <li> gpudb::has_permission_graph: A
         *                         Graph object
         *                                 <li> gpudb::has_permission_proc: UDF
         *                         Procedure
         *                                 <li> gpudb::has_permission_schema:
         *                         Schema
         *                                 <li> gpudb::has_permission_sql_proc:
         *                         SQL Procedure
         *                                 <li> gpudb::has_permission_system:
         *                         System-level access
         *                                 <li> gpudb::has_permission_table:
         *                         Database Table
         *                                 <li>
         *                         gpudb::has_permission_table_monitor: Table
         *                         monitor
         *                         </ul>
         * @param[in] permission_  Permission to check for.
         *                         <ul>
         *                                 <li> gpudb::has_permission_admin:
         *                         Full read/write and administrative access on
         *                         the object.
         *                                 <li> gpudb::has_permission_connect:
         *                         Connect access on the given data source or
         *                         data sink.
         *                                 <li> gpudb::has_permission_delete:
         *                         Delete rows from tables.
         *                                 <li> gpudb::has_permission_execute:
         *                         Ability to Execute the Procedure object.
         *                                 <li> gpudb::has_permission_insert:
         *                         Insert access to tables.
         *                                 <li> gpudb::has_permission_read:
         *                         Ability to read, list and use the object.
         *                                 <li> gpudb::has_permission_update:
         *                         Update access to the table.
         *                                 <li>
         *                         gpudb::has_permission_user_admin: Access to
         *                         administer users and roles that do not have
         *                         system_admin permission.
         *                                 <li> gpudb::has_permission_write:
         *                         Access to write, change and delete objects.
         *                         </ul>
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::has_permission_no_error_if_not_exists:
         *                      If @a false will return an error if the
         *                      provided @a object does not exist or is blank.
         *                      If @a true then it will return @a false for @a
         *                      hasPermission.
         *                      <ul>
         *                              <li> gpudb::has_permission_true
         *                              <li> gpudb::has_permission_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::has_permission_false.
         *                      </ul>
         * 
         */
        HasPermissionRequest(const std::string& principal_, const std::string& object_, const std::string& objectType_, const std::string& permission_, const std::map<std::string, std::string>& options_):
            principal( principal_ ),
            object( object_ ),
            objectType( objectType_ ),
            permission( permission_ ),
            options( options_ )
        {
        }

        std::string principal;
        std::string object;
        std::string objectType;
        std::string permission;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::HasPermissionRequest>
    {
        static void encode(Encoder& e, const gpudb::HasPermissionRequest& v)
        {
            ::avro::encode(e, v.principal);
            ::avro::encode(e, v.object);
            ::avro::encode(e, v.objectType);
            ::avro::encode(e, v.permission);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::HasPermissionRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.principal);
                            break;

                        case 1:
                            ::avro::decode(d, v.object);
                            break;

                        case 2:
                            ::avro::decode(d, v.objectType);
                            break;

                        case 3:
                            ::avro::decode(d, v.permission);
                            break;

                        case 4:
                            ::avro::decode(d, v.options);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.principal);
                ::avro::decode(d, v.object);
                ::avro::decode(d, v.objectType);
                ::avro::decode(d, v.permission);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #hasPermission(const HasPermissionRequest&) const}.
     * <p>
     * Checks if the specified user has the specified permission on the
     * specified object.
     */
    struct HasPermissionResponse
    {

        /**
         * Constructs a HasPermissionResponse object with default parameter
         * values.
         */
        HasPermissionResponse() :
            principal(std::string()),
            object(std::string()),
            objectType(std::string()),
            permission(std::string()),
            hasPermission(bool()),
            filters(std::map<std::string, std::string>()),
            info(std::map<std::string, std::string>())
        {
        }

        std::string principal;
        std::string object;
        std::string objectType;
        std::string permission;
        bool hasPermission;
        std::map<std::string, std::string> filters;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::HasPermissionResponse>
    {
        static void encode(Encoder& e, const gpudb::HasPermissionResponse& v)
        {
            ::avro::encode(e, v.principal);
            ::avro::encode(e, v.object);
            ::avro::encode(e, v.objectType);
            ::avro::encode(e, v.permission);
            ::avro::encode(e, v.hasPermission);
            ::avro::encode(e, v.filters);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::HasPermissionResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.principal);
                            break;

                        case 1:
                            ::avro::decode(d, v.object);
                            break;

                        case 2:
                            ::avro::decode(d, v.objectType);
                            break;

                        case 3:
                            ::avro::decode(d, v.permission);
                            break;

                        case 4:
                            ::avro::decode(d, v.hasPermission);
                            break;

                        case 5:
                            ::avro::decode(d, v.filters);
                            break;

                        case 6:
                            ::avro::decode(d, v.info);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.principal);
                ::avro::decode(d, v.object);
                ::avro::decode(d, v.objectType);
                ::avro::decode(d, v.permission);
                ::avro::decode(d, v.hasPermission);
                ::avro::decode(d, v.filters);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
