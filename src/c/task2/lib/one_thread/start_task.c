//
// Created by dark0ghost on 26.03.2021.
//
#include "../start_task.h"
#include "stdio.h"

void* start_task(void* (*func) (void*),struct MainStruct* arg){
   if(arg == NULL) {
       return NULL;
   }

   for(long i = 0; i < arg->total; i++) {
       func(arg);
   }
   return arg;
}