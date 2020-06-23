/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:19:04 by yictseng          #+#    #+#             */
/*   Updated: 2020/06/23 21:48:56 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	init_config(t_config *cfg)
{
	cfg->height = -1;
	cfg->width = -1;
	cfg->ceiling = -1;
	cfg->floor = -1;
	cfg->size_map = 0;
	cfg->map = NULL;
}

void	write_error(int error_code)
{
	if (error_code == -1)
		write(1, "Error : missing space or having invalid character\n", 50);
	else if (error_code == -2)
		write(1, "Error: having invalid identifier\n", 34);
	else if (error_code == -3)
		write(1, "Error: invalid path to the north texture\n", 41);
	else if (error_code == -4)
		write(1, "Error: invalid path to the south texture\n", 41);
	else if (error_code == -5)
		write(1, "Error: invalid path to the west texture\n", 40);
	else if (error_code == -6)
		write(1, "Error: invalid path to the east texture\n", 40);
	else if (error_code == -7)
		write(1, "Error: invalid path to the sprite texture\n", 42);
	else if (error_code == -8)
		write(1, "Error: invalid color input\n", 28);
	else if (error_code == -9)
		write(1, "Error: malloc failed for map\n", 30);
}

int		main(int ac, char **av)
{
	int			fd;
	int			error_code;
	t_config	cfg;
	t_mlx		mlx;

	if (ac != 2)
	{
		write(1, "Error : can only have two arguments\n", 36);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error : opening file failed\n", 28);
		return (0);
	}
	//close(fd);
	init_config(&cfg);
	mlx.mlx_ptr = mlx_init();
	error_code = parsing(fd, &cfg, &mlx);
	//printf("error code: %d\n", error_code);
	if (error_code < 0)
	{
		write_error(error_code);
		return (0);
	}
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, cfg.width, cfg.height, "Cube3D");
	// mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img[0].img_ptr, 0, 0);
	// mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img[1].img_ptr, 100, 0);
	// mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img[2].img_ptr, 400, 0);
	// mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img[3].img_ptr, 0, 200);
	// mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img[4].img_ptr, 300, 300);
	//mlx_loop(mlx.mlx_ptr);
	// printf("map 0|%s|\n", cfg.map[0]);
	// printf("map 1|%s|\n", cfg.map[1]);
	// printf("map 2|%s|\n", cfg.map[2]);
	return (0);
}
