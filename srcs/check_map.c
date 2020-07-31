/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:06:28 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/31 19:30:06 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_map_elem(t_cfg *cfg)
{
	int x;
	int	y;

	x = 0;
	while (cfg->map[x])
	{
		y = 0;
		while (cfg->map[x][y])
		{
			if (!is_valid_elem(cfg->map, x, y))
				return (0);
			if (cfg->map[x][y] == 'N' || cfg->map[x][y] == 'S'
			|| cfg->map[x][y] == 'W' || cfg->map[x][y] == 'E')
			{
				cfg->player++;
				cfg->start_dir = cfg->map[x][y];
				cfg->start_posx = x;
				cfg->start_posy = y;
			}
			y++;
		}
		x++;
	}
	cfg->map_rows = x - 1;
	return (1);
}

int		is_valid_map(t_cfg *cfg)
{
	int		x;
	int		y;
	int		error_code;

	x = 0;
	error_code = 0;
	while (cfg->map[x])
	{
		y = 0;
		while (cfg->map[x][y])
		{
			if (cfg->map[x][y] == '0' || cfg->map[x][y] == '2'
				|| cfg->map[x][y] == cfg->start_dir)
			{
				if (!check_wall(x, y, cfg))
					return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

int		count_sprite(t_cfg *cfg, t_mlx *mlx)
{
	int x;
	int	y;

	x = 0;
	while (cfg->map[x])
	{
		y = 0;
		while (cfg->map[x][y])
		{
			if (cfg->map[x][y] == '2')
				cfg->sprite_nb++;
			y++;
		}
		x++;
	}
	if (!(mlx->spr = malloc(sizeof(t_sprite) * cfg->sprite_nb)))
		return (write_error(-14));
	return (1);
}

int		check_map(t_cfg *cfg, t_mlx *mlx)
{
	int		error_code;

	error_code = 0;
	if (!check_map_elem(cfg))
		return (write_error(-16));
	if (cfg->player != 1)
		return (write_error(-17));
	if (!is_valid_map(cfg))
		return (0);
	if (!count_sprite(cfg, mlx))
		return (0);
	if (!(mlx->buf = malloc(sizeof(double) * (cfg->width - 1))))
		return (write_error(-14));
	return (1);
}
