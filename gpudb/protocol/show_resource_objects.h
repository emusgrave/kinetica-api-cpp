/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __SHOW_RESOURCE_OBJECTS_H__
#define __SHOW_RESOURCE_OBJECTS_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #showResourceObjects(const ShowResourceObjectsRequest&) const}.
     * <p>
     * Returns information about the internal sub-components (tiered objects)
     * which use resources of the system. The request can either return results
     * from
     * actively used objects (default) or it can be used to query the status of
     * the
     * objects of a given list of tables.
     * Returns detailed information about the requested resource objects.
     */
    struct ShowResourceObjectsRequest
    {

        /**
         * Constructs a ShowResourceObjectsRequest object with default
         * parameter values.
         */
        ShowResourceObjectsRequest() :
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a ShowResourceObjectsRequest object with the specified
         * parameters.
         * 
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::show_resource_objects_tiers:
         *                      Comma-separated list of tiers to query, leave
         *                      blank for all tiers.
         *                              <li>
         *                      gpudb::show_resource_objects_expression: An
         *                      expression to filter the returned objects.
         *                      Expression is
         *                      limited to the following operators:
         *                      =,!=,<,<=,>,>=,+,-,*,AND,OR,LIKE. For details
         *                      see
         *                      <a href="../../../concepts/expressions/"
         *                      target="_top">Expressions</a>. To use a more
         *                      complex expression, query the
         *                      ki_catalog.ki_tiered_objects table directly.
         *                              <li>
         *                      gpudb::show_resource_objects_order_by: Single
         *                      column to be sorted by as well as the sort
         *                      direction, e.g., 'size asc'.
         *                      <ul>
         *                              <li> gpudb::show_resource_objects_size
         *                              <li> gpudb::show_resource_objects_id
         *                              <li>
         *                      gpudb::show_resource_objects_priority
         *                              <li> gpudb::show_resource_objects_tier
         *                              <li>
         *                      gpudb::show_resource_objects_evictable
         *                              <li>
         *                      gpudb::show_resource_objects_owner_resource_group
         *                      </ul>
         *                              <li>
         *                      gpudb::show_resource_objects_limit: An integer
         *                      indicating the maximum number of results to be
         *                      returned, per rank, or (-1) to indicate that
         *                      the maximum number of results allowed by the
         *                      server
         *                      should be returned.  The number of records
         *                      returned will never exceed the server's own
         *                      limit,
         *                      defined by the <a
         *                      href="../../../config/#config-main-general"
         *                      target="_top">max_get_records_size</a>
         *                      parameter in the server
         *                      configuration.  The default value is '100'.
         *                              <li>
         *                      gpudb::show_resource_objects_table_names:
         *                      Comma-separated list of tables to restrict the
         *                      results to. Use '*' to show all tables.
         *                      </ul>
         * 
         */
        ShowResourceObjectsRequest(const std::map<std::string, std::string>& options_):
            options( options_ )
        {
        }

        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::ShowResourceObjectsRequest>
    {
        static void encode(Encoder& e, const gpudb::ShowResourceObjectsRequest& v)
        {
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::ShowResourceObjectsRequest& v)
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
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #showResourceObjects(const ShowResourceObjectsRequest&) const}.
     * <p>
     * Returns information about the internal sub-components (tiered objects)
     * which use resources of the system. The request can either return results
     * from
     * actively used objects (default) or it can be used to query the status of
     * the
     * objects of a given list of tables.
     * Returns detailed information about the requested resource objects.
     */
    struct ShowResourceObjectsResponse
    {

        /**
         * Constructs a ShowResourceObjectsResponse object with default
         * parameter values.
         */
        ShowResourceObjectsResponse() :
            rankObjects(std::map<std::string, std::string>()),
            info(std::map<std::string, std::string>())
        {
        }

        std::map<std::string, std::string> rankObjects;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::ShowResourceObjectsResponse>
    {
        static void encode(Encoder& e, const gpudb::ShowResourceObjectsResponse& v)
        {
            ::avro::encode(e, v.rankObjects);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::ShowResourceObjectsResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.rankObjects);
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
                ::avro::decode(d, v.rankObjects);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif