/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __ALTER_RESOURCE_GROUP_H__
#define __ALTER_RESOURCE_GROUP_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #alterResourceGroup(const AlterResourceGroupRequest&) const}.
     * <p>
     * Alters properties of exisiting resource group to facilitate resource
     * management.
     */
    struct AlterResourceGroupRequest
    {

        /**
         * Constructs an AlterResourceGroupRequest object with default
         * parameter values.
         */
        AlterResourceGroupRequest() :
            name(std::string()),
            tierAttributes(std::map<std::string, std::map<std::string, std::string> >()),
            ranking(std::string()),
            adjoiningResourceGroup(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an AlterResourceGroupRequest object with the specified
         * parameters.
         * 
         * @param[in] name_  Name of the group to be altered. Must be an
         *                   existing resource group name.
         * @param[in] tierAttributes_  Optional map containing tier names and
         *                             their respective attribute group limits.
         *                             The only valid attribute limit that can
         *                             be set is max_memory (in bytes) for the
         *                             VRAM & RAM tiers.
         *                             For instance, to set max VRAM capacity
         *                             to 1GB and max RAM capacity to 10GB,
         *                             use:
         *                             {'VRAM':{'max_memory':'1000000000'},
         *                             'RAM':{'max_memory':'10000000000'}}
         *                             <ul>
         *                                     <li>
         *                             gpudb::alter_resource_group_max_memory:
         *                             Maximum amount of memory usable in the
         *                             given tier at one time for this group.
         *                             </ul>
         * @param[in] ranking_  If the resource group ranking has to be
         *                      updated, this indicates the relative ranking
         *                      among existing resource groups where this
         *                      resource group will be moved. Left bank if not
         *                      changing the ranking.
         *                      <ul>
         *                              <li>
         *                      gpudb::alter_resource_group_empty_string
         *                              <li> gpudb::alter_resource_group_first
         *                              <li> gpudb::alter_resource_group_last
         *                              <li> gpudb::alter_resource_group_before
         *                              <li> gpudb::alter_resource_group_after
         *                      </ul>
         *                      The default value is
         *                      gpudb::alter_resource_group_empty_string.
         * @param[in] adjoiningResourceGroup_  If the ranking is 'before' or
         *                                     'after', this field indicates
         *                                     the resource group before or
         *                                     after which the current group
         *                                     will be placed otherwise left
         *                                     blank.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::alter_resource_group_max_cpu_concurrency:
         *                      Maximum number of simultaneous threads that
         *                      will be used to execute a request for this
         *                      group.
         *                              <li>
         *                      gpudb::alter_resource_group_max_scheduling_priority:
         *                      Maximum priority of a scheduled task for this
         *                      group.
         *                              <li>
         *                      gpudb::alter_resource_group_max_tier_priority:
         *                      Maximum priority of a tiered object for this
         *                      group.
         *                              <li>
         *                      gpudb::alter_resource_group_is_default_group:
         *                      If @a true, this request applies to the global
         *                      default resource group. It is an error for this
         *                      field to be @a true when the @a name field is
         *                      also populated.
         *                      <ul>
         *                              <li> gpudb::alter_resource_group_true
         *                              <li> gpudb::alter_resource_group_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::alter_resource_group_false.
         *                      </ul>
         * 
         */
        AlterResourceGroupRequest(const std::string& name_, const std::map<std::string, std::map<std::string, std::string> >& tierAttributes_, const std::string& ranking_, const std::string& adjoiningResourceGroup_, const std::map<std::string, std::string>& options_):
            name( name_ ),
            tierAttributes( tierAttributes_ ),
            ranking( ranking_ ),
            adjoiningResourceGroup( adjoiningResourceGroup_ ),
            options( options_ )
        {
        }

        std::string name;
        std::map<std::string, std::map<std::string, std::string> > tierAttributes;
        std::string ranking;
        std::string adjoiningResourceGroup;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AlterResourceGroupRequest>
    {
        static void encode(Encoder& e, const gpudb::AlterResourceGroupRequest& v)
        {
            ::avro::encode(e, v.name);
            ::avro::encode(e, v.tierAttributes);
            ::avro::encode(e, v.ranking);
            ::avro::encode(e, v.adjoiningResourceGroup);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AlterResourceGroupRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.name);
                            break;

                        case 1:
                            ::avro::decode(d, v.tierAttributes);
                            break;

                        case 2:
                            ::avro::decode(d, v.ranking);
                            break;

                        case 3:
                            ::avro::decode(d, v.adjoiningResourceGroup);
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
                ::avro::decode(d, v.name);
                ::avro::decode(d, v.tierAttributes);
                ::avro::decode(d, v.ranking);
                ::avro::decode(d, v.adjoiningResourceGroup);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #alterResourceGroup(const AlterResourceGroupRequest&) const}.
     * <p>
     * Alters properties of exisiting resource group to facilitate resource
     * management.
     */
    struct AlterResourceGroupResponse
    {

        /**
         * Constructs an AlterResourceGroupResponse object with default
         * parameter values.
         */
        AlterResourceGroupResponse() :
            name(std::string()),
            info(std::map<std::string, std::string>())
        {
        }

        std::string name;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AlterResourceGroupResponse>
    {
        static void encode(Encoder& e, const gpudb::AlterResourceGroupResponse& v)
        {
            ::avro::encode(e, v.name);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::AlterResourceGroupResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.name);
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
                ::avro::decode(d, v.name);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
