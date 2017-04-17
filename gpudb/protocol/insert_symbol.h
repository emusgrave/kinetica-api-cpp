/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __INSERT_SYMBOL_H__
#define __INSERT_SYMBOL_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #insertSymbol(const InsertSymbolRequest&) const}.
     * <p>
     * Adds a symbol or icon (i.e. an image) to represent data points when data
     * is rendered visually. Users must provide the symbol identifier (string),
     * a format (currently supported: 'svg' and 'svg_path'), the data for the
     * symbol, and any additional optional parameter (e.g. color). To have a
     * symbol used for rendering create a table with a string column named
     * 'SYMBOLCODE' (along with 'x' or 'y' for example). Then when the table is
     * rendered (via <a href="../rest/wms_rest.html" target="_top">WMS</a>) if
     * the 'dosymbology' parameter is 'true' then the value of the 'SYMBOLCODE'
     * column is used to pick the symbol displayed for each point.
     */
    struct InsertSymbolRequest
    {

        /**
         * Constructs an InsertSymbolRequest object with default parameter
         * values.
         */
        InsertSymbolRequest() :
            symbolId(std::string()),
            symbolFormat(std::string()),
            symbolData(std::vector<uint8_t>()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an InsertSymbolRequest object with the specified
         * parameters.
         * 
         * @param[in] symbolId_  The id of the symbol being added. This is the
         *                       same id that should be in the 'SYMBOLCODE'
         *                       column for objects using this symbol
         * @param[in] symbolFormat_  Specifies the symbol format. Must be
         *                           either 'svg' or 'svg_path'. Values: 'svg',
         *                           'svg_path'.
         * @param[in] symbolData_  The actual symbol data. If @a symbolFormat
         *                         is 'svg' then this should be the raw bytes
         *                         representing an svg file. If @a symbolFormat
         *                         is svg path then this should be an svg path
         *                         string, for example:
         *                         'M25.979,12.896,5.979,12.896,5.979,19.562,25.979,19.562z'
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li> color: If @a symbolFormat is 'svg'
         *                      this is ignored. If @a symbolFormat is
         *                      'svg_path' then this option specifies the color
         *                      (in RRGGBB hex format) of the path. For
         *                      example, to have the path rendered in red, used
         *                      'FF0000'. If 'color' is not provided then
         *                      '00FF00' (i.e. green) is used by default.
         *                      </ul>
         *                        Default value is an empty std::map.
         * 
         */
        InsertSymbolRequest(const std::string& symbolId_, const std::string& symbolFormat_, const std::vector<uint8_t>& symbolData_, const std::map<std::string, std::string>& options_):
            symbolId( symbolId_ ),
            symbolFormat( symbolFormat_ ),
            symbolData( symbolData_ ),
            options( options_ )
        {
        }

        std::string symbolId;
        std::string symbolFormat;
        std::vector<uint8_t> symbolData;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::InsertSymbolRequest>
    {
        static void encode(Encoder& e, const gpudb::InsertSymbolRequest& v)
        {
            ::avro::encode(e, v.symbolId);
            ::avro::encode(e, v.symbolFormat);
            ::avro::encode(e, v.symbolData);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::InsertSymbolRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.symbolId);
                            break;

                        case 1:
                            ::avro::decode(d, v.symbolFormat);
                            break;

                        case 2:
                            ::avro::decode(d, v.symbolData);
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
                ::avro::decode(d, v.symbolId);
                ::avro::decode(d, v.symbolFormat);
                ::avro::decode(d, v.symbolData);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #insertSymbol(const InsertSymbolRequest&) const}.
     * <p>
     * Adds a symbol or icon (i.e. an image) to represent data points when data
     * is rendered visually. Users must provide the symbol identifier (string),
     * a format (currently supported: 'svg' and 'svg_path'), the data for the
     * symbol, and any additional optional parameter (e.g. color). To have a
     * symbol used for rendering create a table with a string column named
     * 'SYMBOLCODE' (along with 'x' or 'y' for example). Then when the table is
     * rendered (via <a href="../rest/wms_rest.html" target="_top">WMS</a>) if
     * the 'dosymbology' parameter is 'true' then the value of the 'SYMBOLCODE'
     * column is used to pick the symbol displayed for each point.
     */
    struct InsertSymbolResponse
    {

        /**
         * Constructs an InsertSymbolResponse object with default parameter
         * values.
         */
        InsertSymbolResponse() :
            symbolId(std::string())
        {
        }

        std::string symbolId;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::InsertSymbolResponse>
    {
        static void encode(Encoder& e, const gpudb::InsertSymbolResponse& v)
        {
            ::avro::encode(e, v.symbolId);
        }

        static void decode(Decoder& d, gpudb::InsertSymbolResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.symbolId);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.symbolId);
            }
        }
    };
}

#endif
