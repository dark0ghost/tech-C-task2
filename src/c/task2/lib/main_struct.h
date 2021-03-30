//
// Created by  on 28.03.2021.
//

#ifndef TECH_C_MAIN_STRUCT_H
#define TECH_C_MAIN_STRUCT_H

#pragma pack(push, 1)
struct Data{
    long total;
    double diff_time;
};

struct MainStruct{
    unsigned long size;
    struct Data* data;

};
#pragma pack(pop)
#endif //TECH_C_MAIN_STRUCT_H
