/*
 *  This file was autogenerated by the Kinetica schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __ADMIN_SHOW_CLUSTER_OPERATIONS_H__
#define __ADMIN_SHOW_CLUSTER_OPERATIONS_H__

namespace gpudb
{
    /**
     * A set of parameters for @ref
     * GPUdb::adminShowClusterOperations(const AdminShowClusterOperationsRequest&) const
     * "GPUdb::adminShowClusterOperations".
     *
     * Requests the detailed status of the current operation (by default) or a
     * prior cluster operation specified by @ref historyIndex.
     * Returns details on the requested cluster operation.
     *
     * The response will also indicate how many cluster operations are stored
     * in the history.
     */
    struct AdminShowClusterOperationsRequest
    {
        /**
         * Constructs an AdminShowClusterOperationsRequest object with default
         * parameters.
         */
        AdminShowClusterOperationsRequest() :
            historyIndex(int32_t()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an AdminShowClusterOperationsRequest object with the
         * specified parameters.
         *
         * @param[in] historyIndex_  Indicates which cluster operation to
         *                           retrieve.  Use 0 for the most recent. The
         *                           default value is 0.
         * @param[in] options_  Optional parameters. The default value is an
         *                      empty map.
         */
        AdminShowClusterOperationsRequest(const int32_t historyIndex_, const std::map<std::string, std::string>& options_):
            historyIndex( historyIndex_ ),
            options( options_ )
        {
        }

        /**
         * Indicates which cluster operation to retrieve.  Use 0 for the most
         * recent. The default value is 0.
         */
        int32_t historyIndex;

        /**
         * Optional parameters. The default value is an empty map.
         */
        std::map<std::string, std::string> options;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::AdminShowClusterOperationsRequest>
    {
        static void encode(Encoder& e, const gpudb::AdminShowClusterOperationsRequest& v)
        {
            ::avro::encode(e, v.historyIndex);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AdminShowClusterOperationsRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.historyIndex);
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
                ::avro::decode(d, v.historyIndex);
                ::avro::decode(d, v.options);
            }
        }
    };
} // end namespace avro

namespace gpudb
{
    /**
     * A set of results returned by @ref
     * GPUdb::adminShowClusterOperations(const AdminShowClusterOperationsRequest&) const
     * "GPUdb::adminShowClusterOperations".
     */
    struct AdminShowClusterOperationsResponse
    {
        /**
         * Constructs an AdminShowClusterOperationsResponse object with default
         * parameters.
         */
        AdminShowClusterOperationsResponse() :
            historyIndex(int32_t()),
            historySize(int32_t()),
            inProgress(bool()),
            startTime(std::string()),
            endTime(std::string()),
            endpoint(std::string()),
            endpointSchema(std::string()),
            overallStatus(std::string()),
            userStopped(bool()),
            percentComplete(int32_t()),
            dryRun(bool()),
            messages(std::vector<std::string>()),
            addRanks(bool()),
            addRanksStatus(std::string()),
            ranksBeingAdded(std::vector<int32_t>()),
            rankHosts(std::vector<std::string>()),
            addRanksPercentComplete(int32_t()),
            removeRanks(bool()),
            removeRanksStatus(std::string()),
            ranksBeingRemoved(std::vector<int32_t>()),
            removeRanksPercentComplete(int32_t()),
            rebalance(bool()),
            rebalanceUnshardedData(bool()),
            rebalanceUnshardedDataStatus(std::string()),
            unshardedRebalancePercentComplete(int32_t()),
            rebalanceShardedData(bool()),
            shardArrayVersion(int64_t()),
            rebalanceShardedDataStatus(std::string()),
            numShardsChanging(int32_t()),
            shardedRebalancePercentComplete(int32_t()),
            info(std::map<std::string, std::string>())
        {
        }

        /**
         * The index of this cluster operation in the reverse-chronologically
         * sorted list of operations, where 0 is the most recent operation.
         */
        int32_t historyIndex;

