/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:57:17 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/17 12:58:27 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx/mlx.h"
# include "get_next_line.h"
# include <math.h>

# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_ARROW_LEFT		123
# define KEY_ARROW_RIGHT	124
# define KEY_ESC			53

typedef struct		s_img
{
	void			*img_ptr;
	int				*img_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct		s_key
{
	int				forward;
	int				back;
	int				left;
	int				right;
	int				leftside;
	int				rightside;
	int				esc;
}					t_key;

typedef struct		s_mlx
{
	t_img			img[6];
	void			*mlx_ptr;
	void			*win_ptr;
	void			*new_img;
	int				*pixel;
	int				bpp;
	int				size_line;
	int				endian;
	double			posx;
	double			posy;
	double			vecdirx;
	double			vecdiry;
	double			old_dirx;
	double			planex;
	double			planey;
	double			old_planex;
	double			camerax;
	double			raydirx;
	double			raydiry;
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
	double			mvspeed;
	double			rotspeed;
}					t_mlx;

typedef struct		s_cfg
{
	int				height;
	int				width;
	int				player;
	int				start_posx;
	int				start_posy;
	int				map_rows;
	int				ceiling;
	int				floor;
	char			start_dir;
	char			**map;
}					t_cfg;

typedef struct		s_cub
{
	t_cfg			cfg;
	t_mlx			mlx;
	t_key			key;
}					t_cub;

int					parsing(int fd, t_cfg *cfg, t_mlx *mlx);
int					parse_resolution(t_cfg *cfg, char *line);
int					parse_texture(t_cfg *cfg, t_mlx *mlx, char *line);
int					get_texture_no(t_mlx *mlx, char *line);
int					get_texture_we(t_mlx *mlx, char *line);
int					get_texture_ea(t_mlx *mlx, char *line);
int					get_texture_s(t_mlx *mlx, char *line);
int					check_map(t_cfg *cfg);
int					ft_atoi(int i, char *line);
int					ft_atoi_save_index(int *i, char *line);
int					is_valid_identifier(char *line);
int					is_wall(char *line);
int					is_valid_color(int red, int green, int blue);
int					is_valid_elem(char **map, int x, int y);
void				init_struct(t_cfg *cfg);
void				init_raycasting(t_cfg *cfg, t_mlx *mlx);
void				find_walls(t_cfg *cfg, t_mlx *mlx);
void				calcul_perp_wall_dist(t_mlx *mlx);
void				calcul_pixel_to_fill_in_stripe(t_mlx *mlx);
void				draw_walls(int hor, t_cfg *cfg, t_mlx *mlx);
void				run_raycasting(t_cub *cub);
int					run_cub3d(t_cub *cub);
int					press_key(int keyboard, t_key *key);
int					release_key(int keyboard, t_key *key);
void				move_vertical(t_cfg *cfg, t_mlx *mlx, t_key *key);
void				move_horizontal(t_cfg *cfg, t_mlx *mlx, t_key *key);
void				rotate_view(t_mlx *mlx, t_key *key);
char				**ft_stradd_back(char *line, char **tab);
char				*ft_strdup(const char *s1);
#endif
