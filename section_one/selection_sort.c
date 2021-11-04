#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 *
 *
 */
static void swap(void * a,
                 void * b,
                 size_t data_size)
{
    //memcpy from a into temp
    //memcpy from b into a
    //memcpy from temp into b
    char temp[data_size];
    //void * temp = malloc(data_size);
    //void*temp=memcpy(malloc(data_size),a,data_size);
    memcpy(temp,a,data_size);
    memcpy(a,b,data_size);
    memcpy(b,temp,data_size);
    //free(temp);
    
}

/**
 * @brief Selection sort algorithm
 * 
 *
 */
void * selection_sort(void * data, 
                      size_t n_elem, 
                      size_t data_size,
                      int (*compare)(void*,void*))
{
}

int main(int argc, char ** argv)
{
//    void * my_ptr;
//    int * a;
//    a = malloc(sizeof(int)*3);
//    //int a[3];
//    a[0] = 10;
//    a[1] = 20;
//    my_ptr = a;
    int * a, * b;
    a = malloc(sizeof(int));
    b = malloc(sizeof(int));
    *a = 10;
    *b = 20;
    fprintf(stdout, "a:\t%d\tb:\t%d\n",*a,*b);
    for(int i = 0; i < 100000; i++)
        swap(a,b,sizeof(int));
    fprintf(stdout, "a:\t%d\tb:\t%d\n",*a,*b);


    //fprintf(stdout, "%d\n", *(int *)my_ptr);    
    //fprintf(stdout, "%d\n", *(((int *)my_ptr)+1));    
    free(a);
    free(b);
}

