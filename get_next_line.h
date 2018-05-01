/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:14:09 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/12/26 19:36:42 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# define NULL_CHECK(x) if (!x) return (-1);
# define ERR_CHECK(x, y, z) if (x < 0 || !y || z < 0) return (-1);
# define END_CHECK(x, y) if (x < BUFF_SIZE && !y) return (0);
# define BREAKER(x) if (x) break;

int			get_next_line(const int fd, char **line);

#endif
