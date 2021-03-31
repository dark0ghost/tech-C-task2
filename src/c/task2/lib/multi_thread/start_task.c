//
//  on 26.03.2021.
//
#include "../main_struct.h"
#include <pthread.h>
#include <stdlib.h>


void* start_task(void* (*func) (void*),struct MainStruct* arg){
    if(arg == NULL){
        return NULL;
    }

    pthread_t* tid = (pthread_t*)calloc(arg->total, sizeof(pthread_t));

    if(tid == NULL) {
        return NULL;
    }

    for(long i = 0; i < arg->total; i++) {
        if (pthread_create(&tid[i], NULL, func, arg) != 0) {
            for(long y = 0; y < arg->total; y++) {
                pthread_join(tid[i], NULL);
            }
            return NULL;
        }
    }
    for(long i = 0; i < arg->total; i++) {
        pthread_join(tid[i], NULL);
    }

    return arg;
}