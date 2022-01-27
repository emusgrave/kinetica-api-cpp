/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __SHOW_RESOURCE_GROUPS_H__
#define __SHOW_RESOURCE_GROUPS_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #showResourceGroups(const ShowResourceGroupsRequest&) const}.
     * <p>
     * Requests resource group properties.
     * Returns detailed information about the requested resource groups.
     */
    struct ShowResourceGroupsRequest
    {

        /**
         * Constructs a ShowResourceGroupsRequest object with default parameter
         * values.
         */
        ShowResourceGroupsRequest() :
            names(std::vector<std::string>()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a ShowResourceGroupsRequest object with the specified
         * parameters.
         * 
         * @param[in] names_  List of names of groups to be shown. A single
         *                    entry with an empty string returns all groups.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::show_resource_groups_show_default_values:
         *                      If @a true include values of fields that are
         *                      based on the default resource group.
         *                      <ul>
         *                              <li> gpudb::show_resource_groups_true
         *                              <li> gpudb::show_resource_groups_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::show_resource_groups_true.
         *                              <li>
         *                      gpudb::show_resource_groups_show_default_group:
         *                      If @a true include the default and system
         *                      resource groups in the response. This value
         *                      defaults to false if an explicit list of group
         *                      names is provided, and true otherwise.
         *                      <ul>
         *                              <li> gpudb::show_resource_groups_true
         *                              <li> gpudb::show_resource_groups_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::show_resource_groups_true.
         *                              <li>
         *                      gpudb::show_resource_groups_show_tier_usage: If
         *                      @a true include the resource group usage on the
         *                      worker ranks in the response.
         *                      <ul>
         *                              <li> gpudb::show_resource_groups_true
         *                              <li> gpudb::show_resource_groups_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::show_resource_groups_false.
         *                      </ul>
         * 
         */
        ShowResourceGroupsRequest(const std::vector<std::string>& names_, const std::map<std::string, std::string>& options_):
            names( names_ ),
            options( options_ )
        {
        }

        std::vector<std::string> names;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::ShowResourceGroupsRequest>
    {
        static void encode(Encoder& e, const gpudb::ShowResourceGroupsRequest& v)
        {
            ::avro::encode(e, v.names);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::ShowResourceGroupsRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.names);
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
                ::avro::decode(d, v.names);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #showResourceGroups(const ShowResourceGroupsRequest&) const}.
     * <p>
     * Requests resource group properties.
     * Returns detailed information about the requested resource groups.
     */
    struct ShowResourceGroupsResponse
    {

        /**
         * Constructs a ShowResourceGroupsResponse object with default
         * parameter values.
         */
        ShowResourceGroupsResponse() :
            groups(std::vector<std::map<std::string, std::string> >()),
            rankUsage(std::map<std::string, std::string>()),
            info(std::map<std::string, std::string>())
        {
        }

        std::vector<std::map<std::string, std::string> > groups;
        std::map<std::string, std::string> rankUsage;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::ShowResourceGroupsResponse>
    {
        static void encode(Encoder& e, const gpudb::ShowResourceGroupsResponse& v)
        {
            ::avro::encode(e, v.groups);
            ::avro::encode(e, v.rankUsage);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::ShowResourceGroupsResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.groups);
                            break;

                        case 1:
                            ::avro::decode(d, v.rankUsage);
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
                ::avro::decode(d, v.groups);
                ::avro::decode(d, v.rankUsage);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
