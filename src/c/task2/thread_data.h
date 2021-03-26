//
// Created by  on 26.03.2021.
//

#ifndef TECH_C_THREAD_DATA_H
#define TECH_C_THREAD_DATA_H
#include "func_prototype.h"
struct ThreadStruct{
    const unsigned long total;
    double diff_time;
};

void thread_start(struct ThreadStruct* st, func_test func);
#endif //TECH_C_THREAD_DATA_H
