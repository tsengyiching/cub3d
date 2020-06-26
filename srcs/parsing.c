/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:15:15 by yictseng          #+#    #+#             */
/*   Updated: 2020/06/26 16:48:59 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		find_element(t_config *cfg, t_mlx *mlx, char *line)
{
	int		error_code;

	if (!is_valid_char(line))
		return (-2);
	if (line[0] == 'R')
	{
		if ((error_code = parse_resolution(cfg, line)) < 0)
			return (error_code);
	}
	else if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W'
		|| line[0] == 'E' || line[0] == 'C' || line[0] == 'F')
	{
		if ((error_code = parse_texture(cfg, mlx, line)) < 0)
			return (error_code);
	}
	else if (line[0] == '1' || line[0] == ' ')
	{
		if (is_wall(line))
			return (2);
		else
			return (-10);
	}
	return (1);
}

int		get_map(int ret, int fd, t_config *cfg, char *line)
{
	char	**tab;

	tab = NULL;
	while (ret > 0)
	{
		if (line != NULL)
		{
			if (!(cfg->map = malloc(sizeof(char *) * 2)))
				return (-9);
			if (!(cfg->map[0] = ft_strdup(line)))
				return (-9);
			cfg->map[1] = NULL;
			free(line);
			line = NULL;
		}
		ret = get_next_line(fd, &line);
		if (!is_wall(line))
			return (-10);
		tab = cfg->map;
		if (!(cfg->map = ft_stradd_back(line, tab)))
			return (-9);
		free(line);
		line = NULL;
	}
	return (1);
}

int		parsing(int fd, t_config *cfg, t_mlx *mlx)
{
	char	*line;
	int		ret;
	int		error_code;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		error_code = find_element(cfg, mlx, line);
		if (error_code < 0)
			return (error_code);
		if (error_code == 2)
			break ;
		free(line);
		line = NULL;
	}
	if (ret > 0)
	{
		error_code = get_map(ret, fd, cfg, line);
		if (error_code < 0)
			return (error_code);
	}
	else if (ret == 0)
		return (-10);
	return (1);
}
