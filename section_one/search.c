#include <stdlib.h>
#include "search.h"

void * linear_search(void * data,
                     const int n_elem,
                     const size_t data_size,
                     const void * key,
                     int * result,
                     int (*compare)(const void *, const void *))
{
    for(int i = 0; i < n_elem; i++)
    {
        if(compare(key,data+i*data_size)==0)
        {
            *result = i;
            return NULL;
        }
    }
    *result = -1;
    return NULL;
}


