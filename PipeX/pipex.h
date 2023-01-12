/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:48:24 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/08/19 16:39:37 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct input
{
	char	**argv;
	char	**envp;
	int		argc;
}				t_input;

//		INPUT-HANDLING
int		input_check(int argc, char **argv);
int		check_paths(t_input *data);
t_input	*create_input(char **argv, int argc, char **envp);
int		check_doc(char **argv);

//		PROCESSES
int		parent(t_input *data, int *fd, int bon);
int		child(t_input *data, char *path, char **command);
int		bonus(int *fd, t_input *data, int read_end, int i);
int		ending(t_input *data, int *fd);
int		bonus_starter(t_input *data);

//		MISC
char	*search_path(char *argv, char **envp);
void	free_split(char **tofree);
int		locate_path(char **envp);
void	child_helper(int *fd, int file);

//		Norminette
int		pid_check(t_input *data, int pid, char *path, char **command);
void	first_bonus(int *fd, int *file);
void	parent_free(int *fd, int *file, char **command, char *path);
int		create_pipes(int *fd, int *file);
int		starter_badpid(char **command, char *path);

#endif