#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_format
{
	int		left_justify;
	int		lpad_0;
	int		hash_prefix;
	int		invisible_plus;
	int		force_sign;
	size_t	min_width;
	int		precision;
}			t_format;

int			ft_printf(const char *str, ...);
int			check_precision(char *arg, char specifier, size_t precision);
int			is_specifier(char c);
t_format	*get_format(const char *str);
int			print_padding(
				char *arg,
				char specifier,
				t_format *format,
				size_t printed);
int			print_prefix(char *arg, char specifier, t_format *format);

#endif
