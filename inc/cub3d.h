#ifndef CUB3D_H
# define CUB3D_H

#define PATH_TO_MINIMAP "/home/tlupu/CUB3D/CUB3D/inc/minimap.xpm"

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// struct to hold all the player info
typedef struct s_player
{
	float player_dlt_x; // player distance x
	float	player_dlt_y;
	float	player_angle;
	float	player_x;
	float	player_y;
	float	fov;
	char	direction;
}			t_player;

// typedef struct s_raycst
// {

// }			t_raycst;


//need a poiner for each struct for easier acacces
typedef struct s_mlx
{
	void	*background_img;
	void	*window;
	void 	*mlx_pointer; 
	t_player *player; //pointer to players struct 
}			t_mlx;

#endif