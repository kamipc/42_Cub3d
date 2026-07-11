/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:35:21 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/11 22:53:43 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

int	main(int ac, char *av)
{
	t_cub3d	*cub3d;

	if (ac != 2)
		call_error(cub3d, ERROR_ARG);
	cub3d = init_cub3d();
	cub3d->map_filename = ft_strdup(av[1]);
	validate(cub3d);
}
