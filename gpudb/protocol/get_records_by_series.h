/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __GET_RECORDS_BY_SERIES_H__
#define __GET_RECORDS_BY_SERIES_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #getRecordsBySeriesRaw(const GetRecordsBySeriesRequest&) const}.
     * <p>
     * Retrieves the complete series/track records from the given
     * @a worldTableName based on the partial track information contained in
     * the @a tableName.
     * <p>
     * This operation supports paging through the data via the @a offset and
     * @a limit parameters.
     * <p>
     * In contrast to {@link
     * #getRecordsRaw(const GetRecordsRequest&) const} this returns records
     * grouped by
     * series/track. So if @a offset is 0 and @a limit is 5 this operation
     * would return the first 5 series/tracks in @a tableName. Each
     * series/track
     * will be returned sorted by their TIMESTAMP column.
     */
    struct GetRecordsBySeriesRequest
    {

        /**
         * Constructs a GetRecordsBySeriesRequest object with default parameter
         * values.
         */
        GetRecordsBySeriesRequest() :
            tableName(std::string()),
            worldTableName(std::string()),
            offset(int32_t()),
            limit(int32_t()),
            encoding(std::string("binary")),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a GetRecordsBySeriesRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Name of the table or view for which
         *                        series/tracks will be fetched, in
         *                        [schema_name.]table_name format, using
         *                        standard <a
         *                        href="../../../concepts/tables/#table-name-resolution"
         *                        target="_top">name resolution rules</a>.
         * @param[in] worldTableName_  Name of the table containing the
         *                             complete series/track information to be
         *                             returned for the tracks present in the
         *                             @a tableName, in
         *                             [schema_name.]table_name format, using
         *                             standard <a
         *                             href="../../../concepts/tables/#table-name-resolution"
         *                             target="_top">name resolution rules</a>.
         *                             Typically this is used when retrieving
         *                             series/tracks from a view (which
         *                             contains partial series/tracks) but the
         *                             user wants to retrieve the entire
         *                             original series/tracks. Can be blank.
         * @param[in] offset_  A positive integer indicating the number of
         *                     initial series/tracks to skip (useful for paging
         *                     through the results).  The minimum allowed value
         *                     is 0. The maximum allowed value is MAX_INT.
         * @param[in] limit_  A positive integer indicating the maximum number
         *                    of series/tracks to be returned. Or END_OF_SET
         *                    (-9999) to indicate that the max number of
         *                    results should be returned.
         * @param[in] options_  Optional parameters.
         * 
         */
        GetRecordsBySeriesRequest(const std::string& tableName_, const std::string& worldTableName_, const int32_t offset_, const int32_t limit_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            worldTableName( worldTableName_ ),
            offset( offset_ ),
            limit( limit_ ),
            encoding( "binary" ),
            options( options_ )
        {
        }

        /**
         * Constructs a GetRecordsBySeriesRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Name of the table or view for which
         *                        series/tracks will be fetched, in
         *                        [schema_name.]table_name format, using
         *                        standard <a
         *                        href="../../../concepts/tables/#table-name-resolution"
         *                        target="_top">name resolution rules</a>.
         * @param[in] worldTableName_  Name of the table containing the
         *                             complete series/track information to be
         *                             returned for the tracks present in the
         *                             @a tableName, in
         *                             [schema_name.]table_name format, using
         *                             standard <a
         *                             href="../../../concepts/tables/#table-name-resolution"
         *                             target="_top">name resolution rules</a>.
         *                             Typically this is used when retrieving
         *                             series/tracks from a view (which
         *                             contains partial series/tracks) but the
         *                             user wants to retrieve the entire
         *                             original series/tracks. Can be blank.
         * @param[in] offset_  A positive integer indicating the number of
         *                     initial series/tracks to skip (useful for paging
         *                     through the results).  The minimum allowed value
         *                     is 0. The maximum allowed value is MAX_INT.
         * @param[in] limit_  A positive integer indicating the maximum number
         *                    of series/tracks to be returned. Or END_OF_SET
         *                    (-9999) to indicate that the max number of
         *                    results should be returned.
         * @param[in] encoding_  Specifies the encoding for returned records;
         *                       either @a binary or @a json.
         *                       <ul>
         *                               <li>
         *                       gpudb::get_records_by_series_binary
         *                               <li> gpudb::get_records_by_series_json
         *                       </ul>
         *                       The default value is
         *                       gpudb::get_records_by_series_binary.
         * @param[in] options_  Optional parameters.
         * 
         */
        GetRecordsBySeriesRequest(const std::string& tableName_, const std::string& worldTableName_, const int32_t offset_, const int32_t limit_, const std::string& encoding_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            worldTableName( worldTableName_ ),
            offset( offset_ ),
            limit( limit_ ),
            encoding( encoding_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::string worldTableName;
        int32_t offset;
        int32_t limit;
        std::string encoding;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::GetRecordsBySeriesRequest>
    {
        static void encode(Encoder& e, const gpudb::GetRecordsBySeriesRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.worldTableName);
            ::avro::encode(e, v.offset);
            ::avro::encode(e, v.limit);
            ::avro::encode(e, v.encoding);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::GetRecordsBySeriesRequest& v)
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
                            ::avro::decode(d, v.worldTableName);
                            break;

                        case 2:
                            ::avro::decode(d, v.offset);
                            break;

                        case 3:
                            ::avro::decode(d, v.limit);
                            break;

                        case 4:
                            ::avro::decode(d, v.encoding);
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
                ::avro::decode(d, v.worldTableName);
                ::avro::decode(d, v.offset);
                ::avro::decode(d, v.limit);
                ::avro::decode(d, v.encoding);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #getRecordsBySeriesRaw(const GetRecordsBySeriesRequest&) const}.
     * <p>
     * Retrieves the complete series/track records from the given
     * @a worldTableName based on the partial track information contained in
     * the @a tableName.
     * <p>
     * This operation supports paging through the data via the @a offset and
     * @a limit parameters.
     * <p>
     * In contrast to {@link
     * #getRecordsRaw(const GetRecordsRequest&) const} this returns records
     * grouped by
     * series/track. So if @a offset is 0 and @a limit is 5 this operation
     * would return the first 5 series/tracks in @a tableName. Each
     * series/track
     * will be returned sorted by their TIMESTAMP column.
     */
    struct RawGetRecordsBySeriesResponse
    {

        /**
         * Constructs a RawGetRecordsBySeriesResponse object with default
         * parameter values.
         */
        RawGetRecordsBySeriesResponse() :
            tableNames(std::vector<std::string>()),
            typeNames(std::vector<std::string>()),
            typeSchemas(std::vector<std::string>()),
            listRecordsBinary(std::vector<std::vector<std::vector<uint8_t> > >()),
            listRecordsJson(std::vector<std::vector<std::string> >()),
            info(std::map<std::string, std::string>())
        {
        }

        std::vector<std::string> tableNames;
        std::vector<std::string> typeNames;
        std::vector<std::string> typeSchemas;
        std::vector<std::vector<std::vector<uint8_t> > > listRecordsBinary;
        std::vector<std::vector<std::string> > listRecordsJson;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::RawGetRecordsBySeriesResponse>
    {
        static void encode(Encoder& e, const gpudb::RawGetRecordsBySeriesResponse& v)
        {
            ::avro::encode(e, v.tableNames);
            ::avro::encode(e, v.typeNames);
            ::avro::encode(e, v.typeSchemas);
            ::avro::encode(e, v.listRecordsBinary);
            ::avro::encode(e, v.listRecordsJson);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::RawGetRecordsBySeriesResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.tableNames);
                            break;

                        case 1:
                            ::avro::decode(d, v.typeNames);
                            break;

                        case 2:
                            ::avro::decode(d, v.typeSchemas);
                            break;

                        case 3:
                            ::avro::decode(d, v.listRecordsBinary);
                            break;

                        case 4:
                            ::avro::decode(d, v.listRecordsJson);
                            break;

                        case 5:
                            ::avro::decode(d, v.info);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.tableNames);
                ::avro::decode(d, v.typeNames);
                ::avro::decode(d, v.typeSchemas);
                ::avro::decode(d, v.listRecordsBinary);
                ::avro::decode(d, v.listRecordsJson);
                ::avro::decode(d, v.info);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #getRecordsBySeries(const GetRecordsBySeriesRequest&) const}.
     * <p>
     * Retrieves the complete series/track records from the given
     * @a worldTableName based on the partial track information contained in
     * the @a tableName.
     * <p>
     * This operation supports paging through the data via the @a offset and
     * @a limit parameters.
     * <p>
     * In contrast to {@link #getRecords(const GetRecordsRequest&) const}
     * this returns records grouped by
     * series/track. So if @a offset is 0 and @a limit is 5 this operation
     * would return the first 5 series/tracks in @a tableName. Each
     * series/track
     * will be returned sorted by their TIMESTAMP column.
     * 
     * @param <T>  The type of object being processed.
     * 
     */
    template<typename T> struct GetRecordsBySeriesResponse
    {

        /**
         * Constructs a GetRecordsBySeriesResponse object with default
         * parameter values.
         */
        GetRecordsBySeriesResponse() :
            tableNames(std::vector<std::string>()),
            typeNames(std::vector<std::string>()),
            typeSchemas(std::vector<std::string>()),
            data(std::vector<std::vector<T> >()),
            info(std::map<std::string, std::string>())
        {
        }

        std::vector<std::string> tableNames;
        std::vector<std::string> typeNames;
        std::vector<std::string> typeSchemas;
        std::vector<std::vector<T> > data;
        std::map<std::string, std::string> info;
    };
}

#endif
