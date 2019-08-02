#include <stdio.h>
#include <pthread.h>

int sum = 0; // share global variable

void *countgold(void *param)
{
    int i;
    for(i = 0; i<10000; i++)
	sum += 1;
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
