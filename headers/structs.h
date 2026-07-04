/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:22:08 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/04 17:11:42 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_col
{
	int	x;
	int	y_start;
	int	y_end;
	int	color;
}	t_col;

typedef struct s_tex_col
{
	int		x;
	int		y_start;
	int		y_end;
	int		tex_x;
	double	tex_pos;
	double	step;
	t_img	*tex;
}	t_tex_col;

typedef struct s_textures
{
	char	*NO;
	char	*SO;
	char	*EA;
	char	*WE;
	t_img	img_no;
	t_img	img_so;
	t_img	img_ea;
	t_img	img_we;
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
	int		width;
	int		height;
}	t_map;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;
 
typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}	t_player;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;
 
typedef struct s_cub3d
{
	void		*mlx;
	void		*win;
	char		*map_filename;
	t_img		img;
	t_map		*map;
	t_player	*player;
	t_textures	*textures;
	t_keys		keys;
}	t_cub3d;
 
#endif