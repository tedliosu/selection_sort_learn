
/* 
 * Author - Ted Li
 *
 * Definitions and macros associated with generation of
 *    an array of random data.
 *
 * */

#include <time.h>

/* Enumerated data type representing possible data types
 * in C; represented types include the following:
 * - char
 * - int
 * - long
 * - float
 * - double
 */
typedef enum {
    CHAR,
    INT,
    LONG,
    FLOAT,
    DOUBLE
} DATA_TYPE_ENUM;


/* Generates a random array of length "array_len" and 
 *   data type specified by "type"; integer-types from minimum
 *   to maximum possible values are returned, whereas
 *   for floating-point types a number between -1 and 1
 *   is returned.
 */
void *get_rand_array(DATA_TYPE_ENUM type, size_t array_len);

