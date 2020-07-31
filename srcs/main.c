/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:19:04 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/31 22:37:50 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		is_save(char *str)
{
	int		i;
	int		len;
	char	*src;

	i = 0;
	src = "--save";
	len = ft_strlen(str);
	if (len != 6)
		return (0);
	while(str[i] == src[i] && str[i] && src[i])
		i++;
	if (i != 6)
		return(0);
	return (1);
}

int		check_arg(int ac, char **av)
{
	int len;
	
	if (ac < 2 || ac > 3)
		return (write_error(-1));
	if (ac == 2)
	{
		len = ft_strlen(av[1]);
		if (av[1][len - 1] != 'b' || av[1][len - 2] != 'u' ||
			av[1][len - 3] != 'c' || av[1][len - 4] != '.')
			return (write_error(-22));
	}
	if (ac == 3)
	{
		if (!is_save(av[2]))
			return (write_error(-23));
	}
	return (1);
}

int		get_config(int ac, char **av, t_cub *cub)
{
	int	fd;
	
	if (!check_arg(ac, av))
		return (0);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (write_error(-2));
	init_config(&cub->cfg);
	cub->mlx.mlx_ptr = mlx_init();
	if (!parsing(fd, &cub->cfg, &cub->mlx))
	{
		mlx_destroy_window(cub->mlx.mlx_ptr, cub->mlx.win_ptr);
		free_tab(cub->cfg.map);
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int		main(int ac, char **av)
{
	t_cub		cub;

	if (!get_config(ac, av, &cub))
		return (0);
	init_raycasting(&cub.cfg, &cub.mlx);
	cub.mlx.win_ptr = mlx_new_window(cub.mlx.mlx_ptr, cub.cfg.width,
						cub.cfg.height, "Cube3D");
	cub.mlx.new_img = mlx_new_image(cub.mlx.mlx_ptr, cub.cfg.width,
						cub.cfg.height);
	cub.mlx.pixel = (int *)mlx_get_data_addr(cub.mlx.new_img, &cub.mlx.bpp,
						&cub.mlx.size_line, &cub.mlx.endian);
	if (ac == 3)
		print_screen(&cub);
	mlx_loop_hook(cub.mlx.mlx_ptr, run_cub3d, &cub);
	mlx_hook(cub.mlx.win_ptr, 2, 0, press_key, &cub.key);
	mlx_hook(cub.mlx.win_ptr, 3, 0, release_key, &cub.key);
	mlx_hook(cub.mlx.win_ptr, 17, 0, close_window, &cub);
	mlx_loop(cub.mlx.mlx_ptr);
	return (0);
}
