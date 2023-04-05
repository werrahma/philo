/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:29:41 by werrahma          #+#    #+#             */
/*   Updated: 2023/04/05 15:53:41 by werrahma         ###   ########.fr       */
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
    int				a;
    int             inc;
    pthread_t		*philo;
    pthread_mutex_t	*left;
    pthread_mutex_t	*right;
    pthread_mutex_t	*print;
    unsigned long	fork;
    unsigned long	t_die;
    unsigned long	t_eat;
    unsigned long	t_sleep;
    unsigned long 	id;
} t_list;
int	ft_atoi(const	char *str);

#endif