/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:16:16 by werrahma          #+#    #+#             */
/*   Updated: 2023/04/11 01:31:50 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_list	**list;
	int		i;

	i = 0;
	if (!handling_errors(ac, av))
	{
		printf("eroor\n");
		return (0);
	}
	list = malloc(sizeof(t_list *) * ft_atoi(av[1]));
	if (!(*list))
		return (0);
	hold_arg(av, list);
	init_all(list);
	right_fork(list);
	id_philo(list);
	create_philosophers(list);
	usleep(100);
	if (!philosopher_monitor(list, ac))
		return (0);
	i = 0;
	while (i < (*list)->num_philo)
		pthread_join(*list[i++]->philo, NULL);
}
