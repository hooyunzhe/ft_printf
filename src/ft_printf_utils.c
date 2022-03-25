/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun-zhe <hyun-zhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 16:34:43 by hyun-zhe          #+#    #+#             */
/*   Updated: 2021/11/19 13:38:33 by hyun-zhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/ft_printf.h"

int	is_specifier(char c)
{
	return (ft_strchr("cspdiuxX%", c) != NULL);
}

t_format	*get_flags(const char *str)
{
	t_format	*format;

	format = malloc(sizeof(t_format));
	format->left_justify = 0;
	format->lpad_0 = 0;
	format->hash_prefix = 0;
	format->invisible_plus = 0;
	format->force_sign = 0;
	format->min_width = 0;
	format->precision = -1;
	while (!is_specifier(*str) && (!ft_isdigit(*str) || *str == '0'))
	{
		if (*str == '-')
			format->left_justify = 1;
		else if (*str == '0')
			format->lpad_0 = 1;
		else if (*str == '#')
			format->hash_prefix = 1;
		else if (*str == ' ')
			format->invisible_plus = 1;
		else if (*str == '+')
			format->force_sign = 1;
		str++;
	}
	return (format);
}

t_format	*get_format(const char *str)
{
	t_format	*format;

	format = get_flags(str);
	while (!is_specifier(*str))
	{
		if (((!format->min_width && format->precision == -1)
				&& (ft_isdigit(*str) && *str != '0')))
			format->min_width = ft_atoi(str);
		if (*str++ == '.')
		{
			if (is_specifier(*str))
				format->precision = 0;
			else
				format->precision = ft_atoi(str);
		}
	}
	return (format);
}

int	print_padding(char *arg, char specifier, t_format *format, size_t printed)
{
	size_t	chars_written;
	char	padding;

	chars_written = 0;
	padding = 32 + (16 * format->lpad_0 * (format->precision < 0 && !printed));
	if (!format->left_justify)
	{
		if (specifier == 'p')
			printed += ft_hexlen((unsigned long)arg) + 2 - (!format->precision);
		if (arg && format->precision > 0)
			printed += check_precision(arg, specifier, format->precision);
		if (!printed)
		{
			if ((specifier == 'x' || specifier == 'X') && *arg)
				printed += ft_hexlen(ft_atoui(arg)) + 2 * format->hash_prefix;
			else
				printed += ft_strlen(arg) + (specifier == 'c' && !*arg);
			if ((specifier == 'd' || specifier == 'i') && arg[0] != '-')
				printed += format->force_sign + format->invisible_plus;
		}
	}
	while ((chars_written < (format->min_width - printed)
			&& printed < format->min_width))
		chars_written += write(1, &padding, 1);
	return ((int)chars_written);
}

int	print_prefix(char *arg, char specifier, t_format *format)
{
	int	i;
	int	chars_written;

	chars_written = 0;
	if (specifier == 'p')
		chars_written += write(1, "0x", 2);
	if (ft_tolower(specifier) == 'x' && format->hash_prefix && arg[0] != 48)
		chars_written += write(1, "0", 1) + write(1, &specifier, 1);
	if ((specifier == 'd' || specifier == 'i') && arg[0] != '-')
	{
		if (format->force_sign)
			chars_written += write(1, "+", 1);
		else if (format->invisible_plus)
			chars_written += write(1, " ", 1);
	}
	if (specifier == 'p')
		i = ft_hexlen((unsigned long)arg);
	else if (specifier == 'x' || specifier == 'X')
		i = ft_hexlen(ft_atoui(arg));
	else
		i = ft_strlen(arg) - (arg[0] == '-');
	while (i++ < format->precision)
		chars_written += write(1, "0", 1);
	return (chars_written);
}
