/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun-zhe <hyun-zhe.student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:10:11 by hyun-zhe          #+#    #+#             */
/*   Updated: 2021/09/08 19:55:53 by hyun-zhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_hexlen(unsigned long num)
{
	size_t	len;

	len = 0;
	if (num / 16 > 0)
	{
		len += ft_hexlen(num / 16);
	}
	return (len + 1);
}
