
#include <stdio.h>
#include <stdlib.h>
#include "gen_rand_array.h"

#define DATA_TYPE_MACRO int
#define ARG_DATA_TYPE INT
#define ARRAY_LEN 10
#define DISPLAY_FORMAT_STR "%d\n"

/* 
 * Sorts "some_array" using selection sort;
 * As implemented by https://www.geeksforgeeks.org/selection-sort/
 * */
void selection_sort(DATA_TYPE_MACRO* some_array, const int array_len);

/*
 * Swaps the value between two variables.
 * */
void swap_values(DATA_TYPE_MACRO* value_first, DATA_TYPE_MACRO* value_second);


int main(int argc, char* argv[]) {

  DATA_TYPE_MACRO* test_array = get_rand_array(ARG_DATA_TYPE, ARRAY_LEN);

  selection_sort(test_array, ARRAY_LEN);

  for (int curr_entry = 0; curr_entry < ARRAY_LEN; ++curr_entry) {
  
          printf(DISPLAY_FORMAT_STR, test_array[curr_entry]);
  
  }

  free(test_array);

  return EXIT_SUCCESS;

}


void selection_sort(DATA_TYPE_MACRO* some_array, const int array_len) {

  for (int sorted_arr_end_ind = 0;
            sorted_arr_end_ind < array_len - 1;
            ++sorted_arr_end_ind) {
  
      int index_of_min = sorted_arr_end_ind;
      int unsorted_arr_begin_ind = sorted_arr_end_ind + 1; 

      while (unsorted_arr_begin_ind < array_len) {
     
          if (some_array[unsorted_arr_begin_ind] < some_array[index_of_min]) { 
              index_of_min = unsorted_arr_begin_ind;
          }
          ++unsorted_arr_begin_ind; 

      }

      swap_values(&some_array[index_of_min], &some_array[sorted_arr_end_ind]);

  }

}


void swap_values(DATA_TYPE_MACRO* value_first, DATA_TYPE_MACRO* value_second) {

  DATA_TYPE_MACRO old_first_val = *value_first;
  *value_first = *value_second;
  *value_second = old_first_val;

}

