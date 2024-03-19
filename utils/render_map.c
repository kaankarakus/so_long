/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:30:26 by kkarakus          #+#    #+#             */
/*   Updated: 2024/03/19 14:21:39 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	render_map(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("mlx cannot be initialized");
		free_map(game);
		exit(0);
	}
	game->win = mlx_new_window(game->mlx, game->map_width * 64,
			game->map_height * 64, " S O _ L O N G ");
	if (!game->win)
	{
		ft_printf("win cannot be initialized");
		free_map(game);
		exit(0);
	}
	ft_init_images(game);
	ft_put_images(game);
}

static void	ft_put_img(t_game *game, char c, int x, int y)
{
	if (c == FLOOR)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.f, x, y);
	else if (c == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.w, x, y);
	else if (c == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.p, x, y);
	else if (c == ITEM)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.c, x, y);
	else if (c == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.e, x, y);
}

void	ft_put_images(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			ft_put_img(game, game->map[y][x], x * 64, y * 64);
			x++;
		}
		y++;
	}
}

int	ft_init_images(t_game *game)
{
	int	x;
	int	y;

	game->imgs.p = mlx_xpm_file_to_image(game->mlx,
			"images/horse.xpm", &x, &y);
	if (!game->imgs.p)
		return (ft_printf("IMG file cannot be found"), free_map(game), ERROR);
	game->imgs.e = mlx_xpm_file_to_image(game->mlx, "images/exit.xpm", &x, &y);
	if (!game->imgs.e)
		return (ft_printf("IMG file cannot be found"), free_map(game), ERROR);
	game->imgs.c = mlx_xpm_file_to_image(game->mlx,
			"images/carrot.xpm", &x, &y);
	if (!game->imgs.c)
		return (ft_printf("IMG file cannot be found"), free_map(game), ERROR);
	game->imgs.f = mlx_xpm_file_to_image(game->mlx, "images/floor.xpm", &x, &y);
	if (!game->imgs.f)
		return (ft_printf("IMG file cannot be found"), free_map(game), ERROR);
	game->imgs.w = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", &x, &y);
	if (!game->imgs.w)
		return (ft_printf("wall file cannot be found"), free_map(game), ERROR);
	return (SUCCESS);
}
