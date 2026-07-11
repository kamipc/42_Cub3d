/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:09:44 by sade-ara          #+#    #+#             */
/*   Updated: 2026/06/29 14:09:44 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	move_forward_back(t_cub3d *cub3d)
{
	t_player	*p;
	double		spd;
	char		**map;

	p = cub3d->player;
	spd = p->move_speed;
	map = cub3d->map->map;
	if (cub3d->keys.w)
	{
		if (map[(int)p->y][(int)(p->x + p->dir_x * spd)] != '1')
			p->x += p->dir_x * spd;
		if (map[(int)(p->y + p->dir_y * spd)][(int)p->x] != '1')
			p->y += p->dir_y * spd;
	}
	if (cub3d->keys.s)
	{
		if (map[(int)p->y][(int)(p->x - p->dir_x * spd)] != '1')
			p->x -= p->dir_x * spd;
		if (map[(int)(p->y - p->dir_y * spd)][(int)p->x] != '1')
			p->y -= p->dir_y * spd;
	}
}

static void	move_strafe(t_cub3d *cub3d)
{
	t_player	*p;
	double		spd;
	char		**map;

	p = cub3d->player;
	spd = p->move_speed;
	map = cub3d->map->map;
	if (cub3d->keys.d)
	{
		if (map[(int)p->y][(int)(p->x - p->dir_y * spd)] != '1')
			p->x -= p->dir_y * spd;
		if (map[(int)(p->y + p->dir_x * spd)][(int)p->x] != '1')
			p->y += p->dir_x * spd;
	}
	if (cub3d->keys.a)
	{
		if (map[(int)p->y][(int)(p->x + p->dir_y * spd)] != '1')
			p->x += p->dir_y * spd;
		if (map[(int)(p->y - p->dir_x * spd)][(int)p->x] != '1')
			p->y -= p->dir_x * spd;
	}
}

void	move_player(t_cub3d *cub3d)
{
	move_forward_back(cub3d);
	move_strafe(cub3d);
	rotate_player(cub3d);
}
