/*
 *  This file was autogenerated by the Kinetica schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __ALTER_SCHEMA_H__
#define __ALTER_SCHEMA_H__

namespace gpudb
{
    /**
     * A set of parameters for @ref
     * GPUdb::alterSchema(const AlterSchemaRequest&) const
     * "GPUdb::alterSchema".
     *
     * Used to change the name of a SQL-style <a
     * href="../../../concepts/schemas/" target="_top">schema</a>, specified in
     * @ref schemaName.
     */
    struct AlterSchemaRequest
    {
        /**
         * Constructs an AlterSchemaRequest object with default parameters.
         */
        AlterSchemaRequest() :
            schemaName(std::string()),
            action(std::string()),
            value(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an AlterSchemaRequest object with the specified
         * parameters.
         *
         * @param[in] schemaName_  Name of the schema to be altered.
         * @param[in] action_  Modification operation to be applied.
         *                     Supported values:
         *                     <ul>
         *                         <li>@ref gpudb::alter_schema_add_comment
         *                             "alter_schema_add_comment": Adds a
         *                             comment describing the schema
         *                         <li>@ref gpudb::alter_schema_rename_schema
         *                             "alter_schema_rename_schema": Renames a
         *                             schema to @a value_. Has the same naming
         *                             restrictions as <a
         *                             href="../../../concepts/tables/"
         *                             target="_top">tables</a>.
         *                     </ul>
         * @param[in] value_  The value of the modification, depending on @a
         *                    action_.  For now the only value of @a action_ is
         *                    @ref gpudb::alter_schema_rename_schema
         *                    "rename_schema".  In this case the value is the
         *                    new name of the schema.
         * @param[in] options_  Optional parameters. The default value is an
         *                      empty map.
         */
        AlterSchemaRequest(const std::string& schemaName_, const std::string& action_, const std::string& value_, const std::map<std::string, std::string>& options_):
            schemaName( schemaName_ ),
            action( action_ ),
            value( value_ ),
            options( options_ )
        {
        }

        /**
         * Name of the schema to be altered.
         */
        std::string schemaName;

        /**
         * Modification operation to be applied.
         * Supported values:
         * <ul>
         *     <li>@ref gpudb::alter_schema_add_comment
         *         "alter_schema_add_comment": Adds a comment describing the
         *         schema
         *     <li>@ref gpudb::alter_schema_rename_schema
         *         "alter_schema_rename_schema": Renames a schema to @ref
         *         value. Has the same naming restrictions as <a
         *         href="../../../concepts/tables/" target="_top">tables</a>.
         * </ul>
         */
        std::string action;

        /**
         * The value of the modification, depending on @ref action.  For now
         * the only value of @ref action is @ref
         * gpudb::alter_schema_rename_schema "rename_schema".  In this case the
         * value is the new name of the schema.
         */
        std::string value;

        /**
         * Optional parameters. The default value is an empty map.
         */
        std::map<std::string, std::string> options;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::AlterSchemaRequest>
    {
        static void encode(Encoder& e, const gpudb::AlterSchemaRequest& v)
        {
            ::avro::encode(e, v.schemaName);
            ::avro::encode(e, v.action);
            ::avro::encode(e, v.value);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AlterSchemaRequest& v)
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
                            ::avro::decode(d, v.action);
                            break;

                        case 2:
                            ::avro::decode(d, v.value);
                            break;

                        case 3:
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
                ::avro::decode(d, v.action);
                ::avro::decode(d, v.value);
                ::avro::decode(d, v.options);
            }
        }
    };
} // end namespace avro

namespace gpudb
{
    /**
     * A set of results returned by @ref
     * GPUdb::alterSchema(const AlterSchemaRequest&) const
     * "GPUdb::alterSchema".
     */
    struct AlterSchemaResponse
    {
        /**
         * Constructs an AlterSchemaResponse object with default parameters.
         */
        AlterSchemaResponse() :
            schemaName(std::string()),
            info(std::map<std::string, std::string>())
        {
        }

        /**
         * Value of @ref gpudb::AlterSchemaRequest::schemaName "schemaName".
         */
        std::string schemaName;

        /**
         * Additional information.
         */
        std::map<std::string, std::string> info;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::AlterSchemaResponse>
    {
        static void encode(Encoder& e, const gpudb::AlterSchemaResponse& v)
        {
            ::avro::encode(e, v.schemaName);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::AlterSchemaResponse& v)
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
                ::avro::decode(d, v.info);
            }
        }
    };
} // end namespace avro

#endif // __ALTER_SCHEMA_H__
