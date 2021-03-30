cmake_minimum_required(VERSION 3.17)
project(tech_c)

set(CMAKE_C_STANDARD 11)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

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

add_library(${PROJECT_NAME}_lib STATIC src/c/task2/lib/start_task.h src/c/task2/lib/main_struct.h src/c/task2/lib/one_thread/start_task.c)
add_library(${PROJECT_NAME}_dynamic_lib SHARED src/c/task2/lib/start_task.h src/c/task2/lib/main_struct.h src/c/task2/lib/multi_thread/start_task.c)


add_executable(stress_test_static src/test/stress_test_static.cpp)
add_executable(stress_test_dynamic src/test/stress_test_dynamic.cpp)


target_link_libraries(stress_test_static PRIVATE ${PROJECT_NAME}_lib GTest::GTest GTest::Main)
target_link_libraries(stress_test_dynamic PRIVATE ${PROJECT_NAME}_dynamic_lib GTest::GTest GTest::Main)

add_test(stress_test_static stress_test_static)
add_test(stress_test_dynamic stress_test_dynamic)






