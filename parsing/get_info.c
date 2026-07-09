/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:33:03 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/09 22:08:30 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

//save every line from the map file into an array
void	save_info(t_cub3d *cub3d)
{
	int		fd;
	char	*line;
	char	**info;
	int		i;

	i = 0;
	info = NULL;
	fd = open(cub3d->map_filename, O_RDONLY);
	if (fd < 0)
		call_error(cub3d, strerror(errno));
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!info)
			info = (char **)malloc(2 * sizeof(char *));
		else
			info = ft_realloc(info, (i + 1) * sizeof(char *), (i + 2) * sizeof(char *));
		info[i] = ft_strdup(line);
		info[i + 1] = NULL;
		free(line);
		i++;
	}
	cub3d->map->map = info;
	close(fd);
}

//check the array line by lina to verify what info it has (textures or map info),
//and remove lines that are not map lines
void	trim_info(t_cub3d *cub3d)
{
	int	i;
	char	*temp;
	bool	map_found;

	i = 0;
	map_found = false;
	while (cub3d->map->map[i])
	{
		if (!map_found && save_textures(cub3d, cub3d->map->map[i]))
			remove_line(cub3d, i);
		else if (is_empty(cub3d->map->map[i]))
			remove_line(cub3d, i);
		else if (is_map_line(cub3d->map->map[i]))
		{
			map_found = true;
			temp = ft_strtrim(cub3d->map->map[i], "\n");
			free (cub3d->map->map[i]);
			cub3d->map->map[i] = temp;
			i++;
		}
		else
			call_error(cub3d, ERROR_JUNK_INFO);
	}
}

void	get_info(t_cub3d *cub3d)
{
	cub3d->textures = init_textures(cub3d);
	cub3d->map = init_map(cub3d);
	save_info(cub3d);
	trim_info(cub3d);
}
// if (save_textures(cub3d, line))
// 			continue ;
// 		if (is_map_start(line))
// 			map_start_found = true;
// 		if (!map_start_found)
// 		{
// 			if (is_junk(line))
// 				call_error(cub3d, ERROR_JUNK_INFO);
// 		}
// 		else
// 			//save_map(cub3d, line, &i);
// 		free(line);