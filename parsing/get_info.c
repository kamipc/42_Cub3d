/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:33:03 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/06/03 18:49:22 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	save_info(t_cub3d *cub3d)
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
		if (save_textures(cub3d, line))
			continue ;
		if (is_map_start(line))
			map_start_found = true;
		if (!map_start_found)
		{
			if (is_junk(line))
				call_error(cub3d, ERROR_JUNK_INFO);
		}
		else
			//save_map(cub3d, line, &i);
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
