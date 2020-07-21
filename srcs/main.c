/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:19:04 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/20 22:17:56 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		write_error(int error_code)
{
	if (error_code == -1)
		write(1, "Error: Wrong number of argument\n", 32);
	else if (error_code == -2)
		write(1, "Error: Opening file failed\n", 27);
	else if (error_code == -3)
		write(1, "Error: Having invalid identifier\n", 34);
	else if (error_code == -4)
		write(1, "Error: Resolution\n", 18);
	else if (error_code == -5)
		write(1, "Error: Invalid path to the north texture\n", 41);
	else if (error_code == -6)
		write(1, "Error: Invalid path to the west texture\n", 40);
	else if (error_code == -7)
		write(1, "Error: Invalid path to the east texture\n", 40);
	else if (error_code == -8)
		write(1, "Error: Invalid path to the south texture\n", 41);
	else if (error_code == -9)
		write(1, "Error: Invalid path to the sprite texture\n", 42);
	else if (error_code == -10)
		write(1, "Error: Invalid ceiling RGB\n", 28);
	else if (error_code == -11)
		write(1, "Error: Invalid floor RGB\n", 26);
	else if (error_code == -12)
		write(1, "Error: Invalid char after RGB\n", 30);
	else if (error_code == -13)
		write(1, "Error: Invalid map\n", 19);
	else if (error_code == -14)
		write(1, "Error: Memory allocation failure\n", 33);
	else if (error_code == -15)
		write(1, "Error: Missing map\n", 18);
	else if (error_code == -16)
		write(1, "Error: Map has invalid char\n", 28);
	else if (error_code == -17)
		write(1, "Error: Map has wrong number of starting position\n", 49);
	else if (error_code == -18)
		write(1, "Error: Map is not closed with walls (left)\n", 43);
	else if (error_code == -19)
		write(1, "Error: Map is not closed with walls (right)\n", 44);
	else if (error_code == -20)
		write(1, "Error: Map is not closed with walls (up)\n", 41);
	else if (error_code == -21)
		write(1, "Error: Map is not closed with walls (down)\n", 43);
	else if (error_code == -22)
		write(1, "Error: Invalid file extension\n", 30);
	return (0);
}

int		is_valide_file(char *str)
{
	int		len;
	
	len = ft_strlen(str);
	if (str[len - 1] != 'b')
		return (0);
	if (str[len - 2] != 'u')
		return (0);
	if (str[len - 3] != 'c')
		return (0);
	if (str[len - 4] != '.')
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	int			fd;
	int			error_code;
	t_cub		cub;

	if (ac != 2)
		return (write_error(-1));
	if (!is_valide_file(av[1]))
		return (write_error(-22));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (write_error(-2));
	init_struct(&cub.cfg);
	cub.mlx.mlx_ptr = mlx_init();
	error_code = parsing(fd, &cub.cfg, &cub.mlx);
	close(fd);
	if (error_code < 0)
		return (write_error(error_code));
	init_raycasting(&cub.cfg, &cub.mlx);
	cub.mlx.win_ptr = mlx_new_window(cub.mlx.mlx_ptr, cub.cfg.width, cub.cfg.height, "Cube3D");
	cub.mlx.new_img = mlx_new_image(cub.mlx.mlx_ptr, cub.cfg.width, cub.cfg.height);
	cub.mlx.pixel = (int *)mlx_get_data_addr(cub.mlx.new_img, &cub.mlx.bpp, &cub.mlx.size_line, &cub.mlx.endian);
	mlx_loop_hook(cub.mlx.mlx_ptr, run_cub3d, &cub);
	mlx_hook(cub.mlx.win_ptr, 2, 0, press_key, &cub.key);
	mlx_hook(cub.mlx.win_ptr, 3, 0, release_key, &cub.key);
	mlx_loop(cub.mlx.mlx_ptr);
	return (0);
}
