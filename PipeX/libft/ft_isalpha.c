/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:08:14 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/01/11 10:01:11 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c <= 'Z' && c >= 'A') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
