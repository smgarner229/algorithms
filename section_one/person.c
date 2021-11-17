#include "person.h"

void init_person(Person * person, char* name, const int age, const double height)
{
    person->name=name;
    person->age=age;
    person->height=height;
}

void print_person(const Person * person)
{
    fprintf(stdout,"%s\t%d\t%f\n",person->name,person->age,person->height);
}

void print_ordered(const Person * people, const size_t n_people, const char* ordering_criterea)
{
   fprintf(stdout, "List of poeople order by %s\n", ordering_criterea);
   fprintf(stdout, "Name\tAge\tHeight\n");
   for(size_t i = 0; i < n_people; i++)
       print_person(people+i);
   fprintf(stdout,"\n");
   return;
}

int increasing_age(const void * p1, const void * p2)
{
    int a1 = ((Person*)p1)->age;
    int a2 = ((Person*)p2)->age;
    return increasing_ints(&a1,&a2);
}

int decreasing_age(const void * p1, const void * p2)
{
    return -1 * increasing_age(p1,p2);
}

int increasing_height(const void * p1, const void *p2)
{
    double h1 = ((Person*)p1)->height;
    double h2 = ((Person*)p2)->height;
    return increasing_doubles(&h1,&h2);
}

int alphabetically(const void * p1, const void * p2)
{
    const char * n1 = ((Person*)p1)->name;
    const char * n2 = ((Person*)p2)->name;
    return strcmp(n1,n2);
}


