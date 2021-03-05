/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __IMPORT_MODEL_H__
#define __IMPORT_MODEL_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #importModel(const ImportModelRequest&) const}.
     * <p>
     * @private
     */
    struct ImportModelRequest
    {

        /**
         * @private
         * Constructs an ImportModelRequest object with default parameter
         * values.
         */
        ImportModelRequest() :
            modelName(std::string()),
            registryName(std::string()),
            container(std::string()),
            runFunction(std::string()),
            modelType(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * @private
         * Constructs an ImportModelRequest object with the specified
         * parameters.
         * 
         * @param[in] modelName_
         * @param[in] registryName_
         * @param[in] container_
         * @param[in] runFunction_
         * @param[in] modelType_
         * @param[in] options_
         *                      <ul>
         *                              <li> gpudb::import_model_memory_limit:
         *                      The default value is ''.
         *                      </ul>
         * 
         */
        ImportModelRequest(const std::string& modelName_, const std::string& registryName_, const std::string& container_, const std::string& runFunction_, const std::string& modelType_, const std::map<std::string, std::string>& options_):
            modelName( modelName_ ),
            registryName( registryName_ ),
            container( container_ ),
            runFunction( runFunction_ ),
            modelType( modelType_ ),
            options( options_ )
        {
        }

        std::string modelName;
        std::string registryName;
        std::string container;
        std::string runFunction;
        std::string modelType;
        std::map<std::string, std::string> options;
    };
}

    /**
     * @private
     */

namespace avro
{
    template<> struct codec_traits<gpudb::ImportModelRequest>
    {
        static void encode(Encoder& e, const gpudb::ImportModelRequest& v)
        {
            ::avro::encode(e, v.modelName);
            ::avro::encode(e, v.registryName);
            ::avro::encode(e, v.container);
            ::avro::encode(e, v.runFunction);
            ::avro::encode(e, v.modelType);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::ImportModelRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.modelName);
                            break;

                        case 1:
                            ::avro::decode(d, v.registryName);
                            break;

                        case 2:
                            ::avro::decode(d, v.container);
                            break;

                        case 3:
                            ::avro::decode(d, v.runFunction);
                            break;

                        case 4:
                            ::avro::decode(d, v.modelType);
                            break;

                        case 5:
                            ::avro::decode(d, v.options);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.modelName);
                ::avro::decode(d, v.registryName);
                ::avro::decode(d, v.container);
                ::avro::decode(d, v.runFunction);
                ::avro::decode(d, v.modelType);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #importModel(const ImportModelRequest&) const}.
     * <p>
     * @private
     */
    struct ImportModelResponse
    {

        /**
         * @private
         * Constructs an ImportModelResponse object with default parameter
         * values.
         */
        ImportModelResponse() :
            modelName(std::string()),
            entityId(int32_t()),
            info(std::map<std::string, std::string>())
        {
        }

        std::string modelName;
        int32_t entityId;
        std::map<std::string, std::string> info;
    };
}

    /**
     * @private
     */

namespace avro
{
    template<> struct codec_traits<gpudb::ImportModelResponse>
    {
        static void encode(Encoder& e, const gpudb::ImportModelResponse& v)
        {
            ::avro::encode(e, v.modelName);
            ::avro::encode(e, v.entityId);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::ImportModelResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.modelName);
                            break;

                        case 1:
                            ::avro::decode(d, v.entityId);
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
                ::avro::decode(d, v.modelName);
                ::avro::decode(d, v.entityId);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
