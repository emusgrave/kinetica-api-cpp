/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __ALTER_TABLE_H__
#define __ALTER_TABLE_H__

namespace gpudb
{

    /**
     * A set of input parameters for {@link
     * #alterTable(const AlterTableRequest&) const}.
     * <p>
     * Apply various modifications to a table, view, or collection.  The
     * available modifications include the following:
     * <p>
     * Create or delete an <a href="../../concepts/indexes.html#column-index"
     * target="_top">index</a> on a
     * particular column. This can speed up certain operations when using
     * expressions
     * containing equality or relational operators on indexed columns. This
     * only
     * applies to tables.
     * <p>
     * Set the <a href="../../concepts/ttl.html" target="_top">time-to-live
     * (TTL)</a>. This can be applied
     * to tables, views, or collections.  When applied to collections, every
     * contained
     * table & view that is not protected will have its TTL set to the given
     * value.
     * <p>
     * Set the global access mode (i.e. locking) for a table. This setting
     * trumps any
     * role-based access controls that may be in place; e.g., a user with write
     * access
     * to a table marked read-only will not be able to insert records into it.
     * The mode
     * can be set to read-only, write-only, read/write, and no access.
     * <p>
     * Change the <a href="../../concepts/protection.html"
     * target="_top">protection</a> mode to prevent or
     * allow automatic expiration. This can be applied to tables, views, and
     * collections.
     * <p>
     * Manage a <a href="../../concepts/tables.html#partitioning"
     * target="_top">range-partitioned</a>
     * table's partitions.
     * <p>
     * Allow homogeneous tables within a collection.
     * <p>
     * Manage a table's columns--a column can be added, removed, or have its
     * <a href="../../concepts/types.html" target="_top">type and
     * properties</a> modified.
     * <p>
     * Set or unset <a href="../../concepts/compression.html"
     * target="_top">compression</a> for a column.
     */
    struct AlterTableRequest
    {

        /**
         * Constructs an AlterTableRequest object with default parameter
         * values.
         */
        AlterTableRequest() :
            tableName(std::string()),
            action(std::string()),
            value(std::string()),
            options(std::map<std::string, std::string>())
        {
        }

