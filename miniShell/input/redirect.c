/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:35:18 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/11/04 17:35:19 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	name_len(char *string, int *i)
{
	int		len;
	char	check;

	check = ' ';
	len = 0;
	if (!string)
		return (-1);
	*i = skip_whitesp(string, *i);
	if (string[*i] == '"' || string[*i] == '\'')
	{
		check = string[*i];
		*i = *i + 1;
	}
	while (string[*i + len] && string[*i + len] != check)
		len++;
	if (string[*i + len] == check)
		len++;
	return (len);
}

static char	*get_file(int help, int len, char *string)
{
	char	*file;

	file = malloc(sizeof(char) * (len + 1));
	if (!file)
		return (err("MALLOC_ERROR redirect"));
	ft_strlcpy(file, &string[skip_whitesp(string, help)], len + 1);
	remove_quotes(file);
	if (file[len - 1] == ' ')
		file[len - 1] = '\0';
	return (file);
}

/*
Gets FILENAME from string, opens file and cuts out filename from string
*/
int	redirect_in(char *string, int i)
{
	int		help;
	int		len;
	int		out;
	char	*file;

	help = i;
	len = name_len(string, &i);
	if (len < 0)
		return (-1);
	file = get_file(help, len, string);
	if (!file)
		return (0);
	if (access(file, F_OK | R_OK) != 0)
		return (err_int("NO_FILE_ACCESS"));
	out = open(file, O_RDWR);
	if (out < 0)
		return (err_int("File didnt say aaaaah"));
	free(file);
	i = skip_whitesp(string, help);
	len += i - help;
	if (string[help + len] == '"' || string[help + len] == '\'')
		len++;
	str_cut(string, help - 1, help + len);
	return (out);
}

void	help_out(char *string, int *len, int *help)
{
	int	tmp;

	tmp = skip_whitesp(string, *help) - 1;
	*len += (tmp - *help);
	if (string[*help + *len] == '"' || string[*help + *len] == '\'')
		len += 1;
	if (string[*help - 1] == '>' || string[*help - 1] == '<')
		*help -= 1;
	if (string[*help - 1] == '>' || string[*help - 1] == '<')
	{
		*help -= 1;
		*len += 1;
	}
	if (string[*help] == '>' || string[*help] == '<')
	{
		*len += 1;
	}
}

/*
Gets FILENAME from string,
opens file
creates file if not existing
cuts out filename from string
*/
int	redirect_out(char *string, int i, int append)
{
	int		help;
	int		len;
	int		out;
	char	*file;

	help = i;
	len = name_len(string, &i);
	if (len < 0)
		return (-1);
	file = get_file(help, len, string);
	if (!file)
		return (0);
	if (append)
		out = open(file, O_RDWR | O_APPEND | O_CREAT, 0777);
	else
		out = open(file, O_RDWR | O_CREAT, 0777);
	if (access(file, R_OK | W_OK) != 0)
		return (err_int_id(0, "NO FILE ACCESS", file));
	if (out < 0)
		return (err_int("File didnt say aaaaah"));
	free(file);
	help_out(string, &len, &help);
	str_cut(string, help, help + len + 1);
	return (out);
}
