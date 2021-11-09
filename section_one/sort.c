#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sort_helpers.h"
#include "sort.h"

/**
 * @brief Insertion sort algorithm.  Thread Safe.
 * 
 * @param data pointer to start of array of elements
 * @param n_elem number of elements
 * @param data_size size of the data type being sorted in bytes
 * @param compare  Function which takes void pointer to the data type, and determines appropriate order. 
 *                 Returns <=0 if the first argument should come first, > 0 if the second
 */
void * insertion_sort(void * data, 
                      const int n_elem, 
                      const size_t data_size,
                      int (*compare)(const void*,const void*))
{
//    void * key = malloc(data_size);
    char key[data_size];
    int j = 0;
    for(int i = 1; i < n_elem; i++)
    {
        //Hold onto our current item being sorted, cast into a char array
        memcpy(key,data+i*data_size,data_size);
        j = i - 1;
        //Loop down the chain from current item to start of array, exitting when 
        //We no longer need to contine to swap data up a position
        while(j>=0 && (*compare)(data+j*data_size,key) > 0)
        {
            swap(data+j*data_size,data+(j+1)*data_size,data_size);
            j--;
        }
    }
//    free(key);
    return data;
}

/**
 * @brief Selection sort algorithm.  Thread Safe.
 * 
 * @param data pointer to start of array of elements
 * @param n_elem number of elements
 * @param data_size size of the data type being sorted in bytes
 * @param compare  Function which takes void pointer to the data type, and determines appropriate order. 
 *                 Returns <=0 if the first argument should come first, > 0 if the second
 */

void * selection_sort(void * data,
                      const int n_elem,
                      const size_t data_size,
                      int (*compare)(const void*,const void*))
{
    int cur_min;
    for(int i = 0; i < n_elem; i++)
    {
        cur_min = i;
        for(int j = i + 1; j < n_elem; j++)
        {
            if(compare(data+cur_min*data_size,data+j*data_size)>0)
            {
                cur_min = j;
            }
        }
        swap(data+i*data_size,data+cur_min*data_size,data_size);
    }
    return data;
}

