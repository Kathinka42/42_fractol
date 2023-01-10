/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_drawing_experiments.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:56:33 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/10 10:02:30 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "fractol.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>

/* https://www.geeksforgeeks.org/bresenhams-circle-drawing-algorithm/
*  Adapted Bresenham circle drawing algorithm

*/

void	draw_circle(mlx_image_t *g_img, mlx_t *mlx, int xc, int yc, int x, int y)
{
	mlx_put_pixel(g_img, xc+x , yc+y, get_rgba(0, 0, 255));
	mlx_put_pixel(g_img, xc-x , yc+y, get_rgba(0, 0, 255));
    mlx_put_pixel(g_img, xc+x , yc-y, get_rgba(0, 0, 255));
    mlx_put_pixel(g_img, xc-x , yc-y, get_rgba(0, 0, 255));
    mlx_put_pixel(g_img, xc+y , yc+x, get_rgba(0, 0, 255));
    mlx_put_pixel(g_img, xc-y , yc+x, get_rgba(0, 0, 255));
    mlx_put_pixel(g_img, xc+y , yc-x, get_rgba(0, 0, 255));
    mlx_put_pixel(g_img, xc-y , yc-y, get_rgba(0, 0, 255));
}

void	circleBres(mlx_image_t *g_img, mlx_t *mlx)
{
    int xc = 50;
	int yc = 50;
	int r = 30;
	int x = 0, y = r;
    int d = 3 - 2 * r;
	mlx_image_to_window(mlx, g_img, 100, 100);
    draw_circle(g_img, mlx, xc, yc, x, y);
    while (y >= x)
    {
        // for each pixel we will
        // draw all eight pixels
         
        x++;
 
        // check for decision parameter
        // and correspondingly
        // update d, x, y
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        draw_circle(g_img, mlx, xc, yc, x, y);
       // delay(50);
    }
}

void	draw_square(mlx_image_t	*g_img, mlx_t *mlx, int x, int y)
{	
	mlx_image_to_window(mlx, g_img, 100, 100);
	
	int i;
	int j;

	i = x;
	j = y;
	
	while(x > (i - 10))
	{
		mlx_put_pixel(g_img, x , y, get_rgba(0, 0, 255));
		x--;
	}
	while(y > (j - 10))
	{
		mlx_put_pixel(g_img, x , y, get_rgba(20, 20, 0));
		y--;
	}
	printf("x is: %d\n", x);
	printf("y is: %d\n", x);
	
}
void drawcircle(mlx_image_t	*g_img, mlx_t *mlx)
{
    int x0 = 400;
    int y0 = 400;
    int radius = 100;
    int x = radius;
    int y = 0;
    int err = 0;
    mlx_image_to_window(mlx, g_img, 100, 100);
    while (x >= y)
    {
        mlx_put_pixel(g_img, x0 + x , y0 + y, get_rgba(0, 0, 255));
        mlx_put_pixel(g_img, x0 + y , y0 + x, get_rgba(0, 0, 255));
        mlx_put_pixel(g_img, x0 - y , y0 + x, get_rgba(0, 0, 255));
        mlx_put_pixel(g_img, x0 - x , y0 + y, get_rgba(0, 0, 255));
        mlx_put_pixel(g_img, x0 - x , y0 - y, get_rgba(0, 0, 255));
        mlx_put_pixel(g_img, x0 - y , y0 - x, get_rgba(0, 0, 255));
        mlx_put_pixel(g_img, x0 + y , y0 - x, get_rgba(0, 0, 255));
        mlx_put_pixel(g_img, x0 + x , y0 - y, get_rgba(0, 0, 255));
        
if (err <= 0)
{
    y += 1;
    err += 2*y + 1;
}
 
if (err > 0)
{
    x -= 1;
    err -= 2*x + 1;
}
    }
}

void	draw_line(mlx_image_t	*g_img, mlx_t *mlx)
{
// {	int i = 0;
// 	int x = 40;
// 	int y = 40;

// 	while (i < 5)
// 	{
// 		draw_square(g_img, mlx, x, y);
// 		x += 5;
// 		y += 5;
// 		i++;
// 	}
// circleBres(g_img, mlx);

drawcircle(g_img, mlx);

	
}