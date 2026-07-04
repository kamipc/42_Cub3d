/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 16:58:49 by sade-ara          #+#    #+#             */
/*   Updated: 2026/07/04 16:58:49 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static double	get_rot_speed(t_cub3d *cub3d)
{
	if (cub3d->keys.right)
		return (-cub3d->player->rot_speed);
	return (cub3d->player->rot_speed);
}

static void	apply_rotation(double *x, double *y, double cos_a, double sin_a)
{
	double	old_x;

	old_x = *x;
	*x = *x * cos_a - *y * sin_a;
	*y = old_x * sin_a + *y * cos_a;
}

void	rotate_player(t_cub3d *cub3d)
{
	t_player	*p;
	double		cos_a;
	double		sin_a;
	double		spd;

	p = cub3d->player;
	if (!cub3d->keys.left && !cub3d->keys.right)
		return ;
	spd = get_rot_speed(cub3d);
	cos_a = cos(spd);
	sin_a = sin(spd);
	apply_rotation(&p->dir_x, &p->dir_y, cos_a, sin_a);
	apply_rotation(&p->plane_x, &p->plane_y, cos_a, sin_a);
}
