/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:09:54 by sade-ara          #+#    #+#             */
/*   Updated: 2026/07/02 17:45:22 by sade-ara         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../headers/cub3d.h"


 
/*
** PASSO 2 — DDA (Digital Differential Analysis).
**
** Avança célula a célula no grid, escolhendo sempre o eixo
** cuja side_dist seja menor (chegou mais perto de uma parede).
**
** side == 0: bateu numa parede pelo eixo X (face E ou W)
** side == 1: bateu numa parede pelo eixo Y (face N ou S)
*/
void	dda(t_cub3d *cub3d, t_ray *ray)
{
	char	**map;
 
	map = cub3d->map->map;
	while (!ray->hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}
 
/*
** PASSO 3 — Calcular altura da fatia de parede a desenhar.
**
** perp_wall_dist: distância perpendicular à câmara (corrige fish-eye).
**   Se bateu no eixo X: side_dist_x - delta_dist_x
**   Se bateu no eixo Y: side_dist_y - delta_dist_y
**   (subtrai delta porque side_dist já avançou um passo além)
**
** line_height: altura em píxeis da parede para esta distância.
**   Quanto mais longe, menor a fatia.
**
** draw_start/draw_end: píxeis verticais onde a fatia começa e acaba.
*/
void	calc_wall_slice(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	if (ray->perp_wall_dist <= 0)
		ray->perp_wall_dist = 0.0001;
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}
 
/*
** PASSO 4 — Desenhar a fatia de parede com cor sólida.
**
** Cores por face (temporário, até as texturas XPM estarem ligadas):
**   Norte (side=1, step_y=1):  vermelho escuro
**   Sul   (side=1, step_y=-1): vermelho claro
**   Este  (side=0, step_x=-1): verde escuro
**   Oeste (side=0, step_x=1):  verde claro
**
** Faces com side==1 ficam mais escuras (iluminação simples).
*/
void	draw_wall_slice(t_cub3d *cub3d, t_ray *ray, int x)
{
	int	y;
	int	color;
 
	/* Cor por face — substituir por texture sampling depois */
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			color = 0x008000; /* Oeste: verde */
		else
			color = 0x00CC00; /* Este: verde claro */
	}
	else
	{
		if (ray->step_y > 0)
			color = 0xCC0000; /* Sul: vermelho */
		else
			color = 0xFF4444; /* Norte: vermelho claro */
	}
	/* Teto */
	y = 0;
	while (y < ray->draw_start)
	{
		pixel_put(&cub3d->img, x, y, cub3d->textures->ceil_color);
		y++;
	}
	/* Parede */
	while (y <= ray->draw_end)
	{
		pixel_put(&cub3d->img, x, y, color);
		y++;
	}
	/* Chão */
	while (y < WIN_HEIGHT)
	{
		pixel_put(&cub3d->img, x, y, cub3d->textures->floor_color);
		y++;
	}
}
 
/*
** Loop principal — lança um raio por cada coluna de píxeis.
*/
void	cast_rays(t_cub3d *cub3d)
{
	t_ray	ray;
	int		x;
 
	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(cub3d, &ray, x);
		dda(cub3d, &ray);
		calc_wall_slice(&ray);
		draw_wall_slice(cub3d, &ray, x);
		x++;
	}
}
 