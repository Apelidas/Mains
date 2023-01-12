/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:32:36 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:32:38 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	just_built_it(t_env	**env_list, char **cmd, t_lst *lst)
{
	if (compare_str(cmd[0], "cd") == 0)
		cd_cmd(*env_list, cmd);
	if (compare_str(cmd[0], "echo") == 0)
		echo_cmd(cmd);
	if (compare_str(cmd[0], "env") == 0)
		env_cmd(*env_list, cmd);
	if (compare_str(cmd[0], "export") == 0)
		export_cmd(*env_list, cmd);
	if (compare_str(cmd[0], "pwd") == 0)
		pwd_cmd();
	if (compare_str(cmd[0], "unset") == 0)
		unset_cmd(env_list, cmd);
	if (compare_str(cmd[0], "exit") == 0)
		exit_cmd(cmd, env_list, lst);
}
