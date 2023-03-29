/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:16:16 by werrahma          #+#    #+#             */
/*   Updated: 2023/03/29 21:56:15 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// pthread_mutex_t lock;
// pthread_mutex_t lock1;

void    *ft(void *lo)
{
	int i = 0;
	t_list *list;
	list = (t_list*)lo;
	static int count;
		// usleep(100);
	
	while(1)
	{
		// printf("id : %d\n", list->id);
		pthread_mutex_lock(&list->lock[0]);
		pthread_mutex_lock(&list->lock[1]);
		// usleep(100000);
		// count += 1;
		// printf("id = %lu\n", list[i].id);
		// if(list[i].id == 0)
		printf("philo %lu is start eating\n", list->id);
		usleep(1000);
		// if(list[i].id == 0)
			printf("philo %lu is finish\n", list->id);
		pthread_mutex_unlock(&list->lock[0]);
		pthread_mutex_unlock(&list->lock[1]);
	}
	return(0);
}

int main(int ac, char **av)
{
    t_list **list;
	list = malloc(sizeof(t_list*)*ft_atoi(av[1]));
	for (int i =0; i < ft_atoi(av[1]); i++)
	{
		list[i] = malloc(sizeof(t_list));
		list[i]->fork = ft_atoi(av[1]);
		list[i]->t_die = ft_atoi(av[2]);
		list[i]->t_eat = ft_atoi(av[3]);
		list[i]->t_sleep = ft_atoi(av[4]);
	}
    // pthread_mutex_t *lock;
	pthread_t t1[2];
	// pthread_t t2;
	int i = 0;
	int philo;
	
	philo = ft_atoi(av[1]);
    int g= 0;
	while(i < (*list)->fork)
    {
		list[i]->lock = malloc(sizeof (pthread_mutex_t) * 2);
        pthread_mutex_init(&list[i]->lock[0], NULL);
        pthread_mutex_init(&list[i]->lock[1], NULL);
		i++;
    }
    i = 0;
    if(!(*list)->lock)
        return(0);
	while(i < (*list)->fork)
	{
		(*(list + i))->id = i;
		i++;
	}
	// exit(1);
	i = 0;
	while(i < philo)
	{
		printf("##### %d #######\n", i);
		pthread_create(&(t1[i]), NULL, &ft, list[i]);
	    i++;
	}
	// usleep(2000000);
	// pthread_create(&t2, NULL, &ft, NULL);
	pthread_join(t1[0], NULL);
	pthread_join(t1[1], NULL);
}