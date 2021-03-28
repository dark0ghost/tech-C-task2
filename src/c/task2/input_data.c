//
// Created by  on 26.03.2021.
//


#include "input_data.h"
#include "one_thread/one_thread.h"
#include "test_func/test_func.h"
#include "multi_thread/thread_data.h"
#include <pthread.h>
#include <stdio.h>
#include <zlib.h>


int input_data(int (input)(const char *__restrict __format, ...),int (out)(const char *__restrict __format, ...)) {
    unsigned long number = 2;
    if (input("%ld", &number) != 1) {
        return -1;
    }
    auto core = sysconf(_SC_NPROCESSORS_ONLN);
    struct Data data = {core, 0};
    struct MainStruct main_struct = {number, &data};
    one_thread(&data, test_func, &main_struct);

    out("one thread %f\n", data.diff_time);

    thread_start(&data, test_func, &number);
    out("multi thread %f", data.diff_time);
    pthread_exit(NULL);
}
