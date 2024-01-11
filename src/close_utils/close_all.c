/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 07:49:25 by ranascim          #+#    #+#             */
/*   Updated: 2024/01/10 08:04:44 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	free_ptr(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static void	clean_all_2(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->sprite_img);
	mlx_destroy_image(game->mlx, game->sprites->ea->sprite_img);
	mlx_destroy_image(game->mlx, game->sprites->no->sprite_img);
	mlx_destroy_image(game->mlx, game->sprites->so->sprite_img);
	mlx_destroy_image(game->mlx, game->sprites->we->sprite_img);
	free_ptr((void **)&game->sprites->ea);
	free_ptr((void **)&game->sprites->so);
	free_ptr((void **)&game->sprites->we);
	free_ptr((void **)&game->sprites->no);
	free_ptr((void **)&game->sprites);
	free_ptr((void **)&game->img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_ptr((void **)&game->mlx);
}

int	clean_all(t_game *game)
{
	close_scene(game->scene);
	if (game->mlx != NULL)
		clean_all_2(game);
	exit (0);
	return (1);
}
