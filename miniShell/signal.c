/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:36:12 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:36:15 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int sig)
{
	if (sig == SIGINT)
	{
		g_status = 1;
		write(1, "\nWe test a prompt>> ", 20);
		rl_on_new_line();
		rl_redisplay();
	}
}
