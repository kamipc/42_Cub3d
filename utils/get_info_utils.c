/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:07:13 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/15 14:20:12 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

bool	check_dup(t_cub3d *cub3d, char *trim, char *type)
{
	if (((ft_strncmp(type, "NO", 2)) == 0) && cub3d->textures->no == NULL)
		cub3d->textures->no = trim;
	else if ((ft_strncmp(type, "SO", 2)) == 0 && cub3d->textures->so == NULL)
		cub3d->textures->so = trim;
	else if ((ft_strncmp(type, "EA", 2)) == 0 && cub3d->textures->ea == NULL)
		cub3d->textures->ea = trim;
	else if ((ft_strncmp(type, "WE", 2)) == 0 && cub3d->textures->we == NULL)
		cub3d->textures->we = trim;
	else if ((ft_strncmp(type, "F", 1)) == 0
		&& cub3d->textures->floor_color == -1)
		save_color(cub3d, trim, type);
	else if ((ft_strncmp(type, "C", 1)) == 0
		&& cub3d->textures->ceil_color == -1)
		save_color(cub3d, trim, type);
	else
		return (free(trim), call_error(cub3d, ERROR_DUP_TEXT), false);
	return (true);
}

//trim path to remove excess spaces if they exist and the \n at the end 
//and save clean path to the textures
bool	trim_path(t_cub3d *cub3d, char *line, char *type)
{
	char	*trim;

	if (ft_strncmp(line, type, ft_strlen(type)) != 0)
		return (false);
	trim = ft_strtrim(line + ft_strlen(type), " \t\n\r");
	if (!check_dup(cub3d, trim, type))
		return (false);
	return (true);
}

bool	save_textures(t_cub3d *cub3d, char *line)
{
	if (trim_path(cub3d, line, "NO"))
		return (true);
	if (trim_path(cub3d, line, "SO"))
		return (true);
	if (trim_path(cub3d, line, "EA"))
		return (true);
	if (trim_path(cub3d, line, "WE"))
		return (true);
	if (trim_path(cub3d, line, "F"))
		return (true);
	if (trim_path(cub3d, line, "C"))
		return (true);
	return (false);
}

void	remove_line(t_cub3d *cub3d, int i)
{
	int		j;
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
