//
// Created by on 26.03.2021.
//
#include <stdlib.h>
#include "test_func.h"


void* test_func(void* arg){
    const size_t size_array = 104857602;
    char* test_array = (char*)malloc(104857602 * sizeof(char));
    for(int i = 0; i < size_array; i = i + 3){
        test_array[i] = '0';
        test_array[i + 1] = '1';
        test_array[i + 2] = '2';
    }
    free(test_array);
    return NULL;
}