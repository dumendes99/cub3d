/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:57:10 by elima-me          #+#    #+#             */
/*   Updated: 2022/04/11 16:40:24 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	start_game(t_data *data)
{
	data->mlx = mlx_init();
	data->player.x = 128;
	data->player.y = 128;
	data->win = mlx_new_window(data->mlx, WIN_WIDHT, WIN_HEIGHT, "CUB3D");
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_memset(&data, '\0', sizeof(t_data));
	if (ft_setup(argc, argv, &data))
	{
		ft_clean(&data.map);
		return (1);
	}
	game_config(&data);
	create_rays(&data);
	start_game(&data);
	render_walls(&data);
	ft_clean(&data.map);
	return (0);
}
