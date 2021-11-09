#ifndef SORT_H
#define SORT_H

void * selection_sort(void * data,
                      const int n_elem,
                      const size_t data_size,
                      int (*compare)(const void*,const void*));

void * insertion_sort(void * data, 
                      const int n_elem, 
                      const size_t data_size,
                      int (*compare)(const void*,const void*));

#endif
