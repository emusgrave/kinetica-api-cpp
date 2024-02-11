/*
 *  This file was autogenerated by the Kinetica schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __DELETE_FILES_H__
#define __DELETE_FILES_H__

namespace gpudb
{
    /**
     * A set of parameters for @ref
     * GPUdb::deleteFiles(const DeleteFilesRequest&) const
     * "GPUdb::deleteFiles".
     *
     * Deletes one or more files from <a href="../../../tools/kifs/"
     * target="_top">KiFS</a>.
     */
    struct DeleteFilesRequest
    {
        /**
         * Constructs a DeleteFilesRequest object with default parameters.
         */
        DeleteFilesRequest() :
            fileNames(std::vector<std::string>()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a DeleteFilesRequest object with the specified
         * parameters.
         *
         * @param[in] fileNames_  An array of names of files to be deleted.
         *                        File paths may contain wildcard characters
         *                        after the KiFS directory delimeter.  Accepted
         *                        wildcard characters are asterisk (*) to
         *                        represent any string of zero or more
         *                        characters, and question mark (?) to indicate
         *                        a single character.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                          <li>@ref
         *                              gpudb::delete_files_no_error_if_not_exists
         *                              "delete_files_no_error_if_not_exists":
         *                              If @ref gpudb::delete_files_true
         *                              "true", no error is returned if a
         *                              specified file does not exist.
         *                              Supported values:
         *                              <ul>
         *                                  <li>@ref gpudb::delete_files_true
         *                                      "delete_files_true"
         *                                  <li>@ref gpudb::delete_files_false
         *                                      "delete_files_false"
         *                              </ul>
         *                              The default value is @ref
         *                              gpudb::delete_files_false
         *                              "delete_files_false".
         *                      </ul>
         *                      The default value is an empty map.
         */
        DeleteFilesRequest(const std::vector<std::string>& fileNames_, const std::map<std::string, std::string>& options_):
            fileNames( fileNames_ ),
            options( options_ )
        {
        }

        /**
         * An array of names of files to be deleted. File paths may contain
         * wildcard characters after the KiFS directory delimeter.
         *
         * Accepted wildcard characters are asterisk (*) to represent any
         * string of zero or more characters, and question mark (?) to indicate
         * a single character.
         */
        std::vector<std::string> fileNames;

        /**
         * Optional parameters.
         * <ul>
         *     <li>@ref gpudb::delete_files_no_error_if_not_exists
         *         "delete_files_no_error_if_not_exists": If @ref
         *         gpudb::delete_files_true "true", no error is returned if a
         *         specified file does not exist.
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::delete_files_true "delete_files_true"
         *             <li>@ref gpudb::delete_files_false "delete_files_false"
         *         </ul>
         *         The default value is @ref gpudb::delete_files_false
         *         "delete_files_false".
         * </ul>
         * The default value is an empty map.
         */
        std::map<std::string, std::string> options;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::DeleteFilesRequest>
    {
        static void encode(Encoder& e, const gpudb::DeleteFilesRequest& v)
        {
            ::avro::encode(e, v.fileNames);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::DeleteFilesRequest& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.fileNames);
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
                ::avro::decode(d, v.fileNames);
                ::avro::decode(d, v.options);
            }
        }
    };
} // end namespace avro

namespace gpudb
{
    /**
     * A set of results returned by @ref
     * GPUdb::deleteFiles(const DeleteFilesRequest&) const
     * "GPUdb::deleteFiles".
     */
    struct DeleteFilesResponse
    {
        /**
         * Constructs a DeleteFilesResponse object with default parameters.
         */
        DeleteFilesResponse() :
            fileNames(std::vector<std::string>()),
            info(std::map<std::string, std::string>())
        {
        }

        /**
         * Names of the files deleted from KiFS
         */
        std::vector<std::string> fileNames;

        /**
         * Additional information.
         */
        std::map<std::string, std::string> info;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::DeleteFilesResponse>
    {
        static void encode(Encoder& e, const gpudb::DeleteFilesResponse& v)
        {
            ::avro::encode(e, v.fileNames);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::DeleteFilesResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.fileNames);
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
                ::avro::decode(d, v.fileNames);
                ::avro::decode(d, v.info);
            }
        }
    };
} // end namespace avro

#endif // __DELETE_FILES_H__
