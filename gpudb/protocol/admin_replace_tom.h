/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __ADMIN_REPLACE_TOM_H__
#define __ADMIN_REPLACE_TOM_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #adminReplaceTom(const AdminReplaceTomRequest&) const}.
     * <p>
     * @private
     */
    struct AdminReplaceTomRequest
    {

        /**
         * @private
         * Constructs an AdminReplaceTomRequest object with default parameter
         * values.
         */
        AdminReplaceTomRequest() :
            oldRankTom(int64_t()),
            newRankTom(int64_t()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * @private
         * Constructs an AdminReplaceTomRequest object with the specified
         * parameters.
         * 
         * @param[in] oldRankTom_
         * @param[in] newRankTom_
         * @param[in] options_
         * 
         */
        AdminReplaceTomRequest(const int64_t oldRankTom_, const int64_t newRankTom_, const std::map<std::string, std::string>& options_):
            oldRankTom( oldRankTom_ ),
            newRankTom( newRankTom_ ),
            options( options_ )
        {
        }

        int64_t oldRankTom;
        int64_t newRankTom;
        std::map<std::string, std::string> options;
    };
}

    /**
     * @private
     */

namespace avro
{
    template<> struct codec_traits<gpudb::AdminReplaceTomRequest>
    {
        static void encode(Encoder& e, const gpudb::AdminReplaceTomRequest& v)
        {
            ::avro::encode(e, v.oldRankTom);
            ::avro::encode(e, v.newRankTom);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AdminReplaceTomRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.oldRankTom);
                            break;

                        case 1:
                            ::avro::decode(d, v.newRankTom);
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
                ::avro::decode(d, v.oldRankTom);
                ::avro::decode(d, v.newRankTom);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #adminReplaceTom(const AdminReplaceTomRequest&) const}.
     * <p>
     * @private
     */
    struct AdminReplaceTomResponse
    {

        /**
         * @private
         * Constructs an AdminReplaceTomResponse object with default parameter
         * values.
         */
        AdminReplaceTomResponse() :
            oldRankTom(int64_t()),
            newRankTom(int64_t()),
            info(std::map<std::string, std::string>())
        {
        }

        int64_t oldRankTom;
        int64_t newRankTom;
        std::map<std::string, std::string> info;
    };
}

    /**
     * @private
     */

namespace avro
{
    template<> struct codec_traits<gpudb::AdminReplaceTomResponse>
    {
        static void encode(Encoder& e, const gpudb::AdminReplaceTomResponse& v)
        {
            ::avro::encode(e, v.oldRankTom);
            ::avro::encode(e, v.newRankTom);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::AdminReplaceTomResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.oldRankTom);
                            break;

                        case 1:
                            ::avro::decode(d, v.newRankTom);
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
                ::avro::decode(d, v.oldRankTom);
                ::avro::decode(d, v.newRankTom);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
