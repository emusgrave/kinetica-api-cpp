/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __FILTER_BY_STRING_H__
#define __FILTER_BY_STRING_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #filterByString(const FilterByStringRequest&) const}.
     * <p>
     * Calculates which objects from a table, collection or view match a string
     * expression for the given string columns. The 'mode' may be:
     * <p>
     *     'search' for full text search query with wildcards and boolean
     * operators, e.g. '(bob* OR sue) AND NOT jane'. Note that for this mode,
     * no column can be specified in @a columnNames; GPUdb will search through
     * all string columns of the table that have text search enabled. Also, the
     * first character of the regular expression cannot be a wildcard (* or ?).
     * <p>
     * * 'equals' for an exact whole-string match
     * * 'contains' for a partial substring match (not accelerated)
     * * 'starts_with' to find strings that start with the given expression
     * (not accelerated)
     * * 'regex' - to use a full regular expression search (not accelerated)
     * <p>
     * The options 'case_sensitive' can be used to modify the behavior for all
     * modes except 'search'
     */
    struct FilterByStringRequest
    {

        /**
         * Constructs a FilterByStringRequest object with default parameter
         * values.
         */
        FilterByStringRequest() :
            tableName(std::string()),
            viewName(std::string()),
            expression(std::string()),
            mode(std::string()),
            columnNames(std::vector<std::string>()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a FilterByStringRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName  Name of the table on which the filter
         *                       operation will be performed.  Must be a valid
         *                       GPUdb table, collection or view.
         * @param[in] viewName  If provided, then this will be the name of the
         *                      view containing the results. Must not be an
         *                      already existing collection, table or view.
         *                      Default value is an empty string.
         * @param[in] expression  The expression with which to filter the
         *                        table.
         * @param[in] mode  The string filtering mode to apply. See above for
         *                  details.
         * @param[in] columnNames  List of columns on which to apply the
         *                         filter. Ignored for 'search' mode.
         * @param[in] options  Optional parameters.  Default value is an empty
         *                     std::map.
         * <ul>
         *     <li>case_sensitive: If 'false' then string filtering will ignore case. Does not apply to 'search' mode.  Default value is 'true'. values:TRUE, FALSE
         * </ul>
         * 
         */
        FilterByStringRequest(const std::string& tableName, const std::string& viewName, const std::string& expression, const std::string& mode, const std::vector<std::string>& columnNames, const std::map<std::string, std::string>& options):
            tableName(tableName),
            viewName(viewName),
            expression(expression),
            mode(mode),
            columnNames(columnNames),
            options(options)
        {
        }

        std::string tableName;
        std::string viewName;
        std::string expression;
        std::string mode;
        std::vector<std::string> columnNames;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::FilterByStringRequest>
    {
        static void encode(Encoder& e, const gpudb::FilterByStringRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.viewName);
            ::avro::encode(e, v.expression);
            ::avro::encode(e, v.mode);
            ::avro::encode(e, v.columnNames);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::FilterByStringRequest& v)
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
                            ::avro::decode(d, v.mode);
                            break;

                        case 4:
                            ::avro::decode(d, v.columnNames);
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
                ::avro::decode(d, v.tableName);
                ::avro::decode(d, v.viewName);
                ::avro::decode(d, v.expression);
                ::avro::decode(d, v.mode);
                ::avro::decode(d, v.columnNames);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #filterByString(const FilterByStringRequest&) const}.
     * <p>
     * Calculates which objects from a table, collection or view match a string
     * expression for the given string columns. The 'mode' may be:
     * <p>
     *     'search' for full text search query with wildcards and boolean
     * operators, e.g. '(bob* OR sue) AND NOT jane'. Note that for this mode,
     * no column can be specified in @a columnNames; GPUdb will search through
     * all string columns of the table that have text search enabled. Also, the
     * first character of the regular expression cannot be a wildcard (* or ?).
     * <p>
     * * 'equals' for an exact whole-string match
     * * 'contains' for a partial substring match (not accelerated)
     * * 'starts_with' to find strings that start with the given expression
     * (not accelerated)
     * * 'regex' - to use a full regular expression search (not accelerated)
     * <p>
     * The options 'case_sensitive' can be used to modify the behavior for all
     * modes except 'search'
     */
    struct FilterByStringResponse
    {

        /**
         * Constructs a FilterByStringResponse object with default parameter
         * values.
         */
        FilterByStringResponse() :
            count(int64_t())
        {
        }

        int64_t count;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::FilterByStringResponse>
    {
        static void encode(Encoder& e, const gpudb::FilterByStringResponse& v)
        {
            ::avro::encode(e, v.count);
        }

        static void decode(Decoder& d, gpudb::FilterByStringResponse& v)
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

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.count);
            }
        }
    };
}

#endif
