//
// Created by dark0ghost on 26.03.2021.
//

#include "one_thread.h"
#include "func_prototype.h"
#include <time.h>

void one_thread(struct OneThread* one_thread,func_test func){
   time_t  start = time(NULL);
   for(int i = 0; i < one_thread->n; i++)
       func(NULL);

    time_t  end = time(NULL);
    one_thread->diff_time = difftime(end, start);
}