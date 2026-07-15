/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 11:55:51 by sade-ara          #+#    #+#             */
/*   Updated: 2026/07/15 13:25:31 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static bool	all_digits(char *s)
{
	int	i;

	i = 0;
	if (!s[0])
		return (false);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

static bool	parse_rgb(char *value, int *packed)
{
	char	**tok;
	int		r;
	int		g;

	tok = ft_split(value, ',');
	if (!tok || !tok[0] || !tok[1] || !tok[2] || tok[3])
		return (free_array(tok), false);
	if (!all_digits(tok[0]) || !all_digits(tok[1]) || !all_digits(tok[2]))
		return (free_array(tok), false);
	r = ft_atoi(tok[0]);
	g = ft_atoi(tok[1]);
	if (r > 255 || g > 255 || ft_atoi(tok[2]) > 255)
		return (free_array(tok), false);
	*packed = (r << 16) | (g << 8) | ft_atoi(tok[2]);
	return (free_array(tok), true);
}

bool	save_color(t_cub3d *cub3d, char *line, char *type)
{
	int		packed;

	if (!line || !parse_rgb(line, &packed))
		return (free(line), call_error(cub3d, ERROR_RGB_FORMAT), false);
	if (ft_strncmp(type, "F", 1) == 0)
		cub3d->textures->floor_color = packed;
	else
		cub3d->textures->ceil_color = packed;
	free(line);
	return (true);
}
