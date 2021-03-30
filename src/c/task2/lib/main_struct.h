//
// Created by  on 28.03.2021.
//

#ifndef TECH_C_MAIN_STRUCT_H
#define TECH_C_MAIN_STRUCT_H
#include <stdio.h>
#pragma pack(push, 1)
struct DataForFunc{
    long total;
    double diff_time;
};

struct MainStruct{
    size_t size;
    struct DataForFunc* data;
    void (*set_data)(char*,size_t);
};
#pragma pack(pop)
#endif //TECH_C_MAIN_STRUCT_H
