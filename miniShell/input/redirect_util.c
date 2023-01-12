/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:35:09 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:35:09 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	delicut(char *string, int len, int help)
{
	int	tmp;

	if (string[help + len] == '"' || string[help + len] == '\'')
		len++;
	tmp = skip_whitesp(string, help + 1) - 1;
	len += (tmp - help);
	str_cut(string, help - 1, help + len + 1);
}
