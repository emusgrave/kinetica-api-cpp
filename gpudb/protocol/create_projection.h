/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __CREATE_PROJECTION_H__
#define __CREATE_PROJECTION_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #createProjection(const CreateProjectionRequest&) const}.
     * <p>
     * Creates a new projection of an existing table. A projection represents a
     * subset of the columns (potentially including derived columns) of a
     * table.
     */
    struct CreateProjectionRequest
    {

        /**
         * Constructs a CreateProjectionRequest object with default parameter
         * values.
         */
        CreateProjectionRequest() :
            tableName(std::string()),
            projectionName(std::string()),
            columnNames(std::vector<std::string>()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a CreateProjectionRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Name of the existing table on which the
         *                        projection is to be applied.
         * @param[in] projectionName_  Name of the projection to be created.
         *                             Must not be the name of a currently
         *                             existing table. Cannot be an empty
         *                             string. Valid characters are
         *                             'A-Za-z0-9_-(){}[] .:' (excluding the
         *                             single quote), with the first character
         *                             being one of 'A-Za-z0-9_'. The maximum
         *                             length is 256 characters.
         * @param[in] columnNames_  List of columns from @a tableName to be
         *                          included in the projection. Can include
         *                          derived columns. Can be specified as
         *                          aliased via the syntax '<column_name> as
         *                          <alias>.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li> collection_name: Name of a
         *                      collection to which the projection is to be
         *                      assigned as a child.
         *                              <li> expression: An optional filter
         *                      expression to be applied to the source table
         *                      prior to the projection.
         *                              <li> limit: The number of records to
         *                      keep.
         *                              <li> order_by: Comma-separated list of
         *                      the columns to be sorted by; i.e 'timestamp
         *                      asc, x desc'.
         *                      </ul>
         *                        Default value is an empty std::map.
         * 
         */
        CreateProjectionRequest(const std::string& tableName_, const std::string& projectionName_, const std::vector<std::string>& columnNames_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            projectionName( projectionName_ ),
            columnNames( columnNames_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::string projectionName;
        std::vector<std::string> columnNames;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::CreateProjectionRequest>
    {
        static void encode(Encoder& e, const gpudb::CreateProjectionRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.projectionName);
            ::avro::encode(e, v.columnNames);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::CreateProjectionRequest& v)
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
                            ::avro::decode(d, v.projectionName);
                            break;

                        case 2:
                            ::avro::decode(d, v.columnNames);
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
                ::avro::decode(d, v.projectionName);
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
     * #createProjection(const CreateProjectionRequest&) const}.
     * <p>
     * Creates a new projection of an existing table. A projection represents a
     * subset of the columns (potentially including derived columns) of a
     * table.
     */
    struct CreateProjectionResponse
    {

        /**
         * Constructs a CreateProjectionResponse object with default parameter
         * values.
         */
        CreateProjectionResponse() :
            projectionName(std::string())
        {
        }

        std::string projectionName;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::CreateProjectionResponse>
    {
        static void encode(Encoder& e, const gpudb::CreateProjectionResponse& v)
        {
            ::avro::encode(e, v.projectionName);
        }

        static void decode(Decoder& d, gpudb::CreateProjectionResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.projectionName);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.projectionName);
            }
        }
    };
}

#endif