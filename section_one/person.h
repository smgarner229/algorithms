#ifndef PERSON_H
#define PERSON_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "sort_helpers.h"

typedef struct person{
    char * name;
    int age;
    double height;
}Person;

void init_person(Person * person, char* name, const int age, const double height);
void clear_person(Person * person);

void print_person(const Person * person);
void print_ordered(const Person * people, const size_t n_people, const char* ordering_criterea);

int increasing_age(const void * p1, const void * p2);
int decreasing_age(const void * p1, const void * p2);
int increasing_height(const void * p1, const void *p2);
int alphabetically(const void * p1, const void * p2);


#endif
