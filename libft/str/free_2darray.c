/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2darray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsalah <hsalah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:32:40 by hsalah            #+#    #+#             */
/*   Updated: 2024/10/13 11:43:02 by hsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**free_2darray(char **array)
{
	int	index;

	index = ft_count_rows(array);
	while (index > 0)
	{
		free(array[index - 1]);
		index--;
	}
	free(array);
	return (NULL);
}
