#ifndef CUB3DD_H
# define CUB3DD_H

# define PATH_TO_MINIMAP "./inc/minimap.xpm"
# define PATH_TO_MINIFLOOR "./inc/minifloor.xpm"
# define PATH_TO_MINIPLAYER "./inc/ardei.xpm"

# include "../src/cub3d.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_game		t_game;

typedef struct s_mini_ray	t_mini_ray;
// struct to hold all the player info
typedef struct s_player
{
	float player_dlt_x; // player distance x
	float					player_dlt_y;
	float					player_angle;
	float					player_x;
	float					player_y;
	float					mini_ray_x;
	float					mini_ray_y;
	float					fov;
	char					direction;
	t_mini_ray				*mini_ray;
}							t_player;

// typedef struct s_mini_ray
// {
// 	float	mini_ray_x;
// 	float	mini_ray_y;
// }			t_mini_ray;

// typedef struct s_raycst
// {

// }			t_raycst;

// need a poiner for each struct for easier acacces
typedef struct s_mlx
{
	void					*background_img;
	void					*minifloor_img;
	void					*miniplayer_img;
	void					*window;
	void					*mlx_pointer;
	void					*img[4];
	bool					facts;
	bool					first_move;
	t_player *player; // pointer to players struct
	t_game					*game;
	
}							t_mlx;

t_player					*init_player(char direction, t_game *game);
void						draw_minimap(t_mlx *mlx, t_game *game);
int							draw_minimap_player(t_mlx *mlx, t_game *game);
void						init_x_y(t_player *player, t_game *game);

#endif