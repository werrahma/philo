/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:16:16 by werrahma          #+#    #+#             */
/*   Updated: 2023/04/17 01:31:40 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_list	**list;

	if (!handling_errors(ac, av) || (ac == 6 && ft_atoi(av[5]) == 0))
	{
		printf("error\n");
		return (0);
	}
	list = malloc(sizeof(t_list *) * ft_atoi(av[1]));
	if (!(list))
		return (0);
	hold_arg(av, list);
	init_all(list);
	right_fork(list);
	id_philo(list);
	create_philosophers(list);
	if (!philosopher_monitor(list, ac))
		return (0);
}
