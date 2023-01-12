/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banana_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:34:24 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:34:24 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	split_counter(char *in, char delim)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (in[i])
	{
		i = skip_quotes(in, i);
		if (in[i] == delim && i != 0)
		{
			count++;
			while (in[i] == delim)
				i++;
			in += i;
			i = 0;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_copy(char *in, int len)
{
	char	*out;
	int		i;

	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = in[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

static int	loop(char **split, int count, char *in, char delim)
{
	int	k;
	int	i;

	k = 0;
	i = 0;
	while (in[k] && i < count)
	{
		k = skip_quotes(in, k);
		if (in[k] == delim)
		{
			split[i] = ft_copy(in, k);
			if (!split[i])
				return (err_int_id(1, "MALLOC_ERROR copy", split));
			i++;
			while (in[k] == delim)
				k++;
			in += k;
			k = 0;
		}
		else
			k++;
	}
	split[i] = ft_copy(in, ft_strlen(in));
	return (i);
}

/*
Splits the input string by delim
while ignoring every sign inside of quotes.
Only works with closed quotes
*/
char	**banana(char *in, char delim)
{
	int		i;
	int		count;
	char	**split;

	if (!check_quotes(in))
		return (err("QUOTES_OPEN"));
	in += skip_whitesp(in, 0);
	count = split_counter(in, delim);
	split = malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (err("MALLOC_ERROR banana didn`t split"));
	split[count] = NULL;
	i = loop(split, count, in, delim);
	if (!split[i])
		return (err_id(2, "MALLOC_ERROR copy", split));
	return (split);
}
