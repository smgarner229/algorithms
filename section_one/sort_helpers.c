#include "sort_helpers.h"

void swap(void * a,
          void * b,
          const size_t data_size)
{
    char temp[data_size];
    memcpy(temp,a,data_size);
    memcpy(a,b,data_size);
    memcpy(b,temp,data_size);
}

/**
 * @brief Returns int for proper ordering of two ints
 */
int increasing_ints(const void * a, const void * b)
{
    int left = *(int*)a;
    int right = *(int*)b;
    return left - right;
}

/**
 * @brief Returns int for proper ordering of two doubles
 */

int increasing_doubles(const void * a, const void * b)
{
    double left = *(double*)a;
    double right = *(double*)b;
    if((left-right)<=0)
        return -1;
    return 1;
}

