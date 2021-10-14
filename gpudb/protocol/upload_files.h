/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __UPLOAD_FILES_H__
#define __UPLOAD_FILES_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #uploadFiles(const UploadFilesRequest&) const}.
     * <p>
     * Uploads one or more files to <a href="../../../tools/kifs/"
     * target="_top">KiFS</a>. There are
     * two methods for uploading files: load files in their entirety, or load
     * files in
     * parts. The latter is recommeded for files of approximately 60 MB or
     * larger.
     * <p>
     * To upload files in their entirety, populate @a fileNames with the file
     * names to upload into on KiFS, and their respective byte content in
     * @a fileData.
     * <p>
     * Multiple steps are involved when uploading in multiple parts. Only one
     * file at a
     * time can be uploaded in this manner. A user-provided UUID is utilized to
     * tie all
     * the upload steps together for a given file.  To upload a file in
     * multiple parts:
     * <p>
     * 1. Provide the file name in @a fileNames, the UUID in
     *    the @a multipart_upload_uuid key in @a options, and
     *    a @a multipart_operation value of
     *    @a init.
     * 2. Upload one or more parts by providing the file name, the part data
     *    in @a fileData, the UUID, a @a multipart_operation
     *    value of @a upload_part, and
     *    the part number in the @a multipart_upload_part_number.
     *    The part numbers must start at 1 and increase incrementally.
     *    Parts may not be uploaded out of order.
     * 3. Complete the upload by providing the file name, the UUID, and a
     *    @a multipart_operation value of
     *    @a complete.
     * <p>
     * Multipart uploads in progress may be canceled by providing the file
     * name, the
     * UUID, and a @a multipart_operation value of
     * @a cancel.  If an new upload is
     * initialized with a different UUID for an existing upload in progress,
     * the
     * pre-existing upload is automatically canceled in favor of the new
     * upload.
     * <p>
     * The multipart upload must be completed for the file to be usable in
     * KiFS.
     * Information about multipart uploads in progress is available in
     * {@link #showFiles(const ShowFilesRequest&) const}.
     * <p>
     * File data may be pre-encoded using base64 encoding. This should be
     * indicated
     * using the @a file_encoding option, and is recommended when
     * using JSON serialization.
     * <p>
     * Each file path must reside in a top-level KiFS directory, i.e. one of
     * the
     * directories listed in {@link
     * #showDirectories(const ShowDirectoriesRequest&) const}. The user
     * must have write
     * permission on the directory. Nested directories are permitted in file
     * name
     * paths. Directories are deliniated with the directory separator of '/'.
     * For
     * example, given the file path '/a/b/c/d.txt', 'a' must be a KiFS
     * directory.
     * <p>
     * These characters are allowed in file name paths: letters, numbers,
     * spaces, the
     * path delimiter of '/', and the characters: '.' '-' ':' '[' ']' '(' ')'
     * '#' '='.
     */
    struct UploadFilesRequest
    {

        /**
         * Constructs an UploadFilesRequest object with default parameter
         * values.
         */
        UploadFilesRequest() :
            fileNames(std::vector<std::string>()),
            fileData(std::vector<std::vector<uint8_t> >()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an UploadFilesRequest object with the specified
         * parameters.
         * 
         * @param[in] fileNames_  An array of full file name paths to be used
         *                        for the files
         *                        uploaded to KiFS. File names may have any
         *                        number of nested directories in their
         *                        paths, but the top-level directory must be an
         *                        existing KiFS directory. Each file
         *                        must reside in or under a top-level
         *                        directory. A full file name path cannot be
         *                        larger than 1024 characters.
         * @param[in] fileData_  File data for the files being uploaded, for
         *                       the respective files in @a fileNames.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li> gpudb::upload_files_file_encoding:
         *                      Encoding that has been applied to the uploaded
         *                      file data. When using JSON serialization it is
         *                      recommended to utilize
         *                      @a base64. The caller is responsible
         *                      for encoding the data provided in this payload
         *                      <ul>
         *                              <li> gpudb::upload_files_base64:
         *                      Specifies that the file data being uploaded has
         *                      been base64 encoded.
         *                              <li> gpudb::upload_files_none: The
         *                      uploaded file data has not been encoded.
         *                      </ul>
         *                      The default value is gpudb::upload_files_none.
         *                              <li>
         *                      gpudb::upload_files_multipart_operation:
         *                      Multipart upload operation to perform
         *                      <ul>
         *                              <li> gpudb::upload_files_none: Default,
         *                      indicates this is not a multipart upload
         *                              <li> gpudb::upload_files_init:
         *                      Initialize a multipart file upload
         *                              <li> gpudb::upload_files_upload_part:
         *                      Uploads a part of the specified multipart file
         *                      upload
         *                              <li> gpudb::upload_files_complete:
         *                      Complete the specified multipart file upload
         *                              <li> gpudb::upload_files_cancel: Cancel
         *                      the specified multipart file upload
         *                      </ul>
         *                      The default value is gpudb::upload_files_none.
         *                              <li>
         *                      gpudb::upload_files_multipart_upload_uuid: UUID
         *                      to uniquely identify a multipart upload
         *                              <li>
         *                      gpudb::upload_files_multipart_upload_part_number:
         *                      Incremental part number for each part in a
         *                      multipart upload. Part numbers start at 1,
         *                      increment by 1, and must be uploaded
         *                      sequentially
         *                      </ul>
         * 
         */
        UploadFilesRequest(const std::vector<std::string>& fileNames_, const std::vector<std::vector<uint8_t> >& fileData_, const std::map<std::string, std::string>& options_):
            fileNames( fileNames_ ),
            fileData( fileData_ ),
            options( options_ )
        {
        }

        std::vector<std::string> fileNames;
        std::vector<std::vector<uint8_t> > fileData;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::UploadFilesRequest>
    {
        static void encode(Encoder& e, const gpudb::UploadFilesRequest& v)
        {
            ::avro::encode(e, v.fileNames);
            ::avro::encode(e, v.fileData);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::UploadFilesRequest& v)
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
                            ::avro::decode(d, v.fileData);
                            break;

                        case 2:
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
                ::avro::decode(d, v.fileData);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #uploadFiles(const UploadFilesRequest&) const}.
     * <p>
     * Uploads one or more files to <a href="../../../tools/kifs/"
     * target="_top">KiFS</a>. There are
     * two methods for uploading files: load files in their entirety, or load
     * files in
     * parts. The latter is recommeded for files of approximately 60 MB or
     * larger.
     * <p>
     * To upload files in their entirety, populate @a fileNames with the file
     * names to upload into on KiFS, and their respective byte content in
     * @a fileData.
     * <p>
     * Multiple steps are involved when uploading in multiple parts. Only one
     * file at a
     * time can be uploaded in this manner. A user-provided UUID is utilized to
     * tie all
     * the upload steps together for a given file.  To upload a file in
     * multiple parts:
     * <p>
     * 1. Provide the file name in @a fileNames, the UUID in
     *    the @a multipart_upload_uuid key in @a options, and
     *    a @a multipart_operation value of
     *    @a init.
     * 2. Upload one or more parts by providing the file name, the part data
     *    in @a fileData, the UUID, a @a multipart_operation
     *    value of @a upload_part, and
     *    the part number in the @a multipart_upload_part_number.
     *    The part numbers must start at 1 and increase incrementally.
     *    Parts may not be uploaded out of order.
     * 3. Complete the upload by providing the file name, the UUID, and a
     *    @a multipart_operation value of
     *    @a complete.
     * <p>
     * Multipart uploads in progress may be canceled by providing the file
     * name, the
     * UUID, and a @a multipart_operation value of
     * @a cancel.  If an new upload is
     * initialized with a different UUID for an existing upload in progress,
     * the
     * pre-existing upload is automatically canceled in favor of the new
     * upload.
     * <p>
     * The multipart upload must be completed for the file to be usable in
     * KiFS.
     * Information about multipart uploads in progress is available in
     * {@link #showFiles(const ShowFilesRequest&) const}.
     * <p>
     * File data may be pre-encoded using base64 encoding. This should be
     * indicated
     * using the @a file_encoding option, and is recommended when
     * using JSON serialization.
     * <p>
     * Each file path must reside in a top-level KiFS directory, i.e. one of
     * the
     * directories listed in {@link
     * #showDirectories(const ShowDirectoriesRequest&) const}. The user
     * must have write
     * permission on the directory. Nested directories are permitted in file
     * name
     * paths. Directories are deliniated with the directory separator of '/'.
     * For
     * example, given the file path '/a/b/c/d.txt', 'a' must be a KiFS
     * directory.
     * <p>
     * These characters are allowed in file name paths: letters, numbers,
     * spaces, the
     * path delimiter of '/', and the characters: '.' '-' ':' '[' ']' '(' ')'
     * '#' '='.
     */
    struct UploadFilesResponse
    {

        /**
         * Constructs an UploadFilesResponse object with default parameter
         * values.
         */
        UploadFilesResponse() :
            info(std::map<std::string, std::string>())
        {
        }

        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::UploadFilesResponse>
    {
        static void encode(Encoder& e, const gpudb::UploadFilesResponse& v)
        {
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::UploadFilesResponse& v)
        {
            if (::avro::ResolvingDecoder *rd = dynamic_cast< ::avro::ResolvingDecoder*>(&d))
            {
                const std::vector<size_t> fo = rd->fieldOrder();

                for (std::vector<size_t>::const_iterator it = fo.begin(); it != fo.end(); ++it)
                {
                    switch (*it)
                    {
                        case 0:
                            ::avro::decode(d, v.info);
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
