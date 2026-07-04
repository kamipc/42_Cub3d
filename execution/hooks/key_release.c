/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:46:03 by sade-ara          #+#    #+#             */
/*   Updated: 2026/06/27 14:52:22 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"
 
int	key_release(int keycode, t_cub3d *cub3d)
{
	if (keycode == KEY_W)
		cub3d->keys.w = 0;
	else if (keycode == KEY_A)
		cub3d->keys.a = 0;
	else if (keycode == KEY_S)
		cub3d->keys.s = 0;
	else if (keycode == KEY_D)
		cub3d->keys.d = 0;
	else if (keycode == KEY_LEFT)
		cub3d->keys.left = 0;
	else if (keycode == KEY_RIGHT)
		cub3d->keys.right = 0;
	return (0);
}