        /**
         * Number of cluster operations executed to date.
         */
        int32_t historySize;

        /**
         * Whether this cluster operation is currently in progress or not.
         * Supported values:
         * <ul>
         *     <li>@ref gpudb::admin_show_cluster_operations_true
         *         "admin_show_cluster_operations_true"
         *     <li>@ref gpudb::admin_show_cluster_operations_false
         *         "admin_show_cluster_operations_false"
         * </ul>
         */
        bool inProgress;

        /**
         * The start time of the cluster operation.
         */
        std::string startTime;

        /**
         * The end time of the cluster operation, if completed.
         */
        std::string endTime;

        /**
         * The endpoint that initiated the cluster operation.
         */
        std::string endpoint;

        /**
         * The schema for the original request.
         */
        std::string endpointSchema;

        /**
         * Overall success status of the operation.
         * Supported values:
         * <ul>
         *     <li>@ref gpudb::admin_show_cluster_operations_OK
         *         "admin_show_cluster_operations_OK": The operation was
         *         successful, or, if still in progress, the operation is
         *         successful so far.
         *     <li>@ref gpudb::admin_show_cluster_operations_ERROR
         *         "admin_show_cluster_operations_ERROR": An error occurred
         *         executing the operation.
         * </ul>
         */
        std::string overallStatus;

        /**
         * Whether a user stopped this operation at any point while in
         * progress.
         * Supported values:
         * <ul>
         *     <li>@ref gpudb::admin_show_cluster_operations_true
         *         "admin_show_cluster_operations_true"
         *     <li>@ref gpudb::admin_show_cluster_operations_false
         *         "admin_show_cluster_operations_false"
         * </ul>
         */
        bool userStopped;

        /**
         * Percent complete of this entire operation.
         */
        int32_t percentComplete;

        /**
         * Whether this operation was a dry run.
         * Supported values:
         * <ul>
         *     <li>@ref gpudb::admin_show_cluster_operations_true
         *         "admin_show_cluster_operations_true"
         *     <li>@ref gpudb::admin_show_cluster_operations_false
         *         "admin_show_cluster_operations_false"
         * </ul>
         */
        bool dryRun;

        /**
         * Updates and error messages if any.
         */
        std::vector<std::string> messages;

        /**
         * Whether adding ranks is (or was) part of this operation.
         * Supported values:
         * <ul>
         *     <li>@ref gpudb::admin_show_cluster_operations_true
         *         "admin_show_cluster_operations_true"
         *     <li>@ref gpudb::admin_show_cluster_operations_false
         *         "admin_show_cluster_operations_false"
         * </ul>
         */
        bool addRanks;

        /**
         * If this was a rank-adding operation, the add-specific status of the
         * operation.
         * Valid values are:
         * <ul>
         *     <li>@ref gpudb::admin_show_cluster_operations_NOT_STARTED
         *         "admin_show_cluster_operations_NOT_STARTED"
         *     <li>@ref gpudb::admin_show_cluster_operations_IN_PROGRESS
         *         "admin_show_cluster_operations_IN_PROGRESS"
         *     <li>@ref gpudb::admin_show_cluster_operations_INTERRUPTED
         *         "admin_show_cluster_operations_INTERRUPTED"
         *     <li>@ref gpudb::admin_show_cluster_operations_COMPLETED_OK
         *         "admin_show_cluster_operations_COMPLETED_OK"
         *     <li>@ref gpudb::admin_show_cluster_operations_ERROR
         *         "admin_show_cluster_operations_ERROR"
         * </ul>
         */
        std::string addRanksStatus;

        /**
         * The rank numbers of the ranks currently being added, or the rank
         * numbers that were added if the operation is complete.
         */
        std::vector<int32_t> ranksBeingAdded;

        /**
         * The host IP addresses of the ranks being added, in the same order as
         * the @ref ranksBeingAdded list.
         */
        std::vector<std::string> rankHosts;

        /**
         * Current percent complete of the add ranks operation.
         */
        int32_t addRanksPercentComplete;

