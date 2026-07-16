/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:02:48 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/11 23:20:26 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	validate(t_cub3d *cub3d)
{
	validate_file(cub3d);
	get_info(cub3d);
	validate_map(cub3d);
	validate_textures(cub3d);
}
