/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:07:13 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/09 23:21:05 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

//trim path to remove excess spaces if they exist and the \n at the end 
//and save clean path to the textures
bool	trim_path(t_textures *textures, char *line, char *type)
{
	char	*temp;
	char	*trim;

	if(ft_strncmp(line, type, ft_strlen(type)) != 0)
		return (false);
	temp = ft_strtrim(line + ft_strlen(type), " ");
	trim = ft_strtrim(temp, "\n");
	if ((ft_strncmp(type, "NO", 2)) == 0)
		textures->NO = trim;
	else if ((ft_strncmp(type, "SO", 2)) == 0)
		textures->SO = trim;
	else if ((ft_strncmp(type, "EA", 2)) == 0)
		textures->EA = trim;
	else if ((ft_strncmp(type, "WE", 2)) == 0)
		textures->WE = trim;
	else if ((ft_strncmp(type, "F", 1)) == 0)
		textures->F = trim;
	else if ((ft_strncmp(type, "C", 1)) == 0)
		textures->C = trim;
	free(temp);
	return (true);
}

bool	is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}
bool	save_textures(t_cub3d *cub3d, char *line)
{
	if (trim_path(cub3d->textures, line, "NO"))
		return (true);
	else if (trim_path(cub3d->textures, line, "SO"))
		return (true);
	else if (trim_path(cub3d->textures, line, "EA"))
		return (true);
	else if (trim_path(cub3d->textures, line, "WE"))
		return (true);
	else if (trim_path(cub3d->textures, line, "F"))
		return (true);
	else if (trim_path(cub3d->textures, line, "C"))
		return (true);
	else
		return (false);
}

void	remove_line(t_cub3d *cub3d, int i)
{
	int	j;
	char	**new_map;

	j = 0;
	while (cub3d->map->map && cub3d->map->map[j])
		j++;
	new_map = (char **)malloc(j * sizeof(char *));
	if (!new_map)
		call_error(cub3d, strerror(errno));
	j = 0;
	while (cub3d->map->map && cub3d->map->map[j] && cub3d->map->map[j + 1])
	{
		if (i > j)
			new_map[j] = ft_strdup(cub3d->map->map[j]);
		else
			new_map[j] = ft_strdup(cub3d->map->map[j + 1]);
		j++;
	}
	new_map[j] = NULL;
	free_array(cub3d->map->map);
	cub3d->map->map = new_map;
}

bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != ' '
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'W'
			&& line[i] != 'E' && line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}
