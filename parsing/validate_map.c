/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:26:49 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/06/03 18:42:46 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

//finds map in the file to start saving it to then validate
// void	find_map(t_cub3d *cub3d)
// {
// 	int		fd;
// 	char	*line;
// 	bool	map_start_found;
// 	int		i;

// 	i = 0;
// 	map_start_found = false;
// 	fd = open(cub3d->map_filename, O_RDONLY);
// 	if (fd < 0)
// 		call_error(cub3d, strerror(errno));
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		if (!map_start_found)
// 			map_start_found = is_map_start(line);
// 		if (map_start_found)
// 			save_map(cub3d, line, &i);
// 		free(line);
// 	}
// 	close(fd);
// }

void	validate_map(t_cub3d *cub3d)
{
	cub3d->map = init_map(cub3d);
	verify_map_characters(cub3d);
	verify_map_walls(cub3d);
}
