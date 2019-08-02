#include <stdio.h>
#include <pthread.h>


volatile int sum = 0; // share global variable

pthread_mutex_t mutex_key = PTHREAD_MUTEX_INITIALIZER;


void *countgold(void *param)
{
    int i;
    int local = 0;

    
    for(i = 0; i<1000000; i++)
	local += 1; // critical section
    
//-----------------------------------------//
// Other threads that call lock will have to wait until we call unlock
    pthread_mutex_lock(&mutex_key);

    sum += local;

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
