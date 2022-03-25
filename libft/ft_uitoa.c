/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun-zhe <hyun-zhe@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:16:56 by hyun-zhe          #+#    #+#             */
/*   Updated: 2021/08/23 21:16:18 by hyun-zhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_length(unsigned int n)
{
	int	len;

	len = 0 + (n == 0);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	int		i;
	char	*num;

	i = get_num_length(n);
	num = malloc((i * sizeof(char)) + 1);
	if (!num)
		return (NULL);
	num[i--] = 0;
	if (n == 0)
		num[0] = '0';
	while (n != 0)
	{
		if (n > 0)
			num[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}
