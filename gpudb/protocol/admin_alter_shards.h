/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __ADMIN_ALTER_SHARDS_H__
#define __ADMIN_ALTER_SHARDS_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #adminAlterShards(const AdminAlterShardsRequest&) const}.
     * <p>
     * @private
     */
    struct AdminAlterShardsRequest
    {

        /**
         * @private
         * Constructs an AdminAlterShardsRequest object with default parameter
         * values.
         */
        AdminAlterShardsRequest() :
            version(int64_t()),
            useIndex(bool()),
            rank(std::vector<int32_t>()),
            tom(std::vector<int32_t>()),
            index(std::vector<int32_t>()),
            backupMapList(std::vector<int32_t>()),
            backupMapValues(std::vector<std::vector<int32_t> >()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * @private
         * Constructs an AdminAlterShardsRequest object with the specified
         * parameters.
         * 
         * @param[in] version_
         * @param[in] useIndex_
         * @param[in] rank_
         * @param[in] tom_
         * @param[in] index_
         * @param[in] backupMapList_
         * @param[in] backupMapValues_
         * @param[in] options_
         * 
         */
        AdminAlterShardsRequest(const int64_t version_, const bool useIndex_, const std::vector<int32_t>& rank_, const std::vector<int32_t>& tom_, const std::vector<int32_t>& index_, const std::vector<int32_t>& backupMapList_, const std::vector<std::vector<int32_t> >& backupMapValues_, const std::map<std::string, std::string>& options_):
            version( version_ ),
            useIndex( useIndex_ ),
            rank( rank_ ),
            tom( tom_ ),
            index( index_ ),
            backupMapList( backupMapList_ ),
            backupMapValues( backupMapValues_ ),
            options( options_ )
        {
        }

        int64_t version;
        bool useIndex;
        std::vector<int32_t> rank;
        std::vector<int32_t> tom;
        std::vector<int32_t> index;
        std::vector<int32_t> backupMapList;
        std::vector<std::vector<int32_t> > backupMapValues;
        std::map<std::string, std::string> options;
    };
}

    /**
     * @private
     */

namespace avro
{
    template<> struct codec_traits<gpudb::AdminAlterShardsRequest>
    {
        static void encode(Encoder& e, const gpudb::AdminAlterShardsRequest& v)
        {
            ::avro::encode(e, v.version);
            ::avro::encode(e, v.useIndex);
            ::avro::encode(e, v.rank);
            ::avro::encode(e, v.tom);
            ::avro::encode(e, v.index);
            ::avro::encode(e, v.backupMapList);
            ::avro::encode(e, v.backupMapValues);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AdminAlterShardsRequest& v)
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
                            ::avro::decode(d, v.useIndex);
                            break;

                        case 2:
                            ::avro::decode(d, v.rank);
                            break;

                        case 3:
                            ::avro::decode(d, v.tom);
                            break;

                        case 4:
                            ::avro::decode(d, v.index);
                            break;

                        case 5:
                            ::avro::decode(d, v.backupMapList);
                            break;

                        case 6:
                            ::avro::decode(d, v.backupMapValues);
                            break;

                        case 7:
                            ::avro::decode(d, v.options);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.version);
                ::avro::decode(d, v.useIndex);
                ::avro::decode(d, v.rank);
                ::avro::decode(d, v.tom);
                ::avro::decode(d, v.index);
                ::avro::decode(d, v.backupMapList);
                ::avro::decode(d, v.backupMapValues);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #adminAlterShards(const AdminAlterShardsRequest&) const}.
     * <p>
     * @private
     */
    struct AdminAlterShardsResponse
    {

        /**
         * @private
         * Constructs an AdminAlterShardsResponse object with default parameter
         * values.
         */
        AdminAlterShardsResponse() :
            version(int64_t()),
            info(std::map<std::string, std::string>())
        {
        }

        int64_t version;
        std::map<std::string, std::string> info;
    };
}

    /**
     * @private
     */

namespace avro
{
    template<> struct codec_traits<gpudb::AdminAlterShardsResponse>
    {
        static void encode(Encoder& e, const gpudb::AdminAlterShardsResponse& v)
        {
            ::avro::encode(e, v.version);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::AdminAlterShardsResponse& v)
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
                            ::avro::decode(d, v.info);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.version);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif