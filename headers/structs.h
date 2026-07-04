/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:22:08 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/02 17:56:44 by sade-ara         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_textures
{
	char	*NO;
	char	*SO;
	char	*EA;
	char	*WE;
	char	*F;
	char	*C;
	int		floor_color;
	int		ceil_color;
}	t_textures;

typedef struct s_square
{
	int	x;
	int	y;
	int	size;
	int	color;
}	t_square;

typedef struct s_map
{
	char	**map;
	char	**copy_map;
	char	player_start_dir;
	int		player_x;
	int		player_y;
}			t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	wall_x;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	step;
	double	tex_pos;
	double	perp_wall_dist;
	int		tex_x;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_cub3d
{
	void		*mlx;
	void		*win;
	char		*map_filename;
	t_img		img;
	t_img		no;
	t_img		so;
	t_img		ea;
	t_img		we;
	t_map		*map;
	t_player	*player;
	t_textures	*textures;
}	t_cub3d;

#endif