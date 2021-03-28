//
// Created by  on 26.03.2021.
//

#ifndef TECH_C_THREAD_DATA_H
#define TECH_C_THREAD_DATA_H
#include "../lib/func_prototype.h"
#include "../lib/main_struct.h"


extern void* thread_start(struct Data* st, func_test func, void* arg);
#endif //TECH_C_THREAD_DATA_H
