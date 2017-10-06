/*
 *  This file was autogenerated by the GPUdb schema processor.
 *
 *  DO NOT EDIT DIRECTLY.
 */
#ifndef __GPUDB_COLUMN_PROPERTIES__H__
#define __GPUDB_COLUMN_PROPERTIES__H__

#include <string>


namespace gpudb
{
    namespace ColumnProperty
    {

        /**
         * Default property for all numeric and string type columns; makes the
         * column available for GPU queries.
         */
        extern const std::string DATA;


        /**
         * Valid only for 'string' columns. Enables full text search for string
         * columns. Can be set independently of *data* and *store_only*.
         */
        extern const std::string TEXT_SEARCH;


        /**
         * Persist the column value but do not make it available to queries
         * (e.g. /filter/bybox)-i.e. it is mutually exclusive to the 'data'
         * property. Any 'bytes' type column must have a 'store_only' property.
         * This property reduces system memory usage.
         */
        extern const std::string STORE_ONLY;


        /**
         * Works in conjunction with the 'data' property for string columns.
         * This property reduces system disk usage by disabling reverse string
         * lookups. Queries like /filter, /filter/bylist, and /filter/byvalue
         * work as usual but /aggregate/unique, /aggregate/groupby and
         * /get/records/bycolumn are not allowed on columns with this property.
         */
        extern const std::string DISK_OPTIMIZED;


        /**
         * Valid only for 'long' columns. Indicates that this field represents
         * a timestamp and will be provided in milliseconds since the Unix
         * epoch: 00:00:00 Jan 1 1970.  Dates represented by a timestamp must
         * fall between the year 1000 and the year 2900.
         */
        extern const std::string TIMESTAMP;


        /**
         * Valid only for 'string' columns.  It represents a SQL type
         * NUMERIC(19, 4) data type.  There can be up to 15 digits before the
         * decimal point and up to four digits in the fractional part.  The
         * value can be positive or negative (indicated by a minus sign at the
         * beginning).  This property is mutually exclusive with the
         * 'text_search' property.
         */
        extern const std::string DECIMAL;


        /**
         * Valid only for 'string' columns.  Indicates that this field
         * represents a date and will be provided in the format 'YYYY-MM-DD'.
         * The allowable range is 1000-01-01 through 2900-01-01.  This property
         * is mutually exclusive with the *text_search* property.
         */
        extern const std::string DATE;


        /**
         * Valid only for 'string' columns.  Indicates that this field
         * represents a time-of-day and will be provided in the format
         * 'HH:MM:SS.mmm'.  The allowable range is 00:00:00.000 through
         * 23:59:59.999.  This property is mutually exclusive with the
         * *text_search* property.
         */
        extern const std::string TIME;


        /**
         * Valid only for 'string' columns.  Indicates that this field
         * represents a datetime and will be provided in the format 'YYYY-MM-DD
         * HH:MM:SS.mmm'.  The allowable range is 1000-01-01 00:00:00.000
         * through 2900-01-01 23:59:59.999.  This property is mutually
         * exclusive with the *text_search* property.
         */
        extern const std::string DATETIME;


        /**
         * This property provides optimized memory, disk and query performance
         * for string columns. Strings with this property must be no longer
         * than 1 character. This property cannot be combined with
         * *text_search*
         */
        extern const std::string CHAR1;


        /**
         * This property provides optimized memory, disk and query performance
         * for string columns. Strings with this property must be no longer
         * than 2 characters. This property cannot be combined with
         * *text_search*
         */
        extern const std::string CHAR2;


        /**
         * This property provides optimized memory, disk and query performance
         * for string columns. Strings with this property must be no longer
         * than 4 characters. This property cannot be combined with
         * *text_search*
         */
        extern const std::string CHAR4;


        /**
         * This property provides optimized memory, disk and query performance
         * for string columns. Strings with this property must be no longer
         * than 8 characters. This property cannot be combined with
         * *text_search*
         */
        extern const std::string CHAR8;


        /**
         * This property provides optimized memory, disk and query performance
         * for string columns. Strings with this property must be no longer
         * than 16 characters. This property cannot be combined with
         * *text_search*
         */
        extern const std::string CHAR16;


        /**
         * This property provides optimized memory, disk and query performance
         * for string columns. Strings with this property must be no longer
         * than 32 characters. This property cannot be combined with
         * *text_search*
         */
        extern const std::string CHAR32;


        /**
         * This property provides optimized memory, disk and query performance
         * for string columns. Strings with this property must be no longer
         * than 64 characters. This property cannot be combined with
         * *text_search*
         */
        extern const std::string CHAR64;


        /**
         * This property provides optimized memory, disk and query performance
         * for string columns. Strings with this property must be no longer
         * than 128 characters. This property cannot be combined with
         * *text_search*
         */
        extern const std::string CHAR128;


        /**
         * This property provides optimized memory, disk and query performance
         * for string columns. Strings with this property must be no longer
         * than 256 characters. This property cannot be combined with
         * *text_search*
         */
        extern const std::string CHAR256;


        /**
         * This property provides optimized memory and query performance for
         * int columns. Ints with this property must be between -128 and +127
         * (inclusive)
         */
        extern const std::string INT8;


        /**
         * This property provides optimized memory and query performance for
         * int columns. Ints with this property must be between -32768 and
         * +32767 (inclusive)
         */
        extern const std::string INT16;


        /**
         * This property provides optimized memory, disk and query performance
         * for string columns representing IPv4 addresses (i.e. 192.168.1.1).
         * Strings with this property must be of the form: A.B.C.D where A, B,
         * C and D are in the range of 0-255.
         */
        extern const std::string IPV4;


        /**
         * Valid only for 'string' and 'bytes' columns. Indicates that this
         * field contains geospatial geometry objects in Well-Known Text (WKT)
         * or Well-Known Binary (WKB) format.
         */
        extern const std::string WKT;


        /**
         * This property indicates that this column will be part of (or the
         * entire) primary key.
         */
        extern const std::string PRIMARY_KEY;


        /**
         * This property indicates that this column will be part of (or the
         * entire) shard key.
         */
        extern const std::string SHARD_KEY;


        /**
         * This property indicates that this column is nullable.  However,
         * setting this property is insufficient for making the column
         * nullable.  The user must declare the type of the column as a union
         * between its regular type and 'null' in the avro schema for the
         * record type in @a typeDefinition.  For example, if a column is of
         * type integer and is nullable, then the entry for the column in the
         * avro schema must be: ['int', 'null'].
         * <p>
         * The C++, C#, Java, and Python APIs have built-in convenience for
         * bypassing setting the avro schema by hand.  For those two languages,
         * one can use this property as usual and not have to worry about the
         * avro schema for the record.
         */
        extern const std::string NULLABLE;


        /**
         * This property indicates that this column should be dictionary
         * encoded. It can only be used in conjunction with string columns
         * marked with a charN property. This property is appropriate for
         * columns where the cardinality (the number of unique values) is
         * expected to be low, and can save a large amount of memory.
         */
        extern const std::string DICT;


    } // end namespace ColumnProperty
} // end namespace gpudb


#endif // __GPUDB_COLUMN_PROPERTIES__H__
