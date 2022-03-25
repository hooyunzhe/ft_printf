/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun-zhe <hyun-zhe.student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:10:11 by hyun-zhe          #+#    #+#             */
/*   Updated: 2021/09/10 22:01:03 by hyun-zhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid(char *base, int base_len)
{
	int		i;
	char	seen[256];

	i = 0;
	while (i < 256)
		seen[i++] = 0;
	if (base_len < 2)
		return (0);
	i = -1;
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (!seen[(int)base[i]])
			seen[(int)base[i]] = 1;
		else
			return (0);
	}
	return (1);
}

int	to_base_write(char *base, unsigned long num, int base_len)
{
	int	chars_written;

	chars_written = 0;
	if (num / base_len > 0)
	{
		chars_written += to_base_write(base, num / base_len, base_len);
	}
	return (chars_written + write(1, &base[num % base_len], 1));
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int	base_len;

	base_len = 0;
	while (base[base_len])
	{
		base_len++;
	}
	if (is_valid(base, base_len))
	{
		return (to_base_write(base, nbr, base_len));
	}
	return (0);
}
