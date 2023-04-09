/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:29:41 by werrahma          #+#    #+#             */
/*   Updated: 2023/04/09 16:29:01 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
typedef struct s_list
{
    unsigned long	eating;
    int             inc;
    pthread_t		*philo;
    pthread_mutex_t	*left;
    pthread_mutex_t	*right;
    pthread_mutex_t	*print;
    pthread_mutex_t	*protect;
    unsigned long   t_create;
    unsigned long	fork;
    unsigned long	t_die;
    unsigned long	t_eat;
    unsigned long	t_sleep;
    unsigned long 	id;
    unsigned long	rep;
	unsigned long	check;
} t_list;
int				ft_atoi(const	char *str);
int			check_die(unsigned long eating, unsigned long dying, int philo, t_list *list);
unsigned long	ft_gettimeofday(void);
void			print_msg(char *str, t_list *list);
void			fake_usleep(unsigned long new_time, unsigned long time_sleeping);
void			check_finish(t_list **list);
void	 		hold_arg(char **av, t_list **list);

#endif