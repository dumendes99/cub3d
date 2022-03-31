/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:36:40 by guferrei          #+#    #+#             */
/*   Updated: 2022/03/31 15:46:09 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_matrix(char **ptr)
{
	int	count;

	count = 0;
	while (ptr[count])
	{
		free(ptr[count]);
		count++;
	}
	free(ptr);
}
