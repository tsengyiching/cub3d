/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:06:28 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/17 12:50:43 by yictseng         ###   ########lyon.fr   */
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

int		check_horizotal_left(int x, int y, t_cfg *cfg)
{
	while (y > 0 && cfg->map[x][y] != '1' && cfg->map[x][y] != ' ')
		y--;
	if (cfg->map[x][y] != '1')
		return (0);
	return (1);
}

int		check_horizotal_right(int x, int y, t_cfg *cfg)
{
	while (y > 0 && cfg->map[x][y] != '1' && cfg->map[x][y] != ' ')
		y++;
	if (cfg->map[x][y] != '1')
		return (0);
	return (1);
}

int		check_vertical_up(int x, int y, t_cfg *cfg)
{
	while (x > 0 && cfg->map[x][y] != '1' && cfg->map[x][y] != ' ')
		x--;
	if (cfg->map[x][y] != '1')
		return (0);
	return (1);
}

int		check_vertical_down(int x, int y, t_cfg *cfg)
{
	while (x < cfg->map_rows && cfg->map[x][y] != '1' && cfg->map[x][y] != ' '
		&& cfg->map[x][y] != '\0')
		x++;
	if (cfg->map[x][y] != '1')
		return (0);
	return (1);
}

int		check_wall(int x, int y, t_cfg *cfg)
{
	if (!check_horizotal_left(x, y, cfg))
		return (-18);
	if (!check_horizotal_right(x, y, cfg))
		return (-19);
	if (!check_vertical_up(x, y, cfg))
		return (-20);
	if (!check_vertical_down(x, y, cfg))
		return (-21);
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
				if ((error_code = check_wall(x, y, cfg)) < 0)
					return (error_code);
			}
			y++;
		}
		x++;
	}
	return (1);
}

int		check_map(t_cfg *cfg)
{
	int		error_code;

	error_code = 0;
	if (!check_map_elem(cfg))
		return (-16);
	if (cfg->player != 1)
		return (-17);
	if ((error_code = is_valid_map(cfg)) < 0)
		return (error_code);
	return (1);
}
