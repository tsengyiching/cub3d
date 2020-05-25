/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 18:32:01 by yictseng          #+#    #+#             */
/*   Updated: 2020/05/25 16:20:57 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		is_valid_color(int red, int green, int blue)
{
	if (red > 255 || green > 255 || blue > 255)
		return (0);
	if (red == -1 || green == -1 || blue == -1)
		return (0);
	return (1);
}

int		get_rgb(char *line, int *index)
{
	int		red;
	int		green;
	int		blue;
	int		res;

	if (line[*index] != ' ')
		return (-1);
	while (line[*index] == ' ')
		(*index)++;
	red = ft_atoi_save_index(index, line);
	if (line[*index] != ',')
		return (-1);
	(*index)++;
	green = ft_atoi_save_index(index, line);
	if (line[*index] != ',')
		return (-1);
	(*index)++;
	blue = ft_atoi_save_index(index, line);
	if (!is_valid_color(red, green, blue))
		return (-8);
	res = (256 * 256 * red) + (256 * green) + blue;
	return (res);
}

int		parse_rgb(t_config *cfg, char *line)
{
	int	index;

	index = 0;
	if (line[index] == 'C')
	{
		index++;
		cfg->ceiling = get_rgb(line, &index);
		if (cfg->ceiling < 0)
			return (cfg->ceiling);
	}
	else if (line[0] == 'F')
	{
		index++;
		cfg->floor = get_rgb(line, &index);
		if (cfg->floor < 0)
			return (cfg->floor);
	}
	if (line[index] != '\0')
		return (-1);
	return (1);
}
