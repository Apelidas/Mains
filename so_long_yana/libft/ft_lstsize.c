/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:06:29 by ydimitro          #+#    #+#             */
/*   Updated: 2022/01/05 09:06:29 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		temp;

	temp = 0;
	if (lst == NULL)
		return (temp);
	while (lst != NULL)
	{
		lst = lst->next;
		temp++;
	}
	return (temp);
}
