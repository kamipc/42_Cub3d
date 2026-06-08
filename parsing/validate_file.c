/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:02:41 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/06/03 13:44:28 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

//verify if the file name has the correct extension and valid name
void	validate_file(t_cub3d *cub3d)
{
	char	*temp;
	int		i;

	temp = cub3d->map_filename;
	i = 0;
	if (!temp)
		call_error(cub3d, ERROR_FILE_NOEXIST);
	while (temp[i] && temp[i + 1] != '\0')
		i++;
	if ((ft_strncmp(&temp[i - 3], ".cub", 4) != 0) || (ft_strlen(temp) == 4))
		call_error(cub3d, ERROR_FILE_TYPE);
}
