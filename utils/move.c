/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:34:33 by kkarakus          #+#    #+#             */
/*   Updated: 2024/03/19 16:54:32 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	ft_check_next_tile(t_game *game, int direction, char tile)
{
	if (direction == DIR_RIGHT)
	{
		if (game->map[game->player.y][game->player.x + 1] == tile)
			return (1);
	}
	else if (direction == DIR_LEFT)
	{
		if (game->map[game->player.y][game->player.x - 1] == tile)
			return (1);
	}
	else if (direction == DIR_DOWN)
	{
		if (game->map[game->player.y + 1][game->player.x] == tile)
			return (1);
	}
	else if (direction == DIR_UP)
	{
		if (game->map[game->player.y - 1][game->player.x] == tile)
			return (1);
	}
	return (0);
}

static int	ft_check_move(t_game *game, int direction)
{
	if (ft_check_next_tile(game, direction, WALL))
		return (0);
	else if (ft_check_next_tile(game, direction, ITEM))
		game->item--;
	else if (ft_check_next_tile(game, direction, EXIT))
	{
		if (game->item == 0)
		{
			game->moves++;
			ft_printf("Total moves: %d\n", game->moves);
			ft_exit_game(game);
		}
		else
			return (1);
	}
	game->moves++;
	ft_printf("moves: %d\n", game->moves);
	return (1);
}

static void	ft_move(t_game *game, int direction)
{
	if (!ft_check_move(game, direction))
		return ;
	if (game->player.x == game->exit.x
	 	&& game->player.y == game->exit.y)
	game->map[game->player.y][game->player.x] = EXIT;
	else
		game->map[game->player.y][game->player.x] = FLOOR;
	if (direction == DIR_RIGHT)
		game->player.x++;
	else if (direction == DIR_LEFT)
		game->player.x--;
	else if (direction == DIR_DOWN)
		game->player.y++;
	else if (direction == DIR_UP)
		game->player.y--;
	if (!(game->player.x == game->exit.x
			&& game->player.y == game->exit.y))
		game->map[game->player.y][game->player.x] = PLAYER;
}

int	ft_key_hook(int key, t_game *game)
{
	if (key == KEY_ESC)
		ft_exit_game(game);
	else if (key == KEY_A || key == KEY_LEFT)
		ft_move(game, DIR_LEFT);
	else if (key == KEY_D || key == KEY_RIGHT)
		ft_move(game, DIR_RIGHT);
	else if (key == KEY_W || key == KEY_UP)
		ft_move(game, DIR_UP);
	else if (key == KEY_S || key == KEY_DOWN)
		ft_move(game, DIR_DOWN);
	ft_put_images(game);
	ft_write_score(game);
	return (0);
}

void	ft_write_score(t_game *game)
{
	char	*score;
	char	*tmp;

	score = ft_itoa(game->moves);
	tmp = ft_strjoin("Score: ", score);
	mlx_string_put(game->mlx, game->win, 44, 44, 666666, tmp);
	free(score);
	free(tmp);
}
