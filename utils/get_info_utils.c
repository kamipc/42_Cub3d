/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:07:13 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/05 11:56:58 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

//trim path to remove excess spaces if they exist and the \n at the end 
bool	trim_path(t_textures *textures, char *line, char *type)
{
	char	*trimmed;
	int		len;

	len = ft_strlen(type);
	if (ft_strncmp(line, type, len) != 0)
		return (false);
	if (line[len] != ' ' && line[len] != '\t')
		return (false);
	trimmed = ft_strtrim(line + len, " \t\n\r");
	if (!trimmed)
		return (false);
	if (ft_strncmp(type, "NO", 2) == 0)
		textures->NO = trimmed;
	else if (ft_strncmp(type, "SO", 2) == 0)
		textures->SO = trimmed;
	else if (ft_strncmp(type, "EA", 2) == 0)
		textures->EA = trimmed;
	else
		textures->WE = trimmed;
	return (true);
}

bool	is_junk(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (true);
		i++;
	}
	return (false);
}

bool	save_textures(t_cub3d *cub3d, char *line)
{
	if (trim_path(cub3d->textures, line, "NO"))
		return (true);
	if (trim_path(cub3d->textures, line, "SO"))
		return (true);
	if (trim_path(cub3d->textures, line, "EA"))
		return (true);
	if (trim_path(cub3d->textures, line, "WE"))
		return (true);
	if (save_color(cub3d, line, "F"))
		return (true);
	if (save_color(cub3d, line, "C"))
		return (true);
	return (false);
}

bool	is_map_start(char *line)
{
	int	i;
	int	has_map_char;

	i = 0;
	has_map_char = 0;
	while (line[i])
	{
		if (!ft_strchr("01NSEW \n", line[i]))
			return (false);
		if (ft_strchr("01NSEW", line[i]))
			has_map_char = 1;
		i++;
	}
	return (has_map_char);
}

void	save_map(t_cub3d *cub3d, char *line, int *i)
{
	char	*clean;
	char	**new_map;

	clean = ft_strtrim(line, "\n\r");
	if (!clean)
		call_error(cub3d, strerror(errno));
	new_map = ft_realloc(cub3d->map->map, (*i) * sizeof(char *),
			(*i + 2) * sizeof(char *));
	if (!new_map)
	{
		free(clean);
		call_error(cub3d, strerror(errno));
	}
	cub3d->map->map = new_map;
	cub3d->map->map[*i] = clean;
	(*i)++;
	cub3d->map->map[*i] = NULL;
}
