/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:57:17 by yictseng          #+#    #+#             */
/*   Updated: 2020/08/08 18:09:00 by yictseng         ###   ########lyon.fr   */
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
# define NO					0
# define SO					1
# define WE					2
# define EA					3
# define SP					4

typedef struct		s_bmfh
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
}					t_bmfh;

typedef struct		s_bmih
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}					t_bmih;

typedef struct		s_rgb
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}					t_rgb;

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

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			dist;
}					t_sprite;

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
	t_img			img[5];
	t_sprite		*spr;
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
	int				texture;
	double			wall_pos;
	double			step;
	double			text_pos;
	int				textx;
	int				texty;
	double			*buf;
	double			spritex;
	double			spritey;
	double			inv_det;
	double			transformx;
	double			transformy;
	int				spr_screenx;
	int				spr_height;
	int				spr_width;
	int				draw_startx;
	int				draw_starty;
	int				draw_endx;
	int				draw_endy;
}					t_mlx;

typedef struct		s_cfg
{
	int				check_value;
	int				height;
	int				width;
	int				player;
	int				start_posx;
	int				start_posy;
	int				map_rows;
	int				ceiling;
	int				floor;
	int				sprite_nb;
	char			start_dir;
	char			**map;
}					t_cfg;

typedef struct		s_cub
{
	t_cfg			cfg;
	t_mlx			mlx;
	t_key			key;
	t_bmfh			bmfh;
	t_bmih			bmih;
	t_rgb			rgb;
}					t_cub;

int					parsing(int fd, t_cfg *cfg, t_mlx *mlx);
int					parse_resolution(t_cfg *cfg, char *line);
int					parse_texture(t_cfg *cfg, t_mlx *mlx, char *line);
int					get_texture_no(t_mlx *mlx, char *line);
int					get_texture_we(t_mlx *mlx, char *line);
int					get_texture_ea(t_mlx *mlx, char *line);
int					get_texture_sp(t_mlx *mlx, char *line);
int					get_texture_so(t_mlx *mlx, char *line);
int					check_map(t_cfg *cfg, t_mlx *mlx);
int					check_wall(int x, int y, t_cfg *cfg);
int					ft_atoi(int i, char *line);
int					ft_atoi_save_index(int *i, char *line);
int					is_valid_identifier(char *line);
int					is_wall(char *line);
int					is_valid_color(int red, int green, int blue);
int					is_valid_elem(char **map, int x, int y);
void				init_config(t_cfg *cfg);
void				init_raycasting(t_cfg *cfg, t_mlx *mlx);
void				find_walls(t_cfg *cfg, t_mlx *mlx);
void				calcul_perp_wall_dist(t_mlx *mlx);
void				calcul_pixel_to_fill_in_stripe(t_mlx *mlx);
void				calcul_wall_texture(t_mlx *mlx);
void				draw_walls(int hor, t_cfg *cfg, t_mlx *mlx);
void				run_raycasting(t_cub *cub);
int					run_cub3d(t_cub *cub);
int					press_key(int keyboard, t_key *key);
int					release_key(int keyboard, t_key *key);
void				move_vertical(t_cfg *cfg, t_mlx *mlx, t_key *key);
void				move_horizontal(t_cfg *cfg, t_mlx *mlx, t_key *key);
void				rotate_view(t_mlx *mlx, t_key *key);
void				find_sprite(t_cfg *cfg, t_mlx *mlx);
void				init_sprite_dist(t_cfg *cfg, t_mlx *mlx);
void				calcul_sprite(t_mlx *mlx, int i);
void				draw_sprite(t_mlx *mlx, t_cfg *cfg);
int					write_error(int error_code);
int					close_window(t_cub *cub);
void				free_tab(char **tab);
void				print_screen(t_cub *cub);
void				adjust_resolution(t_cfg *cfg);
char				**ft_stradd_back(char *line, char **tab);
char				*ft_strdup(const char *s1);
#endif
