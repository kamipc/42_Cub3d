/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 16:39:04 by sade-ara          #+#    #+#             */
/*   Updated: 2026/07/04 16:39:04 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	set_tex_step(t_tex_col *tc, t_ray *ray)
{
	tc->step = (double)tc->tex->height / ray->line_height;
	tc->tex_pos = (tc->y_start - WIN_HEIGHT / 2 + ray->line_height / 2)
		* tc->step;
}
