/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:16:16 by werrahma          #+#    #+#             */
/*   Updated: 2023/04/05 15:59:46 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// pthread_mutex_t lock;
// pthread_mutex_t lock1;

void	check_die(int t_eat, int t_die, int philo)
{
	// printf("lllllll%d\n", t_eat);
	if(t_die < t_eat)
	{
		printf("time %d philo %d died\n", t_die, philo);
		exit(1);
	}
}

long int	ft_gettimeofday(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	// printf("hi%f\n", (tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	// printf("s:%ld\n", tv.tv_sec);
	// printf("ms:%d\n", tv.tv_usec);
}


void print_msg(char *str, t_list *list)
{
	pthread_mutex_lock(list->print);
	printf("time %lu\t%lu \t %s\n", ft_gettimeofday(), list->id + 1, str);
	pthread_mutex_unlock(list->print);
	
}

void    *ft(void *lo)
{
	int i = 0;
	t_list *list;
	list = (t_list*)lo;
	static int count;
		// usleep(100);
		// usleep(1000);
	while(1)
	{
		pthread_mutex_lock(list->left);
		print_msg("Has Taken a fork", list);
		pthread_mutex_lock(list->right);
		print_msg("Has Taken a fork", list);
		// printf("time %ld philo %lu has taken a left fork\n", ft_gettimeofday(), list->id + 1);
		// printf("time %ld philo %lu has taken a right fork\n", ft_gettimeofday(), list->id + 1);
		// pthread_mutex_unlock(list->print);
		// pthread_mutex_lock(list->print);
		list->a = ft_gettimeofday();
		// printf("time eating is %d\n", list->a);
		// pthread_mutex_unlock(list->print);
		// printf("id : %d\n", list->id);
		// usleep(100000);
		// count += 1;
		// printf("id = %lu\n", list[i].id);
		// if(list[i].id == 0)
		// pthread_mutex_lock(list->print);
		print_msg("is Eating", list);
		// printf("time %lu philo %lu starts eating\n", ft_gettimeofday(), list->id + 1);
		// pthread_mutex_unlock(list->print);
		usleep(list->t_eat * 1000);
		pthread_mutex_unlock(list->left);
		pthread_mutex_unlock(list->right);
		// pthread_mutex_lock(list->print);
		// printf("time %lu philo %lu starts sleeping\n", ft_gettimeofday(), list->id + 1);
		print_msg("is Sleeping", list);
		usleep(list->t_sleep * 1000);
		// pthread_mutex_unlock(list->print);
	}
	return(0);
}

int main(int ac, char **av)
{
    t_list **list;
	int i = 0;
	// struct timeval tv;
	// gettimeofday(&tv, NULL);
	// printf("s:%ld\n", tv.tv_sec);
	// printf("ms:%d\n", tv.tv_usec);
	list = malloc(sizeof(t_list*)*ft_atoi(av[1]));
	while(i < ft_atoi(av[1]))
	{
		list[i] = malloc(sizeof(t_list));
		list[i]->fork = ft_atoi(av[1]);
		list[i]->t_die = ft_atoi(av[2]);
		list[i]->t_eat = ft_atoi(av[3]);
		list[i]->t_sleep = ft_atoi(av[4]);
		i++;
	}
	i = 0;
	(*list)->a = 0;
	int philo;
	pthread_mutex_t *print;
	print = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(print, NULL);
	philo = ft_atoi(av[1]);
    int g= 0;
	while(i < (*list)->fork)
    {
		list[i]->left = malloc(sizeof (pthread_mutex_t));
		list[i]->philo = malloc(sizeof(pthread_t));
		list[i]->print = print;
        pthread_mutex_init(list[i]->left, NULL);
		i++;
    }
	i = 0;
	while(i < (*list)->fork )
	{
		list[i]->right = list[(1 + i) % philo]->left;
		i++;
	}
    i = 0;
    if(!(*list)->left)
        return(0);
	while(i < (*list)->fork)
	{
		(*(list + i))->id = i;
		i++;
	}
	i = 0;
	while(i < philo)
	{
		pthread_create((list[i]->philo), NULL, &ft, list[i]);
		usleep(100);
	    i++;
	}
	i = 0;
	// while (1)
	// {
	// 	i = 0;
	// 	while(i < philo)
	// 	{
	// 		check_die((ft_gettimeofday() - list[i]->a), (*list)->t_die, i);
	// 		i++;
	// 	}
	// }
	i = 0;
	while(i < philo)
		pthread_join(*list[i++]->philo, NULL);
}