        /**
         * Whether removing ranks is (or was) part of this operation.
         * Supported values:
         * <ul>
         *     <li>@ref gpudb::admin_show_cluster_operations_true
         *         "admin_show_cluster_operations_true"
         *     <li>@ref gpudb::admin_show_cluster_operations_false
         *         "admin_show_cluster_operations_false"
         * </ul>
         */
        bool removeRanks;

        /**
         * If this was a rank-removing operation, the removal-specific status
         * of the operation.
         * Valid values are:
         * <ul>
         *     <li>@ref gpudb::admin_show_cluster_operations_NOT_STARTED
         *         "admin_show_cluster_operations_NOT_STARTED"
         *     <li>@ref gpudb::admin_show_cluster_operations_IN_PROGRESS
         *         "admin_show_cluster_operations_IN_PROGRESS"
         *     <li>@ref gpudb::admin_show_cluster_operations_INTERRUPTED
         *         "admin_show_cluster_operations_INTERRUPTED"
         *     <li>@ref gpudb::admin_show_cluster_operations_COMPLETED_OK
         *         "admin_show_cluster_operations_COMPLETED_OK"
         *     <li>@ref gpudb::admin_show_cluster_operations_ERROR
         *         "admin_show_cluster_operations_ERROR"
         * </ul>
         */
        std::string removeRanksStatus;

        /**
         * The ranks being removed, or that have been removed if the operation
         * is completed.
         */
        std::vector<int32_t> ranksBeingRemoved;

        /**
         * Current percent complete of the remove ranks operation.
         */
        int32_t removeRanksPercentComplete;

        /**
         * Whether data and/or shard rebalancing is (or was) part of this
         * operation.
         * Supported values:
         * <ul>
         *     <li>@ref gpudb::admin_show_cluster_operations_true
         *         "admin_show_cluster_operations_true"
         *     <li>@ref gpudb::admin_show_cluster_operations_false
         *         "admin_show_cluster_operations_false"
         * </ul>
         */
        bool rebalance;

        /**
         * Whether rebalancing of unsharded data is (or was) part of this
         * operation.
         * Supported values:
         * <ul>
         *     <li>@ref gpudb::admin_show_cluster_operations_true
         *         "admin_show_cluster_operations_true"
         *     <li>@ref gpudb::admin_show_cluster_operations_false
         *         "admin_show_cluster_operations_false"
         * </ul>
         */
        bool rebalanceUnshardedData;

        /**
         * If this was an operation that included rebalancing unsharded data,
         * the rebalancing-specific status of the operation.
         * Valid values are:
         * <ul>
         *     <li>@ref gpudb::admin_show_cluster_operations_NOT_STARTED
         *         "admin_show_cluster_operations_NOT_STARTED"
         *     <li>@ref gpudb::admin_show_cluster_operations_IN_PROGRESS
         *         "admin_show_cluster_operations_IN_PROGRESS"
         *     <li>@ref gpudb::admin_show_cluster_operations_INTERRUPTED
         *         "admin_show_cluster_operations_INTERRUPTED"
         *     <li>@ref gpudb::admin_show_cluster_operations_COMPLETED_OK
         *         "admin_show_cluster_operations_COMPLETED_OK"
         *     <li>@ref gpudb::admin_show_cluster_operations_ERROR
         *         "admin_show_cluster_operations_ERROR"
         * </ul>
         */
        std::string rebalanceUnshardedDataStatus;

        /**
         * Percentage of unsharded tables that completed rebalancing, out of
         * all unsharded tables to rebalance.
         */
        int32_t unshardedRebalancePercentComplete;

        /**
         * Whether rebalancing of sharded data is (or was) part of this
         * operation.
         * Supported values:
         * <ul>
         *     <li>@ref gpudb::admin_show_cluster_operations_true
         *         "admin_show_cluster_operations_true"
         *     <li>@ref gpudb::admin_show_cluster_operations_false
         *         "admin_show_cluster_operations_false"
         * </ul>
         */
        bool rebalanceShardedData;

