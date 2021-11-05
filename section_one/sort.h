#ifndef SORT_H
#define SORT_H

void * selection_sort(void * data,
                      size_t n_elem,
                      size_t data_size,
                      int (*compare)(void*,void*));

void * insertion_sort(void * data, 
                      size_t n_elem, 
                      size_t data_size,
                      int (*compare)(void*,void*));
#endif
