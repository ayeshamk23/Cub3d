/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_till_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsalah <hsalah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:32:10 by hsalah            #+#    #+#             */
/*   Updated: 2024/10/22 07:37:06 by hsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_join(char *s1, char *s2)
{
	int		line_len;
	char	*joined;

	if (!s2)
		return (s1);
	if (s1)
		line_len = ft_strlen(s1);
	else
		line_len = 0;
	joined = malloc(ft_strlen(s2) + line_len + 1);
	if (!joined)
		return (NULL);
	ft_strcpy(joined, s1);
	ft_strcpy(joined + line_len, s2);
	free(s1);
	return (joined);
}

/*
**	Description:
**	Reads a text file and stores it in one long string. The file is
**	stored in char **line.
**
**	Returns:
**	0 : EOF has been reached
**	-1 : An error happened
*/

int	read_till_end(int fd, char **line)
{
	int			ret;
	static char	buf[BUFFER_SIZE + 1];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = 0;
	ret = 1;
	while (ret > 0)
	{
		*line = ft_join(*line, buf);
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
	}
	return (0);
}
