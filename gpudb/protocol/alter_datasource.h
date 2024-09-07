/*
 *  This file was autogenerated by the Kinetica schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __ALTER_DATASOURCE_H__
#define __ALTER_DATASOURCE_H__

namespace gpudb
{
    /**
     * A set of parameters for @ref
     * GPUdb::alterDatasource(const AlterDatasourceRequest&) const
     * "GPUdb::alterDatasource".
     *
     * Alters the properties of an existing <a
     * href="../../../concepts/data_sources/" target="_top">data source</a>
     */
    struct AlterDatasourceRequest
    {
        /**
         * Constructs an AlterDatasourceRequest object with default parameters.
         */
        AlterDatasourceRequest() :
            name(std::string()),
            datasourceUpdatesMap(std::map<std::string, std::string>()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an AlterDatasourceRequest object with the specified
         * parameters.
         *
         * @param[in] name_  Name of the data source to be altered. Must be an
         *                   existing data source.
         * @param[in] datasourceUpdatesMap_  Map containing the properties of
         *                                   the data source to be updated.
         *                                   Error if empty.
         *                                   <ul>
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_location
         *                                           "alter_datasource_location":
         *                                           Location of the remote
         *                                           storage in
         *                                           'storage_provider_type://[storage_path[:storage_port]]'
         *                                           format.  Supported storage
         *                                           provider types are
         *                                           'azure','gcs','hdfs','kafka'
         *                                           and 's3'.
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_user_name
         *                                           "alter_datasource_user_name":
         *                                           Name of the remote system
         *                                           user; may be an empty
         *                                           string
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_password
         *                                           "alter_datasource_password":
         *                                           Password for the remote
         *                                           system user; may be an
         *                                           empty string
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_skip_validation
         *                                           "alter_datasource_skip_validation":
         *                                           Bypass validation of
         *                                           connection to remote
         *                                           source.
         *                                           Supported values:
         *                                           <ul>
         *                                               <li>@ref
         *                                                   gpudb::alter_datasource_true
         *                                                   "alter_datasource_true"
         *                                               <li>@ref
         *                                                   gpudb::alter_datasource_false
         *                                                   "alter_datasource_false"
         *                                           </ul>
         *                                           The default value is @ref
         *                                           gpudb::alter_datasource_false
         *                                           "alter_datasource_false".
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_connection_timeout
         *                                           "alter_datasource_connection_timeout":
         *                                           Timeout in seconds for
         *                                           connecting to this storage
         *                                           provider
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_wait_timeout
         *                                           "alter_datasource_wait_timeout":
         *                                           Timeout in seconds for
         *                                           reading from this storage
         *                                           provider
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_credential
         *                                           "alter_datasource_credential":
         *                                           Name of the <a
         *                                           href="../../../concepts/credentials"
         *                                           target="_top">credential</a>
         *                                           object to be used in data
         *                                           source
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_s3_bucket_name
         *                                           "alter_datasource_s3_bucket_name":
         *                                           Name of the Amazon S3
         *                                           bucket to use as the data
         *                                           source
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_s3_region
         *                                           "alter_datasource_s3_region":
         *                                           Name of the Amazon S3
         *                                           region where the given
         *                                           bucket is located
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_s3_aws_role_arn
         *                                           "alter_datasource_s3_aws_role_arn":
         *                                           Amazon IAM Role ARN which
         *                                           has required S3
         *                                           permissions that can be
         *                                           assumed for the given S3
         *                                           IAM user
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_s3_encryption_customer_algorithm
         *                                           "alter_datasource_s3_encryption_customer_algorithm":
         *                                           Customer encryption
         *                                           algorithm used encrypting
         *                                           data
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_s3_encryption_customer_key
         *                                           "alter_datasource_s3_encryption_customer_key":
         *                                           Customer encryption key to
         *                                           encrypt or decrypt data
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_hdfs_kerberos_keytab
         *                                           "alter_datasource_hdfs_kerberos_keytab":
         *                                           Kerberos keytab file
         *                                           location for the given
         *                                           HDFS user.  This may be a
         *                                           KIFS file.
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_hdfs_delegation_token
         *                                           "alter_datasource_hdfs_delegation_token":
         *                                           Delegation token for the
         *                                           given HDFS user
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_hdfs_use_kerberos
         *                                           "alter_datasource_hdfs_use_kerberos":
         *                                           Use kerberos
         *                                           authentication for the
         *                                           given HDFS cluster.
         *                                           Supported values:
         *                                           <ul>
         *                                               <li>@ref
         *                                                   gpudb::alter_datasource_true
         *                                                   "alter_datasource_true"
         *                                               <li>@ref
         *                                                   gpudb::alter_datasource_false
         *                                                   "alter_datasource_false"
         *                                           </ul>
         *                                           The default value is @ref
         *                                           gpudb::alter_datasource_false
         *                                           "alter_datasource_false".
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_azure_storage_account_name
         *                                           "alter_datasource_azure_storage_account_name":
         *                                           Name of the Azure storage
         *                                           account to use as the data
         *                                           source, this is valid only
         *                                           if tenant_id is specified
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_azure_container_name
         *                                           "alter_datasource_azure_container_name":
         *                                           Name of the Azure storage
         *                                           container to use as the
         *                                           data source
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_azure_tenant_id
         *                                           "alter_datasource_azure_tenant_id":
         *                                           Active Directory tenant ID
         *                                           (or directory ID)
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_azure_sas_token
         *                                           "alter_datasource_azure_sas_token":
         *                                           Shared access signature
         *                                           token for Azure storage
         *                                           account to use as the data
         *                                           source
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_azure_oauth_token
         *                                           "alter_datasource_azure_oauth_token":
         *                                           OAuth token to access
         *                                           given storage container
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_gcs_bucket_name
         *                                           "alter_datasource_gcs_bucket_name":
         *                                           Name of the Google Cloud
         *                                           Storage bucket to use as
         *                                           the data source
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_gcs_project_id
         *                                           "alter_datasource_gcs_project_id":
         *                                           Name of the Google Cloud
         *                                           project to use as the data
         *                                           source
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_gcs_service_account_keys
         *                                           "alter_datasource_gcs_service_account_keys":
         *                                           Google Cloud service
         *                                           account keys to use for
         *                                           authenticating the data
         *                                           source
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_kafka_url
         *                                           "alter_datasource_kafka_url":
         *                                           The publicly-accessible
         *                                           full path URL to the Kafka
         *                                           broker, e.g.,
         *                                           'http://172.123.45.67:9300'.
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_kafka_topic_name
         *                                           "alter_datasource_kafka_topic_name":
         *                                           Name of the Kafka topic to
         *                                           use as the data source
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_jdbc_driver_jar_path
         *                                           "alter_datasource_jdbc_driver_jar_path":
         *                                           JDBC driver jar file
         *                                           location.  This may be a
         *                                           KIFS file.
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_jdbc_driver_class_name
         *                                           "alter_datasource_jdbc_driver_class_name":
         *                                           Name of the JDBC driver
         *                                           class
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_anonymous
         *                                           "alter_datasource_anonymous":
         *                                           Create an anonymous
         *                                           connection to the storage
         *                                           provider--DEPRECATED: this
         *                                           is now the default.
         *                                           Specify
         *                                           use_managed_credentials
         *                                           for non-anonymous
         *                                           connection.
         *                                           Supported values:
         *                                           <ul>
         *                                               <li>@ref
         *                                                   gpudb::alter_datasource_true
         *                                                   "alter_datasource_true"
         *                                               <li>@ref
         *                                                   gpudb::alter_datasource_false
         *                                                   "alter_datasource_false"
         *                                           </ul>
         *                                           The default value is @ref
         *                                           gpudb::alter_datasource_true
         *                                           "alter_datasource_true".
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_use_managed_credentials
         *                                           "alter_datasource_use_managed_credentials":
         *                                           When no credentials are
         *                                           supplied, we use anonymous
         *                                           access by default.  If
         *                                           this is set, we will use
         *                                           cloud provider user
         *                                           settings.
         *                                           Supported values:
         *                                           <ul>
         *                                               <li>@ref
         *                                                   gpudb::alter_datasource_true
         *                                                   "alter_datasource_true"
         *                                               <li>@ref
         *                                                   gpudb::alter_datasource_false
         *                                                   "alter_datasource_false"
         *                                           </ul>
         *                                           The default value is @ref
         *                                           gpudb::alter_datasource_false
         *                                           "alter_datasource_false".
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_use_https
         *                                           "alter_datasource_use_https":
         *                                           Use https to connect to
         *                                           datasource if true,
         *                                           otherwise use http.
         *                                           Supported values:
         *                                           <ul>
         *                                               <li>@ref
         *                                                   gpudb::alter_datasource_true
         *                                                   "alter_datasource_true"
         *                                               <li>@ref
         *                                                   gpudb::alter_datasource_false
         *                                                   "alter_datasource_false"
         *                                           </ul>
         *                                           The default value is @ref
         *                                           gpudb::alter_datasource_true
         *                                           "alter_datasource_true".
         *                                       <li>@ref
         *                                           gpudb::alter_datasource_schema_name
         *                                           "alter_datasource_schema_name":
         *                                           Updates the schema name.
         *                                           If @ref
         *                                           gpudb::alter_datasource_schema_name
         *                                           "schema_name" doesn't
         *                                           exist, an error will be
         *                                           thrown. If @ref
         *                                           gpudb::alter_datasource_schema_name
         *                                           "schema_name" is empty,
         *                                           then the user's default
         *                                           schema will be used.
         *                                   </ul>
         * @param[in] options_  Optional parameters.
         */
        AlterDatasourceRequest(const std::string& name_, const std::map<std::string, std::string>& datasourceUpdatesMap_, const std::map<std::string, std::string>& options_):
            name( name_ ),
            datasourceUpdatesMap( datasourceUpdatesMap_ ),
            options( options_ )
        {
        }

        /**
         * Name of the data source to be altered. Must be an existing data
         * source.
         */
        std::string name;

        /**
         * Map containing the properties of the data source to be updated.
         * Error if empty.
         * <ul>
         *     <li>@ref gpudb::alter_datasource_location
         *         "alter_datasource_location": Location of the remote storage
         *         in 'storage_provider_type://[storage_path[:storage_port]]'
         *         format.  Supported storage provider types are
         *         'azure','gcs','hdfs','kafka' and 's3'.
         *     <li>@ref gpudb::alter_datasource_user_name
         *         "alter_datasource_user_name": Name of the remote system
         *         user; may be an empty string
         *     <li>@ref gpudb::alter_datasource_password
         *         "alter_datasource_password": Password for the remote system
         *         user; may be an empty string
         *     <li>@ref gpudb::alter_datasource_skip_validation
         *         "alter_datasource_skip_validation": Bypass validation of
         *         connection to remote source.
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::alter_datasource_true
         *                 "alter_datasource_true"
         *             <li>@ref gpudb::alter_datasource_false
         *                 "alter_datasource_false"
         *         </ul>
         *         The default value is @ref gpudb::alter_datasource_false
         *         "alter_datasource_false".
         *     <li>@ref gpudb::alter_datasource_connection_timeout
         *         "alter_datasource_connection_timeout": Timeout in seconds
         *         for connecting to this storage provider
         *     <li>@ref gpudb::alter_datasource_wait_timeout
         *         "alter_datasource_wait_timeout": Timeout in seconds for
         *         reading from this storage provider
         *     <li>@ref gpudb::alter_datasource_credential
         *         "alter_datasource_credential": Name of the <a
         *         href="../../../concepts/credentials"
         *         target="_top">credential</a> object to be used in data
         *         source
         *     <li>@ref gpudb::alter_datasource_s3_bucket_name
         *         "alter_datasource_s3_bucket_name": Name of the Amazon S3
         *         bucket to use as the data source
         *     <li>@ref gpudb::alter_datasource_s3_region
         *         "alter_datasource_s3_region": Name of the Amazon S3 region
         *         where the given bucket is located
         *     <li>@ref gpudb::alter_datasource_s3_aws_role_arn
         *         "alter_datasource_s3_aws_role_arn": Amazon IAM Role ARN
         *         which has required S3 permissions that can be assumed for
         *         the given S3 IAM user
         *     <li>@ref
         *         gpudb::alter_datasource_s3_encryption_customer_algorithm
         *         "alter_datasource_s3_encryption_customer_algorithm":
         *         Customer encryption algorithm used encrypting data
         *     <li>@ref gpudb::alter_datasource_s3_encryption_customer_key
         *         "alter_datasource_s3_encryption_customer_key": Customer
         *         encryption key to encrypt or decrypt data
         *     <li>@ref gpudb::alter_datasource_hdfs_kerberos_keytab
         *         "alter_datasource_hdfs_kerberos_keytab": Kerberos keytab
         *         file location for the given HDFS user.  This may be a KIFS
         *         file.
         *     <li>@ref gpudb::alter_datasource_hdfs_delegation_token
         *         "alter_datasource_hdfs_delegation_token": Delegation token
         *         for the given HDFS user
         *     <li>@ref gpudb::alter_datasource_hdfs_use_kerberos
         *         "alter_datasource_hdfs_use_kerberos": Use kerberos
         *         authentication for the given HDFS cluster.
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::alter_datasource_true
         *                 "alter_datasource_true"
         *             <li>@ref gpudb::alter_datasource_false
         *                 "alter_datasource_false"
         *         </ul>
         *         The default value is @ref gpudb::alter_datasource_false
         *         "alter_datasource_false".
         *     <li>@ref gpudb::alter_datasource_azure_storage_account_name
         *         "alter_datasource_azure_storage_account_name": Name of the
         *         Azure storage account to use as the data source, this is
         *         valid only if tenant_id is specified
         *     <li>@ref gpudb::alter_datasource_azure_container_name
         *         "alter_datasource_azure_container_name": Name of the Azure
         *         storage container to use as the data source
         *     <li>@ref gpudb::alter_datasource_azure_tenant_id
         *         "alter_datasource_azure_tenant_id": Active Directory tenant
         *         ID (or directory ID)
         *     <li>@ref gpudb::alter_datasource_azure_sas_token
         *         "alter_datasource_azure_sas_token": Shared access signature
         *         token for Azure storage account to use as the data source
         *     <li>@ref gpudb::alter_datasource_azure_oauth_token
         *         "alter_datasource_azure_oauth_token": OAuth token to access
         *         given storage container
         *     <li>@ref gpudb::alter_datasource_gcs_bucket_name
         *         "alter_datasource_gcs_bucket_name": Name of the Google Cloud
         *         Storage bucket to use as the data source
         *     <li>@ref gpudb::alter_datasource_gcs_project_id
         *         "alter_datasource_gcs_project_id": Name of the Google Cloud
         *         project to use as the data source
         *     <li>@ref gpudb::alter_datasource_gcs_service_account_keys
         *         "alter_datasource_gcs_service_account_keys": Google Cloud
         *         service account keys to use for authenticating the data
         *         source
         *     <li>@ref gpudb::alter_datasource_kafka_url
         *         "alter_datasource_kafka_url": The publicly-accessible full
         *         path URL to the Kafka broker, e.g.,
         *         'http://172.123.45.67:9300'.
         *     <li>@ref gpudb::alter_datasource_kafka_topic_name
         *         "alter_datasource_kafka_topic_name": Name of the Kafka topic
         *         to use as the data source
         *     <li>@ref gpudb::alter_datasource_jdbc_driver_jar_path
         *         "alter_datasource_jdbc_driver_jar_path": JDBC driver jar
         *         file location.  This may be a KIFS file.
         *     <li>@ref gpudb::alter_datasource_jdbc_driver_class_name
         *         "alter_datasource_jdbc_driver_class_name": Name of the JDBC
         *         driver class
         *     <li>@ref gpudb::alter_datasource_anonymous
         *         "alter_datasource_anonymous": Create an anonymous connection
         *         to the storage provider--DEPRECATED: this is now the
         *         default.  Specify use_managed_credentials for non-anonymous
         *         connection.
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::alter_datasource_true
         *                 "alter_datasource_true"
         *             <li>@ref gpudb::alter_datasource_false
         *                 "alter_datasource_false"
         *         </ul>
         *         The default value is @ref gpudb::alter_datasource_true
         *         "alter_datasource_true".
         *     <li>@ref gpudb::alter_datasource_use_managed_credentials
         *         "alter_datasource_use_managed_credentials": When no
         *         credentials are supplied, we use anonymous access by
         *         default.  If this is set, we will use cloud provider user
         *         settings.
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::alter_datasource_true
         *                 "alter_datasource_true"
         *             <li>@ref gpudb::alter_datasource_false
         *                 "alter_datasource_false"
         *         </ul>
         *         The default value is @ref gpudb::alter_datasource_false
         *         "alter_datasource_false".
         *     <li>@ref gpudb::alter_datasource_use_https
         *         "alter_datasource_use_https": Use https to connect to
         *         datasource if true, otherwise use http.
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::alter_datasource_true
         *                 "alter_datasource_true"
         *             <li>@ref gpudb::alter_datasource_false
         *                 "alter_datasource_false"
         *         </ul>
         *         The default value is @ref gpudb::alter_datasource_true
         *         "alter_datasource_true".
         *     <li>@ref gpudb::alter_datasource_schema_name
         *         "alter_datasource_schema_name": Updates the schema name.  If
         *         @ref gpudb::alter_datasource_schema_name "schema_name"
         *         doesn't exist, an error will be thrown. If @ref
         *         gpudb::alter_datasource_schema_name "schema_name" is empty,
         *         then the user's default schema will be used.
         * </ul>
         */
        std::map<std::string, std::string> datasourceUpdatesMap;

        /**
         * Optional parameters.
         */
        std::map<std::string, std::string> options;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::AlterDatasourceRequest>
    {
        static void encode(Encoder& e, const gpudb::AlterDatasourceRequest& v)
        {
            ::avro::encode(e, v.name);
            ::avro::encode(e, v.datasourceUpdatesMap);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AlterDatasourceRequest& v)
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
                            ::avro::decode(d, v.datasourceUpdatesMap);
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
                ::avro::decode(d, v.datasourceUpdatesMap);
                ::avro::decode(d, v.options);
            }
        }
    };
} // end namespace avro

namespace gpudb
{
    /**
     * A set of results returned by @ref
     * GPUdb::alterDatasource(const AlterDatasourceRequest&) const
     * "GPUdb::alterDatasource".
     */
    struct AlterDatasourceResponse
    {
        /**
         * Constructs an AlterDatasourceResponse object with default
         * parameters.
         */
        AlterDatasourceResponse() :
            updatedPropertiesMap(std::map<std::string, std::string>()),
            info(std::map<std::string, std::string>())
        {
        }

        /**
         * Map of values updated
         */
        std::map<std::string, std::string> updatedPropertiesMap;

        /**
         * Additional information.
         */
        std::map<std::string, std::string> info;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::AlterDatasourceResponse>
    {
        static void encode(Encoder& e, const gpudb::AlterDatasourceResponse& v)
        {
            ::avro::encode(e, v.updatedPropertiesMap);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::AlterDatasourceResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.updatedPropertiesMap);
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
                ::avro::decode(d, v.updatedPropertiesMap);
                ::avro::decode(d, v.info);
            }
        }
    };
} // end namespace avro

#endif // __ALTER_DATASOURCE_H__
