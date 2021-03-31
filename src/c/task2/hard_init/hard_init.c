//
// Created by dark0ghost on 31.03.2021.
//

#include "hard_init.h"


void init_array(char* test_array, size_t size_array){
    for(size_t i = 0; i < size_array; i = i + 4){
        test_array[i] = '0';
        test_array[i + 1] = '1';
        test_array[i + 2] = '2';
        test_array[i + 3] = '3';
    }
}