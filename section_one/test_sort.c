#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "search.h"
#include "person.h"

typedef int(*sort_criterea)(const void *, const void *);

struct _test_functions{
  int size;
  int heap_size;
  sort_criterea * funcs;  
  char ** criterea;
};
typedef struct _test_functions test_functions;

void init_tests(test_functions * suite)
{
  suite->size = 0;
  suite->heap_size = 1;
  suite->funcs = (sort_criterea*)malloc(sizeof(sort_criterea)*suite->heap_size);
  suite->criterea = (char**)malloc(sizeof(char*)*suite->heap_size);
}

void add_test(test_functions * suite, const sort_criterea sort_function, const char * criterea)
{
  if(suite->size >= suite->heap_size)
  {
    suite -> heap_size *= 2;
    suite -> funcs = (sort_criterea*)realloc(suite->funcs,sizeof(sort_criterea)*suite->heap_size);
    suite -> criterea = (char**)realloc(suite->criterea,sizeof(char*)*suite->heap_size);
  }
  suite -> funcs[suite->size] = sort_function;
  suite -> criterea[suite->size] = strdup(criterea);
  suite -> size++;
}

void cleanup_test(test_functions * suite)
{
  free(suite->funcs);
  for(int i = 0; i < suite->size; i++)
  {
    free(suite->criterea[i]);
  }
  free(suite->criterea);
  return;
}

//void run_tests()

int main(int argc, char**argv)
{
    const int n_people = 7;
    test_functions * test_suite = malloc(sizeof(test_functions));
    init_tests(test_suite);

    add_test(test_suite,increasing_age,"age");
    add_test(test_suite,alphabetically,"name");
    add_test(test_suite,decreasing_age,"backward age");
    add_test(test_suite,increasing_height,"height");
    
    Person * people = malloc(sizeof(Person)*n_people);
    init_person(people,"Rich",45,2.0);
    init_person(people+1,"Sally",8,1.0);
    init_person(people+2,"Alice",88,1.5);
    init_person(people+3,"Bob",25,2.2);
    init_person(people+4,"Scort",26,2.2);
    init_person(people+5,"Norg",23,1.8);
    init_person(people+6,"Leo",26,2.0);

    for(int i = 0; i < test_suite->size; i++)
    {
	merge_sort(people,n_people,sizeof(Person),test_suite->funcs[i]);
//#insertion_sort(people,n_people,sizeof(Person),test_suite->funcs[i]);
        print_ordered(people,n_people,test_suite->criterea[i]);
    }
    

    for(int i = 0; i < n_people; i++)
    {clear_person(people+i);}
    free(people);

    cleanup_test(test_suite);
    free(test_suite);
}

