//
// Created by dark0ghost on 31.03.2021.
//

#include <iostream>
#include <gtest/gtest.h>
#include <cstdlib>
#include <cstdio>
#include <dlfcn.h>
#include <zlib.h>



/*extern "C" {
#include "libtech_c_dynamic_lib.h"

void init_array(char* test_array, size_t size_array){
    for(size_t i = 0; i < size_array; i = i + 4){
        test_array[i] = '0';
        test_array[i + 1] = '1';
        test_array[i + 2] = '2';
        test_array[i + 3] = '3';
    }
}

void* test_func(void* arg){
    if (arg == nullptr)
        return nullptr;
    struct MainStruct* sz = (struct MainStruct*)arg;
    const size_t size_array =  sz->size * 1024 * 1024;

    char* test_array = (char*)malloc(size_array * sizeof(char));
    if (test_array == nullptr)
        return nullptr;

    sz->set_data(test_array,size_array);
    free(test_array);
    return sz;
}
}



TEST(stress_test, tests_input) {

    long core = sysconf(_SC_NPROCESSORS_ONLN);

    struct DataForFunc data = {core, 0};
    struct MainStruct main_struct = {100, &data};
    main_struct.set_data = init_array;
    start_task(test_func, &main_struct);
    printf("one thread %f\n", main_struct.data->diff_time);
}*/

int main(int argc, char **argv){
    ::testing::GTEST_FLAG(catch_exceptions) = true;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}