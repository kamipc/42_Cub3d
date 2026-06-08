/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:22:08 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/06/03 13:35:31 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_textures
{
	char	*NO;
	char	*SO;
	char	*EA;
	char	*WE;
	char	*F;
	char	*C;
}			t_textures;

typedef struct s_map
{
	char	**map;
	char	**copy_map;
	char	player_start_dir;
	int		player_x;
	int		player_y;
}			t_map;

typedef struct s_cub3d
{
	void		*mlx;
	void		*win;
	char		*map_filename;
	t_map		*map;
	t_textures	*textures;
}			t_cub3d;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
}	t_player;


#endif