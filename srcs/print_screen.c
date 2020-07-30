/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 16:39:30 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/30 23:41:11 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	write_in_bmp(int fd, t_cub *cub)
{
	int		x;
	int		y;
	int		pixel;

	y = cub->cfg.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < cub->cfg.width - 1)
		{
			pixel = cub->mlx.pixel[x + y * cub->cfg.width];
			x++;
		}
		y--;
	}
}

void	init_bitmap(t_bmfh *bmfh, t_bmih *bmih, t_cfg *cfg)
{
	bmfh->bitmap_type[0] = 'B';
	bmfh->bitmap_type[1] = 'M';
	bmfh->file_size = 54 + 3 * cfg->width * cfg->height;
	bmfh->reserved1 = 0;
	bmfh->reserved2 = 0;
	bmfh->offset_bits = 0;
	bmih->size_header = 40;
	bmih->width = cfg->width;
	bmih->height = cfg->height;
	bmih->planes = 1;
	bmih->bit_count = 24;
	bmih->compression = 0;
	bmih->image_size = 54 + 3 * cfg->width * cfg->height;
	bmih->ppm_x = 1;
	bmih->ppm_y = 1;
	bmih->clr_used = 0;
	bmih->clr_important = 0;
}

int		print_screen(t_cub *cub)
{
	int		fd;

	run_cub3d(cub);
	init_bitmap(&cub->bmfh, &cub->bmih, &cub->cfg);
	if ((fd = open("screenshop.bmp", O_RDWR | O_CREAT, 0777)) == -1)
		return (write_error(-2));
	write(fd, &cub->bmfh, 14);
	write(fd, &cub->bmih, 40);
	write_in_bmp(fd, cub);
	close(fd);
	close_window(cub);
	return (1);
}
