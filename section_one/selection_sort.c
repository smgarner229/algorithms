#include <stdio.h>
#include <stdlib.h>

/*
 * Generic selection sort algorithm as detailed on page 
 * 
 *
 */
void * selection_sort(void * data, 
                      size_t n_elem, 
                      size_t stride
                      int (*compare)(void*,void*))
{
}

int main(int argc, char ** argv)
{
    void * my_ptr;
    int * a;
    a = malloc(sizeof(int)*3);
    //int a[3];
    a[0] = 10;
    a[1] = 20;
    my_ptr = a;
    fprintf(stdout, "%d\n", *(int *)my_ptr);    
    fprintf(stdout, "%d\n", *(((int *)my_ptr)+1));    
    free(a);
}

