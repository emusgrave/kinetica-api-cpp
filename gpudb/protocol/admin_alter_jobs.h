/*
 *  This file was autogenerated by the Kinetica schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __ADMIN_ALTER_JOBS_H__
#define __ADMIN_ALTER_JOBS_H__

namespace gpudb
{
    /**
     * A set of parameters for @ref
     * GPUdb::adminAlterJobs(const AdminAlterJobsRequest&) const
     * "GPUdb::adminAlterJobs".
     *
     * Perform the requested action on a list of one or more job(s). Based on
     * the type of job and the current state of execution, the action may not
     * be successfully executed. The final result of the attempted actions for
     * each specified job is returned in the status array of the response. See
     * <a href="../../../admin/job_manager/" target="_top">Job Manager</a> for
     * more information.
     */
    struct AdminAlterJobsRequest
    {
        /**
         * Constructs an AdminAlterJobsRequest object with default parameters.
         */
        AdminAlterJobsRequest() :
            jobIds(std::vector<int64_t>()),
            action(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an AdminAlterJobsRequest object with the specified
         * parameters.
         *
         * @param[in] jobIds_  Jobs to be modified.
         * @param[in] action_  Action to be performed on the jobs specified by
         *                     job_ids.
         *                     Supported values:
         *                     <ul>
         *                         <li>@ref gpudb::admin_alter_jobs_cancel
         *                             "admin_alter_jobs_cancel"
         *                     </ul>
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                          <li>@ref gpudb::admin_alter_jobs_job_tag
         *                              "admin_alter_jobs_job_tag": Job tag
         *                              returned in call to create the job
         *                      </ul>
         *                      The default value is an empty map.
         */
        AdminAlterJobsRequest(const std::vector<int64_t>& jobIds_, const std::string& action_, const std::map<std::string, std::string>& options_):
            jobIds( jobIds_ ),
            action( action_ ),
            options( options_ )
        {
        }

        /**
         * Jobs to be modified.
         */
        std::vector<int64_t> jobIds;

        /**
         * Action to be performed on the jobs specified by job_ids.
         * Supported values:
         * <ul>
         *     <li>@ref gpudb::admin_alter_jobs_cancel
         *         "admin_alter_jobs_cancel"
         * </ul>
         */
        std::string action;

        /**
         * Optional parameters.
         * <ul>
         *     <li>@ref gpudb::admin_alter_jobs_job_tag
         *         "admin_alter_jobs_job_tag": Job tag returned in call to
         *         create the job
         * </ul>
         * The default value is an empty map.
         */
        std::map<std::string, std::string> options;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::AdminAlterJobsRequest>
    {
        static void encode(Encoder& e, const gpudb::AdminAlterJobsRequest& v)
        {
            ::avro::encode(e, v.jobIds);
            ::avro::encode(e, v.action);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AdminAlterJobsRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.jobIds);
                            break;

                        case 1:
                            ::avro::decode(d, v.action);
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
                ::avro::decode(d, v.jobIds);
                ::avro::decode(d, v.action);
                ::avro::decode(d, v.options);
            }
        }
    };
} // end namespace avro

namespace gpudb
{
    /**
     * A set of results returned by @ref
     * GPUdb::adminAlterJobs(const AdminAlterJobsRequest&) const
     * "GPUdb::adminAlterJobs".
     */
    struct AdminAlterJobsResponse
    {
        /**
         * Constructs an AdminAlterJobsResponse object with default parameters.
         */
        AdminAlterJobsResponse() :
            jobIds(std::vector<int64_t>()),
            action(std::string()),
            status(std::vector<std::string>()),
            info(std::map<std::string, std::string>())
        {
        }

        /**
         * Jobs on which the action was performed.
         */
        std::vector<int64_t> jobIds;

        /**
         * Action requested on the jobs.
         */
        std::string action;

        /**
         * Status of the requested action for each job.
         */
        std::vector<std::string> status;

        /**
         * Additional information.
         */
        std::map<std::string, std::string> info;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::AdminAlterJobsResponse>
    {
        static void encode(Encoder& e, const gpudb::AdminAlterJobsResponse& v)
        {
            ::avro::encode(e, v.jobIds);
            ::avro::encode(e, v.action);
            ::avro::encode(e, v.status);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::AdminAlterJobsResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.jobIds);
                            break;

                        case 1:
                            ::avro::decode(d, v.action);
                            break;

                        case 2:
                            ::avro::decode(d, v.status);
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
                ::avro::decode(d, v.jobIds);
                ::avro::decode(d, v.action);
                ::avro::decode(d, v.status);
                ::avro::decode(d, v.info);
            }
        }
    };
} // end namespace avro

#endif // __ADMIN_ALTER_JOBS_H__
