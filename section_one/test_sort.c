#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

int increasing_ints(const void * a, const void * b)
{
    int left = *(int*)a;
    int right = *(int*)b;
    return left - right;
}

int increasing_doubles(const void * a, const void * b)
{
    double left = *(double*)a;
    double right = *(double*)b;
    if((left-right)<=0)
        return -1;
    return 1;
}

typedef struct person{
    char * name;
    int age;
    double height;
}Person;

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

void init_person(Person * person, char* name, const int age, const double height)
{
    person->name=name;
    person->age=age;
    person->height=height;
}

void print_ordered(const Person * people, const size_t n_people, const char* ordering_criterea)
{
   fprintf(stdout, "List of poeople order by %s\n", ordering_criterea);
   fprintf(stdout, "Name\tAge\tHeight\n");
   for(size_t i = 0; i < n_people; i++)
       fprintf(stdout,"%s\t%d\t%f\n",people[i].name,people[i].age,people[i].height);
   fprintf(stdout,"\n");
   return;
}

int main(int argc, char**argv)
{
    Person * people = malloc(sizeof(Person)*4);
    init_person(people,"Rich",45,2.0);
    init_person(people+1,"Sally",8,1.0);
    init_person(people+2,"Alice",88,1.5);
    init_person(people+3,"Bob",25,2.2);

    typedef int(*sort_criterea)(const void *, const void *);

    sort_criterea sort_list[4];
    sort_list[0] = &increasing_age;
    sort_list[1] = alphabetically;
    sort_list[2] = &decreasing_age;
    sort_list[3] = &increasing_height;

    for(int i = 0; i < 4; i++)
    {
        insertion_sort(people,4,sizeof(Person),sort_list[i]);
        print_ordered(people,4,"idk");
    }

    print_ordered(people,4,"nothing");
 
    insertion_sort(people,4,sizeof(Person),&increasing_age);
    print_ordered(people,4,"increasing age");

    insertion_sort(people,4,sizeof(Person),&alphabetically);
    print_ordered(people,4,"alphabetically");

    insertion_sort(people,4,sizeof(Person),&decreasing_age);
    print_ordered(people,4,"decreasing age");

    insertion_sort(people,4,sizeof(Person),&increasing_height);
    print_ordered(people,4,"height");

    free(people);

}

