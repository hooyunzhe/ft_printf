/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun-zhe <hyun-zhe.student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:36:44 by hyun-zhe          #+#    #+#             */
/*   Updated: 2021/09/13 16:19:29 by hyun-zhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/ft_printf.h"

int	check_precision(char *arg, char specifier, size_t precision)
{
	if (((specifier == 'd' || specifier == 'i' || specifier == 'u')
			&& ft_strlen(arg) - (arg[0] == '-') < precision))
		return (precision + (arg[0] == '-'));
	if (((specifier == 's' && ft_strlen(arg) > precision)
			|| (ft_tolower(specifier) == 'x'
				&& ft_hexlen(ft_atoui(arg)) < precision)
			|| (specifier == 'p'
				&& ft_hexlen((unsigned long)arg) < precision)))
		return (precision);
	return (0);
}

int	print_any(char *arg, char specifier, t_format *format)
{
	if (specifier == 'c')
		return (write(1, arg, 1));
	else if (specifier == 's')
	{
		if ((format->precision >= 0
				&& (int)ft_strlen(arg) > format->precision))
			return (write(1, arg, format->precision));
	}
	else if (specifier != 'p' && arg[0] == '-')
		return (write(1, arg + 1, ft_strlen(arg) - 1));
	return (write(1, arg, ft_strlen(arg)));
}

char	*get_arg(va_list args, const char specifier, int precision)
{
	char	*arg;

	arg = "";
	if (specifier == 'c')
		arg = ft_chartostr(va_arg(args, int));
	else if (specifier == 's')
		arg = ft_strdup(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		arg = ft_itoa(va_arg(args, int));
	else if (specifier == 'x' || specifier == 'X')
		arg = ft_itoa(va_arg(args, int));
	else if (specifier == 'p')
		arg = va_arg(args, void *);
	else if (specifier == 'u')
		arg = ft_uitoa(va_arg(args, unsigned int));
	else if (specifier == '%')
		arg = ft_chartostr('%');
	if (specifier == 's' && !arg)
		arg = ft_strdup("(null)");
	if (((specifier != 'c' && specifier != 'p')
			&& ((specifier == 's' || arg[0] == '0') && !precision)))
		*arg = 0;
	return (arg);
}

int	specifier_print(va_list args, const char specifier, t_format *format)
{
	int		chars_written;
	char	*arg;

	chars_written = 0;
	arg = get_arg(args, specifier, format->precision);
	if (!format->left_justify && (!format->lpad_0 || format->precision != -1))
		chars_written += print_padding(arg, specifier, format, 0);
	if ((specifier == 'd' || specifier == 'i') && arg[0] == '-')
		chars_written += write(1, "-", 1);
	if (!format->left_justify && format->lpad_0 && format->precision == -1)
		chars_written += print_padding(arg, specifier, format, 0);
	if (specifier != 'c' && specifier != 's' && specifier != '%')
		chars_written += print_prefix(arg, specifier, format);
	if (specifier == 'p' && (format->precision || arg))
		chars_written += ft_putnbr_hex((unsigned long)arg, 0);
	else if ((specifier == 'x' || specifier == 'X') && arg && *arg)
		chars_written += ft_putnbr_hex(ft_atoui(arg), specifier == 'X');
	else
		chars_written += print_any(arg, specifier, format);
	if (format->left_justify)
		chars_written += print_padding(arg, specifier, format, chars_written);
	if (specifier != 'p')
		free(arg);
	free(format);
	return (chars_written);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_format	*format;
	int			has_specifier;
	int			chars_written;

	va_start(args, str);
	has_specifier = 0;
	chars_written = 0;
	while (*str)
	{
		if (*str++ == '%' && !has_specifier)
		{
			has_specifier = 1;
			format = get_format(str);
		}
		else if (has_specifier && is_specifier(*(str - 1)))
		{
			has_specifier = 0;
			chars_written += specifier_print(args, *(str - 1), format);
		}
		else if (!has_specifier)
			chars_written += write(1, (str - 1), 1);
	}
	va_end(args);
	return (chars_written);
}
