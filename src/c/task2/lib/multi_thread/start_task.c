//
//  on 26.03.2021.
//
#include "../main_struct.h"
#include <pthread.h>
#include <time.h>
#include <stdlib.h>


void* start_task(void* (*func) (void*),struct MainStruct* arg){
    if(arg == NULL){
        return NULL;
    }
    struct DataForFunc* st = arg->data;
    if(st == NULL) {
        return NULL;
    }
    pthread_t* tid = (pthread_t*)calloc(st->total, sizeof(pthread_t));
    if(tid == NULL) {
        return NULL;
    }
    time_t start = time(NULL);

    for(long i = 0; i < st->total; i++) {
        if (pthread_create(&tid[i], NULL, func, arg) != 0) {
            for(long y = 0; y < st->total; y++) {
                pthread_join(tid[i], NULL);
            }
            return NULL;
        }
    }
    for(long i = 0; i < st->total; i++) {
        pthread_join(tid[i], NULL);
    }

    time_t end = time(NULL);

    st->diff_time = difftime(end, start) / (double)st->total;
    return arg;
}