/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __CREATE_GRAPH_H__
#define __CREATE_GRAPH_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #createGraph(const CreateGraphRequest&) const}.
     * <p>
     * Creates a new graph network using given nodes, edges, weights, and
     * restrictions.

     * IMPORTANT: It's highly recommended that you review the <a
     * href="../../graph_solver/network_graph_solver.html"
     * target="_top">Network Graphs & Solvers</a> concepts documentation, the
     * <a href="../../graph_solver/examples/graph_rest_guide.html"
     * target="_top">Graph REST Tutorial</a>, and/or some <a
     * href="../../graph_solver/examples.html" target="_top">graph examples</a>
     * before using this endpoint.
     */
    struct CreateGraphRequest
    {

        /**
         * Constructs a CreateGraphRequest object with default parameter
         * values.
         */
        CreateGraphRequest() :
            graphName(std::string()),
            directedGraph(bool()),
            nodes(std::vector<std::string>()),
            edges(std::vector<std::string>()),
            weights(std::vector<std::string>()),
            restrictions(std::vector<std::string>()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a CreateGraphRequest object with the specified
         * parameters.
         * 
         * @param[in] graphName_  Name of the graph resource to generate.
         * @param[in] directedGraph_  If set to @a true, the graph will be
         *                            directed. If set to @a false, the graph
         *                            will not be directed. Consult <a
         *                            href="../../graph_solver/network_graph_solver.html#directed-graphs"
         *                            target="_top">Directed Graphs</a> for
         *                            more details.
         *                            <ul>
         *                                    <li> gpudb::create_graph_true
         *                                    <li> gpudb::create_graph_false
         *                            </ul>
         *                            The default value is
         *                            gpudb::create_graph_true.
         * @param[in] nodes_  Nodes represent fundamental topological units of
         *                    a graph. Nodes must be specified using <a
         *                    href="../../graph_solver/network_graph_solver.html#identifiers"
         *                    target="_top">identifiers</a>; identifiers are
         *                    grouped as <a
         *                    href="../../graph_solver/network_graph_solver.html#id-combos"
         *                    target="_top">combinations</a>. Identifiers can
         *                    be used with existing column names, e.g.,
         *                    'table.column AS NODE_ID', expressions, e.g.,
         *                    'ST_MAKEPOINT(column1, column2) AS
         *                    NODE_WKTPOINT', or raw values, e.g., '{9, 10, 11}
         *                    AS NODE_ID'. If using raw values in an identifier
         *                    combination, the number of values specified must
         *                    match across the combination.
         * @param[in] edges_  Edges represent the required fundamental
         *                    topological unit of a graph that typically
         *                    connect nodes. Edges must be specified using <a
         *                    href="../../graph_solver/network_graph_solver.html#identifiers"
         *                    target="_top">identifiers</a>; identifiers are
         *                    grouped as <a
         *                    href="../../graph_solver/network_graph_solver.html#id-combos"
         *                    target="_top">combinations</a>. Identifiers can
         *                    be used with existing column names, e.g.,
         *                    'table.column AS EDGE_ID', expressions, e.g.,
         *                    'SUBSTR(column, 1, 6) AS EDGE_NODE1_NAME', or raw
         *                    values, e.g., "{'family', 'coworker'} AS
         *                    EDGE_LABEL". If using raw values in an identifier
         *                    combination, the number of values specified must
         *                    match across the combination.
         * @param[in] weights_  Weights represent a method of informing the
         *                      graph solver of the cost of including a given
         *                      edge in a solution. Weights must be specified
         *                      using <a
         *                      href="../../graph_solver/network_graph_solver.html#identifiers"
         *                      target="_top">identifiers</a>; identifiers are
         *                      grouped as <a
         *                      href="../../graph_solver/network_graph_solver.html#id-combos"
         *                      target="_top">combinations</a>. Identifiers can
         *                      be used with existing column names, e.g.,
         *                      'table.column AS WEIGHTS_EDGE_ID', expressions,
         *                      e.g., 'ST_LENGTH(wkt) AS
         *                      WEIGHTS_VALUESPECIFIED', or raw values, e.g.,
         *                      '{4, 15} AS WEIGHTS_VALUESPECIFIED'. If using
         *                      raw values in an identifier combination, the
         *                      number of values specified must match across
         *                      the combination.
         * @param[in] restrictions_  Restrictions represent a method of
         *                           informing the graph solver which edges
         *                           and/or nodes should be ignored for the
         *                           solution. Restrictions must be specified
         *                           using <a
         *                           href="../../graph_solver/network_graph_solver.html#identifiers"
         *                           target="_top">identifiers</a>; identifiers
         *                           are grouped as <a
         *                           href="../../graph_solver/network_graph_solver.html#id-combos"
         *                           target="_top">combinations</a>.
         *                           Identifiers can be used with existing
         *                           column names, e.g., 'table.column AS
         *                           RESTRICTIONS_EDGE_ID', expressions, e.g.,
         *                           'column/2 AS RESTRICTIONS_VALUECOMPARED',
         *                           or raw values, e.g., '{0, 0, 0, 1} AS
         *                           RESTRICTIONS_ONOFFCOMPARED'. If using raw
         *                           values in an identifier combination, the
         *                           number of values specified must match
         *                           across the combination.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::create_graph_restriction_threshold_value:
         *                      Value-based restriction comparison. Any node or
         *                      edge with a RESTRICTIONS_VALUECOMPARED value
         *                      greater than the @a restriction_threshold_value
         *                      will not be included in the graph.
         *                              <li>
         *                      gpudb::create_graph_merge_tolerance: If node
         *                      geospatial positions are input (e.g., WKTPOINT,
         *                      X, Y), determines the minimum separation
         *                      allowed between unique nodes. If nodes are
         *                      within the tolerance of each other, they will
         *                      be merged as a single node.  The default value
         *                      is '1.0E-4'.
         *                              <li> gpudb::create_graph_min_x: Minimum
         *                      x (longitude) value for spatial graph
         *                      associations.  The default value is '-180.0'.
         *                              <li> gpudb::create_graph_max_x: Maximum
         *                      x (longitude) value for spatial graph
         *                      associations.  The default value is '180.0'.
         *                              <li> gpudb::create_graph_min_y: Minimum
         *                      y (latitude) value for spatial graph
         *                      associations.  The default value is '-90.0'.
         *                              <li> gpudb::create_graph_max_y: Maximum
         *                      y (latitude) value for spatial graph
         *                      associations.  The default value is '90.0'.
         *                              <li> gpudb::create_graph_recreate: If
         *                      set to @a true and the graph (using @a
         *                      graphName) already exists, the graph is deleted
         *                      and recreated.
         *                      <ul>
         *                              <li> gpudb::create_graph_true
         *                              <li> gpudb::create_graph_false
         *                      </ul>
         *                      The default value is gpudb::create_graph_false.
         *                              <li> gpudb::create_graph_modify: If set
         *                      to @a true and @a true and if the graph (using
         *                      @a graphName) already exists, the graph is
         *                      updated with these components.
         *                      <ul>
         *                              <li> gpudb::create_graph_true
         *                              <li> gpudb::create_graph_false
         *                      </ul>
         *                      The default value is gpudb::create_graph_false.
         *                              <li>
         *                      gpudb::create_graph_export_create_results: If
         *                      set to @a true, returns the graph topology in
         *                      the response as arrays.
         *                      <ul>
         *                              <li> gpudb::create_graph_true
         *                              <li> gpudb::create_graph_false
         *                      </ul>
         *                      The default value is gpudb::create_graph_false.
         *                              <li>
         *                      gpudb::create_graph_enable_graph_draw: If set
         *                      to @a true, adds a 'EDGE_WKTLINE' column
         *                      identifier to the specified @a graph_table so
         *                      the graph can be viewed via WMS; for social and
         *                      non-geospatial graphs, the 'EDGE_WKTLINE'
         *                      column identifier will be populated with
         *                      spatial coordinates derived from a flattening
         *                      layout algorithm so the graph can still be
         *                      viewed.
         *                      <ul>
         *                              <li> gpudb::create_graph_true
         *                              <li> gpudb::create_graph_false
         *                      </ul>
         *                      The default value is gpudb::create_graph_false.
         *                              <li> gpudb::create_graph_save_persist:
         *                      If set to @a true, the graph will be saved in
         *                      the persist directory (see the <a
         *                      href="../../config/index.html"
         *                      target="_top">config reference</a> for more
         *                      information). If set to @a false, the graph
         *                      will be removed when the graph server is
         *                      shutdown.
         *                      <ul>
         *                              <li> gpudb::create_graph_true
         *                              <li> gpudb::create_graph_false
         *                      </ul>
         *                      The default value is gpudb::create_graph_false.
         *                              <li> gpudb::create_graph_sync_db: If
         *                      set to @a true and @a save_persist is set to @a
         *                      true, the graph will be fully reconstructed
         *                      upon a database restart and be updated to align
         *                      with any source table(s) updates made since the
         *                      creation of the graph. If dynamic graph updates
         *                      upon table inserts are desired, use @a
         *                      add_table_monitor instead.
         *                      <ul>
         *                              <li> gpudb::create_graph_true
         *                              <li> gpudb::create_graph_false
         *                      </ul>
         *                      The default value is gpudb::create_graph_false.
         *                              <li>
         *                      gpudb::create_graph_add_table_monitor: Adds a
         *                      table monitor to every table used in the
         *                      creation of the graph; this table monitor will
         *                      trigger the graph to update dynamically upon
         *                      inserts to the source table(s). Note that upon
         *                      database restart, if @a save_persist is also
         *                      set to @a true, the graph will be fully
         *                      reconstructed and the table monitors will be
         *                      reattached. For more details on table monitors,
         *                      see /create/tablemonitor.
         *                      <ul>
         *                              <li> gpudb::create_graph_true
         *                              <li> gpudb::create_graph_false
         *                      </ul>
         *                      The default value is gpudb::create_graph_false.
         *                              <li> gpudb::create_graph_graph_table:
         *                      If the @a graph_table name is NOT left blank,
         *                      the created graph is also created as a table
         *                      with the given name and following identifier
         *                      columns: 'EDGE_ID', 'EDGE_NODE1_ID',
         *                      'EDGE_NODE2_ID'. If left blank, no table is
         *                      created.  The default value is ''.
         *                      </ul>
         * 
         */
        CreateGraphRequest(const std::string& graphName_, const bool directedGraph_, const std::vector<std::string>& nodes_, const std::vector<std::string>& edges_, const std::vector<std::string>& weights_, const std::vector<std::string>& restrictions_, const std::map<std::string, std::string>& options_):
            graphName( graphName_ ),
            directedGraph( directedGraph_ ),
            nodes( nodes_ ),
            edges( edges_ ),
            weights( weights_ ),
            restrictions( restrictions_ ),
            options( options_ )
        {
        }

        std::string graphName;
        bool directedGraph;
        std::vector<std::string> nodes;
        std::vector<std::string> edges;
        std::vector<std::string> weights;
        std::vector<std::string> restrictions;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::CreateGraphRequest>
    {
        static void encode(Encoder& e, const gpudb::CreateGraphRequest& v)
        {
            ::avro::encode(e, v.graphName);
            ::avro::encode(e, v.directedGraph);
            ::avro::encode(e, v.nodes);
            ::avro::encode(e, v.edges);
            ::avro::encode(e, v.weights);
            ::avro::encode(e, v.restrictions);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::CreateGraphRequest& v)
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
                            ::avro::decode(d, v.directedGraph);
                            break;

                        case 2:
                            ::avro::decode(d, v.nodes);
                            break;

                        case 3:
                            ::avro::decode(d, v.edges);
                            break;

                        case 4:
                            ::avro::decode(d, v.weights);
                            break;

                        case 5:
                            ::avro::decode(d, v.restrictions);
                            break;

                        case 6:
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
                ::avro::decode(d, v.directedGraph);
                ::avro::decode(d, v.nodes);
                ::avro::decode(d, v.edges);
                ::avro::decode(d, v.weights);
                ::avro::decode(d, v.restrictions);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #createGraph(const CreateGraphRequest&) const}.
     * <p>
     * Creates a new graph network using given nodes, edges, weights, and
     * restrictions.

     * IMPORTANT: It's highly recommended that you review the <a
     * href="../../graph_solver/network_graph_solver.html"
     * target="_top">Network Graphs & Solvers</a> concepts documentation, the
     * <a href="../../graph_solver/examples/graph_rest_guide.html"
     * target="_top">Graph REST Tutorial</a>, and/or some <a
     * href="../../graph_solver/examples.html" target="_top">graph examples</a>
     * before using this endpoint.
     */
    struct CreateGraphResponse
    {

        /**
         * Constructs a CreateGraphResponse object with default parameter
         * values.
         */
        CreateGraphResponse() :
            numNodes(int64_t()),
            numEdges(int64_t()),
            edgesIds(std::vector<int64_t>()),
            info(std::map<std::string, std::string>())
        {
        }

        int64_t numNodes;
        int64_t numEdges;
        std::vector<int64_t> edgesIds;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::CreateGraphResponse>
    {
        static void encode(Encoder& e, const gpudb::CreateGraphResponse& v)
        {
            ::avro::encode(e, v.numNodes);
            ::avro::encode(e, v.numEdges);
            ::avro::encode(e, v.edgesIds);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::CreateGraphResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.numNodes);
                            break;

                        case 1:
                            ::avro::decode(d, v.numEdges);
                            break;

                        case 2:
                            ::avro::decode(d, v.edgesIds);
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
                ::avro::decode(d, v.numNodes);
                ::avro::decode(d, v.numEdges);
                ::avro::decode(d, v.edgesIds);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
