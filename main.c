/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:35:21 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/06/22 15:45:07 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

int main(int ac, char **av)
{
	t_cub3d	*cub3d;

	if (ac != 2)
		call_error(cub3d, ERROR_ARG);
	cub3d = init_cub3d();
	if (!cub3d->map_filename)
		call_error(cub3d, strerror(errno));
	
	init_window(cub3d);

	//mlx_hook(cub3d.win, 17, 0, close_window, &cub3d);
	//mlx_hook(cub3d.win, 2, 1L << 0, key_press, &cub3d);

	mlx_loop(cub3d->mlx);
	
	//validate(cub3d);
	return(0);
}
