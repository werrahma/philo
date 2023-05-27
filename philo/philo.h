/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:29:41 by werrahma          #+#    #+#             */
/*   Updated: 2023/04/16 23:46:24 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_list
{
	unsigned long	eating;
	pthread_t		*philo;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*print;
	pthread_mutex_t	*protect;
	pthread_mutex_t	*lock;
	unsigned long	t_create;
	unsigned long	t_start;
	int				num_philo;
	unsigned long	t_die;
	unsigned long	t_eat;
	unsigned long	t_sleep;
	unsigned long	id;
	unsigned long	rep;
	unsigned long	check;
}				t_list;

int				ft_atoi(const	char *str);
int				check_die(unsigned long eating, t_list *list);
unsigned long	ft_gettimeofday(void);
void			print_msg(char *str, t_list *list);
void			fake_usleep(unsigned long new_time,
					unsigned long time_sleeping);
int				check_finish(t_list **list);
void			hold_arg(char **av, t_list **list);
void			init_all(t_list **list);
int				philosopher_monitor(t_list **list, int ac);
int				handling_errors(int ac, char **av);
void			right_fork(t_list **list);
void			id_philo(t_list **list);
void			create_philosophers(t_list **list);

#endif