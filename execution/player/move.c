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
 
/*
** Colisão simples: só move se a célula destino não for '1'.
** O offset de 0.2 serve de "margem" para não colar às paredes.
*/
 
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
	/* Strafe: perpendicular à direção = rodar dir 90° */
	if (cub3d->keys.a)
	{
		if (map[(int)p->y][(int)(p->x - p->dir_y * spd)] != '1')
			p->x -= p->dir_y * spd;
		if (map[(int)(p->y + p->dir_x * spd)][(int)p->x] != '1')
			p->y += p->dir_x * spd;
	}
	if (cub3d->keys.d)
	{
		if (map[(int)p->y][(int)(p->x + p->dir_y * spd)] != '1')
			p->x += p->dir_y * spd;
		if (map[(int)(p->y - p->dir_x * spd)][(int)p->x] != '1')
			p->y -= p->dir_x * spd;
	}
}
 
/*
** Rotação: multiplica dir e plane pela matriz de rotação 2D.
**
** [ cos(a) -sin(a) ]   [ dir_x ]
** [ sin(a)  cos(a) ] * [ dir_y ]
**
** Para rotação esquerda: ângulo positivo.
** Para rotação direita:  ângulo negativo.
*/

static void	rotate_player(t_cub3d *cub3d)
{
	t_player	*p;
	double		spd;
	double		old_dir_x;
	double		old_plane_x;
	double		cos_a;
	double		sin_a;
 
	p = cub3d->player;
	spd = p->rot_speed;
	if (!cub3d->keys.left && !cub3d->keys.right)
		return ;
	if (cub3d->keys.right)
		spd = -spd;
	cos_a = cos(spd);
	sin_a = sin(spd);
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos_a - p->dir_y * sin_a;
	p->dir_y = old_dir_x * sin_a + p->dir_y * cos_a;
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos_a - p->plane_y * sin_a;
	p->plane_y = old_plane_x * sin_a + p->plane_y * cos_a;
}
 
void	move_player(t_cub3d *cub3d)
{
	move_forward_back(cub3d);
	move_strafe(cub3d);
	rotate_player(cub3d);
}
