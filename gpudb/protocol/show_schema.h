/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __SHOW_SCHEMA_H__
#define __SHOW_SCHEMA_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #showSchema(const ShowSchemaRequest&) const}.
     * <p>
     * Retrieves information about a <a href="../../concepts/schemas.html"
     * target="_top">schema</a> (or all schemas), as specified in @a
     * schemaName.
     */
    struct ShowSchemaRequest
    {

        /**
         * Constructs a ShowSchemaRequest object with default parameter values.
         */
        ShowSchemaRequest() :
            schemaName(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a ShowSchemaRequest object with the specified parameters.
         * 
         * @param[in] schemaName_  Name of the schema for which to retrieve the
         *                         information. If blank, then info for all
         *                         schemas is returned.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::show_schema_no_error_if_not_exists: If
         *                      @a false will return an error if the provided
         *                      @a schemaName does not exist. If @a true then
         *                      it will return an empty result if the provided
         *                      @a schemaName does not exist.
         *                      <ul>
         *                              <li> gpudb::show_schema_true
         *                              <li> gpudb::show_schema_false
         *                      </ul>
         *                      The default value is gpudb::show_schema_false.
         *                      </ul>
         * 
         */
        ShowSchemaRequest(const std::string& schemaName_, const std::map<std::string, std::string>& options_):
            schemaName( schemaName_ ),
            options( options_ )
        {
        }

        std::string schemaName;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::ShowSchemaRequest>
    {
        static void encode(Encoder& e, const gpudb::ShowSchemaRequest& v)
        {
            ::avro::encode(e, v.schemaName);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::ShowSchemaRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.schemaName);
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
                ::avro::decode(d, v.schemaName);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #showSchema(const ShowSchemaRequest&) const}.
     * <p>
     * Retrieves information about a <a href="../../concepts/schemas.html"
     * target="_top">schema</a> (or all schemas), as specified in @a
     * schemaName.
     */
    struct ShowSchemaResponse
    {

        /**
         * Constructs a ShowSchemaResponse object with default parameter
         * values.
         */
        ShowSchemaResponse() :
            schemaName(std::string()),
            schemaNames(std::vector<std::string>()),
            schemaTables(std::vector<std::vector<std::string> >()),
            additionalInfo(std::vector<std::map<std::string, std::string> >()),
            info(std::map<std::string, std::string>())
        {
        }

        std::string schemaName;
        std::vector<std::string> schemaNames;
        std::vector<std::vector<std::string> > schemaTables;
        std::vector<std::map<std::string, std::string> > additionalInfo;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::ShowSchemaResponse>
    {
        static void encode(Encoder& e, const gpudb::ShowSchemaResponse& v)
        {
            ::avro::encode(e, v.schemaName);
            ::avro::encode(e, v.schemaNames);
            ::avro::encode(e, v.schemaTables);
            ::avro::encode(e, v.additionalInfo);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::ShowSchemaResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.schemaName);
                            break;

                        case 1:
                            ::avro::decode(d, v.schemaNames);
                            break;

                        case 2:
                            ::avro::decode(d, v.schemaTables);
                            break;

                        case 3:
                            ::avro::decode(d, v.additionalInfo);
                            break;

                        case 4:
                            ::avro::decode(d, v.info);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.schemaName);
                ::avro::decode(d, v.schemaNames);
                ::avro::decode(d, v.schemaTables);
                ::avro::decode(d, v.additionalInfo);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
