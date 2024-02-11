/*
 *  This file was autogenerated by the Kinetica schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __ADMIN_REBALANCE_H__
#define __ADMIN_REBALANCE_H__

namespace gpudb
{
    /**
     * A set of parameters for @ref
     * GPUdb::adminRebalance(const AdminRebalanceRequest&) const
     * "GPUdb::adminRebalance".
     *
     * Rebalance the data in the cluster so that all nodes contain an equal
     * number of records approximately and/or rebalance the shards to be
     * equally distributed (as much as possible) across all the ranks.
     *
     * The database must be offline for this operation, see @ref
     * GPUdb::adminOffline(const AdminOfflineRequest&) const
     * "GPUdb::adminOffline"
     *
     * * If @ref GPUdb::adminRebalance(const AdminRebalanceRequest&) const
     * "GPUdb::adminRebalance" is invoked after a change is made to the
     * cluster, e.g., a host was added or removed, <a
     * href="../../../concepts/tables/#sharding" target="_top">sharded data</a>
     * will be evenly redistributed across the cluster by number of shards per
     * rank while unsharded data will be redistributed across the cluster by
     * data size per rank
     * * If @ref GPUdb::adminRebalance(const AdminRebalanceRequest&) const
     * "GPUdb::adminRebalance" is invoked at some point when unsharded data
     * (a.k.a. <a href="../../../concepts/tables/#random-sharding"
     * target="_top">randomly-sharded</a>) in the cluster is unevenly
     * distributed over time, sharded data will not move while unsharded data
     * will be redistributed across the cluster by data size per rank
     *
     * NOTE: Replicated data will not move as a result of this call
     *
     * This endpoint's processing time depends on the amount of data in the
     * system, thus the API call may time out if run directly.  It is
     * recommended to run this endpoint asynchronously via @ref
     * GPUdb::createJob(const CreateJobRequest&) const "GPUdb::createJob".
     */
    struct AdminRebalanceRequest
    {
        /**
         * Constructs an AdminRebalanceRequest object with default parameters.
         */
        AdminRebalanceRequest() :
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an AdminRebalanceRequest object with the specified
         * parameters.
         *
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                          <li>@ref
         *                              gpudb::admin_rebalance_rebalance_sharded_data
         *                              "admin_rebalance_rebalance_sharded_data":
         *                              If @ref gpudb::admin_rebalance_true
         *                              "true", <a
         *                              href="../../../concepts/tables/#sharding"
         *                              target="_top">sharded data</a> will be
         *                              rebalanced approximately equally across
         *                              the cluster. Note that for clusters
         *                              with large amounts of sharded data,
         *                              this data transfer could be time
         *                              consuming and result in delayed query
         *                              responses.
         *                              Supported values:
         *                              <ul>
         *                                  <li>@ref
         *                                      gpudb::admin_rebalance_true
         *                                      "admin_rebalance_true"
         *                                  <li>@ref
         *                                      gpudb::admin_rebalance_false
         *                                      "admin_rebalance_false"
         *                              </ul>
         *                              The default value is @ref
         *                              gpudb::admin_rebalance_true
         *                              "admin_rebalance_true".
         *                          <li>@ref
         *                              gpudb::admin_rebalance_rebalance_unsharded_data
         *                              "admin_rebalance_rebalance_unsharded_data":
         *                              If @ref gpudb::admin_rebalance_true
         *                              "true", unsharded data (a.k.a. <a
         *                              href="../../../concepts/tables/#random-sharding"
         *                              target="_top">randomly-sharded</a>)
         *                              will be rebalanced approximately
         *                              equally across the cluster. Note that
         *                              for clusters with large amounts of
         *                              unsharded data, this data transfer
         *                              could be time consuming and result in
         *                              delayed query responses.
         *                              Supported values:
         *                              <ul>
         *                                  <li>@ref
         *                                      gpudb::admin_rebalance_true
         *                                      "admin_rebalance_true"
         *                                  <li>@ref
         *                                      gpudb::admin_rebalance_false
         *                                      "admin_rebalance_false"
         *                              </ul>
         *                              The default value is @ref
         *                              gpudb::admin_rebalance_true
         *                              "admin_rebalance_true".
         *                          <li>@ref
         *                              gpudb::admin_rebalance_table_includes
         *                              "admin_rebalance_table_includes":
         *                              Comma-separated list of unsharded table
         *                              names to rebalance. Not applicable to
         *                              sharded tables because they are always
         *                              rebalanced. Cannot be used
         *                              simultaneously with @ref
         *                              gpudb::admin_rebalance_table_excludes
         *                              "table_excludes". This parameter is
         *                              ignored if @ref
         *                              gpudb::admin_rebalance_rebalance_unsharded_data
         *                              "rebalance_unsharded_data" is @ref
         *                              gpudb::admin_rebalance_false "false".
         *                          <li>@ref
         *                              gpudb::admin_rebalance_table_excludes
         *                              "admin_rebalance_table_excludes":
         *                              Comma-separated list of unsharded table
         *                              names to not rebalance. Not applicable
         *                              to sharded tables because they are
         *                              always rebalanced. Cannot be used
         *                              simultaneously with @ref
         *                              gpudb::admin_rebalance_table_includes
         *                              "table_includes". This parameter is
         *                              ignored if @ref
         *                              gpudb::admin_rebalance_rebalance_unsharded_data
         *                              "rebalance_unsharded_data" is @ref
         *                              gpudb::admin_rebalance_false "false".
         *                          <li>@ref
         *                              gpudb::admin_rebalance_aggressiveness
         *                              "admin_rebalance_aggressiveness":
         *                              Influences how much data is moved at a
         *                              time during rebalance.  A higher @ref
         *                              gpudb::admin_rebalance_aggressiveness
         *                              "aggressiveness" will complete the
         *                              rebalance faster.  A lower @ref
         *                              gpudb::admin_rebalance_aggressiveness
         *                              "aggressiveness" will take longer but
         *                              allow for better interleaving between
         *                              the rebalance and other queries. Valid
         *                              values are constants from 1 (lowest) to
         *                              10 (highest). The default value is
         *                              '10'.
         *                          <li>@ref
         *                              gpudb::admin_rebalance_compact_after_rebalance
         *                              "admin_rebalance_compact_after_rebalance":
         *                              Perform compaction of deleted records
         *                              once the rebalance completes to reclaim
         *                              memory and disk space. Default is @ref
         *                              gpudb::admin_rebalance_true "true",
         *                              unless @ref
         *                              gpudb::admin_rebalance_repair_incorrectly_sharded_data
         *                              "repair_incorrectly_sharded_data" is
         *                              set to @ref gpudb::admin_rebalance_true
         *                              "true".
         *                              Supported values:
         *                              <ul>
         *                                  <li>@ref
         *                                      gpudb::admin_rebalance_true
         *                                      "admin_rebalance_true"
         *                                  <li>@ref
         *                                      gpudb::admin_rebalance_false
         *                                      "admin_rebalance_false"
         *                              </ul>
         *                              The default value is @ref
         *                              gpudb::admin_rebalance_true
         *                              "admin_rebalance_true".
         *                          <li>@ref
         *                              gpudb::admin_rebalance_compact_only
         *                              "admin_rebalance_compact_only": If set
         *                              to @ref gpudb::admin_rebalance_true
         *                              "true", ignore rebalance options and
         *                              attempt to perform compaction of
         *                              deleted records to reclaim memory and
         *                              disk space without rebalancing first.
         *                              Supported values:
         *                              <ul>
         *                                  <li>@ref
         *                                      gpudb::admin_rebalance_true
         *                                      "admin_rebalance_true"
         *                                  <li>@ref
         *                                      gpudb::admin_rebalance_false
         *                                      "admin_rebalance_false"
         *                              </ul>
         *                              The default value is @ref
         *                              gpudb::admin_rebalance_false
         *                              "admin_rebalance_false".
         *                          <li>@ref
         *                              gpudb::admin_rebalance_repair_incorrectly_sharded_data
         *                              "admin_rebalance_repair_incorrectly_sharded_data":
         *                              Scans for any data sharded incorrectly
         *                              and re-routes the data to the correct
         *                              location. Only necessary if @ref
         *                              GPUdb::adminVerifyDb(const AdminVerifyDbRequest&) const
         *                              "GPUdb::adminVerifyDb" reports an error
         *                              in sharding alignment. This can be done
         *                              as part of a typical rebalance after
         *                              expanding the cluster or in a
         *                              standalone fashion when it is believed
         *                              that data is sharded incorrectly
         *                              somewhere in the cluster. Compaction
         *                              will not be performed by default when
         *                              this is enabled. If this option is set
         *                              to @ref gpudb::admin_rebalance_true
         *                              "true", the time necessary to rebalance
         *                              and the memory used by the rebalance
         *                              may increase.
         *                              Supported values:
         *                              <ul>
         *                                  <li>@ref
         *                                      gpudb::admin_rebalance_true
         *                                      "admin_rebalance_true"
         *                                  <li>@ref
         *                                      gpudb::admin_rebalance_false
         *                                      "admin_rebalance_false"
         *                              </ul>
         *                              The default value is @ref
         *                              gpudb::admin_rebalance_false
         *                              "admin_rebalance_false".
         *                      </ul>
         *                      The default value is an empty map.
         */
        AdminRebalanceRequest(const std::map<std::string, std::string>& options_):
            options( options_ )
        {
        }

        /**
         * Optional parameters.
         * <ul>
         *     <li>@ref gpudb::admin_rebalance_rebalance_sharded_data
         *         "admin_rebalance_rebalance_sharded_data": If @ref
         *         gpudb::admin_rebalance_true "true", <a
         *         href="../../../concepts/tables/#sharding"
         *         target="_top">sharded data</a> will be rebalanced
         *         approximately equally across the cluster. Note that for
         *         clusters with large amounts of sharded data, this data
         *         transfer could be time consuming and result in delayed query
         *         responses.
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::admin_rebalance_true
         *                 "admin_rebalance_true"
         *             <li>@ref gpudb::admin_rebalance_false
         *                 "admin_rebalance_false"
         *         </ul>
         *         The default value is @ref gpudb::admin_rebalance_true
         *         "admin_rebalance_true".
         *     <li>@ref gpudb::admin_rebalance_rebalance_unsharded_data
         *         "admin_rebalance_rebalance_unsharded_data": If @ref
         *         gpudb::admin_rebalance_true "true", unsharded data (a.k.a.
         *         <a href="../../../concepts/tables/#random-sharding"
         *         target="_top">randomly-sharded</a>) will be rebalanced
         *         approximately equally across the cluster. Note that for
         *         clusters with large amounts of unsharded data, this data
         *         transfer could be time consuming and result in delayed query
         *         responses.
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::admin_rebalance_true
         *                 "admin_rebalance_true"
         *             <li>@ref gpudb::admin_rebalance_false
         *                 "admin_rebalance_false"
         *         </ul>
         *         The default value is @ref gpudb::admin_rebalance_true
         *         "admin_rebalance_true".
         *     <li>@ref gpudb::admin_rebalance_table_includes
         *         "admin_rebalance_table_includes": Comma-separated list of
         *         unsharded table names to rebalance. Not applicable to
         *         sharded tables because they are always rebalanced. Cannot be
         *         used simultaneously with @ref
         *         gpudb::admin_rebalance_table_excludes "table_excludes". This
         *         parameter is ignored if @ref
         *         gpudb::admin_rebalance_rebalance_unsharded_data
         *         "rebalance_unsharded_data" is @ref
         *         gpudb::admin_rebalance_false "false".
         *     <li>@ref gpudb::admin_rebalance_table_excludes
         *         "admin_rebalance_table_excludes": Comma-separated list of
         *         unsharded table names to not rebalance. Not applicable to
         *         sharded tables because they are always rebalanced. Cannot be
         *         used simultaneously with @ref
         *         gpudb::admin_rebalance_table_includes "table_includes". This
         *         parameter is ignored if @ref
         *         gpudb::admin_rebalance_rebalance_unsharded_data
         *         "rebalance_unsharded_data" is @ref
         *         gpudb::admin_rebalance_false "false".
         *     <li>@ref gpudb::admin_rebalance_aggressiveness
         *         "admin_rebalance_aggressiveness": Influences how much data
         *         is moved at a time during rebalance.  A higher @ref
         *         gpudb::admin_rebalance_aggressiveness "aggressiveness" will
         *         complete the rebalance faster.  A lower @ref
         *         gpudb::admin_rebalance_aggressiveness "aggressiveness" will
         *         take longer but allow for better interleaving between the
         *         rebalance and other queries. Valid values are constants from
         *         1 (lowest) to 10 (highest). The default value is '10'.
         *     <li>@ref gpudb::admin_rebalance_compact_after_rebalance
         *         "admin_rebalance_compact_after_rebalance": Perform
         *         compaction of deleted records once the rebalance completes
         *         to reclaim memory and disk space. Default is @ref
         *         gpudb::admin_rebalance_true "true", unless @ref
         *         gpudb::admin_rebalance_repair_incorrectly_sharded_data
         *         "repair_incorrectly_sharded_data" is set to @ref
         *         gpudb::admin_rebalance_true "true".
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::admin_rebalance_true
         *                 "admin_rebalance_true"
         *             <li>@ref gpudb::admin_rebalance_false
         *                 "admin_rebalance_false"
         *         </ul>
         *         The default value is @ref gpudb::admin_rebalance_true
         *         "admin_rebalance_true".
         *     <li>@ref gpudb::admin_rebalance_compact_only
         *         "admin_rebalance_compact_only": If set to @ref
         *         gpudb::admin_rebalance_true "true", ignore rebalance options
         *         and attempt to perform compaction of deleted records to
         *         reclaim memory and disk space without rebalancing first.
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::admin_rebalance_true
         *                 "admin_rebalance_true"
         *             <li>@ref gpudb::admin_rebalance_false
         *                 "admin_rebalance_false"
         *         </ul>
         *         The default value is @ref gpudb::admin_rebalance_false
         *         "admin_rebalance_false".
         *     <li>@ref gpudb::admin_rebalance_repair_incorrectly_sharded_data
         *         "admin_rebalance_repair_incorrectly_sharded_data": Scans for
         *         any data sharded incorrectly and re-routes the data to the
         *         correct location. Only necessary if @ref
         *         GPUdb::adminVerifyDb(const AdminVerifyDbRequest&) const
         *         "GPUdb::adminVerifyDb" reports an error in sharding
         *         alignment. This can be done as part of a typical rebalance
         *         after expanding the cluster or in a standalone fashion when
         *         it is believed that data is sharded incorrectly somewhere in
         *         the cluster. Compaction will not be performed by default
         *         when this is enabled. If this option is set to @ref
         *         gpudb::admin_rebalance_true "true", the time necessary to
         *         rebalance and the memory used by the rebalance may increase.
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::admin_rebalance_true
         *                 "admin_rebalance_true"
         *             <li>@ref gpudb::admin_rebalance_false
         *                 "admin_rebalance_false"
         *         </ul>
         *         The default value is @ref gpudb::admin_rebalance_false
         *         "admin_rebalance_false".
         * </ul>
         * The default value is an empty map.
         */
        std::map<std::string, std::string> options;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::AdminRebalanceRequest>
    {
        static void encode(Encoder& e, const gpudb::AdminRebalanceRequest& v)
        {
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AdminRebalanceRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.options);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.options);
            }
        }
    };
} // end namespace avro

namespace gpudb
{
    /**
     * A set of results returned by @ref
     * GPUdb::adminRebalance(const AdminRebalanceRequest&) const
     * "GPUdb::adminRebalance".
     */
    struct AdminRebalanceResponse
    {
        /**
         * Constructs an AdminRebalanceResponse object with default parameters.
         */
        AdminRebalanceResponse() :
            info(std::map<std::string, std::string>())
        {
        }

        /**
         * Additional information.
         */
        std::map<std::string, std::string> info;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::AdminRebalanceResponse>
    {
        static void encode(Encoder& e, const gpudb::AdminRebalanceResponse& v)
        {
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::AdminRebalanceResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.info);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.info);
            }
        }
    };
} // end namespace avro

#endif // __ADMIN_REBALANCE_H__
