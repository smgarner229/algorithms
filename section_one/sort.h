#ifndef SORT_H
#define SORT_H

#include <stddef.h>

void * selection_sort(void * data,
                      const int n_elem,
                      const size_t data_size,
                      int (*compare)(const void*,const void*));

void * insertion_sort(void * data, 
                      const int n_elem, 
                      const size_t data_size,
                      int (*compare)(const void*,const void*));

void * merge_sort(void * data,
		  const int n_elem,
		  const size_t data_size,
		  int (*compare)(const void *,const void*));

#endif
