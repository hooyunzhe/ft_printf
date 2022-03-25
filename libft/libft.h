#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_tolower(int c);
char			*ft_strdup(const char *s1);
char			*ft_itoa(int n);
int				ft_putnbr_base(unsigned long nbr, char *base);
char			*ft_uitoa(unsigned int n);
unsigned int	ft_atoui(const char *str);
size_t			ft_hexlen(unsigned long num);
char			*ft_chartostr(char c);
int				ft_putnbr_hex(unsigned long num, int caps);

#endif
