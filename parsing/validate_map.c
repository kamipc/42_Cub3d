/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:26:49 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/05/24 15:26:49 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

bool	is_map_start(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

void	save_map(t_cub3d *cub3d, char *line, int *i)
{
	char	*new_map_line;
	char	**new_map;

	new_map_line = ft_strdup(line);
	new_map = ft_realloc(cub3d->map->map, *i * sizeof(char *), (*i + 1) * sizeof(char *));
	if ((!new_map) || (!new_map_line))
	{
		free(line);
		call_error(cub3d, strerror(errno));
	}
	cub3d->map->map = new_map;
	cub3d->map->map[*i] = new_map_line;
	(*i)++;
	cub3d->map->map[*i] = NULL;
}

void	find_map(t_cub3d *cub3d)
{
	int		fd;
	char	*line;
	bool	map_start_found;
	int		i;

	i = 0;
	map_start_found = false;
	fd = open(cub3d->map_filename, O_RDONLY);
	if (fd < 0)
		call_error(cub3d, strerror(errno));
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!map_start_found)
			map_start_found = is_map_start(line);
		if (map_start_found)
			save_map(cub3d, line, &i);
		free(line);
	}
	close(fd);
}

void	validate_map(t_cub3d *cub3d)
{
	cub3d->map = init_map(cub3d);
	find_map(cub3d);

}
