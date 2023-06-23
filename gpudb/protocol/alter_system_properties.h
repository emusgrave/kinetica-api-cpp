/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __ALTER_SYSTEM_PROPERTIES_H__
#define __ALTER_SYSTEM_PROPERTIES_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #alterSystemProperties(const AlterSystemPropertiesRequest&) const}.
     * <p>
     * The {@link
     * #alterSystemProperties(const AlterSystemPropertiesRequest&) const}
     * endpoint is primarily used to simplify the testing of the system and is
     * not expected to be used during normal execution.  Commands are given
     * through the @a propertyUpdatesMap whose keys are commands and values are
     * strings representing integer values (for example '8000') or boolean
     * values ('true' or 'false').
     */
    struct AlterSystemPropertiesRequest
    {

        /**
         * Constructs an AlterSystemPropertiesRequest object with default
         * parameter values.
         */
        AlterSystemPropertiesRequest() :
            propertyUpdatesMap(std::map<std::string, std::string>()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an AlterSystemPropertiesRequest object with the specified
         * parameters.
         * 
         * @param[in] propertyUpdatesMap_  Map containing the properties of the
         *                                 system to be updated. Error if
         *                                 empty.
         *                                 <ul>
         *                                         <li>
         *                                 gpudb::alter_system_properties_sm_omp_threads:
         *                                 Set the number of OpenMP threads
         *                                 that will be used to service filter
         *                                 & aggregation requests to the
         *                                 specified integer value.
         *                                         <li>
         *                                 gpudb::alter_system_properties_kernel_omp_threads:
         *                                 Set the number of kernel OpenMP
         *                                 threads to the specified integer
         *                                 value.
         *                                         <li>
         *                                 gpudb::alter_system_properties_concurrent_kernel_execution:
         *                                 Enables concurrent kernel execution
         *                                 if the value is @a true and disables
         *                                 it if the value is @a false.
         *                                 <ul>
         *                                         <li>
         *                                 gpudb::alter_system_properties_true
         *                                         <li>
         *                                 gpudb::alter_system_properties_false
         *                                 </ul>
         *                                         <li>
         *                                 gpudb::alter_system_properties_subtask_concurrency_limit:
         *                                 Sets the maximum number of
         *                                 simultaneous threads allocated to a
         *                                 given request, on each rank. Note
         *                                 that thread allocation may also be
         *                                 limted by resource group limits
         *                                 and/or system load.
         *                                         <li>
         *                                 gpudb::alter_system_properties_chunk_size:
         *                                 Sets the number of records per chunk
         *                                 to be used for all new tables.
         *                                         <li>
         *                                 gpudb::alter_system_properties_evict_columns:
         *                                 Attempts to evict columns from
         *                                 memory to the persistent store.
         *                                 Value string is a semicolon
         *                                 separated list of entries, each
         *                                 entry being a table name optionally
         *                                 followed by a comma and a comma
         *                                 separated list of column names to
         *                                 attempt to evict.  An empty value
         *                                 string will attempt to evict all
         *                                 tables and columns.
         *                                         <li>
         *                                 gpudb::alter_system_properties_execution_mode:
         *                                 Sets the execution_mode for kernel
         *                                 executions to the specified string
         *                                 value. Possible values are host,
         *                                 device, default (engine decides) or
         *                                 an integer value that indicates max
         *                                 chunk size to exec on host
         *                                         <li>
         *                                 gpudb::alter_system_properties_external_files_directory:
         *                                 Sets the root directory path where
         *                                 external table data files are
         *                                 accessed from.  Path must exist on
         *                                 the head node
         *                                         <li>
         *                                 gpudb::alter_system_properties_flush_to_disk:
         *                                 Flushes any changes to any tables to
         *                                 the persistent store.  These changes
         *                                 include updates to the vector store,
         *                                 object store, and text search store,
         *                                 Value string is ignored
         *                                         <li>
         *                                 gpudb::alter_system_properties_clear_cache:
         *                                 Clears cached results.  Useful to
         *                                 allow repeated timing of endpoints.
         *                                 Value string is the name of the
         *                                 table for which to clear the cached
         *                                 results, or an empty string to clear
         *                                 the cached results for all tables.
         *                                         <li>
         *                                 gpudb::alter_system_properties_communicator_test:
         *                                 Invoke the communicator test and
         *                                 report timing results. Value string
         *                                 is is a semicolon separated list of
         *                                 [key]=[value] expressions.
         *                                 Expressions are:
         *                                 num_transactions=[num] where num is
         *                                 the number of request reply
         *                                 transactions to invoke per test;
         *                                 message_size=[bytes] where bytes is
         *                                 the size in bytes of the messages to
         *                                 send; check_values=[enabled] where
         *                                 if enabled is true the value of the
         *                                 messages received are verified.
         *                                         <li>
         *                                 gpudb::alter_system_properties_network_speed:
         *                                 Invoke the network speed test and
         *                                 report timing results. Value string
         *                                 is a semicolon-separated list of
         *                                 [key]=[value] expressions.  Valid
         *                                 expressions are: seconds=[time]
         *                                 where time is the time in seconds to
         *                                 run the test; data_size=[bytes]
         *                                 where bytes is the size in bytes of
         *                                 the block to be transferred;
         *                                 threads=[number of threads];
         *                                 to_ranks=[space-separated list of
         *                                 ranks] where the list of ranks is
         *                                 the ranks that rank 0 will send data
         *                                 to and get data from. If to_ranks is
         *                                 unspecified then all worker ranks
         *                                 are used.
         *                                         <li>
         *                                 gpudb::alter_system_properties_request_timeout:
         *                                 Number of minutes after which
         *                                 filtering (e.g., /filter) and
         *                                 aggregating (e.g.,
         *                                 /aggregate/groupby) queries will
         *                                 timeout.  The default value is '20'.
         *                                         <li>
         *                                 gpudb::alter_system_properties_max_get_records_size:
         *                                 The maximum number of records the
         *                                 database will serve for a given data
         *                                 retrieval call.  The default value
         *                                 is '20000'.
         *                                         <li>
         *                                 gpudb::alter_system_properties_enable_audit:
         *                                 Enable or disable auditing.
         *                                         <li>
         *                                 gpudb::alter_system_properties_audit_headers:
         *                                 Enable or disable auditing of
         *                                 request headers.
         *                                         <li>
         *                                 gpudb::alter_system_properties_audit_body:
         *                                 Enable or disable auditing of
         *                                 request bodies.
         *                                         <li>
         *                                 gpudb::alter_system_properties_audit_data:
         *                                 Enable or disable auditing of
         *                                 request data.
         *                                         <li>
         *                                 gpudb::alter_system_properties_audit_response:
         *                                 Enable or disable auditing of
         *                                 response information.
         *                                         <li>
         *                                 gpudb::alter_system_properties_shadow_agg_size:
         *                                 Size of the shadow aggregate chunk
         *                                 cache in bytes.  The default value
         *                                 is '10000000'.
         *                                         <li>
         *                                 gpudb::alter_system_properties_shadow_filter_size:
         *                                 Size of the shadow filter chunk
         *                                 cache in bytes.  The default value
         *                                 is '10000000'.
         *                                         <li>
         *                                 gpudb::alter_system_properties_synchronous_compression:
         *                                 compress vector on set_compression
         *                                 (instead of waiting for background
         *                                 thread).  The default value is
         *                                 'false'.
         *                                         <li>
         *                                 gpudb::alter_system_properties_enable_overlapped_equi_join:
         *                                 Enable overlapped-equi-join filter.
         *                                 The default value is 'true'.
         *                                         <li>
         *                                 gpudb::alter_system_properties_kafka_batch_size:
         *                                 Maximum number of records to be
         *                                 ingested in a single batch.  The
         *                                 default value is '1000'.
         *                                         <li>
         *                                 gpudb::alter_system_properties_kafka_poll_timeout:
         *                                 Maximum time (milliseconds) for each
         *                                 poll to get records from kafka.  The
         *                                 default value is '0'.
         *                                         <li>
         *                                 gpudb::alter_system_properties_kafka_wait_time:
         *                                 Maximum time (seconds) to buffer
         *                                 records received from kafka before
         *                                 ingestion.  The default value is
         *                                 '30'.
         *                                         <li>
         *                                 gpudb::alter_system_properties_egress_parquet_compression:
         *                                 Parquet file compression type
         *                                 <ul>
         *                                         <li>
         *                                 gpudb::alter_system_properties_uncompressed
         *                                         <li>
         *                                 gpudb::alter_system_properties_snappy
         *                                         <li>
         *                                 gpudb::alter_system_properties_gzip
         *                                 </ul>
         *                                 The default value is
         *                                 gpudb::alter_system_properties_snappy.
         *                                         <li>
         *                                 gpudb::alter_system_properties_egress_single_file_max_size:
         *                                 Max file size (in MB) to allow
         *                                 saving to a single file. May be
         *                                 overridden by target limitations.
         *                                 The default value is '100'.
         *                                         <li>
         *                                 gpudb::alter_system_properties_max_concurrent_kernels:
         *                                 Sets the max_concurrent_kernels
         *                                 value of the conf.
         *                                         <li>
         *                                 gpudb::alter_system_properties_tcs_per_tom:
         *                                 Sets the tcs_per_tom value of the
         *                                 conf.
         *                                         <li>
         *                                 gpudb::alter_system_properties_tps_per_tom:
         *                                 Sets the tps_per_tom value of the
         *                                 conf.
         *                                 </ul>
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::alter_system_properties_persist: If @a
         *                      true the system configuration will be written
         *                      to disk upon successful application of this
         *                      request. This will commit the changes from this
         *                      request and any additional in-memory
         *                      modifications.
         *                      <ul>
         *                              <li>
         *                      gpudb::alter_system_properties_true
         *                              <li>
         *                      gpudb::alter_system_properties_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::alter_system_properties_true.
         *                      </ul>
         * 
         */
        AlterSystemPropertiesRequest(const std::map<std::string, std::string>& propertyUpdatesMap_, const std::map<std::string, std::string>& options_):
            propertyUpdatesMap( propertyUpdatesMap_ ),
            options( options_ )
        {
        }

        std::map<std::string, std::string> propertyUpdatesMap;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AlterSystemPropertiesRequest>
    {
        static void encode(Encoder& e, const gpudb::AlterSystemPropertiesRequest& v)
        {
            ::avro::encode(e, v.propertyUpdatesMap);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AlterSystemPropertiesRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.propertyUpdatesMap);
                            break;

                        case 1:
                            ::avro::decode(d, v.options);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.propertyUpdatesMap);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #alterSystemProperties(const AlterSystemPropertiesRequest&) const}.
     * <p>
     * The {@link
     * #alterSystemProperties(const AlterSystemPropertiesRequest&) const}
     * endpoint is primarily used to simplify the testing of the system and is
     * not expected to be used during normal execution.  Commands are given
     * through the @a propertyUpdatesMap whose keys are commands and values are
     * strings representing integer values (for example '8000') or boolean
     * values ('true' or 'false').
     */
    struct AlterSystemPropertiesResponse
    {

        /**
         * Constructs an AlterSystemPropertiesResponse object with default
         * parameter values.
         */
        AlterSystemPropertiesResponse() :
            updatedPropertiesMap(std::map<std::string, std::string>()),
            info(std::map<std::string, std::string>())
        {
        }

        std::map<std::string, std::string> updatedPropertiesMap;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AlterSystemPropertiesResponse>
    {
        static void encode(Encoder& e, const gpudb::AlterSystemPropertiesResponse& v)
        {
            ::avro::encode(e, v.updatedPropertiesMap);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::AlterSystemPropertiesResponse& v)
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
}

#endif
