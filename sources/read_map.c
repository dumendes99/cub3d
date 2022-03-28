/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:29:49 by guferrei          #+#    #+#             */
/*   Updated: 2022/03/28 15:40:32 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	get_fd(char *filename)
{
	return (open(filename, O_RDONLY));
}

int	count_lines(char *filename)
{
	int		gnl;
	int		count;
	int		fd;
	char	*line_read;

	gnl = 1;
	count = 0;
	line_read = NULL;
	fd = get_fd(filename);
	if (fd < 0)
		return (-1);
	while (gnl == 1)
	{
		gnl = get_next_line(fd, &line_read);
		if (!(*line_read == '\0'))
			count++;
		if (line_read)
			free(line_read);
	}
	close(fd);
	return (count);
}

char	**read_map(char *filename, int n_lines)
{
	char	**map;
	int		fd;
	int		gnl;
	int		count;

	count = 0;
	fd = get_fd(filename);
	gnl = 1;
	map = malloc((n_lines + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	while (gnl == 1)
	{
		gnl = get_next_line(fd, &map[count]);
		if (*map[count] == '\0')
			free(map[count]);
		else
			count++;
	}
	if (gnl == -1)
	{
		free_matrix(map);
		return (NULL);
	}
	return (map);
}
