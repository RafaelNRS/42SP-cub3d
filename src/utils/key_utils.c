/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 07:56:23 by ranascim          #+#    #+#             */
/*   Updated: 2024/01/10 07:56:26 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->input_keys.w = TRUE;
	if (keycode == KEY_S)
		game->input_keys.s = TRUE;
	if (keycode == KEY_D)
		game->input_keys.d = TRUE;
	if (keycode == KEY_A)
		game->input_keys.a = TRUE;
	if (keycode == KEY_RIGHT)
		game->input_keys.right = TRUE;
	if (keycode == KEY_LEFT)
		game->input_keys.left = TRUE;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		clean_all(game);
	if (keycode == KEY_W)
		game->input_keys.w = FALSE;
	if (keycode == KEY_S)
		game->input_keys.s = FALSE;
	if (keycode == KEY_D)
		game->input_keys.d = FALSE;
	if (keycode == KEY_A)
		game->input_keys.a = FALSE;
	if (keycode == KEY_RIGHT)
		game->input_keys.right = FALSE;
	if (keycode == KEY_LEFT)
		game->input_keys.left = FALSE;
	return (0);
}
