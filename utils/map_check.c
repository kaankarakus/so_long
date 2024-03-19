/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:47:18 by kkarakus          #+#    #+#             */
/*   Updated: 2024/03/19 15:05:57 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	check_map_extensions(char *file)
{
	int	len;

	len = ft_strlen(file) - 4;
	if ((ft_strncmp(".ber", file + len, 4)) != 0)
		return (ft_printf("Your map's extension should be '.ber'"), ERROR);
	return (SUCCESS);
}

int	check_map_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != (size_t)game->map_width)
			return (ft_printf("Invalid Map Width!"),
				free_map(game), ERROR);
		while (game->map[i][j])
		{
			if (game->map[0][j] != WALL
				|| game->map[game->map_height - 1][j] != WALL)
				return (ft_printf("Invalid Map WALL!"),
					free_map(game), ERROR);
			j++;
		}
		if (game->map[i][0] != WALL
			|| game->map[i][game->map_width - 1] != WALL)
			return (ft_printf("Invalid Map WALL!"), free_map(game), ERROR);
		i++;
	}
	return (SUCCESS);
}

int	check_character_count(t_game *game)
{
	t_count		character;

	character.player = 0;
	character.i = 0;
	character.j = 0;
	character.exit = 0;
	if (player_location(game, character) != SUCCESS)
		return (ft_printf("Check Map Characters!"), free_map(game), ERROR);
	return (SUCCESS);
}

int	player_location(t_game *game, t_count character)
{
	while (character.i < game->map_height)
	{
		character.j = 0;
		while (character.j < game->map_width)
		{
			if (game->map[character.i][character.j] == 'C')
				game->item++;
			if (game->map[character.i][character.j] == 'P')
			{
				character.player++;
				game->player.x = character.j;
				game->player.y = character.i;
			}
			if (game->map[character.i][character.j] == 'E')
			{
				character.exit++;
				game->exit.x = character.j;
				game->exit.y = character.i;
			}
			character.j++;
		}
		character.i++;
	}
	if (character.exit == 1 && game->item >= 1 && character.player == 1)
		return (SUCCESS);
	return (ERROR);
}

int	character_checker(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (i != '\0')
			{
				if (game->map[i][j] != WALL && game->map[i][j] != FLOOR &&
					game->map[i][j] != ITEM && game->map[i][j] != PLAYER &&
					game->map[i][j] != EXIT && game->map[i][j] != '\n')
					return (ft_printf("Unknown Character!"),
						free_map(game), ERROR);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
