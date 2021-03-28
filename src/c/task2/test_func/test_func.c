//
// Created by on 26.03.2021.
//
#include <stdlib.h>
#include "stdio.h"
#include "../lib/main_struct.h"



void* test_func(void* arg){
    if (arg == NULL)
        return NULL;
    struct MainStruct* sz = (struct MainStruct*)arg;
    const size_t size_array =  sz->size * 1024 * 1024;

    char* test_array = (char*)malloc(size_array * sizeof(char));
    if (test_array == NULL)
        exit(-1);
    for(size_t i = 0; i < size_array; i = i + 3){
        test_array[i] = '0';
        test_array[i + 1] = '1';
        test_array[i + 2] = '2';
    }
    free(test_array);
    return sz;
}