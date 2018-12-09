/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __SHOW_TABLE_H__
#define __SHOW_TABLE_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #showTable(const ShowTableRequest&) const}.
     * <p>
     * Retrieves detailed information about a table, view, or collection,
     * specified in @a tableName. If the supplied @a tableName is a collection,
     * the call can return information about either the collection itself or
     * the tables and views it contains. If @a tableName is empty, information
     * about all collections and top-level tables and views can be returned.
     * <p>
     * If the option @a get_sizes is set to @a true, then the sizes (objects
     * and elements) of each table are returned (in @a sizes and @a fullSizes),
     * along with the total number of objects in the requested table (in @a
     * totalSize and @a totalFullSize).
     * <p>
     * For a collection, setting the @a show_children option to @a false
     * returns only information about the collection itself; setting @a
     * show_children to @a true returns a list of tables and views contained in
     * the collection, along with their corresponding detail.
     */
    struct ShowTableRequest
    {

        /**
         * Constructs a ShowTableRequest object with default parameter values.
         */
        ShowTableRequest() :
            tableName(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a ShowTableRequest object with the specified parameters.
         * 
         * @param[in] tableName_  Name of the table for which to retrieve the
         *                        information. If blank, then information about
         *                        all collections and top-level tables and
         *                        views is returned.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li>
         *                      gpudb::show_table_force_synchronous: If @a true
         *                      then the table sizes will wait for read lock
         *                      before returning.
         *                      <ul>
         *                              <li> gpudb::show_table_true
         *                              <li> gpudb::show_table_false
         *                      </ul>
         *                      The default value is gpudb::show_table_true.
         *                              <li> gpudb::show_table_get_sizes: If @a
         *                      true then the table sizes will be returned;
         *                      blank, otherwise.
         *                      <ul>
         *                              <li> gpudb::show_table_true
         *                              <li> gpudb::show_table_false
         *                      </ul>
         *                      The default value is gpudb::show_table_false.
         *                              <li> gpudb::show_table_show_children:
         *                      If @a tableName is a collection, then @a true
         *                      will return information about the children of
         *                      the collection, and @a false will return
         *                      information about the collection itself. If @a
         *                      tableName is a table or view, @a show_children
         *                      must be @a false. If @a tableName is empty,
         *                      then @a show_children must be @a true.
         *                      <ul>
         *                              <li> gpudb::show_table_true
         *                              <li> gpudb::show_table_false
         *                      </ul>
         *                      The default value is gpudb::show_table_true.
         *                              <li>
         *                      gpudb::show_table_no_error_if_not_exists: If @a
         *                      false will return an error if the provided @a
         *                      tableName does not exist. If @a true then it
         *                      will return an empty result.
         *                      <ul>
         *                              <li> gpudb::show_table_true
         *                              <li> gpudb::show_table_false
         *                      </ul>
         *                      The default value is gpudb::show_table_false.
         *                              <li> gpudb::show_table_get_column_info:
         *                      If @a true then column info (memory usage, etc)
         *                      will be returned.
         *                      <ul>
         *                              <li> gpudb::show_table_true
         *                              <li> gpudb::show_table_false
         *                      </ul>
         *                      The default value is gpudb::show_table_false.
         *                      </ul>
         * 
         */
        ShowTableRequest(const std::string& tableName_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::ShowTableRequest>
    {
        static void encode(Encoder& e, const gpudb::ShowTableRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::ShowTableRequest& v)
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
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #showTable(const ShowTableRequest&) const}.
     * <p>
     * Retrieves detailed information about a table, view, or collection,
     * specified in @a tableName. If the supplied @a tableName is a collection,
     * the call can return information about either the collection itself or
     * the tables and views it contains. If @a tableName is empty, information
     * about all collections and top-level tables and views can be returned.
     * <p>
     * If the option @a get_sizes is set to @a true, then the sizes (objects
     * and elements) of each table are returned (in @a sizes and @a fullSizes),
     * along with the total number of objects in the requested table (in @a
     * totalSize and @a totalFullSize).
     * <p>
     * For a collection, setting the @a show_children option to @a false
     * returns only information about the collection itself; setting @a
     * show_children to @a true returns a list of tables and views contained in
     * the collection, along with their corresponding detail.
     */
    struct ShowTableResponse
    {

        /**
         * Constructs a ShowTableResponse object with default parameter values.
         */
        ShowTableResponse() :
            tableName(std::string()),
            tableNames(std::vector<std::string>()),
            tableDescriptions(std::vector<std::vector<std::string> >()),
            typeIds(std::vector<std::string>()),
            typeSchemas(std::vector<std::string>()),
            typeLabels(std::vector<std::string>()),
            properties(std::vector<std::map<std::string, std::vector<std::string> > >()),
            additionalInfo(std::vector<std::map<std::string, std::string> >()),
            sizes(std::vector<int64_t>()),
            fullSizes(std::vector<int64_t>()),
            joinSizes(std::vector<double>()),
            totalSize(int64_t()),
            totalFullSize(int64_t()),
            info(std::map<std::string, std::string>())
        {
        }

        std::string tableName;
        std::vector<std::string> tableNames;
        std::vector<std::vector<std::string> > tableDescriptions;
        std::vector<std::string> typeIds;
        std::vector<std::string> typeSchemas;
        std::vector<std::string> typeLabels;
        std::vector<std::map<std::string, std::vector<std::string> > > properties;
        std::vector<std::map<std::string, std::string> > additionalInfo;
        std::vector<int64_t> sizes;
        std::vector<int64_t> fullSizes;
        std::vector<double> joinSizes;
        int64_t totalSize;
        int64_t totalFullSize;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::ShowTableResponse>
    {
        static void encode(Encoder& e, const gpudb::ShowTableResponse& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.tableNames);
            ::avro::encode(e, v.tableDescriptions);
            ::avro::encode(e, v.typeIds);
            ::avro::encode(e, v.typeSchemas);
            ::avro::encode(e, v.typeLabels);
            ::avro::encode(e, v.properties);
            ::avro::encode(e, v.additionalInfo);
            ::avro::encode(e, v.sizes);
            ::avro::encode(e, v.fullSizes);
            ::avro::encode(e, v.joinSizes);
            ::avro::encode(e, v.totalSize);
            ::avro::encode(e, v.totalFullSize);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::ShowTableResponse& v)
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
                            ::avro::decode(d, v.tableNames);
                            break;

                        case 2:
                            ::avro::decode(d, v.tableDescriptions);
                            break;

                        case 3:
                            ::avro::decode(d, v.typeIds);
                            break;

                        case 4:
                            ::avro::decode(d, v.typeSchemas);
                            break;

                        case 5:
                            ::avro::decode(d, v.typeLabels);
                            break;

                        case 6:
                            ::avro::decode(d, v.properties);
                            break;

                        case 7:
                            ::avro::decode(d, v.additionalInfo);
                            break;

                        case 8:
                            ::avro::decode(d, v.sizes);
                            break;

                        case 9:
                            ::avro::decode(d, v.fullSizes);
                            break;

                        case 10:
                            ::avro::decode(d, v.joinSizes);
                            break;

                        case 11:
                            ::avro::decode(d, v.totalSize);
                            break;

                        case 12:
                            ::avro::decode(d, v.totalFullSize);
                            break;

                        case 13:
                            ::avro::decode(d, v.info);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.tableName);
                ::avro::decode(d, v.tableNames);
                ::avro::decode(d, v.tableDescriptions);
                ::avro::decode(d, v.typeIds);
                ::avro::decode(d, v.typeSchemas);
                ::avro::decode(d, v.typeLabels);
                ::avro::decode(d, v.properties);
                ::avro::decode(d, v.additionalInfo);
                ::avro::decode(d, v.sizes);
                ::avro::decode(d, v.fullSizes);
                ::avro::decode(d, v.joinSizes);
                ::avro::decode(d, v.totalSize);
                ::avro::decode(d, v.totalFullSize);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
