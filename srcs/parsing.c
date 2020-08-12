/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:15:15 by yictseng          #+#    #+#             */
/*   Updated: 2020/08/12 16:25:48 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		find_identifier(t_cfg *cfg, t_mlx *mlx, char *line)
{
	if (!is_valid_identifier(line))
		return (write_error(-3));
	if (line[0] == 'R')
	{
		if (!parse_resolution(cfg, line))
			return (write_error(-4));
	}
	else if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W'
		|| line[0] == 'E' || line[0] == 'C' || line[0] == 'F')
	{
		if (!parse_texture(cfg, mlx, line))
			return (0);
	}
	else if (line[0] == '1' || line[0] == ' ')
	{
		if (is_wall(line))
			return (2);
		else
			return (write_error(-13));
	}
	return (1);
}

void	free_line(char *line)
{
	free(line);
	line = NULL;
}

int		get_map_first_line(t_cfg *cfg, char *line)
{
	if (line != NULL)
	{
		if (!(cfg->map = malloc(sizeof(char *) * 2)))
			return (write_error(-14));
		if (!(cfg->map[0] = ft_strdup(line)))
			return (write_error(-14));
		cfg->map[1] = NULL;
		free(line);
		line = NULL;
	}
	return (1);
}

int		get_map(int ret, int fd, t_cfg *cfg, char *line)
{
	char	**tab;

	tab = NULL;
	while (ret > 0)
	{
		if (!(get_map_first_line(cfg, line)))
			return (0);
		ret = get_next_line(fd, &line);
		if (!is_wall(line) && ret != 0)
		{
			free(line);
			return (write_error(-13));
		}
		tab = cfg->map;
		if (!(cfg->map = ft_stradd_back(line, tab)))
			return (write_error(-14));
		free(line);
		line = NULL;
	}
	return (1);
}

int		parsing(int fd, t_cfg *cfg, t_mlx *mlx)
{
	char	*line;
	int		ret;
	int		error_code;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		error_code = find_identifier(cfg, mlx, line);
		if (error_code != 2)
			free_line(line);
		if (!error_code)
			return (0);
		if (error_code == 2)
			break ;
	}
	if (ret > 0)
		if (!get_map(ret, fd, cfg, line))
			return (0);
	if (ret == 0)
		return (write_error(-15));
	if (!check_map(cfg, mlx))
		return (0);
	return (1);
}
