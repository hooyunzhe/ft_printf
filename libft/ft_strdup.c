/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun-zhe <hyun-zhe@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:15:20 by hyun-zhe          #+#    #+#             */
/*   Updated: 2021/09/07 17:22:28 by hyun-zhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	if (!s1)
		return (NULL);
	i = -1;
	str = malloc((ft_strlen(s1) * sizeof(char)) + 1);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	str[i] = 0;
	return (str);
}
