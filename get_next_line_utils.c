/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:07:00 by fbouteil          #+#    #+#             */
/*   Updated: 2024/12/03 16:42:27 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	size_until_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	while (i < ft_strlen(str))
	{
		copy[i] = str[i];
		i++;
	}
	copy[ft_strlen(str)] = 0;
	return (copy);
}
