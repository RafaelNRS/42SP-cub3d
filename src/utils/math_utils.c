/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 07:56:45 by ranascim          #+#    #+#             */
/*   Updated: 2024/01/10 08:01:10 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

float	fix_ang(float ang)
{
	ang = fmod(ang, 360.0);
	if (ang < 0)
		ang += 360.0;
	return (ang);
}

float	deg_to_rad(float deg)
{
	return (deg * (M_PI / 180));
}

void	ft_freethis(char **str, void *content)
{
	if (*str)
	{
		free(*str);
		*str = (char *) content;
	}
}
