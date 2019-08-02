
// This process runs slower because we lock and unlock the mutex a million times

#include <stdio.h>
#include <pthread.h>

int sum = 0; // share global variable

pthread_mutex_t mutex_key = PTHREAD_MUTEX_INITIALIZER;


void *countgold(void *param)
{
    int i;

//-----------------------------------------//
// Other threads that call lock will have to wait until we call unlock
    pthread_mutex_lock(&mutex_key);
    
    for(i = 0; i<1000000; i++)
	sum += 1; // critical section
    
    pthread_mutex_unlock(&mutex_key);
//----------------------------------------//
    
    return NULL;
}



int main(void)
{
    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, countgold, NULL);
    pthread_create(&tid2, NULL, countgold, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("sum = %d\n", sum);

    return 0;
}
