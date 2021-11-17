#ifndef SORT_HELPERS_H
#define SORT_HELPERS_H

#include <string.h>
#include <stdio.h>

void swap(void * a,
          void * b,
          const size_t data_size);

int increasing_ints(const void * a, const void * b);
int increasing_doubles(const void * a, const void * b);
#endif
