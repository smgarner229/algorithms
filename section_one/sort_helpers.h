#ifndef SORT_HELPERS_H
#define SORT_HELPERS_H

#include <string.h>
#include <stdio.h>

/**
 * @brief Swaps data_size bytes of memory starting at locations a and b
 *
 * @param a location in memory
 * @param b location in memory
 * @param data_size size (in bytes) of data to swap
 *
 */
void swap(void * a,
          void * b,
          const size_t data_size)
{
    char temp[data_size];
    memcpy(temp,a,data_size);
    memcpy(a,b,data_size);
    memcpy(b,temp,data_size);
}

#endif
