/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:41:30 by tursescu          #+#    #+#             */
/*   Updated: 2024/12/14 10:10:58 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_put_pixel(char *buff_data, int x, int y, int color, int size_line,
		int bpp)
{
	int	pixel_index;

	pixel_index = (y * size_line) + (x * (bpp / 8));
	buff_data[pixel_index] = color & 0xFF;             // Blue
	buff_data[pixel_index + 1] = (color >> 8) & 0xFF;  // Green
	buff_data[pixel_index + 2] = (color >> 16) & 0xFF; // Red
}

int	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	rgb_to_hex(int r, int g, int b)
{
	return ((r <<16) | (g << 8) | b);
}

void	game_over(t_mlx *mlx)
{
	ft_printf("%s╔═╗╔═╗╔╦╗╔═╗  ╔═╗╦  ╦╔═╗╦═╗\n", RED);
	ft_printf("%s║ ╦╠═╣║║║║╣   ║ ║╚╗╔╝║╣ ╠╦╝\n", YELLOW);
	ft_printf("%s╚═╝╩ ╩╩ ╩╚═╝  ╚═╝ ╚╝ ╚═╝╩╚═%s", BLUE, RESET);
	ft_printf("\n");
	propper_exit(mlx);
}

int	click_exit(t_mlx *mlx)
{
	game_over(mlx);
	return (0);
}