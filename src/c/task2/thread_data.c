//
//  on 26.03.2021.
//

#include "thread_data.h"
#include <pthread.h>
#include <time.h>
#include "func_prototype.h"






void thread_start(struct ThreadStruct* st, func_test func){
    pthread_t tid;
    time_t start = time(NULL);
    for(size_t i = 0; i < st->total; i++)
        pthread_create(&tid, NULL, func, (void *)&tid);
    time_t end = time(NULL);
    st->diff_time = difftime(end, start);
    pthread_exit(NULL);
}