        /**
         * Version of the shard array that is (or was) being rebalanced to.
         * Each change to the shard array results in the version number
         * incrementing.
         */
        int64_t shardArrayVersion;

        /**
         * If this was an operation that included rebalancing sharded data, the
         * rebalancing-specific status of the operation.
         * Valid values are:
         * <ul>
         *     <li>@ref gpudb::admin_show_cluster_operations_NOT_STARTED
         *         "admin_show_cluster_operations_NOT_STARTED"
         *     <li>@ref gpudb::admin_show_cluster_operations_IN_PROGRESS
         *         "admin_show_cluster_operations_IN_PROGRESS"
         *     <li>@ref gpudb::admin_show_cluster_operations_INTERRUPTED
         *         "admin_show_cluster_operations_INTERRUPTED"
         *     <li>@ref gpudb::admin_show_cluster_operations_COMPLETED_OK
         *         "admin_show_cluster_operations_COMPLETED_OK"
         *     <li>@ref gpudb::admin_show_cluster_operations_ERROR
         *         "admin_show_cluster_operations_ERROR"
         * </ul>
         */
        std::string rebalanceShardedDataStatus;

        /**
         * Number of shards that will change as part of rebalance.
         */
        int32_t numShardsChanging;

        /**
         * Percentage of shard keys, and their associated data if applicable,
         * that have completed rebalancing.
         */
        int32_t shardedRebalancePercentComplete;

