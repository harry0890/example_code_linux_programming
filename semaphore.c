#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <unistd.h>

sem_t s;

void handler()
{
    sem_post(&s); // release
}

void *singsong(void *param)
{
    sem_wait(&s);
    printf("I had to wait until your signal released me!\n");
}


int main(void)
{
    pthread_t tid;

    int ok = sem_init(&s, 0, 0);
    if( ok == -1){
	perror("Could not create unnamed semaphore");
    }

    signal(SIGINT, handler);

    pthread_create(&tid, NULL, singsong, NULL);
    pthread_exit(NULL); // /* Process will exit when there are no more threads */

    return 0;
}
