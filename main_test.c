#include "../headers/cub3d.h"

void	print_textures(t_textures *textures)
{
	printf("=== TEXTURES ===\n");
	if (!textures)
	{
		printf("  (null)\n");
		return ;
	}
	printf("  NO : %s\n", textures->no ? textures->no : "(null)");
	printf("  SO : %s\n", textures->so ? textures->so : "(null)");
	printf("  EA : %s\n", textures->ea ? textures->ea : "(null)");
	printf("  WE : %s\n", textures->we ? textures->we : "(null)");
	printf("  F  : %i\n", textures->floor_color  ? textures->floor_color : 0);
	printf("  C  : %i\n", textures->ceil_color  ? textures->ceil_color : 0);
}

void	print_map(t_map *map)
{
	int	i;

	printf("=== MAP ===\n");
	if (!map)
	{
		printf("  (null)\n");
		return ;
	}
	printf("  player_start_dir : %c\n", map->player_start_dir);
	printf("  player_x         : %d\n", map->player_x);
	printf("  player_y         : %d\n", map->player_y);
	printf("  map grid:\n");
	if (!map->map)
		printf("    (null)\n");
	else
	{
		i = 0;
		while (map->map[i])
		{
			printf("    [%2d] %s\n", i, map->map[i]);
			i++;
		}
	}
	printf("  copy_map grid:\n");
	if (!map->copy_map)
		printf("    (null)\n");
	else
	{
		i = 0;
		while (map->copy_map[i])
		{
			printf("    [%2d] %s\n", i, map->copy_map[i]);
			i++;
		}
	}
}

void	print_cub3d(t_cub3d *cub3d)
{
	printf("========== CUB3D ==========\n");
	if (!cub3d)
	{
		printf("  (null)\n");
		return ;
	}
	printf("  mlx          : %p\n", cub3d->mlx);
	printf("  map_filename : %s\n", cub3d->map_filename ? cub3d->map_filename : "(null)");
	print_textures(cub3d->textures);
	print_map(cub3d->map);
	printf("===========================\n");
}

void	print_array(char **array)
{
	int	i = 0;
	
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_cub3d	*cub3d;

	if (ac != 2)
		call_error(NULL, ERROR_ARG);
	cub3d = init_cub3d();
	cub3d->map_filename = ft_strdup(av[1]);
	validate(cub3d);
	printf("%s\n", cub3d->map_filename);
	print_textures(cub3d->textures);
	print_map(cub3d->map);
	// validate_textures(cub3d);
	// //------print
	// print_cub3d(cub3d);
	// //------
	// if (!verify_imgs(cub3d))
	// 	call_error(cub3d, ERROR_INV_TEXT);
	// ft_printf(1, "images validated!\n");
	free_cub3d(cub3d);
}