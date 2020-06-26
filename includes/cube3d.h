/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 15:48:43 by yictseng          #+#    #+#             */
/*   Updated: 2020/06/26 16:49:37 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../minilibx/mlx.h"
# include "get_next_line.h"

typedef struct	s_image
{
	void	*img_ptr;
	int		*img_data;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}				t_image;

typedef struct 	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		img[6];
}				t_mlx;

typedef struct s_config
{
	int		height;
	int		width;
	int		ceiling;
	int		floor;
	int		size_map;
	char	**map;
}			   t_config;

int		parsing(int fd, t_config *cfg, t_mlx *mlx);
int		parse_resolution(t_config *cfg, char *line);
int		parse_texture(t_config *cfg, t_mlx *mlx, char *line);
int		get_texture_no(t_mlx *mlx, char *line);
int		get_texture_we(t_mlx *mlx, char *line);
int		get_texture_ea(t_mlx *mlx, char *line);
int		get_texture_s(t_mlx *mlx, char *line);
int		ft_atoi(int i, char *line);
int		ft_atoi_save_index(int *i, char *line);
int		is_valid_char(char *line);
int		is_wall(char *line);
int		is_valid_color(int red, int green, int blue);
char	**ft_stradd_back(char *line, char **tab);
char	*ft_strdup(const char *s1);
#endif
