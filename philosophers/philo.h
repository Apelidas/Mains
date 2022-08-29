/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:59:33 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/08/29 13:41:11 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct input
{
	int	die;
	int	eat;
	int	sleep;
	int	number;
}				t_input;

typedef struct fork
{
	pthread_mutex_t	mut;
	int				bol;
}				t_fork;

typedef struct philo
{
	int				pid;
	int				nmeals;
	long int		lmeal;
	t_fork			*lfork;
	t_fork			*rfork;
	pthread_mutex_t	*death;
	struct philo	*next;
}				t_philo;

typedef struct all
{
	t_philo			*lst;
	pthread_mutex_t	death;
	t_input			*in;
	long int		starttime;
}				t_all;

int			ft_atoi(const char *str);

void		destroy_philo(t_philo *todel);
t_philo		*create_t_philo(void);
t_philo		*philo_list(int amount);
void		*destroy_philo_list(t_philo *start);
t_all		*create_all(void);
void		destroy_all(t_all *todel);

//						INPUT
t_input		*create_input(void);
int			input_check(int argc, char **argv, t_input *data);

//						ERROR_HANDLING
void		*err(char *out);
void		*philo_err(t_philo *todel, char *out);
void		*philo_lst_err(t_philo *start, char *out);

//						Time
long int	get_ms(struct timeval *time);

#endif