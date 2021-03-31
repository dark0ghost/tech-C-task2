//
// Created by dark0ghost on 28.03.2021.
//

#include <iostream>
#include <gtest/gtest.h>
#include <dlfcn.h>
#include <zlib.h>

extern "C" {
#include "start_task.h"
#include "../c/task2/test_func/test_func.h"
#include "../c/task2/hard_init/hard_init.h"
}


TEST(stress_test, tests_input) {
    long core = sysconf(_SC_NPROCESSORS_ONLN);
    DataForFunc data = {core};
    MainStruct test_input = {100, &data};
    test_input.set_data = init_array;
    start_task(test_func,&test_input);
    std::cout << test_input.data->diff_time << std::endl;
}

int main(int argc, char **argv){
    ::testing::GTEST_FLAG(catch_exceptions) = true;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}