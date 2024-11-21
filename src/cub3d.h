/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:40:49 by tursescu          #+#    #+#             */
/*   Updated: 2024/11/21 17:07:55 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <sys/time.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../dirs/libft/libft.h"
# include "../dirs/mlx/mlx.h"

# define ESC_KEY 65307
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define RED "\033[31m"
# define RESET "\033[0m"

# define TEXTURE_NO "./textures/NO.xpm"
# define TEXTURE_SO "./textures/SO.xpm"
# define TEXTURE_WE "./textures/WE.xpm"
# define TEXTURE_EA "./textures/EA.xpm"


typedef struct  s_map
{
	char			*line;
	struct s_map	*next;
}   t_map;

typedef struct	s_textures
{
	char	*no_line;
	char	*so_line;
	char	*we_line;	
	char	*ea_line;
	int		ceil[3];
	int		floor[3];
}	t_textures;

typedef struct	s_game
{
	t_map		*map;
	t_map		*just_map;
	char		**map_2d;
	size_t		width;
	size_t		height;
	t_textures	*textures;
	void		*img[4];
	void		*win;
	void		*mlx;
}	t_game;

//INIT
void	init_textures_null(t_textures *textures);
void	init_game(t_game *game);
//PARSING
char	*trim_newline(char *line);
t_map	*make_map(const char *file_path);
void	get_map_dimensions(t_map *head, size_t *width, size_t *height);
void	find_player_pos(t_map *head, size_t *x, size_t *y);
int 	player_found(t_map *head);
int 	is_surrounded(t_game *game);
void	flood_fill(t_map *head, size_t x, size_t y);
int 	good_input(t_game *game);
int		parse_textures_colors(t_map **head, t_textures *textures);
int		parse_color(const char *line, int color[3]);
void 	fill_from_zero(t_map *head);
void 	complete_flood(t_map *head, size_t x, size_t y);
int		is_valid_adjacent(t_map *head, size_t x, size_t y);
//UTILS
int		is_player(char c);
t_map	*create_node(char *line);
void	err(char *str);
t_map	*copy_map(t_map *og);
void	append_node(t_map **head, t_map *new_node);
int 	has_char(const char *str, char c);
char	get_char_at(t_map *head, size_t x, size_t y);
void	set_char_at(t_map *head, size_t x, size_t y, char c);
char	**convert_map(t_game *game);
//FREEING
void	free_list(t_map *head);
int		propper_exit(t_game *game);
void 	free_2d_map(t_game *game);
void	free_textures(t_textures *textures);
void	free_matrix(char **matrix);
//DEBUG
void	print_map(t_map *head);
void	print_matrix(char **map, size_t height);

# endif