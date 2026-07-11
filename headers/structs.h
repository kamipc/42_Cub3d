/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:22:08 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/11 22:44:29 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_textures
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*f;
	char	*c;
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
	char		*map_filename;
	t_map		*map;
	t_textures	*textures;
}			t_cub3d;

#endif