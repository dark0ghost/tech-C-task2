//
// Created by  on 28.03.2021.
//

#ifndef TECH_C_MAIN_STRUCT_H
#define TECH_C_MAIN_STRUCT_H
#include <stdio.h>
#pragma pack(push, 1)

struct MainStruct{
    size_t size;
    long total;
    void (*set_data)(char*,size_t);
};
#pragma pack(pop)
#endif //TECH_C_MAIN_STRUCT_H
