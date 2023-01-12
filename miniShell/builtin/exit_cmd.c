/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:33:03 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:33:03 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exit_cmd(char **cmd, t_env **env_list, t_lst *lst)
{
	int	nbr;

	if (cmd[1])
		nbr = ft_atoi(cmd[1]);
	else
		nbr = g_status;
	destroy_lst(lst);
	free_env(*env_list);
	exit(nbr % 256);
}
