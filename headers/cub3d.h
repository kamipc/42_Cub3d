/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:21:26 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/09 22:03:39 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h> //close, read, write
# include <stdio.h> //printf, perror
# include <stdlib.h> //malloc, free, exit
# include <string.h> //strerror
# include <fcntl.h> //open
# include <sys/time.h> //gettimeofday
# include <stdbool.h> //bool

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# include "structs.h"
# include "../libft/libft.h"

//---------- ERROR MESSAGES ------------//

# define ERROR_ARG "Invalid number of arguments\n"
# define ERROR_FILE_TYPE "Invalid file extension\n"
# define ERROR_FILE_NOEXIST "File does not exist\n"
# define ERROR_MISS_TEXT "Missing texture\n"
# define ERROR_INV_TEXT "Invalid texture\n"
# define ERROR_MAP_CHAR "Map has invalid information\n"
# define ERROR_MAP_PLAYER "Invalid number of players on map\n"
# define ERROR_JUNK_INFO "File has invalid information\n"

//--------------------------------------//

//free
void		free_cub3d(t_cub3d *cub3d);
void		free_array(char **array);
void		free_map(t_map *map);
void		free_textures(t_textures *textures);

//inits
t_cub3d		*init_cub3d(void);
t_map		*init_map(t_cub3d *cub3d);
t_textures	*init_textures(t_cub3d *cub3d);

//parsing
	//get_info
void		get_info(t_cub3d *cub3d);
void		save_info(t_cub3d *cub3d);
void		trim_info(t_cub3d *cub3d);
//validate
void		validate(t_cub3d *cub3d);
char		*find_truefile(char	*filepath, int *i);
//validate_file
void		validate_file(t_cub3d *cub3d);
//validate_textures
void		validate_textures(t_cub3d *cub3d);
bool		verify_imgs(t_cub3d *cub3d);
bool		img_is_valid(t_cub3d *cub3d, char *path);
//validate_map
void		validate_map(t_cub3d *cub3d);

//src

//utils
//get_info_utils
bool		trim_path(t_textures *textures, char *line, char *type);
bool		save_textures(t_cub3d *cub3d, char *line);
bool		is_empty(char *line);
void		remove_line(t_cub3d *cub3d, int i);
bool		is_map_line(char *line);
	//error
void		call_error(t_cub3d *cub3d, char *msg);
	//validate_map_utils
void		verify_map_characters(t_cub3d *cub3d);
bool		not_valid_character(char c);
bool		is_player_start(char c, int *playernum);
void		verify_map_walls(t_cub3d *cub3d);
void		copy_map(t_cub3d *cub3d);

#endif