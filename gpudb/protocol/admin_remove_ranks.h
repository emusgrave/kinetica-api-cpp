/*
 *  This file was autogenerated by the Kinetica schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __ADMIN_REMOVE_RANKS_H__
#define __ADMIN_REMOVE_RANKS_H__

namespace gpudb
{
    /**
     * A set of parameters for @ref
     * GPUdb::adminRemoveRanks(const AdminRemoveRanksRequest&) const
     * "GPUdb::adminRemoveRanks".
     *
     * Remove one or more ranks from an existing Kinetica cluster. All data
     * will be rebalanced to other ranks before the rank(s) is removed unless
     * the @ref gpudb::admin_remove_ranks_rebalance_sharded_data
     * "rebalance_sharded_data" or @ref
     * gpudb::admin_remove_ranks_rebalance_unsharded_data
     * "rebalance_unsharded_data" parameters are set to @ref
     * gpudb::admin_remove_ranks_false "false" in the @ref options, in which
     * case the corresponding <a href="../../../concepts/tables/#sharding"
     * target="_top">sharded data</a> and/or unsharded data (a.k.a. <a
     * href="../../../concepts/tables/#random-sharding"
     * target="_top">randomly-sharded</a>) will be deleted.
     *
     * The database must be offline for this operation, see @ref
     * GPUdb::adminOffline(const AdminOfflineRequest&) const
     * "GPUdb::adminOffline"
     *
     * This endpoint's processing time depends on the amount of data in the
     * system, thus the API call may time out if run directly.  It is
     * recommended to run this endpoint asynchronously via @ref
     * GPUdb::createJob(const CreateJobRequest&) const "GPUdb::createJob".
     */
    struct AdminRemoveRanksRequest
    {
        /**
         * Constructs an AdminRemoveRanksRequest object with default
         * parameters.
         */
        AdminRemoveRanksRequest() :
            ranks(std::vector<std::string>()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an AdminRemoveRanksRequest object with the specified
         * parameters.
         *
         * @param[in] ranks_  Each array value designates one or more ranks to
         *                    remove from the cluster. Values can be formatted
         *                    as 'rankN' for a specific rank, 'hostN' (from the
         *                    gpudb.conf file) to remove all ranks on that
         *                    host, or the host IP address (hostN.address from
         *                    the gpub.conf file) which also removes all ranks
         *                    on that host. Rank 0 (the head rank) cannot be
         *                    removed (but can be moved to another host using
         *                    @ref
         *                    GPUdb::adminSwitchover(const AdminSwitchoverRequest&) const
         *                    "GPUdb::adminSwitchover"). At least one worker
         *                    rank must be left in the cluster after the
         *                    operation.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                          <li>@ref
         *                              gpudb::admin_remove_ranks_rebalance_sharded_data
         *                              "admin_remove_ranks_rebalance_sharded_data":
         *                              If @ref gpudb::admin_remove_ranks_true
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
         *                                      gpudb::admin_remove_ranks_true
         *                                      "admin_remove_ranks_true"
         *                                  <li>@ref
         *                                      gpudb::admin_remove_ranks_false
         *                                      "admin_remove_ranks_false"
         *                              </ul>
         *                              The default value is @ref
         *                              gpudb::admin_remove_ranks_true
         *                              "admin_remove_ranks_true".
         *                          <li>@ref
         *                              gpudb::admin_remove_ranks_rebalance_unsharded_data
         *                              "admin_remove_ranks_rebalance_unsharded_data":
         *                              If @ref gpudb::admin_remove_ranks_true
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
         *                                      gpudb::admin_remove_ranks_true
         *                                      "admin_remove_ranks_true"
         *                                  <li>@ref
         *                                      gpudb::admin_remove_ranks_false
         *                                      "admin_remove_ranks_false"
         *                              </ul>
         *                              The default value is @ref
         *                              gpudb::admin_remove_ranks_true
         *                              "admin_remove_ranks_true".
         *                          <li>@ref
         *                              gpudb::admin_remove_ranks_aggressiveness
         *                              "admin_remove_ranks_aggressiveness":
         *                              Influences how much data is moved at a
         *                              time during rebalance.  A higher @ref
         *                              gpudb::admin_remove_ranks_aggressiveness
         *                              "aggressiveness" will complete the
         *                              rebalance faster.  A lower @ref
         *                              gpudb::admin_remove_ranks_aggressiveness
         *                              "aggressiveness" will take longer but
         *                              allow for better interleaving between
         *                              the rebalance and other queries. Valid
         *                              values are constants from 1 (lowest) to
         *                              10 (highest). The default value is
         *                              '10'.
         *                      </ul>
         *                      The default value is an empty map.
         */
        AdminRemoveRanksRequest(const std::vector<std::string>& ranks_, const std::map<std::string, std::string>& options_):
            ranks( ranks_ ),
            options( options_ )
        {
        }

        /**
         * Each array value designates one or more ranks to remove from the
         * cluster. Values can be formatted as 'rankN' for a specific rank,
         * 'hostN' (from the gpudb.conf file) to remove all ranks on that host,
         * or the host IP address (hostN.address from the gpub.conf file) which
         * also removes all ranks on that host. Rank 0 (the head rank) cannot
         * be removed (but can be moved to another host using @ref
         * GPUdb::adminSwitchover(const AdminSwitchoverRequest&) const
         * "GPUdb::adminSwitchover"). At least one worker rank must be left in
         * the cluster after the operation.
         */
        std::vector<std::string> ranks;

        /**
         * Optional parameters.
         * <ul>
         *     <li>@ref gpudb::admin_remove_ranks_rebalance_sharded_data
         *         "admin_remove_ranks_rebalance_sharded_data": If @ref
         *         gpudb::admin_remove_ranks_true "true", <a
         *         href="../../../concepts/tables/#sharding"
         *         target="_top">sharded data</a> will be rebalanced
         *         approximately equally across the cluster. Note that for
         *         clusters with large amounts of sharded data, this data
         *         transfer could be time consuming and result in delayed query
         *         responses.
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::admin_remove_ranks_true
         *                 "admin_remove_ranks_true"
         *             <li>@ref gpudb::admin_remove_ranks_false
         *                 "admin_remove_ranks_false"
         *         </ul>
         *         The default value is @ref gpudb::admin_remove_ranks_true
         *         "admin_remove_ranks_true".
         *     <li>@ref gpudb::admin_remove_ranks_rebalance_unsharded_data
         *         "admin_remove_ranks_rebalance_unsharded_data": If @ref
         *         gpudb::admin_remove_ranks_true "true", unsharded data
         *         (a.k.a. <a href="../../../concepts/tables/#random-sharding"
         *         target="_top">randomly-sharded</a>) will be rebalanced
         *         approximately equally across the cluster. Note that for
         *         clusters with large amounts of unsharded data, this data
         *         transfer could be time consuming and result in delayed query
         *         responses.
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::admin_remove_ranks_true
         *                 "admin_remove_ranks_true"
         *             <li>@ref gpudb::admin_remove_ranks_false
         *                 "admin_remove_ranks_false"
         *         </ul>
         *         The default value is @ref gpudb::admin_remove_ranks_true
         *         "admin_remove_ranks_true".
         *     <li>@ref gpudb::admin_remove_ranks_aggressiveness
         *         "admin_remove_ranks_aggressiveness": Influences how much
         *         data is moved at a time during rebalance.  A higher @ref
         *         gpudb::admin_remove_ranks_aggressiveness "aggressiveness"
         *         will complete the rebalance faster.  A lower @ref
         *         gpudb::admin_remove_ranks_aggressiveness "aggressiveness"
         *         will take longer but allow for better interleaving between
         *         the rebalance and other queries. Valid values are constants
         *         from 1 (lowest) to 10 (highest). The default value is '10'.
         * </ul>
         * The default value is an empty map.
         */
        std::map<std::string, std::string> options;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::AdminRemoveRanksRequest>
    {
        static void encode(Encoder& e, const gpudb::AdminRemoveRanksRequest& v)
        {
            ::avro::encode(e, v.ranks);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AdminRemoveRanksRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.ranks);
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
                ::avro::decode(d, v.ranks);
                ::avro::decode(d, v.options);
            }
        }
    };
} // end namespace avro

namespace gpudb
{
    /**
     * A set of results returned by @ref
     * GPUdb::adminRemoveRanks(const AdminRemoveRanksRequest&) const
     * "GPUdb::adminRemoveRanks".
     */
    struct AdminRemoveRanksResponse
    {
        /**
         * Constructs an AdminRemoveRanksResponse object with default
         * parameters.
         */
        AdminRemoveRanksResponse() :
            removedRanks(std::vector<std::string>()),
            info(std::map<std::string, std::string>())
        {
        }

        /**
         * The number assigned to each rank removed from the cluster. This
         * array will be empty if the operation fails.
         */
        std::vector<std::string> removedRanks;

        /**
         * Additional information.
         */
        std::map<std::string, std::string> info;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::AdminRemoveRanksResponse>
    {
        static void encode(Encoder& e, const gpudb::AdminRemoveRanksResponse& v)
        {
            ::avro::encode(e, v.removedRanks);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::AdminRemoveRanksResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.removedRanks);
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
                ::avro::decode(d, v.removedRanks);
                ::avro::decode(d, v.info);
            }
        }
    };
} // end namespace avro

#endif // __ADMIN_REMOVE_RANKS_H__
