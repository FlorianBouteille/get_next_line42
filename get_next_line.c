/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:53:54 by fbouteil          #+#    #+#             */
/*   Updated: 2024/12/03 16:50:59 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		size;
	int		i;
	int		j;

	size = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[size] = 0;
	free(s1);
	free(s2);
	return (result);
}

int	check_line(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*get_line(char *str)
{
	int		len;
	int		i;
	char	*result;

	len = check_line(str) + 1;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[len] = 0;
	return (result);
}

char	*clean_temp(char *str)
{
	int		len;
	int		i;
	char	*result;

	len = ft_strlen(str) - check_line(str);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = str[check_line(str) + 1 + i];
		i++;
	}
	result[len] = 0;
	return (result);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*temp;
	char		*line;
	ssize_t		bytes_read;
	
	if (!temp)
		temp = ft_strdup("");
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!check_line(temp))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (NULL);
		buffer[bytes_read] = 0;
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	line = get_line(temp);
	temp = clean_temp(temp);
	return (line);
}
