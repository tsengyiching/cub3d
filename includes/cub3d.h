/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:57:17 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/13 16:21:00 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx/mlx.h"
# include "get_next_line.h"
# include <math.h>

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_LEFT	123
# define KEY_RIGHT	124

typedef struct		s_image
{
	void			*img_ptr;
	int				*img_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
}					t_image;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			img[6];
	char			start_dir;
	double			start_posx;
	double			start_posy;
	double			vector_dirx;
	double			vector_diry;
	double			planex;
	double			planey;
	double			camerax;
	double			ray_dirx;
	double			ray_diry;
	double			delta_distx;
	double			delta_disty;
	double			perp_wall_dist;
	int				stepx;
	int				stepy;
	int				mapx;
	int				mapy;
	int				hit;
	int				side;
	double			side_distx;
	double			side_disty;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				color;
	double			width;
	double			height;
}					t_mlx;

typedef struct		s_config
{
	int				height;
	int				width;
	int				ceiling;
	int				floor;
	int				player;
	int				map_rows;
	char			**map;
}					t_config;

int					parsing(int fd, t_config *cfg, t_mlx *mlx);
int					parse_resolution(t_config *cfg, char *line);
int					parse_texture(t_config *cfg, t_mlx *mlx, char *line);
int					get_texture_no(t_mlx *mlx, char *line);
int					get_texture_we(t_mlx *mlx, char *line);
int					get_texture_ea(t_mlx *mlx, char *line);
int					get_texture_s(t_mlx *mlx, char *line);
int					check_map(t_config *cfg, t_mlx *mlx);
int					ft_atoi(int i, char *line);
int					ft_atoi_save_index(int *i, char *line);
int					is_valid_identifier(char *line);
int					is_wall(char *line);
int					is_valid_color(int red, int green, int blue);
int					is_valid_elem(char **map, int x, int y);
void				init_plane_position(t_mlx *mlx);
void				init_vector_direction(t_mlx *mlx);
void				do_raycasting(t_mlx *mlx, t_config *cfg);
char				**ft_stradd_back(char *line, char **tab);
char				*ft_strdup(const char *s1);
#endif
