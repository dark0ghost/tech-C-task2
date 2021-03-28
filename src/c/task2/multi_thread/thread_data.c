//
//  on 26.03.2021.
//

#include "thread_data.h"
#include <pthread.h>
#include <time.h>
#include <stdlib.h>


extern void* thread_start(struct Data* st, func_test func,  void* arg){
    if(arg == NULL){
        return NULL;
    }
    pthread_t* tid = (pthread_t*)calloc(st->total, sizeof(pthread_t));
    time_t start = time(NULL);

    for(long i = 0; i < st->total; i++)
        if(pthread_create(&tid[i], NULL, func, arg)!= 0)
            return NULL;
    for(long i = 0; i < st->total; i++)
        pthread_join(tid[i],NULL);

    time_t end = time(NULL);

    st->diff_time = difftime(end, start);
    return NULL;
}