/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __SHOW_GRAPH_H__
#define __SHOW_GRAPH_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #showGraph(const ShowGraphRequest&) const}.
     * <p>
     * Shows information and characteristics of graphs that exist on the graph
     * server.
     */
    struct ShowGraphRequest
    {

        /**
         * Constructs a ShowGraphRequest object with default parameter values.
         */
        ShowGraphRequest() :
            graphName(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a ShowGraphRequest object with the specified parameters.
         * 
         * @param[in] graphName_  Name of the graph on which to retrieve
         *                        information. If left as the default value,
         *                        information about all graphs is returned.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::show_graph_show_original_request: If set
         *                      to @a true, the request that was originally
         *                      used to create the graph is also returned as
         *                      JSON.
         *                      <ul>
         *                              <li> gpudb::show_graph_true
         *                              <li> gpudb::show_graph_false
         *                      </ul>
         *                      The default value is gpudb::show_graph_true.
         *                              <li> gpudb::show_graph_server_id:
         *                      Indicates which graph server(s) to send the
         *                      request to. Default is to send to get
         *                      information about all the servers.
         *                      </ul>
         * 
         */
        ShowGraphRequest(const std::string& graphName_, const std::map<std::string, std::string>& options_):
            graphName( graphName_ ),
            options( options_ )
        {
        }

        std::string graphName;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::ShowGraphRequest>
    {
        static void encode(Encoder& e, const gpudb::ShowGraphRequest& v)
        {
            ::avro::encode(e, v.graphName);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::ShowGraphRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.graphName);
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
                ::avro::decode(d, v.graphName);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #showGraph(const ShowGraphRequest&) const}.
     * <p>
     * Shows information and characteristics of graphs that exist on the graph
     * server.
     */
    struct ShowGraphResponse
    {

        /**
         * Constructs a ShowGraphResponse object with default parameter values.
         */
        ShowGraphResponse() :
            result(bool()),
            load(std::vector<int32_t>()),
            memory(std::vector<int64_t>()),
            graphNames(std::vector<std::string>()),
            graphServerIds(std::vector<int32_t>()),
            directed(std::vector<bool>()),
            numNodes(std::vector<int64_t>()),
            numEdges(std::vector<int64_t>()),
            isPersisted(std::vector<bool>()),
            isSyncDb(std::vector<bool>()),
            hasInsertTableMonitor(std::vector<bool>()),
            originalRequest(std::vector<std::string>()),
            info(std::map<std::string, std::string>())
        {
        }

        bool result;
        std::vector<int32_t> load;
        std::vector<int64_t> memory;
        std::vector<std::string> graphNames;
        std::vector<int32_t> graphServerIds;
        std::vector<bool> directed;
        std::vector<int64_t> numNodes;
        std::vector<int64_t> numEdges;
        std::vector<bool> isPersisted;
        std::vector<bool> isSyncDb;
        std::vector<bool> hasInsertTableMonitor;
        std::vector<std::string> originalRequest;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::ShowGraphResponse>
    {
        static void encode(Encoder& e, const gpudb::ShowGraphResponse& v)
        {
            ::avro::encode(e, v.result);
            ::avro::encode(e, v.load);
            ::avro::encode(e, v.memory);
            ::avro::encode(e, v.graphNames);
            ::avro::encode(e, v.graphServerIds);
            ::avro::encode(e, v.directed);
            ::avro::encode(e, v.numNodes);
            ::avro::encode(e, v.numEdges);
            ::avro::encode(e, v.isPersisted);
            ::avro::encode(e, v.isSyncDb);
            ::avro::encode(e, v.hasInsertTableMonitor);
            ::avro::encode(e, v.originalRequest);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::ShowGraphResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.result);
                            break;

                        case 1:
                            ::avro::decode(d, v.load);
                            break;

                        case 2:
                            ::avro::decode(d, v.memory);
                            break;

                        case 3:
                            ::avro::decode(d, v.graphNames);
                            break;

                        case 4:
                            ::avro::decode(d, v.graphServerIds);
                            break;

                        case 5:
                            ::avro::decode(d, v.directed);
                            break;

                        case 6:
                            ::avro::decode(d, v.numNodes);
                            break;

                        case 7:
                            ::avro::decode(d, v.numEdges);
                            break;

                        case 8:
                            ::avro::decode(d, v.isPersisted);
                            break;

                        case 9:
                            ::avro::decode(d, v.isSyncDb);
                            break;

                        case 10:
                            ::avro::decode(d, v.hasInsertTableMonitor);
                            break;

                        case 11:
                            ::avro::decode(d, v.originalRequest);
                            break;

                        case 12:
                            ::avro::decode(d, v.info);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.result);
                ::avro::decode(d, v.load);
                ::avro::decode(d, v.memory);
                ::avro::decode(d, v.graphNames);
                ::avro::decode(d, v.graphServerIds);
                ::avro::decode(d, v.directed);
                ::avro::decode(d, v.numNodes);
                ::avro::decode(d, v.numEdges);
                ::avro::decode(d, v.isPersisted);
                ::avro::decode(d, v.isSyncDb);
                ::avro::decode(d, v.hasInsertTableMonitor);
                ::avro::decode(d, v.originalRequest);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
