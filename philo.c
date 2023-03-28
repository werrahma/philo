/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:16:16 by werrahma          #+#    #+#             */
/*   Updated: 2023/03/28 17:05:27 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// pthread_mutex_t lock;
// pthread_mutex_t lock1;

void    *ft(void *lo)
{
	// pthread_mutex_lock(&lock1);
	t_list *list;
	list = (t_list*)lo;
	pthread_mutex_lock(&list->lock[0]);
	pthread_mutex_lock(&list->lock[1]);
	unsigned long i = 0;
	static int count;
	
	count += 1;
	printf("philo %d is start eating\n", count);
    usleep(100000);
	// while(i < 10000000)
	//     i++;
	printf("philo %d is finish\n", count);
	pthread_mutex_unlock(&list->lock[0]);
	pthread_mutex_unlock(&list->lock[1]);
	return(0);
}

int main(int ac, char **av)
{
    t_list list;
    list.fork = ft_atoi(av[1]);
	list.t_die = ft_atoi(av[2]);
	list.t_eat = ft_atoi(av[3]);
	list.t_sleep = ft_atoi(av[4]);
    // pthread_mutex_t *lock;
	pthread_t t1[2];
	// pthread_t t2;
	int i = 0;
	int philo;
	
	philo = ft_atoi(av[1]);
	list.lock = malloc(sizeof (pthread_mutex_t) *(list.fork));
    int g= 0;
	while(i < fork)
    {
        pthread_mutex_init(&list.lock[i++], NULL);
    }
    i = 0;
    if(!list.lock)
        return(0);
	while(i < philo)
	{
		pthread_create(&(t1[i]), NULL, &ft, &list);
	    i++;
	}
	// usleep(2000000);
	// pthread_create(&t2, NULL, &ft, NULL);
	pthread_join(t1[0], NULL);
	pthread_join(t1[1], NULL);
}