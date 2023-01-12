/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:32:28 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:32:42 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
if directory has been successfully changed
PWD value changes to the new current directory
and OLDPWD changes to the previous directory
*/
void	change_pwd(t_env *env_list, char *directory)
{
	t_env	*current;

	current = env_list;
	while (current && compare_str(current->var[0], "PWD") != 0)
		current = current->next;
	if (current && compare_str(current->var[0], "PWD") == 0)
	{
		change_old_pwd(&env_list, current->var[1]);
		if (current->var[1] == NULL)
			current->var = env_var_size(current->var, "PWD");
		else
			free (current->var[1]);
		current->var[1] = ft_strdup(directory);
		current->env_str = change_env_str(current->env_str,
				current->var[0], current->var[1]);
	}
	else
		change_old_pwd(&env_list, NULL);
}

static void	print_and_status(void)
{
	print_stderror("Error directory\n");
	g_status = 1;
}

static void	cd_error(char *path)
{
	g_status = 127;
	write(2, "cd: ", 4);
	print_stderror(path);
	write(2, ": ", 2);
	perror("");
}

void	cd_exec(char	*path, t_env *env_list)
{
	char	*current_dir;

	current_dir = NULL;
	if (path == NULL)
	{
		print_and_status();
		return ;
	}
	if (chdir(path) == 0)
	{
		current_dir = getcwd(current_dir, PATH_MAX);
		if (!current_dir)
		{
			print_and_status();
			return ;
		}
		change_pwd(env_list, current_dir);
		g_status = 0;
	}
	else
		cd_error(path);
	if (current_dir)
		free(current_dir);
	return ;
}

void	cd_cmd(t_env *env_list, char **cmd)
{
	int	cmd_nbr;

	cmd_nbr = 0;
	while (cmd[cmd_nbr])
		cmd_nbr++;
	if (cmd_nbr == 2)
		cd_exec(cmd[1], env_list);
	else
		print_stderror("cd: only relative or absolute path\n");
}
