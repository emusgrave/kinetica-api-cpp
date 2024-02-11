/*
 *  This file was autogenerated by the Kinetica schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __FILTER_BY_RADIUS_GEOMETRY_H__
#define __FILTER_BY_RADIUS_GEOMETRY_H__

namespace gpudb
{
    /**
     * A set of parameters for @ref
     * GPUdb::filterByRadiusGeometry(const FilterByRadiusGeometryRequest&) const
     * "GPUdb::filterByRadiusGeometry".
     *
     * Calculates which geospatial geometry objects from a table intersect a
     * circle with the given radius and center point (i.e. circular NAI). The
     * operation is synchronous, meaning that a response will not be returned
     * until all the objects are fully available. The response payload provides
     * the count of the resulting set. A new resultant set (view) which
     * satisfies the input circular NAI restriction specification is also
     * created if a @ref viewName is passed in as part of the request.
     */
    struct FilterByRadiusGeometryRequest
    {
        /**
         * Constructs a FilterByRadiusGeometryRequest object with default
         * parameters.
         */
        FilterByRadiusGeometryRequest() :
            tableName(std::string()),
            viewName(std::string()),
            columnName(std::string()),
            xCenter(double()),
            yCenter(double()),
            radius(double()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs a FilterByRadiusGeometryRequest object with the specified
         * parameters.
         *
         * @param[in] tableName_  Name of the table on which the filter by
         *                        radius operation will be performed, in
         *                        [schema_name.]table_name format, using
         *                        standard <a
         *                        href="../../../concepts/tables/#table-name-resolution"
         *                        target="_top">name resolution rules</a>.
         *                        Must be an existing table.
         * @param[in] viewName_  If provided, then this will be the name of the
         *                       view containing the results, in
         *                       [schema_name.]view_name format, using standard
         *                       <a
         *                       href="../../../concepts/tables/#table-name-resolution"
         *                       target="_top">name resolution rules</a> and
         *                       meeting <a
         *                       href="../../../concepts/tables/#table-naming-criteria"
         *                       target="_top">table naming criteria</a>.  Must
         *                       not be an already existing table or view. The
         *                       default value is ''.
         * @param[in] columnName_  Name of the geospatial geometry column to be
         *                         filtered.
         * @param[in] xCenter_  Value of the longitude of the center. Must be
         *                      within [-180.0, 180.0]. The minimum allowed
         *                      value is -180. The maximum allowed value is
         *                      180.
         * @param[in] yCenter_  Value of the latitude of the center. Must be
         *                      within [-90.0, 90.0]. The minimum allowed value
         *                      is -90. The maximum allowed value is 90.
         * @param[in] radius_  The radius of the circle within which the search
         *                     will be performed. Must be a non-zero positive
         *                     value. It is in meters; so, for example, a value
         *                     of '42000' means 42 km. The minimum allowed
         *                     value is 0. The maximum allowed value is
         *                     MAX_INT.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                          <li>@ref
         *                              gpudb::filter_by_radius_geometry_create_temp_table
         *                              "filter_by_radius_geometry_create_temp_table":
         *                              If @ref
         *                              gpudb::filter_by_radius_geometry_true
         *                              "true", a unique temporary table name
         *                              will be generated in the sys_temp
         *                              schema and used in place of @a
         *                              viewName_. This is always allowed even
         *                              if the caller does not have permission
         *                              to create tables. The generated name is
         *                              returned in @ref
         *                              gpudb::filter_by_radius_geometry_qualified_view_name
         *                              "qualified_view_name".
         *                              Supported values:
         *                              <ul>
         *                                  <li>@ref
         *                                      gpudb::filter_by_radius_geometry_true
         *                                      "filter_by_radius_geometry_true"
         *                                  <li>@ref
         *                                      gpudb::filter_by_radius_geometry_false
         *                                      "filter_by_radius_geometry_false"
         *                              </ul>
         *                              The default value is @ref
         *                              gpudb::filter_by_radius_geometry_false
         *                              "filter_by_radius_geometry_false".
         *                          <li>@ref
         *                              gpudb::filter_by_radius_geometry_collection_name
         *                              "filter_by_radius_geometry_collection_name":
         *                              [DEPRECATED--please specify the
         *                              containing schema for the view as part
         *                              of @a viewName_ and use @ref
         *                              GPUdb::createSchema(const CreateSchemaRequest&) const
         *                              "GPUdb::createSchema" to create the
         *                              schema if non-existent]  Name of a
         *                              schema for the newly created view. If
         *                              the schema provided is non-existent, it
         *                              will be automatically created.
         *                      </ul>
         *                      The default value is an empty map.
         */
        FilterByRadiusGeometryRequest(const std::string& tableName_, const std::string& viewName_, const std::string& columnName_, const double xCenter_, const double yCenter_, const double radius_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            viewName( viewName_ ),
            columnName( columnName_ ),
            xCenter( xCenter_ ),
            yCenter( yCenter_ ),
            radius( radius_ ),
            options( options_ )
        {
        }

        /**
         * Name of the table on which the filter by radius operation will be
         * performed, in [ schema_name.\ ]table_name format, using standard <a
         * href="../../../concepts/tables/#table-name-resolution"
         * target="_top">name resolution rules</a>.  Must be an existing table.
         */
        std::string tableName;

        /**
         * If provided, then this will be the name of the view containing the
         * results, in [ schema_name.\ ]view_name format, using standard <a
         * href="../../../concepts/tables/#table-name-resolution"
         * target="_top">name resolution rules</a> and meeting <a
         * href="../../../concepts/tables/#table-naming-criteria"
         * target="_top">table naming criteria</a>.  Must not be an already
         * existing table or view. The default value is ''.
         */
        std::string viewName;

        /**
         * Name of the geospatial geometry column to be filtered.
         */
        std::string columnName;

        /**
         * Value of the longitude of the center. Must be within [-180.0,
         * 180.0]. The minimum allowed value is -180. The maximum allowed value
         * is 180.
         */
        double xCenter;

        /**
         * Value of the latitude of the center. Must be within [-90.0, 90.0].
         * The minimum allowed value is -90. The maximum allowed value is 90.
         */
        double yCenter;

        /**
         * The radius of the circle within which the search will be performed.
         * Must be a non-zero positive value. It is in meters; so, for example,
         * a value of '42000' means 42 km. The minimum allowed value is 0. The
         * maximum allowed value is MAX_INT.
         */
        double radius;

        /**
         * Optional parameters.
         * <ul>
         *     <li>@ref gpudb::filter_by_radius_geometry_create_temp_table
         *         "filter_by_radius_geometry_create_temp_table": If @ref
         *         gpudb::filter_by_radius_geometry_true "true", a unique
         *         temporary table name will be generated in the sys_temp
         *         schema and used in place of @ref viewName. This is always
         *         allowed even if the caller does not have permission to
         *         create tables. The generated name is returned in @ref
         *         gpudb::filter_by_radius_geometry_qualified_view_name
         *         "qualified_view_name".
         *         Supported values:
         *         <ul>
         *             <li>@ref gpudb::filter_by_radius_geometry_true
         *                 "filter_by_radius_geometry_true"
         *             <li>@ref gpudb::filter_by_radius_geometry_false
         *                 "filter_by_radius_geometry_false"
         *         </ul>
         *         The default value is @ref
         *         gpudb::filter_by_radius_geometry_false
         *         "filter_by_radius_geometry_false".
         *     <li>@ref gpudb::filter_by_radius_geometry_collection_name
         *         "filter_by_radius_geometry_collection_name":
         *         [DEPRECATED--please specify the containing schema for the
         *         view as part of @ref viewName and use @ref
         *         GPUdb::createSchema(const CreateSchemaRequest&) const
         *         "GPUdb::createSchema" to create the schema if non-existent]
         *         Name of a schema for the newly created view. If the schema
         *         provided is non-existent, it will be automatically created.
         * </ul>
         * The default value is an empty map.
         */
        std::map<std::string, std::string> options;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::FilterByRadiusGeometryRequest>
    {
        static void encode(Encoder& e, const gpudb::FilterByRadiusGeometryRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.viewName);
            ::avro::encode(e, v.columnName);
            ::avro::encode(e, v.xCenter);
            ::avro::encode(e, v.yCenter);
            ::avro::encode(e, v.radius);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::FilterByRadiusGeometryRequest& v)
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
                            ::avro::decode(d, v.columnName);
                            break;

                        case 3:
                            ::avro::decode(d, v.xCenter);
                            break;

                        case 4:
                            ::avro::decode(d, v.yCenter);
                            break;

                        case 5:
                            ::avro::decode(d, v.radius);
                            break;

                        case 6:
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
                ::avro::decode(d, v.columnName);
                ::avro::decode(d, v.xCenter);
                ::avro::decode(d, v.yCenter);
                ::avro::decode(d, v.radius);
                ::avro::decode(d, v.options);
            }
        }
    };
} // end namespace avro

