/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 07:57:52 by ranascim          #+#    #+#             */
/*   Updated: 2024/01/11 08:03:37 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	check_args(int argc, char **argv)
{
	char	*substr;

	if (argc != 2)
	{
		throw_err(NUM_PARAM);
		return (0);
	}
	substr = ft_substr(argv[1], ft_strlen(argv[1]) - 4, 4);
	if (ft_strncmp(".cub", substr, 4))
	{
		throw_err(WRONG_FILE);
		ft_freethis(&substr, NULL);
		return (0);
	}
	ft_freethis(&substr, NULL);
	return (1);
}
