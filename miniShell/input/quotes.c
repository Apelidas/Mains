/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:35:02 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:35:02 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_quotes(char *string)
{
	char	quote;
	int		i;

	i = 0;
	quote = 0;
	while (string[i])
	{
		if (string[i] == '"' || string[i] == '\'')
		{
			quote = string[i];
			i++;
		}
		while (quote != 0 && string[i] && string[i] != quote)
			i++;
		if (string[i] == quote)
			quote = 0;
		if (string[i])
			i++;
	}
	if (quote != 0)
		return (0);
	return (1);
}

void	remove_quotes(char *split)
{
	int	k;
	int	check;

	k = 0;
	check = 0;
	while (split[k + check])
	{
		if (split[k + check])
			split[k] = split[k + check];
		else
			break ;
		if ((split[k + check] == '"' || split[k + check] == 39))
			check++;
		else
			k++;
	}
	split[k] = '\0';
}
