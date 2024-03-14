/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:53:42 by kkarakus          #+#    #+#             */
/*   Updated: 2024/03/12 16:25:52 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"
// void	*floor = mlx_xpm_file_to_image(mlx, "images/floor.xpm", &a, &b);
// mlx_put_image_to_window(mlx, win, floor, x.a, y.b);

int	main(int ac, char **av)
{
	t_game	*game;
	int		i;

	game = NULL;
	i = 0;
	if (ac != 2)
		return (ft_printf("Check to parameters!\n"), ERROR);
	map(av[1], &game);
	while (i < game->map_height)
		ft_printf("%s\n", game->map[i++]);
	free_map(game);
	free(game);
	return (0);
}

// __attribute__((destructor))
// static void test() {
// 	system("leaks so_long");
// }
