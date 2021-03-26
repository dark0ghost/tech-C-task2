//
// Created by dark0ghost on 26.03.2021.
//

#ifndef TECH_C_ONE_THREAD_H
#define TECH_C_ONE_THREAD_H

#include "func_prototype.h"

struct OneThread{
    unsigned long n;
    double diff_time;

};

void one_thread(struct OneThread* one_thread,func_test func);
#endif //TECH_C_ONE_THREAD_H
