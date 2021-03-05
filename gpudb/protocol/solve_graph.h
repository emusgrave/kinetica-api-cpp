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
     * nodes, and
     * additional, optional weights and restrictions.
     * <p>
     * IMPORTANT: It's highly recommended that you review the
     * <a href="../../../graph_solver/network_graph_solver/"
     * target="_top">Network Graphs & Solvers</a>
     * concepts documentation, the
     * <a href="../../../graph_solver/examples/graph_rest_guide/"
     * target="_top">Graph REST Tutorial</a>,
     * and/or some
     * <a href="../../../graph_solver/examples/#match-graph"
     * target="_top">/match/graph examples</a>
     * before using this endpoint.
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
            sourceNodes(std::vector<std::string>()),
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
         *                             of an existing
         *                             graph. Weights must be specified using
         *                             <a
         *                             href="../../../graph_solver/network_graph_solver/#identifiers"
         *                             target="_top">identifiers</a>;
         *                             identifiers are grouped as
         *                             <a
         *                             href="../../../graph_solver/network_graph_solver/#id-combos"
         *                             target="_top">combinations</a>.
         *                             Identifiers can be used with existing
         *                             column names, e.g.,
         *                             'table.column AS WEIGHTS_EDGE_ID',
         *                             expressions, e.g.,
         *                             'ST_LENGTH(wkt) AS
         *                             WEIGHTS_VALUESPECIFIED', or constant
         *                             values, e.g.,
         *                             '{4, 15, 2} AS WEIGHTS_VALUESPECIFIED'.
         *                             Any provided weights will be added
         *                             (in the case of
         *                             'WEIGHTS_VALUESPECIFIED') to or
         *                             multiplied with
         *                             (in the case of
         *                             'WEIGHTS_FACTORSPECIFIED') the existing
         *                             weight(s). If using
         *                             constant values in an identifier
         *                             combination, the number of values
         *                             specified
         *                             must match across the combination.
         * @param[in] restrictions_  Additional restrictions to apply to the
         *                           nodes/edges of an
         *                           existing graph. Restrictions must be
         *                           specified using
         *                           <a
         *                           href="../../../graph_solver/network_graph_solver/#identifiers"
         *                           target="_top">identifiers</a>;
         *                           identifiers are grouped as
         *                           <a
         *                           href="../../../graph_solver/network_graph_solver/#id-combos"
         *                           target="_top">combinations</a>.
         *                           Identifiers can be used with existing
         *                           column names, e.g.,
         *                           'table.column AS RESTRICTIONS_EDGE_ID',
         *                           expressions, e.g.,
         *                           'column/2 AS RESTRICTIONS_VALUECOMPARED',
         *                           or constant values, e.g.,
         *                           '{0, 0, 0, 1} AS
         *                           RESTRICTIONS_ONOFFCOMPARED'. If using
         *                           constant values in an
         *                           identifier combination, the number of
         *                           values specified must match across the
         *                           combination. If @a
         *                           remove_previous_restrictions is set
         *                           to @a true, any
         *                           provided restrictions will replace the
         *                           existing restrictions. If
         *                           @a remove_previous_restrictions is set to
         *                           @a false, any provided
         *                           restrictions will be added (in the case of
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
         *                         links of the graph topology. Weights are not
         *                         required to use this solver.
         *                                 <li>
         *                         gpudb::solve_graph_PROBABILITY_RANK: Solves
         *                         for the transitional probability (Hidden
         *                         Markov) for each node based on the weights
         *                         (probability assigned over given edges).
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
         *                                 <li> gpudb::solve_graph_ALLPATHS:
         *                         Solves for paths that would give costs
         *                         between max and min solution radia - Make
         *                         sure to limit by the 'max_solution_targets'
         *                         option. Min cost shoudl be >= shortest_path
         *                         cost.
         *                         </ul>
         *                         The default value is
         *                         gpudb::solve_graph_SHORTEST_PATH.
         * @param[in] sourceNodes_  It can be one of the nodal identifiers -
         *                          e.g: 'NODE_WKTPOINT' for source nodes. For
         *                          @a BACKHAUL_ROUTING, this list depicts the
         *                          fixed assets.
         * @param[in] destinationNodes_  It can be one of the nodal identifiers
         *                               - e.g: 'NODE_WKTPOINT' for destination
         *                               (target) nodes. For @a
         *                               BACKHAUL_ROUTING, this list depicts
         *                               the remote assets.
         * @param[in] solutionTable_  Name of the table to store the solution,
         *                            in [schema_name.]table_name format, using
         *                            standard <a
         *                            href="../../../concepts/tables/#table-name-resolution"
         *                            target="_top">name resolution rules</a>.
         * @param[in] options_  Additional parameters
         *                      <ul>
         *                              <li>
         *                      gpudb::solve_graph_max_solution_radius: For @a
         *                      SHORTEST_PATH and @a INVERSE_SHORTEST_PATH
         *                      solvers only. Sets the maximum solution cost
         *                      radius, which ignores the @a destinationNodes
         *                      list and instead outputs the nodes within the
         *                      radius sorted by ascending cost. If set to
         *                      '0.0', the setting is ignored.  The default
         *                      value is '0.0'.
         *                              <li>
         *                      gpudb::solve_graph_min_solution_radius: For @a
         *                      SHORTEST_PATH and @a INVERSE_SHORTEST_PATH
         *                      solvers only. Applicable only when @a
         *                      max_solution_radius is set. Sets the minimum
         *                      solution cost radius, which ignores the @a
         *                      destinationNodes list and instead outputs the
         *                      nodes within the radius sorted by ascending
         *                      cost. If set to '0.0', the setting is ignored.
         *                      The default value is '0.0'.
         *                              <li>
         *                      gpudb::solve_graph_max_solution_targets: For @a
         *                      SHORTEST_PATH and @a INVERSE_SHORTEST_PATH
         *                      solvers only. Sets the maximum number of
         *                      solution targets, which ignores the @a
         *                      destinationNodes list and instead outputs no
         *                      more than n number of nodes sorted by ascending
         *                      cost where n is equal to the setting value. If
         *                      set to 0, the setting is ignored.  The default
         *                      value is '0'.
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
         *                              <li>
         *                      gpudb::solve_graph_uniform_weights: When
         *                      specified, assigns the given value to all the
         *                      edges in the graph. Note that weights provided
         *                      in @a weightsOnEdges will override this value.
         *                              <li>
         *                      gpudb::solve_graph_left_turn_penalty: This will
         *                      add an additonal weight over the edges labelled
         *                      as 'left turn' if the 'add_turn' option
         *                      parameter of the /create/graph was invoked at
         *                      graph creation.  The default value is '0.0'.
         *                              <li>
         *                      gpudb::solve_graph_right_turn_penalty: This
         *                      will add an additonal weight over the edges
         *                      labelled as' right turn' if the 'add_turn'
         *                      option parameter of the /create/graph was
         *                      invoked at graph creation.  The default value
         *                      is '0.0'.
         *                              <li>
         *                      gpudb::solve_graph_intersection_penalty: This
         *                      will add an additonal weight over the edges
         *                      labelled as 'intersection' if the 'add_turn'
         *                      option parameter of the /create/graph was
         *                      invoked at graph creation.  The default value
         *                      is '0.0'.
         *                              <li>
         *                      gpudb::solve_graph_sharp_turn_penalty: This
         *                      will add an additonal weight over the edges
         *                      labelled as 'sharp turn' or 'u-turn' if the
         *                      'add_turn' option parameter of the
         *                      /create/graph was invoked at graph creation.
         *                      The default value is '0.0'.
         *                              <li> gpudb::solve_graph_num_best_paths:
         *                      For @a MULTIPLE_ROUTING solvers only; sets the
         *                      number of shortest paths computed from each
         *                      node. This is the heuristic criterion. Default
         *                      value of zero allows the number to be computed
         *                      automatically by the solver. The user may want
         *                      to override this parameter to speed-up the
         *                      solver.  The default value is '0'.
         *                              <li>
         *                      gpudb::solve_graph_max_num_combinations: For @a
         *                      MULTIPLE_ROUTING solvers only; sets the cap on
         *                      the combinatorial sequences generated. If the
         *                      default value of two millions is overridden to
         *                      a lesser value, it can potentially speed up the
         *                      solver.  The default value is '2000000'.
         *                              <li> gpudb::solve_graph_accurate_snaps:
         *                      Valid for single source destination pair solves
         *                      if points are described in NODE_WKTPOINT
         *                      identifier types: When true (default), it snaps
         *                      to the nearest node of the graph; otherwise, it
         *                      searches for the closest entity that could be
         *                      an edge. For the latter case (false), the
         *                      solver modifies the resulting cost with the
         *                      weights proportional to the ratio of the snap
         *                      location within the edge. This may be an
         *                      over-kill when the performance is considered
         *                      and the difference is well less than 1 percent.
         *                      In batch runs, since the performance is of
         *                      utmost importance, the option is always
         *                      considered 'false'.
         *                      <ul>
         *                              <li> gpudb::solve_graph_true
         *                              <li> gpudb::solve_graph_false
         *                      </ul>
         *                      The default value is gpudb::solve_graph_true.
         *                              <li>
         *                      gpudb::solve_graph_output_edge_path: If true
         *                      then concatenated edge ids will be added as the
         *                      EDGE path column of the solution table for each
         *                      source and target pair in shortest path solves.
         *                      <ul>
         *                              <li> gpudb::solve_graph_true
         *                              <li> gpudb::solve_graph_false
         *                      </ul>
         *                      The default value is gpudb::solve_graph_false.
         *                              <li>
         *                      gpudb::solve_graph_output_wkt_path: If true
         *                      then concatenated wkt line segments will be
         *                      added as the Wktroute column of the solution
         *                      table for each source and target pair in
         *                      shortest path solves.
         *                      <ul>
         *                              <li> gpudb::solve_graph_true
         *                              <li> gpudb::solve_graph_false
         *                      </ul>
         *                      The default value is gpudb::solve_graph_true.
         *                              <li> gpudb::solve_graph_server_id:
         *                      Indicates which graph server(s) to send the
         *                      request to. Default is to send to the server,
         *                      amongst those containing the corresponding
         *                      graph, that has the most computational
         *                      bandwidth. For SHORTEST_PATH solver type, the
         *                      input is split amongst the server containing
         *                      the corresponding graph.
         *                      </ul>
         * 
         */
        SolveGraphRequest(const std::string& graphName_, const std::vector<std::string>& weightsOnEdges_, const std::vector<std::string>& restrictions_, const std::string& solverType_, const std::vector<std::string>& sourceNodes_, const std::vector<std::string>& destinationNodes_, const std::string& solutionTable_, const std::map<std::string, std::string>& options_):
            graphName( graphName_ ),
            weightsOnEdges( weightsOnEdges_ ),
            restrictions( restrictions_ ),
            solverType( solverType_ ),
            sourceNodes( sourceNodes_ ),
            destinationNodes( destinationNodes_ ),
            solutionTable( solutionTable_ ),
            options( options_ )
        {
        }

        std::string graphName;
        std::vector<std::string> weightsOnEdges;
        std::vector<std::string> restrictions;
        std::string solverType;
        std::vector<std::string> sourceNodes;
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
            ::avro::encode(e, v.sourceNodes);
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
                            ::avro::decode(d, v.sourceNodes);
                            break;

                        case 5:
                            ::avro::decode(d, v.destinationNodes);
                            break;

                        case 6:
                            ::avro::decode(d, v.solutionTable);
                            break;

                        case 7:
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
                ::avro::decode(d, v.sourceNodes);
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
     * nodes, and
     * additional, optional weights and restrictions.
     * <p>
     * IMPORTANT: It's highly recommended that you review the
     * <a href="../../../graph_solver/network_graph_solver/"
     * target="_top">Network Graphs & Solvers</a>
     * concepts documentation, the
     * <a href="../../../graph_solver/examples/graph_rest_guide/"
     * target="_top">Graph REST Tutorial</a>,
     * and/or some
     * <a href="../../../graph_solver/examples/#match-graph"
     * target="_top">/match/graph examples</a>
     * before using this endpoint.
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
