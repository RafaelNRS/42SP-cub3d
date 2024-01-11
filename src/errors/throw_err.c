/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 07:50:19 by ranascim          #+#    #+#             */
/*   Updated: 2024/01/10 07:51:34 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	print_model_colors(void)
{
	ft_putstr_fd("One or more colors could not be parsed correctly!\n", 2);
	ft_putstr_fd("Only values from 0 to 255 are valid!\n", 2);
	ft_putstr_fd("Only one color for the floor and one for the celling is \
valid!\n", 2);
	ft_putstr_fd("Colors must be specified as follows:\n", 2);
	ft_putstr_fd("F 255,255,0\n", 2);
	ft_putstr_fd("C 0,255,255\n", 2);
}

static void	print_model_textures(void)
{
	ft_putstr_fd("One or more textures could not be found on specified path, \
some file could not be open or there is more than one texture per \
position!\n\n", 2);
	ft_putstr_fd("Textures must be specified as follows:\n", 2);
	ft_putstr_fd("NO ./path_to_the_north_texture\n", 2);
	ft_putstr_fd("SO ./path_to_the_south_texture\n", 2);
	ft_putstr_fd("WE ./path_to_the_west_texture\n", 2);
	ft_putstr_fd("EA ./path_to_the_east_texture\n", 2);
}

void	throw_err(int err)
{
	ft_putstr_fd("Error\n", 2);
	if (err == NUM_PARAM)
		ft_putstr_fd("Cub3D only accepts one parameter!\n", 2);
	if (err == WRONG_FILE)
		ft_putstr_fd("Cub3D only accepts files of .cub type!\n", 2);
	if (err == MAP_NONEXISTENT)
		ft_putstr_fd("Could not find scene file on specified path or file failed \
to open!\n", 2);
	if (err == TEXTURES_INVALID)
		print_model_textures();
	if (err == COLORS_INVALID)
		print_model_colors();
	if (err == MAP_NOT_LAST)
		ft_putstr_fd("The map must come last on the scene file!\n", 2);
	if (err == MAP_NOT_WALLED)
		ft_putstr_fd("The map must be fully walled!\n", 2);
	if (err == MAP_CHARS_NOT_VALID)
		ft_putstr_fd("The map must only contain valid characters! (01NWSE )\n", 2);
	if (err == MAP_PLAYERS_NOT_VALID)
		ft_putstr_fd("The map must only contain one player starting position!\n", 2);
	if (err == MINILIB_FAILED_WINDOW)
		ft_putstr_fd("Minilib's windows failed to load!\n", 2);
	if (err == MINILIB_FAILED_SPRITE)
		ft_putstr_fd("Minilib failed to load sprites\n", 2);
	if (err == END_LINE_INVALID)
		ft_putstr_fd("The map must end without a line break\n", 2);
}
