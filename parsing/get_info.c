/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:33:03 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/05 10:37:42 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	save_info(t_cub3d *cub3d)
{
	int		fd;
	char	*line;
	bool	map_found;
	int		i;

	i = 0;
	map_found = false;
	fd = open(cub3d->map_filename, O_RDONLY);
	if (fd < 0)
		call_error(cub3d, strerror(errno));
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!map_found && save_textures(cub3d, line))
			;
		else if (map_found || is_map_start(line))
		{
			map_found = true;
			save_map(cub3d, line, &i);
		}
		else if (is_junk(line))
			call_error(cub3d, ERROR_JUNK_INFO);
		free(line);
	}
	close(fd);
}

void	get_info(t_cub3d *cub3d)
{
	cub3d->textures = init_textures(cub3d);
	cub3d->map = init_map(cub3d);
	save_info(cub3d);
}
