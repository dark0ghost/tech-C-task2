//
// Created by dark0ghost on 28.03.2021.
//

#include <iostream>
#include <gtest/gtest.h>
#include <cstdlib>
#include <dlfcn.h>
#include <stdio.h>
#include <zlib.h>

extern "C" {

}
TEST(stress_test, tests_input) {

}

int main(int argc, char **argv){
    ::testing::GTEST_FLAG(catch_exceptions) = true;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}