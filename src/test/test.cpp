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

TEST(multi_thread_test, tests_thread){

    struct Data data = {1,1};
    EXPECT_EQ(thread_start(&data,test_func,nullptr),NULL);
}

TEST(one_thread_test, tests_one_thread){

    struct Data data = {1,1};
    EXPECT_EQ(one_thread(&data,test_func,nullptr),NULL);
}

TEST(test_func_test, tests_one_thread) {
    EXPECT_EQ(test_func(nullptr),NULL);
}



int main(int argc, char **argv){
    ::testing::GTEST_FLAG(catch_exceptions) = true;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}






