#include "philo.h"

int mails  = 0;
pthread_mutex_t mutex;
void *f()
{
	int i = 0;
	// printf("hello from threads\n");
    while(i < 10000000)
    {
	pthread_mutex_lock(&mutex);
		i++;
	pthread_mutex_unlock(&mutex);
    }
	mails++;
    printf("%d\n", i);
	return(NULL);
}
// int main()
// {
//     pthread_t t1;
//     pthread_t t2;
// 	pthread_mutex_init(&mutex, NULL);
//     pthread_create(&t1, NULL, &f, NULL);
//     pthread_create(&t1, NULL, &f, NULL);
//     pthread_join(t1, NULL);
//     pthread_join(t2, NULL);
// 	pthread_mutex_destroy(&mutex);
// 	// printf("process id  %d\n", getpid());
// }