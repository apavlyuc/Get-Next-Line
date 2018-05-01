/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linecount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 22:16:00 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/12/21 18:18:34 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int			ft_linecount(char *file)
{
	int		fd;
	char	buff[50];
	int		readed;
	int		count;

	count = 0;
	fd = open(file, O_RDONLY);
	while ((readed = read(fd, buff, 50)))
	{
		buff[readed] = '\0';
		count += ft_partscount(buff, "\n");
		ft_bzero(buff, ft_strlen(buff));
	}
	return (++count);
}
