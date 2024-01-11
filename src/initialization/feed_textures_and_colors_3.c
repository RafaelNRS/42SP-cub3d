/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_textures_and_colors_3.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 07:53:57 by ranascim          #+#    #+#             */
/*   Updated: 2024/01/10 07:53:58 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	final_scene_checks(t_scene *scene)
{
	if (!scene->no || !scene->so || !scene->we || !scene->ea)
	{
		throw_err(TEXTURES_INVALID);
		return (0);
	}
	if (!check_textures_exist(scene))
	{
		throw_err(TEXTURES_INVALID);
		return (0);
	}
	return (1);
}
