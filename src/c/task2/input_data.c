//
// Created by  on 26.03.2021.
//


#include "input_data.h"
#include "thread_data.h"
#include "one_thread.h"
#include "test_func.h"


int input_data(int (input)(const char *__restrict __format, ...),int (out)(const char *__restrict __format, ...)){
    unsigned long number = 2;
  if(input("%ld",&number) != 1){
      return -1;
  }
  struct ThreadStruct ts= {number,0};
  thread_start(&ts,test_func);
  out("multi thread %f",ts.diff_time);

  struct OneThread ot = {number, 0};
  one_thread(&ot,test_func);
  out("one thread %f",ts.diff_time);


  return 0;
}
