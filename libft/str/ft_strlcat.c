/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsalah <hsalah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:49:11 by hsalah            #+#    #+#             */
/*   Updated: 2024/10/22 07:37:52 by hsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dest_len;

	dest_len = ft_strlen(dst);
	i = 0;
	if (dstsize > dest_len)
	{
		while (i < dstsize - dest_len - 1 && src[i])
		{
			dst[i + dest_len] = src[i];
			i++;
		}
		dst[i + dest_len] = '\0';
		return (dest_len + ft_strlen(src));
	}
	return (dstsize + ft_strlen(src));
}