        /**
         * Additional information.
         */
        std::map<std::string, std::string> info;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::AdminShowClusterOperationsResponse>
    {
        static void encode(Encoder& e, const gpudb::AdminShowClusterOperationsResponse& v)
        {
            ::avro::encode(e, v.historyIndex);
            ::avro::encode(e, v.historySize);
            ::avro::encode(e, v.inProgress);
            ::avro::encode(e, v.startTime);
            ::avro::encode(e, v.endTime);
            ::avro::encode(e, v.endpoint);
            ::avro::encode(e, v.endpointSchema);
            ::avro::encode(e, v.overallStatus);
            ::avro::encode(e, v.userStopped);
            ::avro::encode(e, v.percentComplete);
            ::avro::encode(e, v.dryRun);
            ::avro::encode(e, v.messages);
            ::avro::encode(e, v.addRanks);
            ::avro::encode(e, v.addRanksStatus);
            ::avro::encode(e, v.ranksBeingAdded);
            ::avro::encode(e, v.rankHosts);
            ::avro::encode(e, v.addRanksPercentComplete);
            ::avro::encode(e, v.removeRanks);
            ::avro::encode(e, v.removeRanksStatus);
            ::avro::encode(e, v.ranksBeingRemoved);
            ::avro::encode(e, v.removeRanksPercentComplete);
            ::avro::encode(e, v.rebalance);
            ::avro::encode(e, v.rebalanceUnshardedData);
            ::avro::encode(e, v.rebalanceUnshardedDataStatus);
            ::avro::encode(e, v.unshardedRebalancePercentComplete);
            ::avro::encode(e, v.rebalanceShardedData);
            ::avro::encode(e, v.shardArrayVersion);
            ::avro::encode(e, v.rebalanceShardedDataStatus);
            ::avro::encode(e, v.numShardsChanging);
            ::avro::encode(e, v.shardedRebalancePercentComplete);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::AdminShowClusterOperationsResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.historyIndex);
                            break;

                        case 1:
                            ::avro::decode(d, v.historySize);
                            break;

                        case 2:
                            ::avro::decode(d, v.inProgress);
                            break;

                        case 3:
                            ::avro::decode(d, v.startTime);
                            break;

                        case 4:
                            ::avro::decode(d, v.endTime);
                            break;

                        case 5:
                            ::avro::decode(d, v.endpoint);
                            break;

                        case 6:
                            ::avro::decode(d, v.endpointSchema);
                            break;

                        case 7:
                            ::avro::decode(d, v.overallStatus);
                            break;

                        case 8:
                            ::avro::decode(d, v.userStopped);
                            break;

                        case 9:
                            ::avro::decode(d, v.percentComplete);
                            break;

                        case 10:
                            ::avro::decode(d, v.dryRun);
                            break;

                        case 11:
                            ::avro::decode(d, v.messages);
                            break;

                        case 12:
                            ::avro::decode(d, v.addRanks);
                            break;

                        case 13:
                            ::avro::decode(d, v.addRanksStatus);
                            break;

                        case 14:
                            ::avro::decode(d, v.ranksBeingAdded);
                            break;

                        case 15:
                            ::avro::decode(d, v.rankHosts);
                            break;

                        case 16:
                            ::avro::decode(d, v.addRanksPercentComplete);
                            break;

                        case 17:
                            ::avro::decode(d, v.removeRanks);
                            break;

                        case 18:
                            ::avro::decode(d, v.removeRanksStatus);
                            break;

                        case 19:
                            ::avro::decode(d, v.ranksBeingRemoved);
                            break;

                        case 20:
                            ::avro::decode(d, v.removeRanksPercentComplete);
                            break;

                        case 21:
                            ::avro::decode(d, v.rebalance);
                            break;

                        case 22:
                            ::avro::decode(d, v.rebalanceUnshardedData);
                            break;

                        case 23:
                            ::avro::decode(d, v.rebalanceUnshardedDataStatus);
                            break;

                        case 24:
                            ::avro::decode(d, v.unshardedRebalancePercentComplete);
                            break;

                        case 25:
                            ::avro::decode(d, v.rebalanceShardedData);
                            break;

                        case 26:
                            ::avro::decode(d, v.shardArrayVersion);
                            break;

                        case 27:
                            ::avro::decode(d, v.rebalanceShardedDataStatus);
                            break;

                        case 28:
                            ::avro::decode(d, v.numShardsChanging);
                            break;

                        case 29:
                            ::avro::decode(d, v.shardedRebalancePercentComplete);
                            break;

                        case 30:
                            ::avro::decode(d, v.info);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.historyIndex);
                ::avro::decode(d, v.historySize);
                ::avro::decode(d, v.inProgress);
                ::avro::decode(d, v.startTime);
                ::avro::decode(d, v.endTime);
                ::avro::decode(d, v.endpoint);
                ::avro::decode(d, v.endpointSchema);
                ::avro::decode(d, v.overallStatus);
                ::avro::decode(d, v.userStopped);
                ::avro::decode(d, v.percentComplete);
                ::avro::decode(d, v.dryRun);
                ::avro::decode(d, v.messages);
                ::avro::decode(d, v.addRanks);
                ::avro::decode(d, v.addRanksStatus);
                ::avro::decode(d, v.ranksBeingAdded);
                ::avro::decode(d, v.rankHosts);
                ::avro::decode(d, v.addRanksPercentComplete);
                ::avro::decode(d, v.removeRanks);
                ::avro::decode(d, v.removeRanksStatus);
                ::avro::decode(d, v.ranksBeingRemoved);
                ::avro::decode(d, v.removeRanksPercentComplete);
                ::avro::decode(d, v.rebalance);
                ::avro::decode(d, v.rebalanceUnshardedData);
                ::avro::decode(d, v.rebalanceUnshardedDataStatus);
                ::avro::decode(d, v.unshardedRebalancePercentComplete);
                ::avro::decode(d, v.rebalanceShardedData);
                ::avro::decode(d, v.shardArrayVersion);
                ::avro::decode(d, v.rebalanceShardedDataStatus);
                ::avro::decode(d, v.numShardsChanging);
                ::avro::decode(d, v.shardedRebalancePercentComplete);
                ::avro::decode(d, v.info);
            }
        }
    };
} // end namespace avro

#endif // __ADMIN_SHOW_CLUSTER_OPERATIONS_H__
