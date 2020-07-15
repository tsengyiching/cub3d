/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:15:15 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/15 16:41:18 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		find_identifier(t_config *cfg, t_mlx *mlx, char *line)
{
	int		error_code;

	error_code = 0;
	if (!is_valid_identifier(line))
		return (-3);
	if (line[0] == 'R')
	{
		if (!parse_resolution(cfg, line))
			return (-4);
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
			return (-13);
	}
	return (1);
}

int		get_map(int ret, int fd, t_mlx *mlx, char *line)
{
	char	**tab;

	tab = NULL;
	while (ret > 0)
	{
		if (line != NULL)
		{
			if (!(mlx->map = malloc(sizeof(char *) * 2)))
				return (-14);
			if (!(mlx->map[0] = ft_strdup(line)))
				return (-14);
			mlx->map[1] = NULL;
			free(line);
			line = NULL;
		}
		ret = get_next_line(fd, &line);
		if (!is_wall(line) && ret != 0)
			return (-13);
		tab = mlx->map;
		if (!(mlx->map = ft_stradd_back(line, tab)))
			return (-14);
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
		error_code = find_identifier(cfg, mlx, line);
		if (error_code < 0)
			return (error_code);
		if (error_code == 2)
			break ;
		free(line);
		line = NULL;
	}
	if (ret > 0)
		if ((error_code = get_map(ret, fd, mlx, line)) < 0)
			return (error_code);
	if (ret == 0)
		return (-15);
	if ((error_code = check_map(cfg, mlx)) < 0)
		return (error_code);
	return (1);
}
