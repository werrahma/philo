/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:22:53 by werrahma          #+#    #+#             */
/*   Updated: 2023/04/11 01:43:20 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_action(void *lst)
{
	t_list	*list;

	list = (t_list *)lst;
	pthread_mutex_lock(list->print);
	list->t_create = ft_gettimeofday();
	pthread_mutex_unlock(list->print);
	while (1)
	{
		pthread_mutex_lock(list->left);
		print_msg("Has Taken a fork", list);
		pthread_mutex_lock(list->right);
		print_msg("Has Taken a fork", list);
		list->check++;
		print_msg("is Eating", list);
		pthread_mutex_lock(list->protect);
		list->eating = ft_gettimeofday();
		pthread_mutex_unlock(list->protect);
		fake_usleep(ft_gettimeofday(), list->t_eat);
		pthread_mutex_unlock(list->left);
		pthread_mutex_unlock(list->right);
		print_msg("is Sleeping", list);
		fake_usleep(ft_gettimeofday(), list->t_sleep);
		print_msg("is thinking", list);
	}
	return (0);
}

void	right_fork(t_list **list)
{
	int	i;

	i = 0;
	while (i < (*list)->num_philo)
	{
		list[i]->right = list[(1 + i) % (*list)->num_philo]->left;
		i++;
	}
}

void	id_philo(t_list **list)
{
	int	i;

	i = 0;
	while (i < (*list)->num_philo)
	{
		list[i]->id = i;
		i++;
	}
}

void	create_philosophers(t_list **list)
{
	int	i;

	i = 0;
	while (i < (*list)->num_philo)
	{
		pthread_create((list[i]->philo), NULL, &philosopher_action, list[i]);
		usleep(100);
		i++;
	}
}
