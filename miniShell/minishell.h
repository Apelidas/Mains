/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:36:06 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:36:08 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>

//# define malloc(size) NULL

extern int	g_status;
//		BUILT_IN

typedef struct s_env
{
	char			*env_str;
	char			**var;
	int				check;
	int				index;
	struct s_env	*next;
}				t_env;

typedef struct s_cmd_lst
{
	char				*path;
	char				**cmd;
	char				*delim;
	int					build;
	int					fd_in;
	int					fd_out;
	int					append;
	struct s_cmd_lst	*next;
	struct s_cmd_lst	*prev;
}				t_lst;

/*-----env,export && export_utils-----*/
void	just_built_it(t_env	**env_list, char **cmd, t_lst *lst);
/* environment variable list */
void	env_cmd(t_env *env_list, char **cmd);
void	create_env_list(t_env	**env_list, char **envp);
int		find_char(const char *string, int character);
char	*copy_before_equal(char	*str);
char	*copy_after_equal(char	*str);
char	**env_and_value(char *str);
t_env	*last_node(t_env *head);
t_env	*new_env_node(char *string);
void	add_to_end(t_env **list, t_env *add);
void	print_env(t_env *head);
void	free_env(t_env *list);
void	free_splits(char **splits);

/* export aka sorted env */
void	export_no_arg(t_env *env);
void	export_arg(t_env *env_list, char **arg);
void	export_add_arg(t_env **env_list, char *str);
int		check_size(t_env *list);
int		compare_str(const char *st1, const char *st2);
void	add_index(t_env *env);
char	*unchecked_str(t_env *env, char	*biggest);
void	print_by_index(t_env *env);
void	reset_index(t_env *env);

void	echo_cmd(char **cmd);
/* Change-directory */
void	cd_exec(char	*path, t_env *env_list);
void	cd_cmd(t_env *env_list, char **cmd);
void	change_old_pwd(t_env **env_list, char *value);
void	print_stderror(const char *str);
/* Unset */
void	unset_cmd(t_env **env_list, char **unset);
char	*change_env_str(char	*env_str, char *env_var, char *value);
void	export_cmd(t_env *env_list, char **arguments);
char	**list_convert_export(t_env *env);
char	**list_convert_env(t_env *env);
char	**list_convert_full(t_env *env);
void	pwd_cmd(void);
void	malloc_exit(void);
void	exit_cmd(char **cmd, t_env **env_list, t_lst *lst);
int		check_split_size(char **cmd);
char	**env_var_size(char **env_var, char *var);
void	add_oldpwd(t_env *env_list);

/*-----INPUT CHECK FUNCTIONS-----*/
void	free_split(char **tofree);
char	**banana(char *in, char delim);
void	print_split(char **split);
int		is_buildin(char *string);
void	clean_split(char **split);

//		INPUT
t_lst	*input_check(char *in, char **envp);
char	**locate_path(char **envp);
char	*search_path(char *argv, char **envp);
int		check_quotes(char *in);
void	remove_quotes(char *split);
void	replace(char **split, char **env);
int		skip_quotes(char *string, int i);
int		skip_whitesp(char *string, int i);
int		pipe_fil(char *string);

//		REDIRECT
int		search_arrow(char **cmd, t_lst *lst);
int		redirect_out(char *string, int i, int append);
int		redirect_in(char *string, int i);
void	delicut(char *string, int len, int help);

//			VAR
int		is_var(char tocheck);
int		find_var_start(char *in);
int		find_var_end(char *in);
char	*find_var(char *string, char **env, int len);
char	*str_insert(char *string, char *toadd, int pos);
void	str_cut(char *string, int start, int end);
void	replace_var(char **split, char **env, int k, int i);

//		LST
t_lst	*create_lst(void);
void	lst_addback(t_lst **start, t_lst *toadd);
void	destroy_lst(t_lst *start);
void	print_lst(t_lst *start);
int		lst_len(t_lst *lst);

//		ERROR
int		err_int(char *message);
int		err_int_id(int id, char *message, void *todel);
void	*err(char *message);
void	*err_id(int id, char *message, void *todel);

/*-----EXECUTE FUNCTIONS-----*/
int		here_doc(int fd, char *delim);
void	child(t_lst *lst, int out, int in, t_env *env);
void	execute(t_lst *lst, t_env **env);
void	single(t_lst *lst, t_env **env);
int		guardian(t_lst *lst, int out, int *in);
int		parent(t_lst *lst, int file, t_env *env);
void	end(t_lst *lst, int file, t_env *env);
void	builder(t_lst *lst, t_env **env);

/*-----SIGNALS-----*/
void	handler(int sig);

#endif