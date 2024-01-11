/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 07:49:44 by ranascim          #+#    #+#             */
/*   Updated: 2024/01/10 07:49:51 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	free_scene_lines(t_scene *scene)
{
	int	i;

	i = 0;
	if (scene->scene_lines)
	{
		while (scene->scene_lines[i])
		{
			free_ptr((void **)&scene->scene_lines[i]);
			i++;
		}
		free(scene->scene_lines);
		scene->scene_lines = NULL;
	}
}

static void	free_map(t_scene *scene)
{
	int	i;

	i = 0;
	if (scene->map)
	{
		while (scene->map[i])
		{
			free_ptr((void **)&scene->map[i]);
			i++;
		}
		free(scene->map);
		scene->map = NULL;
	}
}

void	close_scene(t_scene *scene)
{
	free_scene_lines(scene);
	free_map(scene);
	free_ptr((void **)&scene->player);
	free_ptr((void **)&scene->no);
	free_ptr((void **)&scene->so);
	free_ptr((void **)&scene->we);
	free_ptr((void **)&scene->ea);
}
