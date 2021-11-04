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
    char temp[data_size];
    memcpy(temp,a,data_size);
    memcpy(a,b,data_size);
    memcpy(b,temp,data_size);
    return;
}

/**
 * @brief Selection sort algorithm
 * 
 * @param data pointer to start of array of elements
 * @param n_elem number of elements
 * @param data_size size of the data type being sorted in bytes
 * @param compare.  takes void pointer to the data type, and determines which is larger. Returns <=0 if the first argument should come first, > 0 if the second
 */
void * selection_sort(void * data, 
                      size_t n_elem, 
                      size_t data_size,
                      int (*compare)(void*,void*))
{
    char key[data_size];
    int j = 0;
    for(int i = 1; i < n_elem; i++)
    {
        memcpy(key,((char*)data)+i*data_size,data_size);
        fprintf(stdout,"Current contents of key:\t%d\n",*(int*)key);
        j = i - 1;
        fprintf(stdout,"First compare gives:\t%d\n",compare(((char*)data)+j*data_size,key) );
        while(j>0 & compare(((char*)data)+j*data_size,key) > 0)
        {
            swap(((char*)data)+(j+1)*data_size,((char*)data)+(j)*data_size,data_size);
            j--;
        }
        memcpy(((char*)data)+(j+1)*data_size,key,data_size);
        for(int i = 0; i < 5; i++)
            fprintf(stdout,"%d\t",*(((int*)data)+i));
        fprintf(stdout,"\n");
    }
}


int comp_ints(void * a, void * b)
{
    int left = *(int *)a;
    int right = *(int *)b;
    return left - right;
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

    int sortme[5]={2,5,3,1,4};
    for(int i = 0; i < 5; i++)
        fprintf(stdout,"%d\t",sortme[i]);
    fprintf(stdout,"\n");

    selection_sort(sortme,5,sizeof(int),&comp_ints);

    for(int i = 0; i < 5; i++)
        fprintf(stdout,"%d\t",sortme[i]);
    fprintf(stdout,"\n");

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

