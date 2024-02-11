/*
 *  This file was autogenerated by the Kinetica schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __CREATE_JOB_H__
#define __CREATE_JOB_H__

namespace gpudb
{
    /**
     * A set of parameters for @ref
     * GPUdb::createJob(const CreateJobRequest&) const "GPUdb::createJob".
     *
     * Create a job which will run asynchronously. The response returns a job
     * ID, which can be used to query the status and result of the job. The
     * status and the result of the job upon completion can be requested by
     * @ref GPUdb::getJob(const GetJobRequest&) const "GPUdb::getJob".
     */
    struct CreateJobRequest
    {
        /**
         * Constructs a CreateJobRequest object with default parameters.
         */
        CreateJobRequest() :
            endpoint(std::string()),
            requestEncoding(std::string()),
            data(std::vector<uint8_t>()),
            dataStr(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a CreateJobRequest object with the specified parameters.
         *
         * @param[in] endpoint_  Indicates which endpoint to execute, e.g.
         *                       '/alter/table'.
         * @param[in] requestEncoding_  The encoding of the request payload for
         *                              the job.
         *                              Supported values:
         *                              <ul>
         *                                  <li>@ref gpudb::create_job_binary
         *                                      "create_job_binary"
         *                                  <li>@ref gpudb::create_job_json
         *                                      "create_job_json"
         *                                  <li>@ref gpudb::create_job_snappy
         *                                      "create_job_snappy"
         *                              </ul>
         *                              The default value is @ref
         *                              gpudb::create_job_binary
         *                              "create_job_binary".
         * @param[in] data_  Binary-encoded payload for the job to be run
         *                   asynchronously.  The payload must contain the
         *                   relevant input parameters for the endpoint
         *                   indicated in @a endpoint_.  Please see the
         *                   documentation for the appropriate endpoint to see
         *                   what values must (or can) be specified.  If this
         *                   parameter is used, then @a requestEncoding_ must
         *                   be @ref gpudb::create_job_binary "binary" or @ref
         *                   gpudb::create_job_snappy "snappy".
         * @param[in] dataStr_  JSON-encoded payload for the job to be run
         *                      asynchronously.  The payload must contain the
         *                      relevant input parameters for the endpoint
         *                      indicated in @a endpoint_.  Please see the
         *                      documentation for the appropriate endpoint to
         *                      see what values must (or can) be specified.  If
         *                      this parameter is used, then @a
         *                      requestEncoding_ must be @ref
         *                      gpudb::create_job_json "json".
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                          <li>@ref
         *                              gpudb::create_job_remove_job_on_complete
         *                              "create_job_remove_job_on_complete":
         *                              Supported values:
         *                              <ul>
         *                                  <li>@ref gpudb::create_job_true
         *                                      "create_job_true"
         *                                  <li>@ref gpudb::create_job_false
         *                                      "create_job_false"
         *                              </ul>
         *                          <li>@ref gpudb::create_job_job_tag
         *                              "create_job_job_tag": Tag to use for
         *                              submitted job. The same tag could be
         *                              used on backup cluster to retrieve
         *                              response for the job. Tags can use
         *                              letter, numbers, '_' and '-'
         *                      </ul>
         *                      The default value is an empty map.
         */
        CreateJobRequest(const std::string& endpoint_, const std::string& requestEncoding_, const std::vector<uint8_t>& data_, const std::string& dataStr_, const std::map<std::string, std::string>& options_):
            endpoint( endpoint_ ),
            requestEncoding( requestEncoding_ ),
            data( data_ ),
            dataStr( dataStr_ ),
            options( options_ )
        {
        }

        /**
         * Indicates which endpoint to execute, e.g.\ '/alter/table'.
         */
        std::string endpoint;

        /**
         * The encoding of the request payload for the job.
         * Supported values:
         * <ul>
         *     <li>@ref gpudb::create_job_binary "create_job_binary"
         *     <li>@ref gpudb::create_job_json "create_job_json"
         *     <li>@ref gpudb::create_job_snappy "create_job_snappy"
         * </ul>
         * The default value is @ref gpudb::create_job_binary
         * "create_job_binary".
         */
        std::string requestEncoding;

        /**
         * Binary-encoded payload for the job to be run asynchronously.  The
         * payload must contain the relevant input parameters for the endpoint
         * indicated in @ref endpoint.  Please see the documentation for the
         * appropriate endpoint to see what values must (or can) be specified.
         * If this parameter is used, then @ref requestEncoding must be @ref
         * gpudb::create_job_binary "binary" or @ref gpudb::create_job_snappy
         * "snappy".
         */
        std::vector<uint8_t> data;

        /**
         * JSON-encoded payload for the job to be run asynchronously.  The
         * payload must contain the relevant input parameters for the endpoint
         * indicated in @ref endpoint.  Please see the documentation for the
         * appropriate endpoint to see what values must (or can) be specified.
         * If this parameter is used, then @ref requestEncoding must be @ref
         * gpudb::create_job_json "json".
         */
        std::string dataStr;

        /**
         * Optional parameters.
         * <ul>
         *     <li>@ref gpudb::create_job_remove_job_on_complete
         *         "create_job_remove_job_on_complete":
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::create_job_true "create_job_true"
         *             <li>@ref gpudb::create_job_false "create_job_false"
         *         </ul>
         *     <li>@ref gpudb::create_job_job_tag "create_job_job_tag": Tag to
         *         use for submitted job. The same tag could be used on backup
         *         cluster to retrieve response for the job. Tags can use
         *         letter, numbers, '_' and '-'
         * </ul>
         * The default value is an empty map.
         */
        std::map<std::string, std::string> options;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::CreateJobRequest>
    {
        static void encode(Encoder& e, const gpudb::CreateJobRequest& v)
        {
            ::avro::encode(e, v.endpoint);
            ::avro::encode(e, v.requestEncoding);
            ::avro::encode(e, v.data);
            ::avro::encode(e, v.dataStr);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::CreateJobRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.endpoint);
                            break;

                        case 1:
                            ::avro::decode(d, v.requestEncoding);
                            break;

                        case 2:
                            ::avro::decode(d, v.data);
                            break;

                        case 3:
                            ::avro::decode(d, v.dataStr);
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
                ::avro::decode(d, v.endpoint);
                ::avro::decode(d, v.requestEncoding);
                ::avro::decode(d, v.data);
                ::avro::decode(d, v.dataStr);
                ::avro::decode(d, v.options);
            }
        }
    };
} // end namespace avro

namespace gpudb
{
    /**
     * A set of results returned by @ref
     * GPUdb::createJob(const CreateJobRequest&) const "GPUdb::createJob".
     */
    struct CreateJobResponse
    {
        /**
         * Constructs a CreateJobResponse object with default parameters.
         */
        CreateJobResponse() :
            jobId(int64_t()),
            info(std::map<std::string, std::string>())
        {
        }

        /**
         * An identifier for the job created by this call.
         */
        int64_t jobId;

        /**
         * Additional information.
         * <ul>
         *     <li>@ref gpudb::create_job_job_tag "create_job_job_tag": The job
         *         tag specified by the user or if unspecified by user, a
         *         unique identifier generated internally for the job across
         *         clusters.
         * </ul>
         * The default value is an empty map.
         */
        std::map<std::string, std::string> info;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::CreateJobResponse>
    {
        static void encode(Encoder& e, const gpudb::CreateJobResponse& v)
        {
            ::avro::encode(e, v.jobId);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::CreateJobResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.jobId);
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
                ::avro::decode(d, v.jobId);
                ::avro::decode(d, v.info);
            }
        }
    };
} // end namespace avro

#endif // __CREATE_JOB_H__
