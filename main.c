/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:35:21 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/06/27 14:22:52 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d	*cub3d;

	if (ac != 2)
	{
		write(2, ERROR_ARG, ft_strlen(ERROR_ARG));
		return (1);
	}
	cub3d = init_cub3d();
	if (!cub3d)
		return (1);
	cub3d->map_filename = ft_strdup(av[1]);
	validate(cub3d);
	start_game(cub3d);
	free_cub3d(cub3d);
	return (0);
}
