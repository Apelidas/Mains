/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:40:39 by ydimitro          #+#    #+#             */
/*   Updated: 2022/12/09 19:40:39 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all_allocated_memory(t_game *game)
{
	destroy_images(game);
	free_map(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	// mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
}

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->collectible.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_closed.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->open_exit.xpm_ptr);
}

void	free_map(t_game *game)
{
	int	string;

	string = 0;
	while (string < game->map.rows)
		free(game->map.full[string++]);
	free(game->map.full);
}
