/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __ADMIN_SWITCHOVER_H__
#define __ADMIN_SWITCHOVER_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #adminSwitchover(const AdminSwitchoverRequest&) const}.
     * <p>
     * Manually switchover one or more processes to another host. Individual
     * ranks or entire hosts may be moved to another host.
     */
    struct AdminSwitchoverRequest
    {

        /**
         * Constructs an AdminSwitchoverRequest object with default parameter
         * values.
         */
        AdminSwitchoverRequest() :
            processes(std::vector<std::string>()),
            destinations(std::vector<std::string>()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an AdminSwitchoverRequest object with the specified
         * parameters.
         * 
         * @param[in] processes_  Indicates the process identifier to
         *                        switchover to another host. Options are
         *                        'hostN' and 'rankN' where 'N' corresponds to
         *                        the number associated with a host or rank in
         *                        the <a href="../../../config/#network"
         *                        target="_top">Network</a> section of the
         *                        gpudb.conf file, e.g., 'host[N].address' or
         *                        'rank[N].host'. If 'hostN' is provided, all
         *                        processes on that host will be moved to
         *                        another host. Each entry in this array will
         *                        be switched over to the corresponding host
         *                        entry at the same index in @a destinations.
         * @param[in] destinations_  Indicates to which host to switchover each
         *                           corresponding process given in @a
         *                           processes. Each index must be specified as
         *                           'hostN' where 'N' corresponds to the
         *                           number associated with a host or rank in
         *                           the <a href="../../../config/#network"
         *                           target="_top">Network</a> section of the
         *                           gpudb.conf file, e.g., 'host[N].address'.
         *                           Each entry in this array will receive the
         *                           corresponding process entry at the same
         *                           index in @a processes.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li> gpudb::admin_switchover_dry_run:
         *                      If set to @a true, only validation checks will
         *                      be performed. Nothing is switched over.
         *                      <ul>
         *                              <li> gpudb::admin_switchover_true
         *                              <li> gpudb::admin_switchover_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::admin_switchover_false.
         *                      </ul>
         * 
         */
        AdminSwitchoverRequest(const std::vector<std::string>& processes_, const std::vector<std::string>& destinations_, const std::map<std::string, std::string>& options_):
            processes( processes_ ),
            destinations( destinations_ ),
            options( options_ )
        {
        }

        std::vector<std::string> processes;
        std::vector<std::string> destinations;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AdminSwitchoverRequest>
    {
        static void encode(Encoder& e, const gpudb::AdminSwitchoverRequest& v)
        {
            ::avro::encode(e, v.processes);
            ::avro::encode(e, v.destinations);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AdminSwitchoverRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.processes);
                            break;

                        case 1:
                            ::avro::decode(d, v.destinations);
                            break;

                        case 2:
                            ::avro::decode(d, v.options);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.processes);
                ::avro::decode(d, v.destinations);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #adminSwitchover(const AdminSwitchoverRequest&) const}.
     * <p>
     * Manually switchover one or more processes to another host. Individual
     * ranks or entire hosts may be moved to another host.
     */
    struct AdminSwitchoverResponse
    {

        /**
         * Constructs an AdminSwitchoverResponse object with default parameter
         * values.
         */
        AdminSwitchoverResponse() :
            info(std::map<std::string, std::string>())
        {
        }

        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AdminSwitchoverResponse>
    {
        static void encode(Encoder& e, const gpudb::AdminSwitchoverResponse& v)
        {
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::AdminSwitchoverResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.info);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
