/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:52:03 by kczichow          #+#    #+#             */
/*   Updated: 2022/11/22 11:21:14 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct {unsigned char r, g, b;} rgb_t;
rgb_t **tex = 0;
int gwin;
//GLuint texture;
int width, height;
int tex_w, tex_h;
double scale = 1./256;
double cx = -.6, cy = 0;
int color_rotate = 0;
int saturation = 1;
int invert = 0;
int max_iter = 256;

// https://rosettacode.org/wiki/Mandelbrot_set#C

void	mandelbrot()
{
	int i, j, iter, min, max;
	rgb_t *px;
	double x, y, zx, zy, zx2, zy2;
	min = max_iter; max = 0;
	for (i = 0; i < height; i++) {
		px = tex[i];
		y = (i - height/2) * scale + cy;
		for (j = 0; j  < width; j++, px++) {
			x = (j - width/2) * scale + cx;
			iter = 0;
 
			zx = hypot(x - .25, y);
			if (x < zx - 2 * zx * zx + .25) iter = max_iter;
			if ((x + 1)*(x + 1) + y * y < 1/16) iter = max_iter;
 
			zx = zy = zx2 = zy2 = 0;
			for (; iter < max_iter && zx2 + zy2 < 4; iter++) {
				zy = 2 * zx * zy + y;
				zx = zx2 - zy2 + x;
				zx2 = zx * zx;
				zy2 = zy * zy;
			}
			if (iter < min) min = iter;
			if (iter > max) max = iter;
			*(unsigned short *)px = iter;
		}
	}
 
	for (i = 0; i < height; i++)
		for (j = 0, px = tex[i]; j  < width; j++, px++)
			printf("TEST\n");
			//hsv_to_rgb(*(unsigned short*)px, min, max, px);
}
