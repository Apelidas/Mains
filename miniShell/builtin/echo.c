/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:32:52 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:32:52 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	echo_cmd(char **cmd)
{
	int		i;
	char	n;

	i = 1;
	n = '\n';
	if (!cmd[1] || !cmd[1][0])
	{
		printf("\n");
		return ;
	}
	if (compare_str(cmd[1], "-n") == 0)
	{
		n = 0;
		i++;
	}
	while (cmd[i])
	{
		printf("%s", cmd[i]);
		i++;
	}
	if (n != 0)
		printf("%c", n);
	g_status = 0;
}
