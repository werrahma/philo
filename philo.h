/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:29:41 by werrahma          #+#    #+#             */
/*   Updated: 2023/03/30 01:10:42 by werrahma         ###   ########.fr       */
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
    pthread_mutex_t *lock;
    pthread_mutex_t *right;
    pthread_mutex_t *print;
    unsigned long	fork;
    unsigned long	t_die;
    unsigned long	t_eat;
    unsigned long	t_sleep;
    unsigned long 	id;
} t_list;
int	ft_atoi(const	char *str);

#endif