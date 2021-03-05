/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __MATCH_GRAPH_H__
#define __MATCH_GRAPH_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #matchGraph(const MatchGraphRequest&) const}.
     * <p>
     * Matches a directed route implied by a given set of
     * latitude/longitude points to an existing underlying road network graph
     * using a
     * given solution type.

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
    struct MatchGraphRequest
    {

        /**
         * Constructs a MatchGraphRequest object with default parameter values.
         */
        MatchGraphRequest() :
            graphName(std::string()),
            samplePoints(std::vector<std::string>()),
            solveMethod(std::string()),
            solutionTable(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a MatchGraphRequest object with the specified parameters.
         * 
         * @param[in] graphName_  Name of the underlying geospatial graph
         *                        resource to match to using @a samplePoints.
         * @param[in] samplePoints_  Sample points used to match to an
         *                           underlying geospatial
         *                           graph. Sample points must be specified
         *                           using
         *                           <a
         *                           href="../../../graph_solver/network_graph_solver/#match-identifiers"
         *                           target="_top">identifiers</a>;
         *                           identifiers are grouped as
         *                           <a
         *                           href="../../../graph_solver/network_graph_solver/#match-combinations"
         *                           target="_top">combinations</a>.
         *                           Identifiers can be used with: existing
         *                           column names, e.g.,
         *                           'table.column AS SAMPLE_X'; expressions,
         *                           e.g.,
         *                           'ST_MAKEPOINT(table.x, table.y) AS
         *                           SAMPLE_WKTPOINT'; or constant values,
         *                           e.g.,
         *                           '{1, 2, 10} AS SAMPLE_TRIPID'.
         * @param[in] solveMethod_  The type of solver to use for graph
         *                          matching.
         *                          <ul>
         *                                  <li>
         *                          gpudb::match_graph_markov_chain: Matches @a
         *                          samplePoints to the graph using the Hidden
         *                          Markov Model (HMM)-based method, which
         *                          conducts a range-tree closest-edge search
         *                          to find the best combinations of possible
         *                          road segments (@a num_segments) for each
         *                          sample point to create the best route. The
         *                          route is secured one point at a time while
         *                          looking ahead @a chain_width number of
         *                          points, so the prediction is corrected
         *                          after each point. This solution type is the
         *                          most accurate but also the most
         *                          computationally intensive. Related options:
         *                          @a num_segments and @a chain_width.
         *                                  <li>
         *                          gpudb::match_graph_match_od_pairs: Matches
         *                          @a samplePoints to find the most probable
         *                          path between origin and destination pairs
         *                          with cost constraints.
         *                                  <li>
         *                          gpudb::match_graph_match_supply_demand:
         *                          Matches @a samplePoints to optimize
         *                          scheduling multiple supplies (trucks) with
         *                          varying sizes to varying demand sites with
         *                          varying capacities per depot. Related
         *                          options: @a partial_loading and @a
         *                          max_combinations.
         *                                  <li>
         *                          gpudb::match_graph_match_batch_solves:
         *                          Matches @a samplePoints source and
         *                          destination pairs for the shortest path
         *                          solves in batch mode.
         *                          </ul>
         *                          The default value is
         *                          gpudb::match_graph_markov_chain.
         * @param[in] solutionTable_  The name of the table used to store the
         *                            results, in [schema_name.]table_name
         *                            format, using standard <a
         *                            href="../../../concepts/tables/#table-name-resolution"
         *                            target="_top">name resolution rules</a>
         *                            and meeting <a
         *                            href="../../../concepts/tables/#table-naming-criteria"
         *                            target="_top">table naming criteria</a>.
         *                            This table contains a <a
         *                            href="../../../geospatial/geo_objects/#geospatial-tracks"
         *                            target="_top">track</a> of geospatial
         *                            points for the matched portion of the
         *                            graph, a track ID, and a score value.
         *                            Also outputs a details table containing a
         *                            trip ID (that matches the track ID), the
         *                            latitude/longitude pair, the timestamp
         *                            the point was recorded at, and an edge ID
         *                            corresponding to the matched road
         *                            segment. Must not be an existing table of
         *                            the same name.
         * @param[in] options_  Additional parameters
         *                      <ul>
         *                              <li> gpudb::match_graph_gps_noise: GPS
         *                      noise value (in meters) to remove redundant
         *                      sample points. Use -1 to disable noise
         *                      reduction. The default value accounts for 95%
         *                      of point variation (+ or -5 meters).  The
         *                      default value is '5.0'.
         *                              <li> gpudb::match_graph_num_segments:
         *                      Maximum number of potentially matching road
         *                      segments for each sample point. For the @a
         *                      markov_chain solver, the default is 3.  The
         *                      default value is '3'.
         *                              <li> gpudb::match_graph_search_radius:
         *                      Maximum search radius used when snapping sample
         *                      points onto potentially matching surrounding
         *                      segments. The default value corresponds to
         *                      approximately 100 meters.  The default value is
         *                      '0.001'.
         *                              <li> gpudb::match_graph_chain_width:
         *                      For the @a markov_chain solver only. Length of
         *                      the sample points lookahead window within the
         *                      Markov kernel; the larger the number, the more
         *                      accurate the solution.  The default value is
         *                      '9'.
         *                              <li> gpudb::match_graph_source:
         *                      Optional WKT starting point from @a
         *                      samplePoints for the solver. The default
         *                      behavior for the endpoint is to use time to
         *                      determine the starting point.  The default
         *                      value is 'POINT NULL'.
         *                              <li> gpudb::match_graph_destination:
         *                      Optional WKT ending point from @a samplePoints
         *                      for the solver. The default behavior for the
         *                      endpoint is to use time to determine the
         *                      destination point.  The default value is 'POINT
         *                      NULL'.
         *                              <li>
         *                      gpudb::match_graph_partial_loading: For the @a
         *                      match_supply_demand solver only. When false
         *                      (non-default), trucks do not off-load at the
         *                      demand (store) side if the remainder is less
         *                      than the store's need
         *                      <ul>
         *                              <li> gpudb::match_graph_true: Partial
         *                      off-loading at multiple store (demand)
         *                      locations
         *                              <li> gpudb::match_graph_false: No
         *                      partial off-loading allowed if supply is less
         *                      than the store's demand.
         *                      </ul>
         *                      The default value is gpudb::match_graph_true.
         *                              <li>
         *                      gpudb::match_graph_max_combinations: For the @a
         *                      match_supply_demand solver only. This is the
         *                      cutoff for the number of generated combinations
         *                      for sequencing the demand locations - can
         *                      increase this up to 2M.  The default value is
         *                      '10000'.
         *                              <li>
         *                      gpudb::match_graph_left_turn_penalty: This will
         *                      add an additonal weight over the edges labelled
         *                      as 'left turn' if the 'add_turn' option
         *                      parameter of the /create/graph was invoked at
         *                      graph creation.  The default value is '0.0'.
         *                              <li>
         *                      gpudb::match_graph_right_turn_penalty: This
         *                      will add an additonal weight over the edges
         *                      labelled as' right turn' if the 'add_turn'
         *                      option parameter of the /create/graph was
         *                      invoked at graph creation.  The default value
         *                      is '0.0'.
         *                              <li>
         *                      gpudb::match_graph_intersection_penalty: This
         *                      will add an additonal weight over the edges
         *                      labelled as 'intersection' if the 'add_turn'
         *                      option parameter of the /create/graph was
         *                      invoked at graph creation.  The default value
         *                      is '0.0'.
         *                              <li>
         *                      gpudb::match_graph_sharp_turn_penalty: This
         *                      will add an additonal weight over the edges
         *                      labelled as 'sharp turn' or 'u-turn' if the
         *                      'add_turn' option parameter of the
         *                      /create/graph was invoked at graph creation.
         *                      The default value is '0.0'.
         *                              <li>
         *                      gpudb::match_graph_aggregated_output: For the
         *                      @a match_supply_demand solver only. When it is
         *                      true (default), each record in the output table
         *                      shows a particular truck's scheduled cumulative
         *                      round trip path (MULTILINESTRING) and the
         *                      corresponding aggregated cost. Otherwise, each
         *                      record shows a single scheduled truck route
         *                      (LINESTRING) towards a particular demand
         *                      location (store id) with its corresponding
         *                      cost.  The default value is 'true'.
         *                              <li> gpudb::match_graph_output_tracks:
         *                      For the @a match_supply_demand solver only.
         *                      When it is true (non-default), the output will
         *                      be in tracks format for all the round trips of
         *                      each truck in which the timestamps are
         *                      populated directly from the edge weights
         *                      starting from their originating depots.  The
         *                      default value is 'false'.
         *                              <li> gpudb::match_graph_max_trip_cost:
         *                      For the @a match_supply_demand solver only. If
         *                      this constraint is greater than zero (default)
         *                      then the trucks will skip travelling from one
         *                      demand location to another if the cost between
         *                      them is greater than this number (distance or
         *                      time). Zero (default) value means no check is
         *                      performed.  The default value is '0.0'.
         *                              <li>
         *                      gpudb::match_graph_filter_folding_paths: For
         *                      the @a markov_chain solver only. When true
         *                      (non-default), the paths per sequence
         *                      combination is checked for folding over
         *                      patterns and can significantly increase the
         *                      execution time depending on the chain width and
         *                      the number of gps samples.
         *                      <ul>
         *                              <li> gpudb::match_graph_true: Filter
         *                      out the folded paths.
         *                              <li> gpudb::match_graph_false: Do not
         *                      filter out the folded paths
         *                      </ul>
         *                      The default value is gpudb::match_graph_false.
         *                              <li>
         *                      gpudb::match_graph_unit_unloading_cost: For the
         *                      @a match_supply_demand solver only. The unit
         *                      cost per load amount to be delivered. If this
         *                      value is greater than zero (default) then the
         *                      additional cost of this unit load multiplied by
         *                      the total dropped load will be added over to
         *                      the trip cost to the demand location.  The
         *                      default value is '0.0'.
         *                              <li>
         *                      gpudb::match_graph_max_num_threads: For the @a
         *                      markov_chain solver only. If specified (greater
         *                      than zero), the maximum number of threads will
         *                      not be greater than the specified value. It can
         *                      be lower due to the memory and the number cores
         *                      available. Default value of zero allows the
         *                      algorithm to set the maximal number of threads
         *                      within these constraints.  The default value is
         *                      '0'.
         *                              <li>
         *                      gpudb::match_graph_truck_service_limit: For the
         *                      @a match_supply_demand solver only. If
         *                      specified (greater than zero), any truck's
         *                      total service cost (distance or time) will be
         *                      limited by the specified value including
         *                      multiple rounds (if set).  The default value is
         *                      '0.0'.
         *                              <li>
         *                      gpudb::match_graph_enable_truck_reuse: For the
         *                      @a match_supply_demand solver only. If
         *                      specified (true), all trucks can be scheduled
         *                      for second rounds from their originating
         *                      depots.
         *                      <ul>
         *                              <li> gpudb::match_graph_true: Allows
         *                      reusing trucks for scheduling again.
         *                              <li> gpudb::match_graph_false: Trucks
         *                      are scheduled only once from their depots.
         *                      </ul>
         *                      The default value is gpudb::match_graph_false.
         *                              <li> gpudb::match_graph_server_id:
         *                      Indicates which graph server(s) to send the
         *                      request to. Default is to send to the server,
         *                      amongst those containing the corresponding
         *                      graph, that has the most computational
         *                      bandwidth.  The default value is ''.
         *                      </ul>
         * 
         */
        MatchGraphRequest(const std::string& graphName_, const std::vector<std::string>& samplePoints_, const std::string& solveMethod_, const std::string& solutionTable_, const std::map<std::string, std::string>& options_):
            graphName( graphName_ ),
            samplePoints( samplePoints_ ),
            solveMethod( solveMethod_ ),
            solutionTable( solutionTable_ ),
            options( options_ )
        {
        }

        std::string graphName;
        std::vector<std::string> samplePoints;
        std::string solveMethod;
        std::string solutionTable;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::MatchGraphRequest>
    {
        static void encode(Encoder& e, const gpudb::MatchGraphRequest& v)
        {
            ::avro::encode(e, v.graphName);
            ::avro::encode(e, v.samplePoints);
            ::avro::encode(e, v.solveMethod);
            ::avro::encode(e, v.solutionTable);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::MatchGraphRequest& v)
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
                            ::avro::decode(d, v.samplePoints);
                            break;

                        case 2:
                            ::avro::decode(d, v.solveMethod);
                            break;

                        case 3:
                            ::avro::decode(d, v.solutionTable);
                            break;

                        case 4:
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
                ::avro::decode(d, v.samplePoints);
                ::avro::decode(d, v.solveMethod);
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
     * #matchGraph(const MatchGraphRequest&) const}.
     * <p>
     * Matches a directed route implied by a given set of
     * latitude/longitude points to an existing underlying road network graph
     * using a
     * given solution type.

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
    struct MatchGraphResponse
    {

        /**
         * Constructs a MatchGraphResponse object with default parameter
         * values.
         */
        MatchGraphResponse() :
            result(bool()),
            matchScore(float()),
            info(std::map<std::string, std::string>())
        {
        }

        bool result;
        float matchScore;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::MatchGraphResponse>
    {
        static void encode(Encoder& e, const gpudb::MatchGraphResponse& v)
        {
            ::avro::encode(e, v.result);
            ::avro::encode(e, v.matchScore);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::MatchGraphResponse& v)
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
                            ::avro::decode(d, v.matchScore);
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
                ::avro::decode(d, v.matchScore);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