        /**
         * Constructs an AlterTableRequest object with the specified
         * parameters.
         * 
         * @param[in] tableName_  Table on which the operation will be
         *                        performed. Must be an existing table, view,
         *                        or collection.
         * @param[in] action_  Modification operation to be applied
         *                     <ul>
         *                             <li>
         *                     gpudb::alter_table_allow_homogeneous_tables: No
         *                     longer supported; action will be ignored.
         *                             <li> gpudb::alter_table_create_index:
         *                     Creates an <a
         *                     href="../../concepts/indexes.html#column-index"
         *                     target="_top">index</a> on the column name
         *                     specified in @a value. If this column is already
         *                     indexed, an error will be returned.
         *                             <li> gpudb::alter_table_delete_index:
         *                     Deletes an existing <a
         *                     href="../../concepts/indexes.html#column-index"
         *                     target="_top">index</a> on the column name
         *                     specified in @a value. If this column does not
         *                     have indexing turned on, an error will be
         *                     returned.
         *                             <li>
         *                     gpudb::alter_table_move_to_collection: Moves a
         *                     table into a collection @a value.
         *                             <li> gpudb::alter_table_protected: Sets
         *                     whether the given @a tableName should be <a
         *                     href="../../concepts/protection.html"
         *                     target="_top">protected</a> or not. The @a value
         *                     must be either 'true' or 'false'.
         *                             <li> gpudb::alter_table_rename_table:
         *                     Renames a table, view or collection to @a value.
         *                     Has the same naming restrictions as <a
         *                     href="../../concepts/tables.html"
         *                     target="_top">tables</a>.
         *                             <li> gpudb::alter_table_ttl: Sets the <a
         *                     href="../../concepts/ttl.html"
         *                     target="_top">time-to-live</a> in minutes of the
         *                     table, view, or collection specified in @a
         *                     tableName.
         *                             <li> gpudb::alter_table_memory_ttl: Sets
         *                     the time-to-live in minutes for the individual
         *                     chunks of the columns of the table, view, or
         *                     collection specified in @a tableName to free
         *                     their memory if unused longer than the given
         *                     time. Specify an empty string to restore the
         *                     global memory_ttl setting and a value of '-1'
         *                     for an infinite timeout.
         *                             <li> gpudb::alter_table_add_column: Adds
         *                     the column specified in @a value to the table
         *                     specified in @a tableName.  Use @a column_type
         *                     and @a column_properties in @a options to set
         *                     the column's type and properties, respectively.
         *                             <li> gpudb::alter_table_change_column:
         *                     Changes type and properties of the column
         *                     specified in @a value.  Use @a column_type and
         *                     @a column_properties in @a options to set the
         *                     column's type and properties, respectively. Note
         *                     that primary key and/or shard key columns cannot
         *                     be changed. All unchanging column properties
         *                     must be listed for the change to take place,
         *                     e.g., to add dictionary encoding to an existing
         *                     'char4' column, both 'char4' and 'dict' must be
         *                     specified in the @a options map.
         *                             <li>
         *                     gpudb::alter_table_set_column_compression:
         *                     Modifies the <a
         *                     href="../../concepts/compression.html"
         *                     target="_top">compression</a> setting on the
         *                     column specified in @a value.
         *                             <li> gpudb::alter_table_delete_column:
         *                     Deletes the column specified in @a value from
         *                     the table specified in @a tableName.
         *                             <li>
         *                     gpudb::alter_table_create_foreign_key: Creates a
         *                     <a href="../../concepts/tables.html#foreign-key"
         *                     target="_top">foreign key</a> using the format
         *                     '(source_column_name [, ...]) references
         *                     target_table_name(primary_key_column_name [,
         *                     ...]) [as foreign_key_name]'.
         *                             <li>
         *                     gpudb::alter_table_delete_foreign_key: Deletes a
         *                     <a href="../../concepts/tables.html#foreign-key"
         *                     target="_top">foreign key</a>.  The @a value
         *                     should be the foreign_key_name specified when
         *                     creating the key or the complete string used to
         *                     define it.
         *                             <li> gpudb::alter_table_add_partition:
         *                     Partition definition to add (for
         *                     range-partitioned tables only).  See <a
         *                     href="../../concepts/tables.html#partitioning-by-range-example"
         *                     target="_top">range partitioning example</a> for
         *                     example format.
         *                             <li>
         *                     gpudb::alter_table_remove_partition: Name of
         *                     partition to remove (for range-partitioned
         *                     tables only).  All data in partition will be
         *                     moved to the default partition
         *                             <li>
         *                     gpudb::alter_table_delete_partition: Name of
         *                     partition to delete (for range-partitioned
         *                     tables only).  All data in the partition will be
         *                     deleted.
         *                             <li>
         *                     gpudb::alter_table_set_global_access_mode: Sets
         *                     the global access mode (i.e. locking) for the
         *                     table specified in @a tableName. Specify the
         *                     access mode in @a value. Valid modes are
         *                     'no_access', 'read_only', 'write_only' and
         *                     'read_write'.
         *                             <li> gpudb::alter_table_refresh: Replays
         *                     all the table creation commands required to
         *                     create this <a
         *                     href="../../concepts/materialized_views.html"
         *                     target="_top">materialized view</a>.
         *                             <li>
         *                     gpudb::alter_table_set_refresh_method: Sets the
         *                     method by which this <a
         *                     href="../../concepts/materialized_views.html"
         *                     target="_top">materialized view</a> is refreshed
         *                     - one of 'manual', 'periodic', 'on_change'.
         *                             <li>
         *                     gpudb::alter_table_set_refresh_start_time: Sets
         *                     the time to start periodic refreshes of this <a
         *                     href="../../concepts/materialized_views.html"
         *                     target="_top">materialized view</a> to datetime
         *                     string with format 'YYYY-MM-DD HH:MM:SS'.
         *                     Subsequent refreshes occur at the specified time
         *                     + N * the refresh period.
         *                             <li>
         *                     gpudb::alter_table_set_refresh_period: Sets the
         *                     time interval in seconds at which to refresh
         *                     this <a
         *                     href="../../concepts/materialized_views.html"
         *                     target="_top">materialized view</a>.  Also, sets
         *                     the refresh method to periodic if not alreay
         *                     set.
         *                             <li>
         *                     gpudb::alter_table_remove_text_search_attributes:
         *                     remove text_search attribute from all columns,
         *                     if exists.
         *                     </ul>
         * @param[in] value_  The value of the modification. May be a column
         *                    name, 'true' or 'false', a TTL, or the global
         *                    access mode depending on @a action.
         * @param[in] options_  Optional parameters.
         *                      <ul>
         *                              <li> gpudb::alter_table_action
         *                              <li> gpudb::alter_table_column_name
         *                              <li> gpudb::alter_table_table_name
         *                              <li>
         *                      gpudb::alter_table_column_default_value: When
         *                      adding a column, set a default value for
         *                      existing records.  For nullable columns, the
         *                      default value will be null, regardless of data
         *                      type.
         *                              <li>
         *                      gpudb::alter_table_column_properties: When
         *                      adding or changing a column, set the column
         *                      properties (strings, separated by a comma:
         *                      data, store_only, text_search, char8, int8
         *                      etc).
         *                              <li> gpudb::alter_table_column_type:
         *                      When adding or changing a column, set the
         *                      column type (strings, separated by a comma:
         *                      int, double, string, null etc).
         *                              <li>
         *                      gpudb::alter_table_compression_type: When
         *                      setting column compression (@a
         *                      set_column_compression for @a action),
         *                      compression type to use: @a none (to use no
         *                      compression) or a valid compression type.
         *                      <ul>
         *                              <li> gpudb::alter_table_none
         *                              <li> gpudb::alter_table_snappy
         *                              <li> gpudb::alter_table_lz4
         *                              <li> gpudb::alter_table_lz4hc
         *                      </ul>
         *                      The default value is gpudb::alter_table_snappy.
         *                              <li>
         *                      gpudb::alter_table_copy_values_from_column:
         *                      please see add_column_expression instead.
         *                              <li> gpudb::alter_table_rename_column:
         *                      When changing a column, specify new column
         *                      name.
         *                              <li>
         *                      gpudb::alter_table_validate_change_column: When
         *                      changing a column, validate the change before
         *                      applying it. If @a true, then validate all
         *                      values. A value too large (or too long) for the
         *                      new type will prevent any change. If @a false,
         *                      then when a value is too large or long, it will
         *                      be truncated.
         *                      <ul>
         *                              <li> gpudb::alter_table_true: true
         *                              <li> gpudb::alter_table_false: false
         *                      </ul>
         *                      The default value is gpudb::alter_table_true.
         *                              <li>
         *                      gpudb::alter_table_update_last_access_time:
         *                      Indicates whether need to update the
         *                      last_access_time.
         *                      <ul>
         *                              <li> gpudb::alter_table_true
         *                              <li> gpudb::alter_table_false
         *                      </ul>
         *                      The default value is gpudb::alter_table_true.
         *                              <li>
         *                      gpudb::alter_table_add_column_expression:
         *                      expression for new column's values (optional
         *                      with add_column). Any valid expressions
         *                      including existing columns.
         *                      </ul>
         * 
         */
        AlterTableRequest(const std::string& tableName_, const std::string& action_, const std::string& value_, const std::map<std::string, std::string>& options_):
            tableName( tableName_ ),
            action( action_ ),
            value( value_ ),
            options( options_ )
        {
        }

