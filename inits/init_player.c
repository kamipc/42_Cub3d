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
 
/*
** Direções e planos de câmara por orientação inicial:
**
** Norte: dir=(0,-1)  plane=(0.66, 0)
** Sul:   dir=(0, 1)  plane=(-0.66, 0)
** Este:  dir=(1, 0)  plane=(0, 0.66)
** Oeste: dir=(-1, 0) plane=(0, -0.66)
**
** O plane define o FOV (~66° com magnitude 0.66).
** É perpendicular ao vetor dir.
*/
 
static void	set_direction(t_player *p, char dir)
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
	else if (dir == 'E')
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

/*
** Posição inicial: centro da célula do mapa onde está o jogador.
** player_x e player_y são índices do array do mapa.
** Adicionamos 0.5 para ficar no centro da célula.
*/

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
