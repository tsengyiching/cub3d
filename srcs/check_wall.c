/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:23:18 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/21 16:24:01 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
