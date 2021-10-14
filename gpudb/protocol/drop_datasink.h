/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __DROP_DATASINK_H__
#define __DROP_DATASINK_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #dropDatasink(const DropDatasinkRequest&) const}.
     * <p>
     * Drops an existing <a href="../../../concepts/data_sinks/"
     * target="_top">data sink</a>.
     * <p>
     * By default, if any <a href="../../../concepts/table_monitors"
     * target="_top">table monitors</a> use this
     * sink as a destination, the request will be blocked unless option
     * @a clear_table_monitors is
     * @a true.
     */
    struct DropDatasinkRequest
    {

        /**
         * Constructs a DropDatasinkRequest object with default parameter
         * values.
         */
        DropDatasinkRequest() :
            name(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a DropDatasinkRequest object with the specified
         * parameters.
         * 
         * @param[in] name_  Name of the data sink to be dropped. Must be an
         *                   existing data sink.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::drop_datasink_clear_table_monitors: If
         *                      @a true, any <a
         *                      href="../../../concepts/table_monitors/"
         *                      target="_top">table monitors</a> that use this
         *                      data sink will be cleared.
         *                      <ul>
         *                              <li> gpudb::drop_datasink_true
         *                              <li> gpudb::drop_datasink_false
         *                      </ul>
         *                      The default value is
         *                      gpudb::drop_datasink_false.
         *                      </ul>
         * 
         */
        DropDatasinkRequest(const std::string& name_, const std::map<std::string, std::string>& options_):
            name( name_ ),
            options( options_ )
        {
        }

        std::string name;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::DropDatasinkRequest>
    {
        static void encode(Encoder& e, const gpudb::DropDatasinkRequest& v)
        {
            ::avro::encode(e, v.name);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::DropDatasinkRequest& v)
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
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #dropDatasink(const DropDatasinkRequest&) const}.
     * <p>
     * Drops an existing <a href="../../../concepts/data_sinks/"
     * target="_top">data sink</a>.
     * <p>
     * By default, if any <a href="../../../concepts/table_monitors"
     * target="_top">table monitors</a> use this
     * sink as a destination, the request will be blocked unless option
     * @a clear_table_monitors is
     * @a true.
     */
    struct DropDatasinkResponse
    {

        /**
         * Constructs a DropDatasinkResponse object with default parameter
         * values.
         */
        DropDatasinkResponse() :
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
    template<> struct codec_traits<gpudb::DropDatasinkResponse>
    {
        static void encode(Encoder& e, const gpudb::DropDatasinkResponse& v)
        {
            ::avro::encode(e, v.name);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::DropDatasinkResponse& v)
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
