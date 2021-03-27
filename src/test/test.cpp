#include <iostream>
#include <gtest/gtest.h>
#include <cstdlib>

extern "C" {

#include "../c/task2/test_func/test_func.c"
#include "../c/task2/one_thread/one_thread.c"
#include "../c/task2/multi_thread/thread_data.c"
#include "../c/task2/input_data.c"
}

int test_input(const char *__restrict format,...){
    return -1;
}

TEST(inpunt_test, tests_input){
    EXPECT_EQ(input_data(test_input,test_input), -1);
}

int main(int argc, char **argv){
    ::testing::GTEST_FLAG(catch_exceptions) = true;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}






