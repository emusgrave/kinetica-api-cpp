/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __FILTER_H__
#define __FILTER_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #filter(const FilterRequest&) const}.
     * <p>
     * Filters data based on the specified expression.  The results are
     * stored in a <a href="../../../concepts/filtered_views/"
     * target="_top">result set</a> with the
     * given @a viewName.
     * <p>
     * For details see <a href="../../../concepts/expressions/"
     * target="_top">Expressions</a>.
     * <p>
     * The response message contains the number of points for which the
     * expression
     * evaluated to be true, which is equivalent to the size of the result
     * view.
     */
    struct FilterRequest
    {

        /**
         * Constructs a FilterRequest object with default parameter values.
         */
        FilterRequest() :
            tableName(std::string()),
            viewName(std::string()),
            expression(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a FilterRequest object with the specified parameters.
         * 
         * @param[in] tableName_  Name of the table to filter, in
         *                        [schema_name.]table_name format, using
         *                        standard <a
         *                        href="../../../concepts/tables/#table-name-resolution"
         *                        target="_top">name resolution rules</a>.
         *                        This may be the name of a table or a view
         *                        (when chaining queries).
         * @param[in] viewName_  If provided, then this will be the name of the
         *                       view containing the results, in
         *                       [schema_name.]view_name format, using standard
         *                       <a
         *                       href="../../../concepts/tables/#table-name-resolution"
         *                       target="_top">name resolution rules</a> and
         *                       meeting <a
         *                       href="../../../concepts/tables/#table-naming-criteria"
         *                       target="_top">table naming criteria</a>.  Must
         *                       not be an already existing table or view.
         * @param[in] expression_  The select expression to filter the
         *                         specified table.  For details see <a
         *                         href="../../../concepts/expressions/"
         *                         target="_top">Expressions</a>.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li> gpudb::filter_create_temp_table:
         *                      If @a true, a unique temporary table name will
         *                      be generated in the sys_temp schema and used in
         *                      place of @a viewName. This is always allowed
         *                      even if the caller does not have permission to
         *                      create tables. The generated name is returned
         *                      in @a qualified_view_name.
         *                      <ul>
         *                              <li> gpudb::filter_true
         *                              <li> gpudb::filter_false
         *                      </ul>
         *                      The default value is gpudb::filter_false.
         *                              <li> gpudb::filter_collection_name:
         *                      [DEPRECATED--please specify the containing
         *                      schema for the view as part of @a viewName and
         *                      use /create/schema to create the schema if
         *                      non-existent]  Name of a schema for the newly
         *                      created view. If the schema is non-existent, it
         *                      will be automatically created.
         *                              <li> gpudb::filter_view_id: view this
         *                      filtered-view is part of.  The default value is
         *                      ''.
         *                              <li> gpudb::filter_ttl: Sets the <a
         *                      href="../../../concepts/ttl/"
         *                      target="_top">TTL</a> of the view specified in
         *                      @a viewName.
         *                      </ul>
         * 
         */
        FilterRequest(const std::string& tableName_, const std::string& viewName_, const std::string& expression_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            viewName( viewName_ ),
            expression( expression_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::string viewName;
        std::string expression;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::FilterRequest>
    {
        static void encode(Encoder& e, const gpudb::FilterRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.viewName);
            ::avro::encode(e, v.expression);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::FilterRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.tableName);
                            break;

                        case 1:
                            ::avro::decode(d, v.viewName);
                            break;

                        case 2:
                            ::avro::decode(d, v.expression);
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
                ::avro::decode(d, v.tableName);
                ::avro::decode(d, v.viewName);
                ::avro::decode(d, v.expression);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #filter(const FilterRequest&) const}.
     * <p>
     * Filters data based on the specified expression.  The results are
     * stored in a <a href="../../../concepts/filtered_views/"
     * target="_top">result set</a> with the
     * given @a viewName.
     * <p>
     * For details see <a href="../../../concepts/expressions/"
     * target="_top">Expressions</a>.
     * <p>
     * The response message contains the number of points for which the
     * expression
     * evaluated to be true, which is equivalent to the size of the result
     * view.
     */
    struct FilterResponse
    {

        /**
         * Constructs a FilterResponse object with default parameter values.
         */
        FilterResponse() :
            count(int64_t()),
            info(std::map<std::string, std::string>())
        {
        }

        int64_t count;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::FilterResponse>
    {
        static void encode(Encoder& e, const gpudb::FilterResponse& v)
        {
            ::avro::encode(e, v.count);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::FilterResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.count);
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
                ::avro::decode(d, v.count);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
