/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:40:49 by tursescu          #+#    #+#             */
/*   Updated: 2024/12/04 15:51:49 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../dirs/libft/libft.h"
# include "../dirs/mlx/mlx.h"
# include "../inc/cub3dd.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

# define TILE_SIZE 120
# define MINI_TILE_SIZE 30

# define ESC_KEY 65307
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define RED "\033[31m"
# define RESET "\033[0m"

# define TEXTURE_NO "../inc/NO.xpm"
# define TEXTURE_SO "../inc/SO.xpm"
# define TEXTURE_WE "../inc/WE.xpm"
# define TEXTURE_EA "../inc/EA.xpm"

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}					t_map;

typedef struct s_textures
{
	char			*no_line;
	char			*so_line;
	char			*we_line;
	char			*ea_line;
	int				ceil[3];
	int				floor[3];
}					t_textures;

typedef struct s_game
{
	t_map			*map;
	char			**map_2d;
	size_t			width;
	size_t			height;
	t_textures		*textures;
}					t_game;






// INIT
void				init_textures_null(t_textures *textures);
void				init_game(t_game *game);
void				textrue_init(t_game *game, t_textures *textures);
void				window_init(t_game *game);
// RENDERING
void				render_map(t_game *game);
void				render_textures(char target, t_game *game, int x, int y);
// PARSING
char				*trim_newline(char *line);
t_map				*make_map(const char *file_path);
void				get_map_dimensions(t_map *head, size_t *width,
						size_t *height);
void				find_player_pos(t_map *head, size_t *x, size_t *y);
int					player_found(t_map *head);
int					only_one_player(t_map *head);
int					players_in_row(const char *line);
int					is_surrounded(t_game *game);
void				flood_fill(t_map *head, size_t x, size_t y);
int					good_input(t_game *game);
int					parse_textures_colors(t_map **head, t_textures *textures);
int					parse_color(const char *line, int color[3]);
void				fill_from_zero(t_map *head);
void				complete_flood(t_map *head, size_t x, size_t y);
int					is_valid_adjacent(t_map *head, size_t x, size_t y);
int					has_bad_char(t_map *head);
int					is_wrong_char(char c);
// UTILS
int					is_player(char c);
int					is_space(char c);
t_map				*create_node(char *line);
void				err(char *str);
t_map				*copy_map(t_map *og);
void				append_node(t_map **head, t_map *new_node);
int					has_char(const char *str, char c);
char				get_char_at(t_map *head, size_t x, size_t y);
void				set_char_at(t_map *head, size_t x, size_t y, char c);
char				**convert_map(t_game *game);
void				eliminate_spaces(t_textures *textures);
void				rmv_space_in_str(char **str);
int					is_empty_line(char *line);
// HOOKS
int					close_on_button(t_game *game);
int					key_hook(int keycode, t_game *game);
void				setup_hooks(t_game *game);
// FREEING
void				free_list(t_map *head);
int					propper_exit(t_game *game);
void				free_2d_map(t_game *game);
void				free_textures(t_textures *textures);
void				free_matrix(char **matrix);
void				free_program(t_game *game);
// DEBUG
void				print_map(t_map *head);
void				print_matrix(char **map, size_t height);
void				print_texture_path(t_game *game);

#endif