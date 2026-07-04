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

// main execution test

int	main(int ac, char **av)
{
	(void)ac;
	t_cub3d	*cub3d;
 
	// if (ac != 2)
	// {
	// 	write(2, ERROR_ARG, ft_strlen(ERROR_ARG));
	// 	return (1);
	// }
	cub3d = init_cub3d();
	if (!cub3d)
		return (1);
	load_scene(cub3d, av[1]); /* substitui validate() enquanto parsing não está pronto */
	start_game(cub3d);
	return (0);
}
