/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __QUERY_GRAPH_H__
#define __QUERY_GRAPH_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #queryGraph(const QueryGraphRequest&) const}.
     * <p>
     * Employs a topological query on a network graph generated a-priori by
     * {@link #createGraph(const CreateGraphRequest&) const} and returns a
     * list of adjacent edge(s) or node(s),
     * also known as an adjacency list, depending on what's been provided to
     * the
     * endpoint; providing edges will return nodes and providing nodes will
     * return
     * edges.
     * <p>
     * To determine the node(s) or edge(s) adjacent to a value from a given
     * column,
     * provide a list of values to @a queries. This field can be populated with
     * column values from any table as long as the type is supported by the
     * given
     * identifier. See
     * <a href="../../../graph_solver/network_graph_solver/#query-identifiers"
     * target="_top">Query Identifiers</a>
     * for more information.
     * <p>
     * To return the adjacency list in the response, leave @a adjacencyTable
     * empty. To return the adjacency list in a table and not in the response,
     * provide
     * a value to @a adjacencyTable and set
     * @a export_query_results to
     * @a false. To return the
     * adjacency list both in a table and the response, provide a value to
     * @a adjacencyTable and set @a export_query_results
     * to @a true.
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
    struct QueryGraphRequest
    {

        /**
         * Constructs a QueryGraphRequest object with default parameter values.
         */
        QueryGraphRequest() :
            graphName(std::string()),
            queries(std::vector<std::string>()),
            restrictions(std::vector<std::string>()),
            adjacencyTable(std::string()),
            rings(int32_t()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a QueryGraphRequest object with the specified parameters.
         * 
         * @param[in] graphName_  Name of the graph resource to query.
         * @param[in] queries_  Nodes or edges to be queried specified using <a
         *                      href="../../../graph_solver/network_graph_solver/#query-identifiers"
         *                      target="_top">query identifiers</a>.
         *                      Identifiers can be used with existing column
         *                      names, e.g., 'table.column AS QUERY_NODE_ID',
         *                      raw values, e.g., '{0, 2} AS QUERY_NODE_ID', or
         *                      expressions, e.g., 'ST_MAKEPOINT(table.x,
         *                      table.y) AS QUERY_NODE_WKTPOINT'. Multiple
         *                      values can be provided as long as the same
         *                      identifier is used for all values. If using raw
         *                      values in an identifier combination, the number
         *                      of values specified must match across the
         *                      combination.
         * @param[in] restrictions_  Additional restrictions to apply to the
         *                           nodes/edges of an existing graph.
         *                           Restrictions must be specified using <a
         *                           href="../../../graph_solver/network_graph_solver/#identifiers"
         *                           target="_top">identifiers</a>; identifiers
         *                           are grouped as <a
         *                           href="../../../graph_solver/network_graph_solver/#id-combos"
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
         * @param[in] adjacencyTable_  Name of the table to store the resulting
         *                             adjacencies, in [schema_name.]table_name
         *                             format, using standard <a
         *                             href="../../../concepts/tables/#table-name-resolution"
         *                             target="_top">name resolution rules</a>
         *                             and meeting <a
         *                             href="../../../concepts/tables/#table-naming-criteria"
         *                             target="_top">table naming criteria</a>.
         *                             If left blank, the query results are
         *                             instead returned in the response even if
         *                             @a export_query_results is set to @a
         *                             false. If the 'QUERY_TARGET_NODE_LABEL'
         *                             <a
         *                             href="../../../graph_solver/network_graph_solver/#query-identifiers"
         *                             target="_top">query identifier</a> is
         *                             used in @a queries, then two additional
         *                             columns will be available: 'PATH_ID' and
         *                             'RING_ID'. See <a
         *                             href="../../../graph_solver/network_graph_solver/#using-labels"
         *                             target="_top">Using Labels</a> for more
         *                             information.
         * @param[in] rings_  Sets the number of rings around the node to query
         *                    for adjacency, with '1' being the edges directly
         *                    attached to the queried node. Also known as
         *                    number of hops. For example, if it is set to '2',
         *                    the edge(s) directly attached to the queried
         *                    node(s) will be returned; in addition, the
         *                    edge(s) attached to the node(s) attached to the
         *                    initial ring of edge(s) surrounding the queried
         *                    node(s) will be returned. If the value is set to
         *                    '0', any nodes that meet the criteria in @a
         *                    queries and @a restrictions will be returned.
         *                    This parameter is only applicable when querying
         *                    nodes.
         * @param[in] options_  Additional parameters
         *                      <ul>
         *                              <li>
         *                      gpudb::query_graph_force_undirected: If set to
         *                      @a true, all inbound edges and outbound edges
         *                      relative to the node will be returned. If set
         *                      to @a false, only outbound edges relative to
         *                      the node will be returned. This parameter is
         *                      only applicable if the queried graph @a
         *                      graphName is directed and when querying nodes.
         *                      Consult <a
         *                      href="../../../graph_solver/network_graph_solver/#directed-graphs"
         *                      target="_top">Directed Graphs</a> for more
         *                      details.
         *                      <ul>
         *                              <li> gpudb::query_graph_true
         *                              <li> gpudb::query_graph_false
         *                      </ul>
         *                      The default value is gpudb::query_graph_false.
         *                              <li> gpudb::query_graph_limit: When
         *                      specified, limits the number of query results.
         *                      Note that if the @a target_nodes_table is
         *                      provided, the size of the corresponding table
         *                      will be limited by the @a limit value.  The
         *                      default value is an empty std::map.
         *                              <li>
         *                      gpudb::query_graph_target_nodes_table: Name of
         *                      the table to store the list of the final nodes
         *                      reached during the traversal, in
         *                      [schema_name.]table_name format, using standard
         *                      <a
         *                      href="../../../concepts/tables/#table-name-resolution"
         *                      target="_top">name resolution rules</a> and
         *                      meeting <a
         *                      href="../../../concepts/tables/#table-naming-criteria"
         *                      target="_top">table naming criteria</a>.  If
         *                      this value is left as the default, the table
         *                      name will default to the @a adjacencyTable
         *                      value plus a '_nodes' suffix, e.g.,
         *                      '<adjacency_table_name>_nodes'.  The default
         *                      value is ''.
         *                              <li>
         *                      gpudb::query_graph_restriction_threshold_value:
         *                      Value-based restriction comparison. Any node or
         *                      edge with a RESTRICTIONS_VALUECOMPARED value
         *                      greater than the @a restriction_threshold_value
         *                      will not be included in the solution.
         *                              <li>
         *                      gpudb::query_graph_export_query_results:
         *                      Returns query results in the response. If set
         *                      to @a true, the @a adjacencyListIntArray (if
         *                      the query was based on IDs), @a
         *                      adjacencyListStringArray (if the query was
         *                      based on names), or @a adjacencyListWktArray
         *                      (if the query was based on WKTs) will be
         *                      populated with the results. If set to @a false,
         *                      none of the arrays will be populated.
         *                      <ul>
         *                              <li> gpudb::query_graph_true
         *                              <li> gpudb::query_graph_false
         *                      </ul>
         *                      The default value is gpudb::query_graph_false.
         *                              <li>
         *                      gpudb::query_graph_enable_graph_draw: If set to
         *                      @a true, adds a WKT-type column named
         *                      'QUERY_EDGE_WKTLINE' to the given @a
         *                      adjacencyTable and inputs WKT values from the
         *                      source graph (if available) or auto-generated
         *                      WKT values (if there are no WKT values in the
         *                      source graph). A subsequent call to the <a
         *                      href="../../../api/rest/wms_rest/"
         *                      target="_top">/wms</a> endpoint can then be
         *                      made to display the query results on a map.
         *                      <ul>
         *                              <li> gpudb::query_graph_true
         *                              <li> gpudb::query_graph_false
         *                      </ul>
         *                      The default value is gpudb::query_graph_false.
         *                              <li> gpudb::query_graph_and_labels: If
         *                      set to @a true, the result of the query has
         *                      entities that satisfy all of the target labels,
         *                      instead of any.
         *                      <ul>
         *                              <li> gpudb::query_graph_true
         *                              <li> gpudb::query_graph_false
         *                      </ul>
         *                      The default value is gpudb::query_graph_false.
         *                              <li>
         *                      gpudb::query_graph_export_solve_results:
         *                      Returns solution results inside the @a
         *                      adjacencyListIntArray array in the response if
         *                      set to @a true.
         *                      <ul>
         *                              <li> gpudb::query_graph_true
         *                              <li> gpudb::query_graph_false
         *                      </ul>
         *                      The default value is gpudb::query_graph_false.
         *                              <li> gpudb::query_graph_server_id:
         *                      Indicates which graph server(s) to send the
         *                      request to. Default is to send to the server,
         *                      amongst those containing the corresponding
         *                      graph, that has the most computational
         *                      bandwidth.
         *                      </ul>
         * 
         */
        QueryGraphRequest(const std::string& graphName_, const std::vector<std::string>& queries_, const std::vector<std::string>& restrictions_, const std::string& adjacencyTable_, const int32_t rings_, const std::map<std::string, std::string>& options_):
            graphName( graphName_ ),
            queries( queries_ ),
            restrictions( restrictions_ ),
            adjacencyTable( adjacencyTable_ ),
            rings( rings_ ),
            options( options_ )
        {
        }

        std::string graphName;
        std::vector<std::string> queries;
        std::vector<std::string> restrictions;
        std::string adjacencyTable;
        int32_t rings;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::QueryGraphRequest>
    {
        static void encode(Encoder& e, const gpudb::QueryGraphRequest& v)
        {
            ::avro::encode(e, v.graphName);
            ::avro::encode(e, v.queries);
            ::avro::encode(e, v.restrictions);
            ::avro::encode(e, v.adjacencyTable);
            ::avro::encode(e, v.rings);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::QueryGraphRequest& v)
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
                            ::avro::decode(d, v.queries);
                            break;

                        case 2:
                            ::avro::decode(d, v.restrictions);
                            break;

                        case 3:
                            ::avro::decode(d, v.adjacencyTable);
                            break;

                        case 4:
                            ::avro::decode(d, v.rings);
                            break;

                        case 5:
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
                ::avro::decode(d, v.queries);
                ::avro::decode(d, v.restrictions);
                ::avro::decode(d, v.adjacencyTable);
                ::avro::decode(d, v.rings);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #queryGraph(const QueryGraphRequest&) const}.
     * <p>
     * Employs a topological query on a network graph generated a-priori by
     * {@link #createGraph(const CreateGraphRequest&) const} and returns a
     * list of adjacent edge(s) or node(s),
     * also known as an adjacency list, depending on what's been provided to
     * the
     * endpoint; providing edges will return nodes and providing nodes will
     * return
     * edges.
     * <p>
     * To determine the node(s) or edge(s) adjacent to a value from a given
     * column,
     * provide a list of values to @a queries. This field can be populated with
     * column values from any table as long as the type is supported by the
     * given
     * identifier. See
     * <a href="../../../graph_solver/network_graph_solver/#query-identifiers"
     * target="_top">Query Identifiers</a>
     * for more information.
     * <p>
     * To return the adjacency list in the response, leave @a adjacencyTable
     * empty. To return the adjacency list in a table and not in the response,
     * provide
     * a value to @a adjacencyTable and set
     * @a export_query_results to
     * @a false. To return the
     * adjacency list both in a table and the response, provide a value to
     * @a adjacencyTable and set @a export_query_results
     * to @a true.
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
    struct QueryGraphResponse
    {

        /**
         * Constructs a QueryGraphResponse object with default parameter
         * values.
         */
        QueryGraphResponse() :
            result(bool()),
            adjacencyListIntArray(std::vector<int64_t>()),
            adjacencyListStringArray(std::vector<std::string>()),
            adjacencyListWktArray(std::vector<std::string>()),
            info(std::map<std::string, std::string>())
        {
        }

        bool result;
        std::vector<int64_t> adjacencyListIntArray;
        std::vector<std::string> adjacencyListStringArray;
        std::vector<std::string> adjacencyListWktArray;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::QueryGraphResponse>
    {
        static void encode(Encoder& e, const gpudb::QueryGraphResponse& v)
        {
            ::avro::encode(e, v.result);
            ::avro::encode(e, v.adjacencyListIntArray);
            ::avro::encode(e, v.adjacencyListStringArray);
            ::avro::encode(e, v.adjacencyListWktArray);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::QueryGraphResponse& v)
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
                            ::avro::decode(d, v.adjacencyListIntArray);
                            break;

                        case 2:
                            ::avro::decode(d, v.adjacencyListStringArray);
                            break;

                        case 3:
                            ::avro::decode(d, v.adjacencyListWktArray);
                            break;

                        case 4:
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
                ::avro::decode(d, v.adjacencyListIntArray);
                ::avro::decode(d, v.adjacencyListStringArray);
                ::avro::decode(d, v.adjacencyListWktArray);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
