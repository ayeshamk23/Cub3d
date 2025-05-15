/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsalah <hsalah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:11:23 by hsalah            #+#    #+#             */
/*   Updated: 2024/10/13 11:44:55 by hsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_in_set(char c, char const *set)
{
	int	j;
	int	len;

	len = ft_strlen(set);
	j = 0;
	while (j < len)
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	i;
	size_t	index;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	index = 0;
	while (ft_in_set(s1[i], set))
		i++;
	index = i;
	i = ft_strlen(s1) - 1;
	while (ft_in_set(s1[i], set) && i > index)
		i--;
	trim = ft_substr(s1, index, (i - index + 1));
	return (trim);
}
