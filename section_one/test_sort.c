#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

int count_calls = 0;

int increasing_ints(void * a, void * b)
{
    int left = *(int*)a;
    int right = *(int*)b;
    return left - right;
}

int increasing_doubles(void * a, void * b)
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

void print_bits(Person people)
{
    for(int bit=0;bit<(sizeof(int)*8);bit++)
    {
        printf("%i",people.age&0x01);
        people.age = people.age >> 1;
    }
    printf("\n");
}


int increasing_age(void * p1, void * p2)
{
    int a1 = ((Person*)p1)->age;
    int a2 = ((Person*)p2)->age;
    return increasing_ints(&a1,&a2);
}

int decreasing_age(void * p1, void * p2)
{
    return -1 * increasing_age(p1,p2);
}

int alphabetically(void * p1, void * p2)
{
    count_calls++;
    fprintf(stdout,"Calls to alphabetical sort:\t%d\n",count_calls);
    char n1[20], n2[20];
    print_bits(*((Person*)p1));
    strcpy(n1,((Person*)p1)->name);
    strcpy(n2,((Person*)p2)->name);
//    char * n1 = ((Person*)p1)->name;
//    char * n2 = ((Person*)p2)->name;
    return strcmp(n1,n2);
}

void init_person(Person * person, char* name, int age, double height)
{
    person->name=name;
    person->age=age;
    person->height=height;
}

void print_ordered(Person * people, size_t n_people, char* ordering_criterea)
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
    Person people[4];
    init_person(&people[0],"Rich",25,2.0);
    init_person(&people[1],"Sally",8,1.0);
    init_person(&people[2],"Alice",88,1.5);
    init_person(&people[3],"Bob",55,2.2);

    print_ordered(people,4,"nothing");

    print_bits(people[0]);

    selection_sort(people,4,sizeof(Person),&alphabetically);
    print_ordered(people,4,"alphabetically");
    
    insertion_sort(people,4,sizeof(Person),&increasing_age);
    print_ordered(people,4,"increasing age");

    selection_sort(people,4,sizeof(Person),&alphabetically);
    print_ordered(people,4,"alphabetically");

    insertion_sort(people,4,sizeof(Person),&increasing_age);
    print_ordered(people,4,"increasing age");

//    insertion_sort(people,4,sizeof(Person),&decreasing_age);
//    print_ordered(people,4,"decreasing age");

    insertion_sort(people,4,sizeof(Person),&alphabetically);
    print_ordered(people,4,"alphabetically");
}

