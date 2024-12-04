/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:41:04 by fbouteil          #+#    #+#             */
/*   Updated: 2024/12/04 14:07:48 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*text;

	fd = open("lescopains.txt", O_RDONLY);
	text = get_next_line(fd);
	printf("%s", text);
	free(text);
	text = get_next_line(fd);
	printf("%s", text);
	free(text);
	text = get_next_line(fd);
	printf("%s", text);
	free(text);
	close(fd);
	return (0);
}
