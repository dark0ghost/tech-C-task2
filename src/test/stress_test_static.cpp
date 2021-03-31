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

    MainStruct test_input = {100, core};

    test_input.set_data = init_array;
    double sum_diff = 0;
    for(int i = 0; i < 100; i++) {
        time_t start = time(nullptr);
        start_task(test_func, &test_input);
        time_t end = time(nullptr);
        sum_diff += static_cast<double>(end - start);
    }
    std::cout << sum_diff / 100 << std::endl;
}

int main(int argc, char **argv){
    ::testing::GTEST_FLAG(catch_exceptions) = true;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}