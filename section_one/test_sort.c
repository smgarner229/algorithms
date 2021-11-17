#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "search.h"
#include "person.h"


int main(int argc, char**argv)
{
    Person * people = malloc(sizeof(Person)*4);
    init_person(people,"Rich",45,2.0);
    init_person(people+1,"Sally",8,1.0);
    init_person(people+2,"Alice",88,1.5);
    init_person(people+3,"Bob",25,2.2);

    typedef int(sort_criterea)(const void *, const void *);

    sort_criterea * sort_list = malloc(sizeof(sort_criterea)*4);

//    sort_criterea sort_list[4];
    
    sort_list = &increasing_age;
    sort_list++;
    sort_list + 1 = alphabetically;
    sort_list++;
    sort_list = &decreasing_age;
    sort_list++;
    sort_list = &increasing_height;
    sort_list-=3;
/*
    sort_list[0] = &increasing_age;
    sort_list[1] = alphabetically;
    sort_list[2] = &decreasing_age;
    sort_list[3] = &increasing_height;
    */

    for(int i = 0; i < 4; i++)
    {
        insertion_sort(people,4,sizeof(Person),sort_list++);
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

