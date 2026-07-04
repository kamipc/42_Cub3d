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
	else if (keycode == KEY_W)
		cub3d->keys.w = 1;
	else if (keycode == KEY_A)
		cub3d->keys.a = 1;
	else if (keycode == KEY_S)
		cub3d->keys.s = 1;
	else if (keycode == KEY_D)
		cub3d->keys.d = 1;
	else if (keycode == KEY_LEFT)
		cub3d->keys.left = 1;
	else if (keycode == KEY_RIGHT)
		cub3d->keys.right = 1;
	return (0);
}
