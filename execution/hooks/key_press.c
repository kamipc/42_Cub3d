/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:45:57 by sade-ara          #+#    #+#             */
/*   Updated: 2026/06/27 14:51:36 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	key_press(int keycode, t_cub3d *cub3d)
{
	if (keycode == KEY_ESC || keycode == 9)
		close_win(cub3d);
	return (0);
}
