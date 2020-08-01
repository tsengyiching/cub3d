/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 18:42:40 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/31 23:22:55 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		get_rgb(char *line, int *index)
{
	int		red;
	int		green;
	int		blue;
	int		res;

	while (line[*index] == ' ')
		(*index)++;
	red = ft_atoi_save_index(index, line);
	if (line[*index] != ',')
		return (0);
	(*index)++;
	green = ft_atoi_save_index(index, line);
	if (line[*index] != ',')
		return (0);
	(*index)++;
	blue = ft_atoi_save_index(index, line);
	if (!is_valid_color(red, green, blue))
		return (0);
	res = (256 * 256 * red) + (256 * green) + blue;
	return (res);
}

int		parse_rgb(t_cfg *cfg, char *line)
{
	int	index;

	index = 0;
	if (line[index] == 'C')
	{
		index++;
		cfg->ceiling = get_rgb(line, &index);
		if (cfg->ceiling == -1)
			return (write_error(-10));
	}
	else if (line[0] == 'F')
	{
		index++;
		cfg->floor = get_rgb(line, &index);
		if (cfg->floor == -1)
			return (write_error(-11));
	}
	if (line[index] != '\0')
		return (write_error(-12));
	return (1);
}

int		parse_texture(t_cfg *cfg, t_mlx *mlx, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		if (!get_texture_no(mlx, line + 2))
			return (write_error(-5));
	if (line[0] == 'W' && line[1] == 'E')
		if (!get_texture_we(mlx, line + 2))
			return (write_error(-6));
	if (line[0] == 'E' && line[1] == 'A')
		if (!get_texture_ea(mlx, line + 2))
			return (write_error(-7));
	if (line[0] == 'C' || line[0] == 'F')
		if (!parse_rgb(cfg, line))
			return (0);
	if (line[0] == 'S')
		if (!get_texture_s(mlx, line + 1))
			return (0);
	return (1);
}

void	adjust_resolution(t_cfg *cfg)
{
	cfg->width = cfg->width > 1440 ? 1440 : cfg->width;
	cfg->height = cfg->height > 900 ? 900 : cfg->height;
	cfg->width = cfg->width < 100 ? 100 : cfg->width;
	cfg->height = cfg->height < 100 ? 100 : cfg->height;
}

int		parse_resolution(t_cfg *cfg, char *line)
{
	int i;

	i = 1;
	while (line[i] == ' ')
		i++;
	if (line[i] >= '0' && line[i] <= '9')
		cfg->width = ft_atoi(i, line);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i] != ' ')
		return (0);
	while (line[i] == ' ')
		i++;
	if (line[i] >= '0' && line[i] <= '9')
		cfg->height = ft_atoi(i, line);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i] != '\0')
		return (0);
	if (cfg->width == -1 || cfg->height == -1)
		return (0);
	adjust_resolution(cfg);
	return (1);
}
