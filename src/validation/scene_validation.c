/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 07:58:08 by ranascim          #+#    #+#             */
/*   Updated: 2024/01/11 08:18:33 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	check_scene(char *map_path, t_scene *scene)
{
	if (!init_scene(scene, map_path))
	{
		throw_err(END_LINE_INVALID);
		return (0);
	}
	if (!feed_scene_textures(scene) || !feed_scene_floor_and_celling(scene) || \
	!feed_scene_map(scene))
		return (0);
	return (1);
}
