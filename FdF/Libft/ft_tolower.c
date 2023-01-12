/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:20:27 by kkleinsc          #+#    #+#             */
/*   Updated: 2022/01/10 15:02:11 by kkleinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int letter)
{
	if (letter > 64 && letter < 91)
	{
		letter = letter + 32;
	}
	return (letter);
}