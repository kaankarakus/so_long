/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:38:36 by kkarakus          #+#    #+#             */
/*   Updated: 2024/03/12 16:19:20 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < (game->map_height))
		free(game->map_copy[i++]);
	free(game->map_copy);
	i = 0;
	while (i < (game->map_height))
		free(game->map[i++]);
	free(game->map);
	exit (0);
}

int	get_map(char *file, t_game *game)
{
	char	*tmp;
	char	*add;
	int		fd;
	int		i;

	add = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Check to map path!"), ERROR);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		add = ft_gnl_strjoin(add, tmp);
		free(tmp);
	}
	game->map = ft_split(add, '\n');
	game->map_copy = ft_split(add, '\n');
	free(add);
	game->map_width = ft_strlen(game->map[0]);
	i = 0;
	while (game->map[i++] != NULL)
		game->map_height++;
	return (close(fd), SUCCESS);
}

int	map(char *file, t_game **game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	check_map_extensions(file);
	*game = malloc(sizeof(t_game));
	if (!(*game))
		return (ft_printf("game cannot be allocated"), ERROR);
	init_game(*game);
	get_map(file, *game);
	check_map_wall(*game);
	character_checker(*game);
	check_character_count(*game);
	check_game(*game);
	return (SUCCESS);
}

void	init_game(t_game *game)
{
	game->item = 0;
	game->map_height = 0;
	game->map_width = 0;
	game->map = NULL;
}
