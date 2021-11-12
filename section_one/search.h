#ifndef SEARCH_H
#define SEARCH_H

void * linear_search(void * data,
                     const int n_elem,
                     const size_t data_size,
                     const void * key,
                     int * result,
                     int (*compare)(const void *, const void *));

#endif
