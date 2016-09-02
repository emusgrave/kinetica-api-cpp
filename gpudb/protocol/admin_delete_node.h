/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __ADMIN_DELETE_NODE_H__
#define __ADMIN_DELETE_NODE_H__

    /**
     * @private
     */

namespace gpudb
{

    /**
     * @private
     * A set of input parameters for {@link
     * #adminDeleteNode(const AdminDeleteNodeRequest&) const}.
     * <p>
     */
    struct AdminDeleteNodeRequest
    {

        /**
         * @private
         * Constructs an AdminDeleteNodeRequest object with default parameter
         * values.
         */
        AdminDeleteNodeRequest() :
            rank(int32_t()),
            authorization(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * @private
         * Constructs an AdminDeleteNodeRequest object with the specified
         * parameters.
         * 
         * @param[in] rank
         * @param[in] authorization
         * @param[in] options
         * 
         */
        AdminDeleteNodeRequest(const int32_t rank, const std::string& authorization, const std::map<std::string, std::string>& options):
            rank(rank),
            authorization(authorization),
            options(options)
        {
        }

    /**
     * @private
     */

        int32_t rank;
        std::string authorization;
        std::map<std::string, std::string> options;
    };
}

    /**
     * @private
     */

namespace avro
{
    template<> struct codec_traits<gpudb::AdminDeleteNodeRequest>
    {
        static void encode(Encoder& e, const gpudb::AdminDeleteNodeRequest& v)
        {
            ::avro::encode(e, v.rank);
            ::avro::encode(e, v.authorization);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AdminDeleteNodeRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.rank);
                            break;

                        case 1:
                            ::avro::decode(d, v.authorization);
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
                ::avro::decode(d, v.rank);
                ::avro::decode(d, v.authorization);
                ::avro::decode(d, v.options);
            }
        }
    };
}

    /**
     * @private
     */

namespace gpudb
{

    /**
     * @private
     * A set of output parameters for {@link
     * #adminDeleteNode(const AdminDeleteNodeRequest&) const}.
     * <p>
     */
    struct AdminDeleteNodeResponse
    {

        /**
         * @private
         * Constructs an AdminDeleteNodeResponse object with default parameter
         * values.
         */
        AdminDeleteNodeResponse() :
            rank(int32_t()),
            message(std::vector<std::string>())
        {
        }

    /**
     * @private
     */

        int32_t rank;
        std::vector<std::string> message;
    };
}

    /**
     * @private
     */

namespace avro
{
    template<> struct codec_traits<gpudb::AdminDeleteNodeResponse>
    {
        static void encode(Encoder& e, const gpudb::AdminDeleteNodeResponse& v)
        {
            ::avro::encode(e, v.rank);
            ::avro::encode(e, v.message);
        }

        static void decode(Decoder& d, gpudb::AdminDeleteNodeResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.rank);
                            break;

                        case 1:
                            ::avro::decode(d, v.message);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.rank);
                ::avro::decode(d, v.message);
            }
        }
    };
}

#endif