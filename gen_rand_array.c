
#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include "gen_rand_array.h"

#include <stdio.h>

void *get_rand_array(DATA_TYPE_ENUM type, const size_t array_len) {

   void* rand_array = NULL;
   struct timespec curr_time_info;
  
   // Retrieve current system nanoseconds and use as seed for random array generation 
   timespec_get(&curr_time_info, TIME_UTC);
   srand(curr_time_info.tv_nsec);

   // Generate the appropriate random array data structure depending on the DATA_TYPE
   if (type == CHAR) {
     
     char* rand_char_array = malloc(array_len * sizeof(*rand_char_array));

     for (size_t curr_entry = 0; curr_entry < array_len; ++curr_entry) {
        rand_char_array[curr_entry] = (char) (rand() % UCHAR_MAX);    
     }
     
     rand_array = (void*) rand_char_array;
   
   } else if (type == INT) {
     
     int* rand_int_array = malloc(array_len * sizeof(*rand_int_array));

     for (size_t curr_entry = 0; curr_entry < array_len; ++curr_entry) {
        rand_int_array[curr_entry] = (int) ((-1.0 + ((double) rand() * 2.0
                                                        / (double) RAND_MAX))
                                                            * (double) UINT_MAX);
       // compensation for above algorithm generating only even numbers
       if (rand() % 2 != 0) {
          ++rand_int_array[curr_entry];
       }
     }
     
     rand_array = (void*) rand_int_array;
   
   } else if (type == LONG) {
     
     long* rand_long_array = malloc(array_len * sizeof(*rand_long_array));

     for (size_t curr_entry = 0; curr_entry < array_len; ++curr_entry) {
        rand_long_array[curr_entry] = (long) ((-1.0 + ((double) rand() * 2.0
                                                          / (double) RAND_MAX))
                                                            * (double) ULONG_MAX);    
       // compensation for above algorithm generating only even numbers
       if (rand() % 2 != 0) {
          ++rand_long_array[curr_entry];
       }
     }
     
     rand_array = (void*) rand_long_array;
   
   } else if (type == FLOAT) {
     
     float* rand_float_array = malloc(array_len * sizeof(*rand_float_array));

     for (size_t curr_entry = 0; curr_entry < array_len; ++curr_entry) {
        rand_float_array[curr_entry] = -1.0f + ((float) rand() * 2.0f / (float) RAND_MAX);    
     }
     
     rand_array = (void*) rand_float_array;
   
   } else if (type == DOUBLE) {
     
     double* rand_double_array = malloc(array_len * sizeof(*rand_double_array));

     for (size_t curr_entry = 0; curr_entry < array_len; ++curr_entry) {
        rand_double_array[curr_entry] = -1.0 + ((double) rand() * 2.0 / (double) RAND_MAX);    
     }
     
     rand_array = (void*) rand_double_array;
   
   } 
    
   return rand_array;

}



