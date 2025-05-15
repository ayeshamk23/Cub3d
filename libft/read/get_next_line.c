/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsalah <hsalah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:40:16 by hsalah            #+#    #+#             */
/*   Updated: 2024/10/22 07:36:55 by hsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_join(char *s1, char *s2, char end)
{
	int		i;
	int		line_len;
	char	*tmp;

	if (!s2)
		return (s1);
	line_len = ft_strlend(s1, end);
	tmp = malloc(ft_strlend(s2, end) + line_len + 1);
	if (!tmp)
		return (NULL);
	ft_strcpy(tmp, s1);
	i = 0;
	while (s2[i] && s2[i] != end)
	{
		tmp[i + line_len] = s2[i];
		i++;
	}
	tmp[i + line_len] = '\0';
	free(s1);
	return (tmp);
}

/*
**	Description:
**	When called in a loop, the get_next_line function reads one line at the
**	time from the file descriptor, until the EOF is reached. The line is
**	stored in char **line.
**
**	Returns:
**	1 : A line has been read
**	0 : EOF has been reached
**	-1 : An error happened
*/

int	get_next_line(int fd, char **line)
{
	int			ret;
	static char	buf[BUFFER_SIZE + 1];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = 0;
	ret = 1;
	while (ret > 0)
	{
		*line = ft_join(*line, buf, '\n');
		if (ft_modstr(buf, '\n'))
			return (1);
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
	}
	return (ret);
}
