/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun-zhe <hyun-zhe.student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:37:42 by hyun-zhe          #+#    #+#             */
/*   Updated: 2021/09/08 14:37:58 by hyun-zhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hex(unsigned long num, int caps)
{
	if (caps)
		return (ft_putnbr_base(num, "0123456789ABCDEF"));
	else
		return (ft_putnbr_base(num, "0123456789abcdef"));
}
