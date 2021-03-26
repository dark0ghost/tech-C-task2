cmake_minimum_required(VERSION 3.17)
project(tech_c)

set(CMAKE_C_STANDARD 11)

#set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
#set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

include(ExternalProject)
ExternalProject_Add(gtest
        URL https://github.com/google/googletest/archive/release-1.10.0.zip
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
        INSTALL_COMMAND ""
        )
ExternalProject_Get_Property(gtest source_dir binary_dir)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

add_executable(tech_c src/c/main.c src/c/task2/input_data.c src/c/task2/input_data.h src/c/task2/thread_data.c src/c/task2/thread_data.h src/c/task2/one_thread.c src/c/task2/one_thread.h src/c/task2/func_prototype.h src/c/task2/test_func.c src/c/task2/test_func.h)


add_executable(test_program src/test/test.cpp)
add_test(test_program test_program)


target_link_libraries(tech_c Threads::Threads)
target_link_libraries(test_program GTest::GTest GTest::Main)



