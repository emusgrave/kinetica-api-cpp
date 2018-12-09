/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __SOLVE_GRAPH_H__
#define __SOLVE_GRAPH_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #solveGraph(const SolveGraphRequest&) const}.
     * <p>
     * Solves an existing graph for a type of problem (e.g., shortest path,
     * page rank, travelling salesman, etc.) using source nodes, destination
     * nodes, and additional, optional weights and restrictions. See <a
     * href="../../graph_solver/network_graph_solver.html"
     * target="_top">Network Graph Solvers</a> for more information.
     */
    struct SolveGraphRequest
    {

        /**
         * Constructs a SolveGraphRequest object with default parameter values.
         */
        SolveGraphRequest() :
            graphName(std::string()),
            weightsOnEdges(std::vector<std::string>()),
            restrictions(std::vector<std::string>()),
            solverType(std::string()),
            sourceNodeId(int64_t()),
            destinationNodeIds(std::vector<int64_t>()),
            nodeType(std::string()),
            sourceNode(std::string()),
            destinationNodes(std::vector<std::string>()),
            solutionTable(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a SolveGraphRequest object with the specified parameters.
         * 
         * @param[in] graphName_  Name of the graph resource to solve.
         * @param[in] weightsOnEdges_  Additional weights to apply to the edges
         *                             of an existing graph. Example format:
         *                             'table.column AS WEIGHTS_EDGE_ID'. Any
         *                             provided weights will be added (in the
         *                             case of 'WEIGHTS_VALUESPECIFIED') to or
         *                             multiplied with (in the case of
         *                             'WEIGHTS_FACTORSPECIFIED') the existing
         *                             weight(s).
         * @param[in] restrictions_  Additional restrictions to apply to the
         *                           nodes/edges of an existing graph. Example
         *                           format: 'table.column AS
         *                           RESTRICTIONS_NODE_ID'. If @a
         *                           remove_previous_restrictions is set to @a
         *                           true, any provided restrictions will
         *                           replace the existing restrictions. If @a
         *                           remove_previous_restrictions is set to @a
         *                           false, any provided weights will be added
         *                           (in the case of
         *                           'RESTRICTIONS_VALUECOMPARED') to or
         *                           replaced (in the case of
         *                           'RESTRICTIONS_ONOFFCOMPARED').
         * @param[in] solverType_  The type of solver to use for the graph.
         *                         <ul>
         *                                 <li>
         *                         gpudb::solve_graph_SHORTEST_PATH: Solves for
         *                         the optimal (shortest) path based on weights
         *                         and restrictions from one source to
         *                         destinations nodes. Also known as the
         *                         Dijkstra solver.
         *                                 <li> gpudb::solve_graph_PAGE_RANK:
         *                         Solves for the probability of each
         *                         destination node being visited based on the
         *                         links of the graph topology.
         *                                 <li> gpudb::solve_graph_CENTRALITY:
         *                         Solves for the degree of a node to depict
         *                         how many pairs of individuals that would
         *                         have to go through the node to reach one
         *                         another in the minimum number of hops. Also
         *                         known as betweenness.
         *                                 <li>
         *                         gpudb::solve_graph_MULTIPLE_ROUTING: Solves
         *                         for finding the minimum cost cumulative path
         *                         for a round-trip starting from the given
         *                         source and visiting each given destination
         *                         node once then returning to the source. Also
         *                         known as the travelling salesman problem.
         *                                 <li>
         *                         gpudb::solve_graph_INVERSE_SHORTEST_PATH:
         *                         Solves for finding the optimal path cost for
         *                         each destination node to route to the source
         *                         node. Also known as inverse Dijkstra or the
         *                         service man routing problem.
         *                                 <li>
         *                         gpudb::solve_graph_BACKHAUL_ROUTING: Solves
         *                         for optimal routes that connect remote asset
         *                         nodes to the fixed (backbone) asset nodes.
         *                         When @a BACKHAUL_ROUTING is invoked, the @a
         *                         destinationNodes or @a destinationNodeIds
         *                         array is used for both fixed and remote
         *                         asset nodes and the @a sourceNodeId
         *                         represents the number of fixed asset nodes
         *                         contained in @a destinationNodes / @a
         *                         destinationNodeIds.
         *                         </ul>
         *                         The default value is
         *                         gpudb::solve_graph_SHORTEST_PATH.
         * @param[in] sourceNodeId_  If @a nodeType is @a NODE_ID, the node ID
         *                           (integer) of the source (starting point)
         *                           for the graph solution. If the @a
         *                           solverType is set to @a BACKHAUL_ROUTING,
         *                           this number represents the number of fixed
         *                           asset nodes contained in @a
         *                           destinationNodes, e.g., if @a sourceNodeId
         *                           is set to 24, the first 24 nodes listed in
         *                           @a destinationNodes / @a
         *                           destinationNodeIds are the fixed asset
         *                           nodes and the rest of the nodes in the
         *                           array are remote assets.
         * @param[in] destinationNodeIds_  List of destination node indices, or
         *                                 indices for pageranks. If the @a
         *                                 solverType is set to @a
         *                                 BACKHAUL_ROUTING, it is the list of
         *                                 all fixed and remote asset nodes.
         * @param[in] nodeType_  Source and destination node identifier type.
         *                       <ul>
         *                               <li> gpudb::solve_graph_NODE_ID: The
         *                       graph's nodes were identified as integers,
         *                       e.g., 1234.
         *                               <li> gpudb::solve_graph_NODE_WKTPOINT:
         *                       The graph's nodes were identified as
         *                       geospatial coordinates, e.g., 'POINT(1.0
         *                       2.0)'.
         *                               <li> gpudb::solve_graph_NODE_NAME: The
         *                       graph's nodes were identified as strings,
         *                       e.g., 'Arlington'.
         *                       </ul>
         *                       The default value is
         *                       gpudb::solve_graph_NODE_ID.
         * @param[in] sourceNode_  If @a nodeType is @a NODE_WKTPOINT or @a
         *                         NODE_NAME, the node (string) of the source
         *                         (starting point) for the graph solution.
         * @param[in] destinationNodes_  If @a nodeType is @a NODE_WKTPOINT or
         *                               @a NODE_NAME, the list of destination
         *                               node or page rank indices (strings)
         *                               for the graph solution. If the @a
         *                               solverType is set to @a
         *                               BACKHAUL_ROUTING, it is the list of
         *                               all fixed and remote asset nodes. The
         *                               string type should be consistent with
         *                               the @a nodeType parameter.
         * @param[in] solutionTable_  Name of the table to store the solution.
         * @param[in] options_  Additional parameters
         *                      <ul>
         *                              <li>
         *                      gpudb::solve_graph_max_solution_radius: For @a
         *                      SHORTEST_PATH and @a INVERSE_SHORTEST_PATH
         *                      solvers only. Sets the maximum solution cost
         *                      radius, which ignores the @a destinationNodeIds
         *                      list and instead outputs the nodes within the
         *                      radius sorted by ascending cost. If set to
         *                      '0.0', the setting is ignored.
         *                              <li>
         *                      gpudb::solve_graph_max_solution_targets: For @a
         *                      SHORTEST_PATH and @a INVERSE_SHORTEST_PATH
         *                      solvers only. Sets the maximum number of
         *                      solution targets, which ignores the @a
         *                      destinationNodeIds list and instead outputs no
         *                      more than n number of nodes sorted by ascending
         *                      cost where n is equal to the setting value. If
         *                      set to 0, the setting is ignored.
         *                              <li>
         *                      gpudb::solve_graph_export_solve_results:
         *                      Returns solution results inside the @a
         *                      resultPerDestinationNode array in the response
         *                      if set to @a true.
         *                      <ul>
         *                              <li> gpudb::solve_graph_true
         *                              <li> gpudb::solve_graph_false
         *                      </ul>
         *                      The default value is gpudb::solve_graph_false.
         *                              <li>
         *                      gpudb::solve_graph_remove_previous_restrictions:
         *                      Ignore the restrictions applied to the graph
         *                      during the creation stage and only use the
         *                      restrictions specified in this request if set
         *                      to @a true.
         *                      <ul>
         *                              <li> gpudb::solve_graph_true
         *                              <li> gpudb::solve_graph_false
         *                      </ul>
         *                      The default value is gpudb::solve_graph_false.
         *                              <li>
         *                      gpudb::solve_graph_restriction_threshold_value:
         *                      Value-based restriction comparison. Any node or
         *                      edge with a RESTRICTIONS_VALUECOMPARED value
         *                      greater than the @a restriction_threshold_value
         *                      will not be included in the solution.
         *                      </ul>
         * 
         */
        SolveGraphRequest(const std::string& graphName_, const std::vector<std::string>& weightsOnEdges_, const std::vector<std::string>& restrictions_, const std::string& solverType_, const int64_t sourceNodeId_, const std::vector<int64_t>& destinationNodeIds_, const std::string& nodeType_, const std::string& sourceNode_, const std::vector<std::string>& destinationNodes_, const std::string& solutionTable_, const std::map<std::string, std::string>& options_):
            graphName( graphName_ ),
            weightsOnEdges( weightsOnEdges_ ),
            restrictions( restrictions_ ),
            solverType( solverType_ ),
            sourceNodeId( sourceNodeId_ ),
            destinationNodeIds( destinationNodeIds_ ),
            nodeType( nodeType_ ),
            sourceNode( sourceNode_ ),
            destinationNodes( destinationNodes_ ),
            solutionTable( solutionTable_ ),
            options( options_ )
        {
        }

        std::string graphName;
        std::vector<std::string> weightsOnEdges;
        std::vector<std::string> restrictions;
        std::string solverType;
        int64_t sourceNodeId;
        std::vector<int64_t> destinationNodeIds;
        std::string nodeType;
        std::string sourceNode;
        std::vector<std::string> destinationNodes;
        std::string solutionTable;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::SolveGraphRequest>
    {
        static void encode(Encoder& e, const gpudb::SolveGraphRequest& v)
        {
            ::avro::encode(e, v.graphName);
            ::avro::encode(e, v.weightsOnEdges);
            ::avro::encode(e, v.restrictions);
            ::avro::encode(e, v.solverType);
            ::avro::encode(e, v.sourceNodeId);
            ::avro::encode(e, v.destinationNodeIds);
            ::avro::encode(e, v.nodeType);
            ::avro::encode(e, v.sourceNode);
            ::avro::encode(e, v.destinationNodes);
            ::avro::encode(e, v.solutionTable);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::SolveGraphRequest& v)
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
                            ::avro::decode(d, v.weightsOnEdges);
                            break;

                        case 2:
                            ::avro::decode(d, v.restrictions);
                            break;

                        case 3:
                            ::avro::decode(d, v.solverType);
                            break;

                        case 4:
                            ::avro::decode(d, v.sourceNodeId);
                            break;

                        case 5:
                            ::avro::decode(d, v.destinationNodeIds);
                            break;

                        case 6:
                            ::avro::decode(d, v.nodeType);
                            break;

                        case 7:
                            ::avro::decode(d, v.sourceNode);
                            break;

                        case 8:
                            ::avro::decode(d, v.destinationNodes);
                            break;

                        case 9:
                            ::avro::decode(d, v.solutionTable);
                            break;

                        case 10:
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
                ::avro::decode(d, v.weightsOnEdges);
                ::avro::decode(d, v.restrictions);
                ::avro::decode(d, v.solverType);
                ::avro::decode(d, v.sourceNodeId);
                ::avro::decode(d, v.destinationNodeIds);
                ::avro::decode(d, v.nodeType);
                ::avro::decode(d, v.sourceNode);
                ::avro::decode(d, v.destinationNodes);
                ::avro::decode(d, v.solutionTable);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #solveGraph(const SolveGraphRequest&) const}.
     * <p>
     * Solves an existing graph for a type of problem (e.g., shortest path,
     * page rank, travelling salesman, etc.) using source nodes, destination
     * nodes, and additional, optional weights and restrictions. See <a
     * href="../../graph_solver/network_graph_solver.html"
     * target="_top">Network Graph Solvers</a> for more information.
     */
    struct SolveGraphResponse
    {

        /**
         * Constructs a SolveGraphResponse object with default parameter
         * values.
         */
        SolveGraphResponse() :
            result(bool()),
            resultPerDestinationNode(std::vector<float>()),
            info(std::map<std::string, std::string>())
        {
        }

        bool result;
        std::vector<float> resultPerDestinationNode;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::SolveGraphResponse>
    {
        static void encode(Encoder& e, const gpudb::SolveGraphResponse& v)
        {
            ::avro::encode(e, v.result);
            ::avro::encode(e, v.resultPerDestinationNode);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::SolveGraphResponse& v)
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
                            ::avro::decode(d, v.resultPerDestinationNode);
                            break;

                        case 2:
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
                ::avro::decode(d, v.resultPerDestinationNode);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
