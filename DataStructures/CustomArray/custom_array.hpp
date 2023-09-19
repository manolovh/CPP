#ifndef CUSTOM_ARRAY_HPP
#define CUSTOM_ARRAY_HPP

typedef struct 
{
    int array[50];
    size_t size;
    size_t length;
} Array;


int get(Array *arr, int idx);

void set(Array *arr, int idx, int value);

double avg(Array *arr);

int max(Array *arr);

#endif