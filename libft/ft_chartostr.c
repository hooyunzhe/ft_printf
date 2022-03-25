/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun-zhe <hyun-zhe@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:15:20 by hyun-zhe          #+#    #+#             */
/*   Updated: 2021/08/23 18:37:12 by hyun-zhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chartostr(char c)
{
	char	*str;

	str = malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = 0;
	return (str);
}
