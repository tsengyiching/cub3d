/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:15:15 by yictseng          #+#    #+#             */
/*   Updated: 2020/05/21 17:10:50 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		is_valid_char(char *line)
{
	if (line[0] == 'R'|| line[0] == 'N' || line[0] == 'S' || line[0] == 'W'
	 || line[0] == 'E' || line[0] == 'F' || line[0] == 'C' || line[0] == '1'
	 || line[0] == ' ' || line[0] == '\0')
		return (1);
	return (0);
}

int		find_element(t_config *cfg, t_mlx *mlx, char *line)
{
	int		error_code;

	if (!is_valid_char(line))
		return (-2);
	if (line[0] == 'R')
	{
		if ((error_code = get_resolution(cfg, line)) < 0)
			return (error_code);
	}
	else if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W'
		|| line[0] == 'E')
	{
		if ((error_code = parse_texture(mlx, line)) < 0)
			return (error_code);
	}
	// else if (line[0] == 'F' || line[0] == 'C')
	// {

	// }
	// else if (line[0] == '1' || line[0] == ' ')
	// {

	// }
	// else if (line[0] != 'R' && line[0] != 'N' && line[0] != 'S' && line[0] != 'W'
	// && line[0] != 'E' && line[0] != 'F' && line[0] != 'C' && line[0] != '1' && line[0] != ' ')
	// 	return (-2);
	return (1);
}

int		parsing(int fd, t_config *cfg, t_mlx *mlx)
{
	char	*line;
	int		ret;
	int		error_code;

	ret = 1;
	error_code = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		error_code = find_element(cfg, mlx, line);
		if (error_code < 0)
			return (error_code);
		// if (error_code == 2)
		// {
		// 	//char **map;
		// }
		free(line);
	}
	return (1);
}