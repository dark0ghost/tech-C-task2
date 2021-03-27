//
// Created by dark0ghost on 26.03.2021.
//

#include "one_thread.h"
#include <time.h>
#include "stdio.h"

void one_thread(struct Data* one_thread,func_test func, void* arg){
   double diff_sum = 0;
   for(int i = 0; i < one_thread->total; i++) {
       time_t start = time(NULL);
       func(arg);
       time_t end = time(NULL);
       diff_sum +=  difftime(end, start);
   }
   one_thread->diff_time = diff_sum / (double)one_thread->total;
}