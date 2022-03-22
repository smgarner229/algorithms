#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sort_helpers.h"
#include "sort.h"

/**
 * @brief Insertion sort algorithm.  MT-Safe
 * 
 * @param data pointer to start of array of elements
 * @param n_elem number of elements
 * @param data_size size of the data type being sorted in bytes
 * @param compare  Function which takes void pointer to the data type, and determines appropriate order. 
 *                 Returns second argument less first argument
 *                 This means if compare(a,b)=a-b => >0 if a>b, <0 if a<b
 *                 Returns >0 if the first argument should come first, < 0 if the second, = if they are the same
 *                 Chosen to match the convention of strcmp
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
 * @brief Selection sort algorithm.  MT-Safe
 * 
 * @param data pointer to start of array of elements
 * @param n_elem number of elements
 * @param data_size size of the data type being sorted in bytes
 * @param compare  Function which takes void pointer to the data type, and determines appropriate order. 
 *                 Returns second argument less first argument
 *                 This means if compare(a,b)=a-b => >0 if a>b, <0 if a<b
 *                 Returns >0 if the first argument should come first, < 0 if the second, = if they are the same
 *                 Chosen to match the convention of strcmp
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

/**
 * @brief Merge sort merge helper
 * 
 * @param data pointer to start of array of elements
 * @param left offset of the current substack's left most end
 * @param mid pivot middle point, to which the left and right sub array are sorted
 * @param right index of the rightmost element where we will sort until
 * @param data_size size of the data type being sorted in bytes
 * @param compare  Function which takes void pointer to the data type, and determines appropriate order. 
 *                 Returns second argument less first argument
 *                 This means if compare(a,b)=a-b => >0 if a>b, <0 if a<b
 *                 Returns >0 if the first argument should come first, < 0 if the second, = if they are the same
 *                 Chosen to match the convention of strcmp
 */
static void * _merge(void * data,
                    int left,
                    int mid,
                    int right,
                    const size_t data_size,
                    int (*compare)(const void *, const void *))
{
  int n_left = mid - left + 1;
  int n_right = right - mid;
  char L[data_size*n_left];
  char R[data_size*n_right];
  memcpy(L,data+left*data_size,data_size*n_left);
  memcpy(R,data+(mid+1)*data_size,data_size*n_right);
  int l_current = 0;
  int r_current = 0;
  void * src_ptr;
  for(int k = left; k <= right; k++)
  {
    if (l_current == n_left)
      src_ptr=R+(r_current++)*data_size;
    else if (r_current == n_right)
      src_ptr=L+(l_current++)*data_size;
    else if (compare(L+l_current*data_size,R+r_current*data_size)<0)
      src_ptr=L+(l_current++)*data_size;
    else
      src_ptr=R+(r_current++)*data_size;
    memcpy(data+k*data_size,src_ptr,data_size);
  } 
}

/**
 * @brief Merge sort core algorithm, called recursively
 * 
 * @param data pointer to start of array of elements
 * @param left offset of the current substack's left most end
 * @param right index of the rightmost element where we will sort until
 * @param data_size size of the data type being sorted in bytes
 * @param compare  Function which takes void pointer to the data type, and determines appropriate order. 
 *                 Returns second argument less first argument
 *                 This means if compare(a,b)=a-b => >0 if a>b, <0 if a<b
 *                 Returns >0 if the first argument should come first, < 0 if the second, = if they are the same
 *                 Chosen to match the convention of strcmp
 */
static void * _merge_sort(void * data,
                          int left,
                          int right,
                          const size_t data_size,
                          int (*compare)(const void *, const void *))
{
  if (left >= right)
    return data;
  int mid = (left+right)/2;
  _merge_sort(data,left,mid,data_size,compare);
  _merge_sort(data,mid+1,right,data_size,compare);
  _merge(data,left,mid,right,data_size,compare);  
  return data;
}

/**
 * @brief Merge sort algorithm, with signature to match standard soring algorithm  MT-Safe
 * 
 * @param data pointer to start of array of elements
 * @param n_elem number of elements
 * @param data_size size of the data type being sorted in bytes
 * @param compare  Function which takes void pointer to the data type, and determines appropriate order. 
 *                 Returns second argument less first argument
 *                 This means if compare(a,b)=a-b => >0 if a>b, <0 if a<b
 *                 Returns >0 if the first argument should come first, < 0 if the second, = if they are the same
 *                 Chosen to match the convention of strcmp
 */
void * merge_sort(void * data,
		  const int n_elem,
		  const size_t data_size,
		  int (*compare)(const void *, const void *))
{
  _merge_sort(data,0,n_elem-1,data_size,compare);	
  return data;
}