namespace gpudb
{
    /**
     * A set of results returned by @ref
     * GPUdb::filterByRadiusGeometry(const FilterByRadiusGeometryRequest&) const
     * "GPUdb::filterByRadiusGeometry".
     */
    struct FilterByRadiusGeometryResponse
    {
        /**
         * Constructs a FilterByRadiusGeometryResponse object with default
         * parameters.
         */
        FilterByRadiusGeometryResponse() :
            count(int64_t()),
            info(std::map<std::string, std::string>())
        {
        }

        /**
         * The number of records passing the radius filter.
         */
        int64_t count;

        /**
         * Additional information.
         * <ul>
         *     <li>@ref gpudb::filter_by_radius_geometry_qualified_view_name
         *         "filter_by_radius_geometry_qualified_view_name": The fully
         *         qualified name of the view (i.e. including the schema)
         * </ul>
         * The default value is an empty map.
         */
        std::map<std::string, std::string> info;
    };
} // end namespace gpudb

namespace avro
{
    template<> struct codec_traits<gpudb::FilterByRadiusGeometryResponse>
    {
        static void encode(Encoder& e, const gpudb::FilterByRadiusGeometryResponse& v)
        {
            ::avro::encode(e, v.count);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::FilterByRadiusGeometryResponse& v)
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
} // end namespace avro

#endif // __FILTER_BY_RADIUS_GEOMETRY_H__
