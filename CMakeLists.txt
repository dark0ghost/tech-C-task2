cmake_minimum_required(VERSION 3.17)
project(tech_c)

set(CMAKE_C_STANDARD 11)

#set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
#set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic -fpermissive")
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

add_executable(tech_c src/c/main.c src/c/task2/input_data.c src/c/task2/input_data.h src/c/task2/multi_thread/thread_data.c src/c/task2/multi_thread/thread_data.h src/c/task2/one_thread/one_thread.c src/c/task2/one_thread/one_thread.h src/c/task2/lib/func_prototype.h src/c/task2/test_func/test_func.c src/c/task2/test_func/test_func.h src/c/task2/lib/main_struct.h)


add_executable(test_program src/test/test.cpp)

add_library(${PROJECT_NAME}_lib STATIC src/c/task2/one_thread/one_thread.h src/c/task2/one_thread/one_thread.c)
add_library(${PROJECT_NAME}_dynamic_lib SHARED src/c/task2/multi_thread/thread_data.h src/c/task2/multi_thread/thread_data.c)

add_executable(stress_test src/test/stress_test.cpp)

add_test(test_program test_program)

add_test(stress_test stress_test)

target_link_libraries(tech_c Threads::Threads)
target_link_libraries(test_program GTest::GTest GTest::Main)

target_link_libraries(stress_test  ${PROJECT_NAME}_lib ${PROJECT_NAME}_dynamic_lib GTest::GTest GTest::Main)




