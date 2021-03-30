//
// Created by  on 26.03.2021.
//

#ifndef TECH_C_START_TASK_H
#define TECH_C_START_TASK_H

#include "main_struct.h"

void* start_task(void* (*func) (void*),struct MainStruct* arg);
#endif //TECH_C_START_TASK_H
