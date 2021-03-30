//
// Created by dark0ghost on 26.03.2021.
//
#include "../start_task.h"
#include "../main_struct.h"
#include "stdio.h"
#include <time.h>

void* start_task(void* (*func) (void*),struct MainStruct* arg){
   if(arg == NULL) {
       return NULL;
   }
   struct DataForFunc* one_thread = arg->data;
   if(one_thread == NULL) {
        return NULL;
    }
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