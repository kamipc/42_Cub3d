/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:21:26 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/05/22 15:21:26 by cpinho-c         ###   ########.fr       */
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

# include "structs.h"
# include "libft/libft.h"

//---------- ERROR MESSAGES ------------//

# define ERROR_ARG "Invalid number of arguments\n"
# define ERROR_FILE_TYPE "Invalid file extension\n"
# define ERROR_FILE_NOEXIST "File does not exist\n"
# define ERROR_MISS_TEXT "Missing texture\n"
# define ERROR_INV_TEXT "Invalid texture\n"

//--------------------------------------//

//inits

//parsing
	//validate
void	validate(t_cub3d *cub3d);
	//validate_file
void	validade_file(t_cub3d *cub3d);
	//validate_textures
void	validate_textures(t_cub3d *cub3d);
void	get_texture_path(t_cub3d *cub3d, t_textures *textures);
int		trim_path(t_cub3d *cub3d, t_textures *textures, char *line, char *type);
bool	verify_imgs(t_cub3d *cub3d);
bool	img_is_valid(t_cub3d *cub3d, char *path);
	//validate_map
void	validate_map(t_cub3d *cub3d);
//src

//utils
void call_error(t_cub3d *cub3d, char *msg);

#endif