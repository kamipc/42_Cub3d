/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:52:09 by sade-ara          #+#    #+#             */
/*   Updated: 2026/07/02 17:56:58 by sade-ara         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../headers/cub3d.h"

/*
** Substitui o parsing real enquanto a execução está a ser desenvolvida.
** Quando o parsing estiver pronto, basta substituir load_scene() pelo
** código real que preenche cub3d->map, cub3d->textures e cub3d->player.
*/
 
static char	*s_map[] = {
	"111111111111111111111111",
	"100000000000000000000001",
	"100000000000000000000001",
	"100000111110001111000001",
	"100000100010001000100001",
	"100000100010001000100001",
	"100000111110001111000001",
	"100000000000000000000001",
	"1000000000N0000000000001",
	"100000000000000000000001",
	"100000000000000000000001",
	"111111111111111111111111",
	NULL
};
 
static void	load_map(t_cub3d *cub3d)
{
	int		rows;
	int		i;
 
	rows = 0;
	while (s_map[rows])
		rows++;
	cub3d->map->map = malloc(sizeof(char *) * (rows + 1));
	if (!cub3d->map->map)
		call_error(cub3d, "malloc map");
	i = 0;
	while (i < rows)
	{
		cub3d->map->map[i] = ft_strdup(s_map[i]);
		if (!cub3d->map->map[i])
			call_error(cub3d, "malloc map row");
		i++;
	}
	cub3d->map->map[i] = NULL;
	cub3d->map->height = rows;
	cub3d->map->width = (int)ft_strlen(s_map[0]);
	/* Player a Norte na posição (8,10) conforme o mapa */
	cub3d->map->player_start_dir = 'N';
	cub3d->map->player_x = 10;
	cub3d->map->player_y = 8;
}
 
static void	load_textures(t_cub3d *cub3d)
{
	cub3d->textures->NO = ft_strdup("textures/north.xpm");
	cub3d->textures->SO = ft_strdup("textures/south.xpm");
	cub3d->textures->EA = ft_strdup("textures/east.xpm");
	cub3d->textures->WE = ft_strdup("textures/west.xpm");
	/* Cor do chão: RGB(94,94,94) → cinza escuro */
	cub3d->textures->floor_color = (94 << 16) | (94 << 8) | 94;
	/* Cor do teto: RGB(135,206,235) → azul céu */
	cub3d->textures->ceil_color = (135 << 16) | (206 << 8) | 235;
}
 
void	load_scene(t_cub3d *cub3d, char *filename)
{
	(void)filename; /* ignorado enquanto usamos dados hardcoded */
	cub3d->map = malloc(sizeof(t_map));
	if (!cub3d->map)
		call_error(cub3d, "malloc map struct");
	ft_memset(cub3d->map, 0, sizeof(t_map));
	cub3d->textures = malloc(sizeof(t_textures));
	if (!cub3d->textures)
		call_error(cub3d, "malloc textures struct");
	ft_memset(cub3d->textures, 0, sizeof(t_textures));
	load_map(cub3d);
	load_textures(cub3d);
}
