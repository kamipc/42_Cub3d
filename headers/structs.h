/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:22:08 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/05/22 15:22:08 by cpinho-c         ###   ########.fr       */
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
	char	*map;
	char	*copy_map;
	char	*player_start;
}			t_map;

typedef struct s_cub3d
{
	void				*mlx;
	char				*map_filename;
	struct s_map		*map;
	struct s_textures	*textures;
}			t_cub3d;

#endif