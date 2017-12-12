/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __ADMIN_SHOW_SHARDS_H__
#define __ADMIN_SHOW_SHARDS_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #adminShowShards(const AdminShowShardsRequest&) const}.
     * <p>
     * Show the mapping of shards to the corresponding rank and tom.  The
     * response message contains list of 16384 (total number of shards in the
     * system) Rank and TOM numbers corresponding to each shard.
     */
    struct AdminShowShardsRequest
    {

        /**
         * Constructs an AdminShowShardsRequest object with default parameter
         * values.
         */
        AdminShowShardsRequest() :
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an AdminShowShardsRequest object with the specified
         * parameters.
         * 
         * @param[in] options_  Optional parameters.
         * 
         */
        AdminShowShardsRequest(const std::map<std::string, std::string>& options_):
            options( options_ )
        {
        }

        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AdminShowShardsRequest>
    {
        static void encode(Encoder& e, const gpudb::AdminShowShardsRequest& v)
        {
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AdminShowShardsRequest& v)
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
     * #adminShowShards(const AdminShowShardsRequest&) const}.
     * <p>
     * Show the mapping of shards to the corresponding rank and tom.  The
     * response message contains list of 16384 (total number of shards in the
     * system) Rank and TOM numbers corresponding to each shard.
     */
    struct AdminShowShardsResponse
    {

        /**
         * Constructs an AdminShowShardsResponse object with default parameter
         * values.
         */
        AdminShowShardsResponse() :
            version(int64_t()),
            rank(std::vector<int32_t>()),
            tom(std::vector<int32_t>())
        {
        }

        int64_t version;
        std::vector<int32_t> rank;
        std::vector<int32_t> tom;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AdminShowShardsResponse>
    {
        static void encode(Encoder& e, const gpudb::AdminShowShardsResponse& v)
        {
            ::avro::encode(e, v.version);
            ::avro::encode(e, v.rank);
            ::avro::encode(e, v.tom);
        }

        static void decode(Decoder& d, gpudb::AdminShowShardsResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.version);
                            break;

                        case 1:
                            ::avro::decode(d, v.rank);
                            break;

                        case 2:
                            ::avro::decode(d, v.tom);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.version);
                ::avro::decode(d, v.rank);
                ::avro::decode(d, v.tom);
            }
        }
    };
}

#endif