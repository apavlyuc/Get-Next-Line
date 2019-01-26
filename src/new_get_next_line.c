#include "../inc/get_next_line.h"
#include "../libft/inc/libft.h"

#include <unistd.h>
#include <stdlib.h>

#define RETX_IF_ECV(a, b, x) if ((a) == (b)) return (x);

static t_list		*get_current(t_list **list, const int fd)
{
	t_list			*temp;

	temp = *list;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	RETN_IF_NULL((temp = (t_list *)ft_memalloc(sizeof(t_list))));
	RETN_IF_NULL((temp->content = ft_strnew(0)));
	temp->content_size = fd;
	ft_lstadd_before(list, temp);
	return (temp);
}

static t_ull		strcpy_to(char **dst, char *src)
{
	t_ull			dst_len;
	t_ull			i;

	dst_len = (ft_strlen(src) + 1) * sizeof(char);
	*dst = (char *)ft_memalloc(dst_len);
	//TODO: change macro in libft_defines.h
	RETN_IF_NULL(((t_ull)(*dst)));
	i = 0;
	while (*(src + i) != '\0' && *(src + i) != '\n')
	{
		*(*dst + i) = *(src + i);
		++i;
	}
	*(*dst + i) = '\0';
	return (i);
}

static int			init_line(char **line, t_list **current)
{
	t_ull			i;
	char			*tmp;
	t_ull			len;

	RETN_IF_NULL((i = strcpy_to(line, (*current)->content)));
	len = ft_strlen((*current)->content);
	tmp = 0;
	if (i < len)
	{
		tmp = ft_strsub((*current)->content, i + 1, len - i - 1);
		RETN_IF_NULL(((t_ull)tmp));
	}
	ft_memdel((void **)(&(*current)->content));
	(*current)->content = tmp;
	return (1);
}

int					new_get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*list;
	int				i;
	t_list			*current;
	char			*tmp;

	ERR_CHECK(fd, line, read(fd, buf, 0));
	NULL_CHECK((current = get_current(&list, fd)));
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = 0;
		NULL_CHECK((tmp = ft_strjoin(current->content, buf)));
		ft_memdel((void **)(&current->content));
		NULL_CHECK((current->content = ft_strdup(tmp)));
		ft_memdel((void **)(&tmp));
		BREAKER(ft_strchr(buf, '\n'));
	}
	//END_CHECK(i, ft_strlen(current->content));
	if (i < BUFF_SIZE && !ft_strlen(current->content))
	{
		free(current);
		return (0);
	}
	NULL_CHECK(init_line(line, &current));
	return (1);
}