#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Swaps data_size bytes of memory starting at locations a and b
 *
 * @param a location in memory
 * @param b location in memory
 * @param data_size size (in bytes) of data to swap
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
 * @brief Insertion sort algorithm.  Thread Safe.
 * 
 * @param data pointer to start of array of elements
 * @param n_elem number of elements
 * @param data_size size of the data type being sorted in bytes
 * @param compare  Function which takes void pointer to the data type, and determines appropriate order. 
 *                 Returns <=0 if the first argument should come first, > 0 if the second
 */
void * insertion_sort(void * data, 
                      size_t n_elem, 
                      size_t data_size,
                      int (*compare)(void*,void*))
{
    char key[data_size];
    int j = 0;
    for(int i = 1; i < n_elem; i++)
    {
        //Hold onto our current item being sorted, cast into a char array
        memcpy(key,((char*)data)+i*data_size,data_size);
        j = i - 1;
        //Loop down the chain from current item to start of array, exitting when 
        while(j>=0 & compare(((char*)data)+j*data_size,key) <= 0)
        {
            swap(((char*)data)+(j+1)*data_size,((char*)data)+(j)*data_size,data_size);
            j--;
        }
    }
}


int comp_ints(void * a, void * b)
{
    int left = *(int *)a;
    int right = *(int *)b;
    return right - left;
}

int comp_doubles(void * a, void * b)
{
    double left = *(double*)a;
    double right = *(double*)b;
    if ((left - right) <= 0)
        return 1;
    return -1;
}

typedef struct my_struct{
    int a;
    char b;
    long long c;
    short d;
    double e;
}my_struct;

int comp_structs(void * a, void * b)
{
    double left = ((my_struct*)a)->e;
    double right= ((my_struct*)b)->e;
    return comp_doubles(&left,&right);
}

int main(int argc, char ** argv)
{

    int sortme[5]={2,5,3,1,4};
    for(int i = 0; i < 5; i++)
        fprintf(stdout,"%d\t",sortme[i]);
    fprintf(stdout,"\n");

    insertion_sort(sortme,5,sizeof(int),&comp_ints);

    for(int i = 0; i < 5; i++)
        fprintf(stdout,"%d\t",sortme[i]);
    fprintf(stdout,"\n");

    double andme[9] = {1.020, 3.2, 3.211, 9.9,1.11,3.2,1.,-12.,0.};
    for(int i = 0; i < 9; i++)
        fprintf(stdout,"%f\t",andme[i]);
    fprintf(stdout,"\n");

    insertion_sort(andme,9,sizeof(double),&comp_doubles);

    for(int i = 0; i < 9; i++)
        fprintf(stdout,"%f\t",andme[i]);
    fprintf(stdout,"\n");


    my_struct alsome[4];
    alsome[0].e=1.0;
    alsome[1].e=2.3;
    alsome[2].e=0.0;
    alsome[3].e=-12.;

    for(int i = 0; i < 4; i++)
        fprintf(stdout,"%f\t",alsome[i].e);
    fprintf(stdout,"\n");


    insertion_sort(alsome,4,sizeof(my_struct),&comp_structs);
    for(int i = 0; i < 4; i++)
        fprintf(stdout,"%f\t",alsome[i].e);
    fprintf(stdout,"\n");

}

