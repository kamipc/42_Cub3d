/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:02:41 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/07/11 22:40:04 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

//verify if the file name has the correct extension and valid name
void	validate_file(t_cub3d *cub3d)
{
	char	*temp;
	int		i;

	i = 0;
	if (!cub3d->map_filename)
		call_error(cub3d, ERROR_FILE_NOEXIST);
	temp = find_truefile(cub3d->map_filename, &i);
	if ((ft_strncmp(&temp[i - 3], ".cub", 4) != 0) || (ft_strlen(temp) == 4))
	{
		free(temp);
		call_error(cub3d, ERROR_FILE_TYPE);
	}
	free(temp);
}

//extract the name of the map file from the full name path
char	*find_truefile(char	*filepath, int *i)
{
	char	*temp;
	int		true_len;
	bool	hasdirname;

	hasdirname = false;
	temp = NULL;
	while (filepath[*i] && filepath[*i + 1] != '\0')
	{
		if (filepath[*i] == '/')
			hasdirname = true;
		(*i)++;
	}
	if (hasdirname == true)
	{
		true_len = *i;
		while (*i > 0 && filepath[*i] != '/')
			(*i)--;
		true_len = true_len - (*i);
		temp = ft_substr(filepath, *i + 1, true_len);
		*i = true_len - 1;
	}
	return (temp);
}
