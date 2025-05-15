/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put2darray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsalah <hsalah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:41:52 by hsalah            #+#    #+#             */
/*   Updated: 2024/10/13 11:41:53 by hsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_put2darray(char **array, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		ft_putstr_fd(array[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}
