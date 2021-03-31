//
// Created by on 26.03.2021.
//
#include "start_task.h"
#include <stdlib.h>
#include "stdio.h"



void* test_func(void* arg){
    if (arg == NULL)
        return NULL;
    struct MainStruct* sz = (struct MainStruct*)arg;
    const size_t size_array =  sz->size * 1024 * 1024;

    char* test_array = (char*)malloc(size_array * sizeof(char));
    if (test_array == NULL)
        return NULL;

    sz->set_data(test_array,size_array);
    free(test_array);
    return sz;
}