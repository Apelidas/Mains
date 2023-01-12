/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:59:33 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/09/14 12:21:05 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct input
{
	int	amount;
	int	die;
	int	eat;
	int	sleep;
	int	number;
}				t_input;

typedef struct death
{
	pthread_mutex_t	mut;
	long int		time;
}				t_death;

typedef struct philo
{
	int				pid;
	int				nmeals;
	int				die;
	int				eat;
	int				amount;
	int				sleep;
	sem_t			*print;
	sem_t			*eaten;
	sem_t			*forks;
	sem_t			*death;
	t_death			*lmeal;
	t_death			*start;
	struct philo	*next;
}				t_philo;

typedef struct all
{
	t_philo			*lst;
	t_input			*in;
	sem_t			*death;
	sem_t			*eaten;
	sem_t			*print;
	sem_t			*forks;
	long int		starttime;
	int				*pid;
}				t_all;

size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);

t_all		*create_all(t_input *in);
void		destroy_all(t_all *all);
void		*create_lst(t_all *data);
void		destroy_lst(t_philo *start);
void		kill_all(t_all *data);
void		*thread_rout(void *in);

//						INPUT
t_input		*create_input(void);
int			input_check(int argc, char **argv, t_input **data);
int			check_zero(t_all *data);

//						ERROR_HANDLING
void		*err(char *out);
void		*err_id(int err_id, char *message, void *todel);
int			err_int(char *message);

//						TIME
long int	get_time(void);
long int	get_ms(struct timeval *time);
void		write_ms(long int time, t_philo *philo, char *out);
void		write_death(long int time, t_philo *philo, char *out);

void		routine(t_philo *phil);

#endif