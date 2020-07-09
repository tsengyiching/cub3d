/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 16:48:38 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/09 15:49:36 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		get_texture_no(t_mlx *mlx, char *line)
{
	if (*line != ' ')
		return (0);
	while (*line == ' ')
		line++;
	mlx->img[0].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, line,
			&mlx->img[0].width, &mlx->img[0].height);
	if (!mlx->img[0].img_ptr)
		return (0);
	mlx->img[0].img_data = (int *)mlx_get_data_addr(mlx->img[0].img_ptr,
			&mlx->img[0].bpp, &mlx->img[0].size_line, &mlx->img[0].endian);
	return (1);
}

int		get_texture_so(t_mlx *mlx, char *line)
{
	if (*line != ' ')
		return (0);
	while (*line == ' ')
		line++;
	mlx->img[1].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, line,
			&mlx->img[1].width, &mlx->img[1].height);
	if (!mlx->img[1].img_ptr)
		return (0);
	mlx->img[1].img_data = (int *)mlx_get_data_addr(mlx->img[1].img_ptr,
			&mlx->img[1].bpp, &mlx->img[1].size_line, &mlx->img[1].endian);
	return (1);
}

int		get_texture_we(t_mlx *mlx, char *line)
{
	if (*line != ' ')
		return (0);
	while (*line == ' ')
		line++;
	mlx->img[2].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, line,
			&mlx->img[2].width, &mlx->img[2].height);
	if (!mlx->img[2].img_ptr)
		return (0);
	mlx->img[2].img_data = (int *)mlx_get_data_addr(mlx->img[2].img_ptr,
			&mlx->img[2].bpp, &mlx->img[2].size_line, &mlx->img[2].endian);
	return (1);
}

int		get_texture_ea(t_mlx *mlx, char *line)
{
	if (*line != ' ')
		return (0);
	while (*line == ' ')
		line++;
	mlx->img[3].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, line,
			&mlx->img[3].width, &mlx->img[3].height);
	if (!mlx->img[3].img_ptr)
		return (0);
	mlx->img[3].img_data = (int *)mlx_get_data_addr(mlx->img[3].img_ptr,
			&mlx->img[3].bpp, &mlx->img[3].size_line, &mlx->img[3].endian);
	return (1);
}

int		get_texture_s(t_mlx *mlx, char *line)
{
	if (*line == 'O')
	{
		if (!get_texture_so(mlx, line + 1))
			return (-8);
	}
	else
	{
		if (*line != ' ')
			return (-9);
		while (*line == ' ')
			line++;
		mlx->img[4].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, line,
			&mlx->img[4].width, &mlx->img[4].height);
		if (!mlx->img[4].img_ptr)
			return (-9);
		mlx->img[4].img_data = (int *)mlx_get_data_addr(mlx->img[4].img_ptr,
			&mlx->img[4].bpp, &mlx->img[4].size_line, &mlx->img[4].endian);
	}
	return (1);
}