        std::string tableName;
        std::string action;
        std::string value;
        std::map<std::string, std::string> options;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AlterTableRequest>
    {
        static void encode(Encoder& e, const gpudb::AlterTableRequest& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.action);
            ::avro::encode(e, v.value);
            ::avro::encode(e, v.options);
        }

        static void decode(Decoder& d, gpudb::AlterTableRequest& v)
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
                ::avro::decode(d, v.tableName);
                ::avro::decode(d, v.action);
                ::avro::decode(d, v.value);
                ::avro::decode(d, v.options);
            }
        }
    };
}

namespace gpudb
{

    /**
     * A set of output parameters for {@link
     * #alterTable(const AlterTableRequest&) const}.
     * <p>
     * Apply various modifications to a table, view, or collection.  The
     * available modifications include the following:
     * <p>
     * Create or delete an <a href="../../concepts/indexes.html#column-index"
     * target="_top">index</a> on a
     * particular column. This can speed up certain operations when using
     * expressions
     * containing equality or relational operators on indexed columns. This
     * only
     * applies to tables.
     * <p>
     * Set the <a href="../../concepts/ttl.html" target="_top">time-to-live
     * (TTL)</a>. This can be applied
     * to tables, views, or collections.  When applied to collections, every
     * contained
     * table & view that is not protected will have its TTL set to the given
     * value.
     * <p>
     * Set the global access mode (i.e. locking) for a table. This setting
     * trumps any
     * role-based access controls that may be in place; e.g., a user with write
     * access
     * to a table marked read-only will not be able to insert records into it.
     * The mode
     * can be set to read-only, write-only, read/write, and no access.
     * <p>
     * Change the <a href="../../concepts/protection.html"
     * target="_top">protection</a> mode to prevent or
     * allow automatic expiration. This can be applied to tables, views, and
     * collections.
     * <p>
     * Manage a <a href="../../concepts/tables.html#partitioning"
     * target="_top">range-partitioned</a>
     * table's partitions.
     * <p>
     * Allow homogeneous tables within a collection.
     * <p>
     * Manage a table's columns--a column can be added, removed, or have its
     * <a href="../../concepts/types.html" target="_top">type and
     * properties</a> modified.
     * <p>
     * Set or unset <a href="../../concepts/compression.html"
     * target="_top">compression</a> for a column.
     */
    struct AlterTableResponse
    {

