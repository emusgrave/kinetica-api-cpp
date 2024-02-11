/*
 *  This file was autogenerated by the Kinetica schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __ALTER_CREDENTIAL_H__
#define __ALTER_CREDENTIAL_H__

namespace gpudb
{
    /**
     * A set of parameters for @ref
     * GPUdb::alterCredential(const AlterCredentialRequest&) const
     * "GPUdb::alterCredential".
     *
     * Alter the properties of an existing <a
     * href="../../../concepts/credentials/" target="_top">credential</a>.
     */
    struct AlterCredentialRequest
    {
        /**
         * Constructs an AlterCredentialRequest object with default parameters.
         */
        AlterCredentialRequest() :
            credentialName(std::string()),
            credentialUpdatesMap(std::map<std::string, std::string>()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an AlterCredentialRequest object with the specified
         * parameters.
         *
         * @param[in] credentialName_  Name of the credential to be altered.
         *                             Must be an existing credential.
         * @param[in] credentialUpdatesMap_  Map containing the properties of
         *                                   the credential to be updated.
         *                                   Error if empty.
         *                                   <ul>
         *                                       <li>@ref
         *                                           gpudb::alter_credential_type
         *                                           "alter_credential_type":
         *                                           New type for the
         *                                           credential.
         *                                           Supported values:
         *                                           <ul>
         *                                               <li>@ref
         *                                                   gpudb::alter_credential_aws_access_key
         *                                                   "alter_credential_aws_access_key"
         *                                               <li>@ref
         *                                                   gpudb::alter_credential_aws_iam_role
         *                                                   "alter_credential_aws_iam_role"
         *                                               <li>@ref
         *                                                   gpudb::alter_credential_azure_ad
         *                                                   "alter_credential_azure_ad"
         *                                               <li>@ref
         *                                                   gpudb::alter_credential_azure_oauth
         *                                                   "alter_credential_azure_oauth"
         *                                               <li>@ref
         *                                                   gpudb::alter_credential_azure_sas
         *                                                   "alter_credential_azure_sas"
         *                                               <li>@ref
         *                                                   gpudb::alter_credential_azure_storage_key
         *                                                   "alter_credential_azure_storage_key"
         *                                               <li>@ref
         *                                                   gpudb::alter_credential_docker
         *                                                   "alter_credential_docker"
         *                                               <li>@ref
         *                                                   gpudb::alter_credential_gcs_service_account_id
         *                                                   "alter_credential_gcs_service_account_id"
         *                                               <li>@ref
         *                                                   gpudb::alter_credential_gcs_service_account_keys
         *                                                   "alter_credential_gcs_service_account_keys"
         *                                               <li>@ref
         *                                                   gpudb::alter_credential_hdfs
         *                                                   "alter_credential_hdfs"
         *                                               <li>@ref
         *                                                   gpudb::alter_credential_kafka
         *                                                   "alter_credential_kafka"
         *                                           </ul>
         *                                       <li>@ref
         *                                           gpudb::alter_credential_identity
         *                                           "alter_credential_identity":
         *                                           New user for the
         *                                           credential
         *                                       <li>@ref
         *                                           gpudb::alter_credential_secret
         *                                           "alter_credential_secret":
         *                                           New password for the
         *                                           credential
         *                                       <li>@ref
         *                                           gpudb::alter_credential_schema_name
         *                                           "alter_credential_schema_name":
         *                                           Updates the schema name.
         *                                           If @ref
         *                                           gpudb::alter_credential_schema_name
         *                                           "schema_name" doesn't
         *                                           exist, an error will be
         *                                           thrown. If @ref
         *                                           gpudb::alter_credential_schema_name
         *                                           "schema_name" is empty,
         *                                           then the user's default
         *                                           schema will be used.
         *                                   </ul>
         * @param[in] options_  Optional parameters.
         */
        AlterCredentialRequest(const std::string& credentialName_, const std::map<std::string, std::string>& credentialUpdatesMap_, const std::map<std::string, std::string>& options_):
            credentialName( credentialName_ ),
            credentialUpdatesMap( credentialUpdatesMap_ ),
            options( options_ )
        {
        }

        /**
         * Name of the credential to be altered. Must be an existing
         * credential.
         */
        std::string credentialName;

        /**
         * Map containing the properties of the credential to be updated. Error
         * if empty.
         * <ul>
         *     <li>@ref gpudb::alter_credential_type "alter_credential_type":
         *         New type for the credential.
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::alter_credential_aws_access_key
         *                 "alter_credential_aws_access_key"
         *             <li>@ref gpudb::alter_credential_aws_iam_role
         *                 "alter_credential_aws_iam_role"
         *             <li>@ref gpudb::alter_credential_azure_ad
         *                 "alter_credential_azure_ad"
         *             <li>@ref gpudb::alter_credential_azure_oauth
         *                 "alter_credential_azure_oauth"
         *             <li>@ref gpudb::alter_credential_azure_sas
         *                 "alter_credential_azure_sas"
         *             <li>@ref gpudb::alter_credential_azure_storage_key
         *                 "alter_credential_azure_storage_key"
         *             <li>@ref gpudb::alter_credential_docker
         *                 "alter_credential_docker"
         *             <li>@ref gpudb::alter_credential_gcs_service_account_id
         *                 "alter_credential_gcs_service_account_id"
         *             <li>@ref
         *                 gpudb::alter_credential_gcs_service_account_keys
         *                 "alter_credential_gcs_service_account_keys"
         *             <li>@ref gpudb::alter_credential_hdfs
         *                 "alter_credential_hdfs"
         *             <li>@ref gpudb::alter_credential_kafka
         *                 "alter_credential_kafka"
         *         </ul>
         *     <li>@ref gpudb::alter_credential_identity
         *         "alter_credential_identity": New user for the credential
         *     <li>@ref gpudb::alter_credential_secret
         *         "alter_credential_secret": New password for the credential
         *     <li>@ref gpudb::alter_credential_schema_name
         *         "alter_credential_schema_name": Updates the schema name.  If
         *         @ref gpudb::alter_credential_schema_name "schema_name"
         *         doesn't exist, an error will be thrown. If @ref
         *         gpudb::alter_credential_schema_name "schema_name" is empty,
         *         then the user's default schema will be used.
         * </ul>
         */
        std::map<std::string, std::string> credentialUpdatesMap;

        /**
         * Optional parameters.
         */
        std::map<std::string, std::string> options;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::AlterCredentialRequest>
    {
        static void encode(Encoder& e, const gpudb::AlterCredentialRequest& v)
        {
            ::avro::encode(e, v.credentialName);
            ::avro::encode(e, v.credentialUpdatesMap);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AlterCredentialRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.credentialName);
                            break;

                        case 1:
                            ::avro::decode(d, v.credentialUpdatesMap);
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
                ::avro::decode(d, v.credentialName);
                ::avro::decode(d, v.credentialUpdatesMap);
                ::avro::decode(d, v.options);
            }
        }
    };
} // end namespace avro

namespace gpudb
{
    /**
     * A set of results returned by @ref
     * GPUdb::alterCredential(const AlterCredentialRequest&) const
     * "GPUdb::alterCredential".
     */
    struct AlterCredentialResponse
    {
        /**
         * Constructs an AlterCredentialResponse object with default
         * parameters.
         */
        AlterCredentialResponse() :
            credentialName(std::string()),
            info(std::map<std::string, std::string>())
        {
        }

        /**
         * Value of @ref gpudb::AlterCredentialRequest::credentialName
         * "credentialName".
         */
        std::string credentialName;

        /**
         * Additional information.
         */
        std::map<std::string, std::string> info;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::AlterCredentialResponse>
    {
        static void encode(Encoder& e, const gpudb::AlterCredentialResponse& v)
        {
            ::avro::encode(e, v.credentialName);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::AlterCredentialResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.credentialName);
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
                ::avro::decode(d, v.credentialName);
                ::avro::decode(d, v.info);
            }
        }
    };
} // end namespace avro

#endif // __ALTER_CREDENTIAL_H__
