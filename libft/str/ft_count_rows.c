/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_rows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsalah <hsalah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 07:12:40 by hsalah            #+#    #+#             */
/*   Updated: 2024/10/13 11:43:16 by hsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_rows(char **array)
{
	int	count;

	if (!array)
		return (0);
	count = 0;
	while (array[count])
		count++;
	return (count);
}
