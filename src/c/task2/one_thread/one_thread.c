//
// Created by dark0ghost on 26.03.2021.
//

#include "one_thread.h"
#include <time.h>
#include "stdio.h"

extern void* one_thread(struct Data* one_thread,func_test func, void* arg){
   if(arg == NULL)
       return NULL;

    if(one_thread == NULL)
        return NULL;
   double diff_sum = 0;
   for(long i = 0; i < one_thread->total; i++) {
       time_t start = time(NULL);
       func(arg);
       time_t end = time(NULL);
       diff_sum +=  difftime(end, start);
   }
   one_thread->diff_time = diff_sum / (double)one_thread->total;
    return one_thread;
}