        /**
         * Constructs an AlterTableResponse object with default parameter
         * values.
         */
        AlterTableResponse() :
            tableName(std::string()),
            action(std::string()),
            value(std::string()),
            typeId(std::string()),
            typeDefinition(std::string()),
            properties(std::map<std::string, std::vector<std::string> >()),
            label(std::string()),
            info(std::map<std::string, std::string>())
        {
        }

        std::string tableName;
        std::string action;
        std::string value;
        std::string typeId;
        std::string typeDefinition;
        std::map<std::string, std::vector<std::string> > properties;
        std::string label;
        std::map<std::string, std::string> info;
    };
}

namespace avro
{
    template<> struct codec_traits<gpudb::AlterTableResponse>
    {
        static void encode(Encoder& e, const gpudb::AlterTableResponse& v)
        {
            ::avro::encode(e, v.tableName);
            ::avro::encode(e, v.action);
            ::avro::encode(e, v.value);
            ::avro::encode(e, v.typeId);
            ::avro::encode(e, v.typeDefinition);
            ::avro::encode(e, v.properties);
            ::avro::encode(e, v.label);
            ::avro::encode(e, v.info);
        }

        static void decode(Decoder& d, gpudb::AlterTableResponse& v)
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
                            ::avro::decode(d, v.action);
                            break;

                        case 2:
                            ::avro::decode(d, v.value);
                            break;

                        case 3:
                            ::avro::decode(d, v.typeId);
                            break;

                        case 4:
                            ::avro::decode(d, v.typeDefinition);
                            break;

                        case 5:
                            ::avro::decode(d, v.properties);
                            break;

                        case 6:
                            ::avro::decode(d, v.label);
                            break;

                        case 7:
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
                ::avro::decode(d, v.action);
                ::avro::decode(d, v.value);
                ::avro::decode(d, v.typeId);
                ::avro::decode(d, v.typeDefinition);
                ::avro::decode(d, v.properties);
                ::avro::decode(d, v.label);
                ::avro::decode(d, v.info);
            }
        }
    };
}

#endif
