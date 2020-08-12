/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 16:48:38 by yictseng          #+#    #+#             */
/*   Updated: 2020/08/08 18:10:49 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		get_texture_no(t_mlx *mlx, char *line)
{
	while (*line == ' ')
		line++;
	mlx->img[NO].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, line,
			&mlx->img[NO].width, &mlx->img[NO].height);
	if (!mlx->img[NO].img_ptr)
		return (0);
	mlx->img[NO].img_data = (int *)mlx_get_data_addr(mlx->img[0].img_ptr,
			&mlx->img[NO].bpp, &mlx->img[NO].size_line, &mlx->img[NO].endian);
	if (!mlx->img[NO].img_data)
		return (0);
	return (1);
}

int		get_texture_so(t_mlx *mlx, char *line)
{
	while (*line == ' ')
		line++;
	mlx->img[SO].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, line,
			&mlx->img[SO].width, &mlx->img[SO].height);
	if (!mlx->img[SO].img_ptr)
		return (0);
	mlx->img[SO].img_data = (int *)mlx_get_data_addr(mlx->img[1].img_ptr,
			&mlx->img[SO].bpp, &mlx->img[SO].size_line, &mlx->img[SO].endian);
	if (!mlx->img[SO].img_data)
		return (0);
	return (1);
}

int		get_texture_we(t_mlx *mlx, char *line)
{
	while (*line == ' ')
		line++;
	mlx->img[WE].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, line,
			&mlx->img[WE].width, &mlx->img[WE].height);
	if (!mlx->img[WE].img_ptr)
		return (0);
	mlx->img[WE].img_data = (int *)mlx_get_data_addr(mlx->img[WE].img_ptr,
			&mlx->img[WE].bpp, &mlx->img[WE].size_line, &mlx->img[WE].endian);
	if (!mlx->img[WE].img_data)
		return (0);
	return (1);
}

int		get_texture_ea(t_mlx *mlx, char *line)
{
	while (*line == ' ')
		line++;
	mlx->img[EA].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, line,
			&mlx->img[EA].width, &mlx->img[EA].height);
	if (!mlx->img[EA].img_ptr)
		return (0);
	mlx->img[EA].img_data = (int *)mlx_get_data_addr(mlx->img[EA].img_ptr,
			&mlx->img[EA].bpp, &mlx->img[EA].size_line, &mlx->img[EA].endian);
	if (!mlx->img[EA].img_data)
		return (0);
	return (1);
}

int		get_texture_sp(t_mlx *mlx, char *line)
{
	while (*line == ' ')
		line++;
	mlx->img[SP].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, line,
		&mlx->img[SP].width, &mlx->img[SP].height);
	if (!mlx->img[SP].img_ptr)
		return (0);
	mlx->img[SP].img_data = (int *)mlx_get_data_addr(mlx->img[SP].img_ptr,
		&mlx->img[SP].bpp, &mlx->img[SP].size_line, &mlx->img[SP].endian);
	if (!mlx->img[SP].img_data)
		return (0);
	return (1);
}
