/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:59:33 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/09/10 15:57:25 by kkleinsc         ###   ########.fr       */
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
	int	amount;
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
	int				die;
	int				eat;
	int				amount;
	int				sleep;
	long int		lmeal;
	long int		start;
	pthread_mutex_t	*print;
	t_fork			*eaten;
	t_fork			*lfork;
	t_fork			*rfork;
	t_fork			*death;
	struct philo	*next;
}				t_philo;

typedef struct all
{
	t_philo			*lst;
	t_fork			*death;
	t_fork			*eaten;
	t_input			*in;
	pthread_mutex_t	print;
	long int		starttime;
}				t_all;

int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
void		write_ms(long int time, t_philo *phil, char *out);
void		write_death(long int time, t_philo *philo, char *out);

void		destroy_philo(t_philo *todel);
t_philo		*create_t_philo(t_all *data);
t_philo		*philo_list(t_all *data);
void		*destroy_philo_list(t_philo *start);
t_all		*create_all(void);
void		destroy_all(t_all *todel);
void		*philo_death(t_philo *phil);

//						INPUT
t_input		*create_input(void);
int			input_check(int argc, char **argv, t_input *data);

//						ERROR_HANDLING
void		*err(char *out);
void		*err_id(int err_id, char *message, void *todel);
int			err_int(char *message);

//						Time
long int	get_ms(struct timeval *time);
long int	get_time(void);

//						Routine
void		*routine(void *in);
int			check_starve(t_philo *phil);
int			check_death(t_philo *phil);
int			check_ffork(t_fork *tocheck);
int			block_forks(t_philo *phil);
void		unblock_forks(t_philo *phil);

//						Norminette

#endif