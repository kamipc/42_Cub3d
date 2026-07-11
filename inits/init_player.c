/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 21:05:15 by sade-ara          #+#    #+#             */
/*   Updated: 2026/06/30 21:05:15 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	set_north_south(t_player *p, char dir)
{
	if (dir == 'N')
	{
		p->dir_x = 0;
		p->dir_y = -1;
		p->plane_x = 0.66;
		p->plane_y = 0;
	}
	else if (dir == 'S')
	{
		p->dir_x = 0;
		p->dir_y = 1;
		p->plane_x = -0.66;
		p->plane_y = 0;
	}
}

static void	set_east_west(t_player *p, char dir)
{
	if (dir == 'E')
	{
		p->dir_x = 1;
		p->dir_y = 0;
		p->plane_x = 0;
		p->plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		p->dir_x = -1;
		p->dir_y = 0;
		p->plane_x = 0;
		p->plane_y = -0.66;
	}
}

static void	set_direction(t_player *p, char dir)
{
	set_north_south(p, dir);
	set_east_west(p, dir);
}

void	init_player(t_cub3d *cub3d)
{
	t_player	*p;

	p = cub3d->player;
	p->x = cub3d->map->player_x + 0.5;
	p->y = cub3d->map->player_y + 0.5;
	p->move_speed = 0.05;
	p->rot_speed = 0.03;
	set_direction(p, cub3d->map->player_start_dir);
}
