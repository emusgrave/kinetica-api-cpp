/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __CREATE_DATASOURCE_H__
#define __CREATE_DATASOURCE_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #createDatasource(const CreateDatasourceRequest&) const}.
     * <p>
     * Creates a <a href="../../../concepts/data_sources/" target="_top">data
     * source</a>, which contains the
     * location and connection information for a data store that is external to
     * the database.
     */
    struct CreateDatasourceRequest
    {

        /**
         * Constructs a CreateDatasourceRequest object with default parameter
         * values.
         */
        CreateDatasourceRequest() :
            name(std::string()),
            location(std::string()),
            userName(std::string()),
            password(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a CreateDatasourceRequest object with the specified
         * parameters.
         * 
         * @param[in] name_  Name of the data source to be created.
         * @param[in] location_  Location of the remote storage in
         *                       'storage_provider_type://[storage_path[:storage_port]]'
         *                       format.
         *                       Supported storage provider types are 'hdfs'
         *                       and 's3'.
         * @param[in] userName_  Name of the remote system user; may be an
         *                       empty string
         * @param[in] password_  Password for the remote system user; may be an
         *                       empty string
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::create_datasource_skip_validation:
         *                      Bypass validation of connection to remote
         *                      source.
         *                      <ul>
         *                              <li> gpudb::create_datasource_true
         *                              <li> gpudb::create_datasource_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::create_datasource_false.
         *                              <li>
         *                      gpudb::create_datasource_connection_timeout:
         *                      Timeout in seconds for connecting to this
         *                      storage provider
         *                              <li>
         *                      gpudb::create_datasource_wait_timeout: Timeout
         *                      in seconds for reading from this storage
         *                      provider
         *                              <li>
         *                      gpudb::create_datasource_credential: Name of
         *                      the Credential object to be used in data source
         *                              <li>
         *                      gpudb::create_datasource_s3_bucket_name: Name
         *                      of the Amazon S3 bucket to use as the data
         *                      source
         *                              <li>
         *                      gpudb::create_datasource_s3_region: Name of the
         *                      Amazon S3 region where the given bucket is
         *                      located
         *                              <li>
         *                      gpudb::create_datasource_s3_aws_role_arn:
         *                      Amazon IAM Role ARN which has required S3
         *                      permissions that can be assumed for the given
         *                      S3 IAM user
         *                              <li>
         *                      gpudb::create_datasource_hdfs_kerberos_keytab:
         *                      Kerberos keytab file location for the given
         *                      HDFS user
         *                              <li>
         *                      gpudb::create_datasource_hdfs_delegation_token:
         *                      Delegation token for the given HDFS user
         *                              <li>
         *                      gpudb::create_datasource_hdfs_use_kerberos: Use
         *                      kerberos authentication for the given HDFS
         *                      cluster
         *                      <ul>
         *                              <li> gpudb::create_datasource_true
         *                              <li> gpudb::create_datasource_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::create_datasource_false.
         *                              <li>
         *                      gpudb::create_datasource_azure_storage_account_name:
         *                      Name of the Azure storage account to use as the
         *                      data source, this is valid only if tenant_id is
         *                      specified
         *                              <li>
         *                      gpudb::create_datasource_azure_container_name:
         *                      Name of the Azure storage container to use as
         *                      the data source
         *                              <li>
         *                      gpudb::create_datasource_azure_tenant_id:
         *                      Active Directory tenant ID (or directory ID)
         *                              <li>
         *                      gpudb::create_datasource_azure_sas_token:
         *                      Shared access signature token for Azure storage
         *                      account to use as the data source
         *                              <li>
         *                      gpudb::create_datasource_azure_oauth_token:
         *                      Oauth token to access given storage container
         *                              <li>
         *                      gpudb::create_datasource_is_stream: To load
         *                      from S3/Azure as a stream continuously.
         *                      <ul>
         *                              <li> gpudb::create_datasource_true
         *                              <li> gpudb::create_datasource_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::create_datasource_false.
         *                              <li>
         *                      gpudb::create_datasource_kafka_topic_name: Name
         *                      of the Kafka topic to use as the data source
         *                      </ul>
         * 
         */
        CreateDatasourceRequest(const std::string& name_, const std::string& location_, const std::string& userName_, const std::string& password_, const std::map<std::string, std::string>& options_):
            name( name_ ),
            location( location_ ),
            userName( userName_ ),
            password( password_ ),
            options( options_ )
        {
        }

        std::string name;
        std::string location;
        std::string userName;
        std::string password;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::CreateDatasourceRequest>
    {
        static void encode(Encoder& e, const gpudb::CreateDatasourceRequest& v)
        {
            ::avro::encode(e, v.name);
            ::avro::encode(e, v.location);
            ::avro::encode(e, v.userName);
            ::avro::encode(e, v.password);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::CreateDatasourceRequest& v)
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
                            ::avro::decode(d, v.location);
                            break;

                        case 2:
                            ::avro::decode(d, v.userName);
                            break;

                        case 3:
                            ::avro::decode(d, v.password);
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
                ::avro::decode(d, v.name);
                ::avro::decode(d, v.location);
                ::avro::decode(d, v.userName);
                ::avro::decode(d, v.password);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #createDatasource(const CreateDatasourceRequest&) const}.
     * <p>
     * Creates a <a href="../../../concepts/data_sources/" target="_top">data
     * source</a>, which contains the
     * location and connection information for a data store that is external to
     * the database.
     */
    struct CreateDatasourceResponse
    {

        /**
         * Constructs a CreateDatasourceResponse object with default parameter
         * values.
         */
        CreateDatasourceResponse() :
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
    template<> struct codec_traits<gpudb::CreateDatasourceResponse>
    {
        static void encode(Encoder& e, const gpudb::CreateDatasourceResponse& v)
        {
            ::avro::encode(e, v.name);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::CreateDatasourceResponse& v)
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