/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:46:38 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/10 15:52:33 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int n, t_image *image)
{
	int color[16];

	// color[0] = 0xF08080;
	// color[1] = 0xFE5000;
	// color[2] = 0xCE0058;
	// color[3] = 0x10069F;
	// color[4] = 0x0085CA;
	// color[5] = 0xFCAEBB;
	// color[6] = 0xBF9BDE;
	// color[7] = 0x44D62C;
	// color[8] = 0xFF7276;
	// color[9] = 0xECD898;

	color[0] = 0x0007091a;
	color[1] = 0x0009012F;
	color[2] = 0x001e2148;
	color[3] = 0x00000764;
	color[4] = 0x00040449;
	color[5] = 0x000C2C8A;
	color[6] = 0x001852B1;
	color[7] = 0x00397DD1;
	color[8] = 0x0086B5E5;
	color[9] = 0x00D3ECF8;
	color[10] = 0x00bff1eb;
	color[11] = 0x00a15ff8;
	color[12] = 0x009000ff;
	color[13] = 0x008f00cc;
	color[14] = 0x005e0099;
	color[15] = 0x0035036a;
	
	image->set->r = color[n] / (256*256);
	image->set->g = (color[n] / 256) % 256;
	image->set->b = color[n] % 256;
	
	// printf("n = %d\n", n);
	// printf("i = %d\n", color[n]);
	// printf("r = %f\n", image->set->r);
	// printf("g = %f\n", image->set->g);
	// printf("b = %f\n", image->set->b);
	
	return(color[n]);
}

// int get_rgba(int r, int g, int b, int a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// int convert_hex(int i, t_image *image)
// {
// 	image->set->r = (i >> 16 & 0xFF) / 255;
// 	image->set->g = (i >> 8 & 0xFF) / 255;
// 	image->set->b = (i & 0xFF) / 255;

// 	printf("r = %d", image->set->r);
// 	printf("i = %d", i);
	
// }

int	select_color(int iter, t_image *image)
{
	int	r;
	int	g;
	int	b;
	int	a;
	int i;
	double x;
	double res;
	double y;

	if (iter == image->set->max_iter)
		return (get_rgba(0,0,0));

	x = iter - log(log(image->set->z_re * image->set->z_re + image->set->z_im * image->set->z_im));
	// x = iter - log(log(image->set->z_real)/ log(256))/log(2.0);

	y = 2 * 3.14 * x;
	res = (1 + cos(y)) / 2;
	//x = log(iter);
	// printf("x is: %f\n", x);
	// printf("iter is: %d\n", iter);
	// printf("res is: %f\n", res);
	//x = log(iter)
	
	i = get_color(iter % 16, image);
	// convert_hex(i, image);
	// if (iter > 1)
	// 	printf("iter is: %d", iter);
	r = image->set->r * iter / image->set->max_iter;
	g = image->set->g * iter / image->set->max_iter;
	b = image->set->b * iter / image->set->max_iter;
	// r = image->set->r * res;
	// g = image->set->g * res;
	// b = image->set->b * res;
	a = 255;
	
	// if (iter == image->set->max_iter)
	// 	return (get_rgba(252, 174, 187 ,255));
	return (get_rgba(r,g,b));
}

//greenbriar: 4b9b69
// double a = n+2 - log(log(zr*zr+zi*zi))/M_LN2;
// sn = n - log2log2(z * z ) + k;

void		put_pixel(t_image *image, int x, int y)
{
	uint32_t color;

	if (image->set->iter == image->set->max_iter)
		mlx_put_pixel(image->g_img, x, y, 0x0035036a);
	else
		color = generate_colors(image);
		mlx_put_pixel(image->g_img, x, y, color);
}

uint32_t    generate_colors(t_image *image)
{
    t_set	*set;
	double  ratio;
    double  ratio_reciprocal;
    uint8_t colors[3];
	
	set = image->set;
    ratio = (double)set->iter / (double)set->max_iter;
    ratio_reciprocal = 1.0 - ratio;
    colors[0] = 9 * (ratio * ratio * ratio) * ratio_reciprocal * 255;
    colors[1] = 15 * (ratio * ratio) * (ratio_reciprocal * ratio_reciprocal) * 255;
    colors[2] = 9 * ratio * (ratio_reciprocal * ratio_reciprocal * ratio_reciprocal) * 255;
	// printf("%d\n", get_rgba(colors[set->i], colors[set->j], colors[set->k]));
    return (get_rgba(colors[set->i], colors[set->j], colors[set->k]));
}
// int change_color(t_set *set)
// {
//     if (set->i < 2)
//     {
//         if (set->j < 2)
//         {
//             if (set->k < 2)
//                 return (set->k++);
//             return (set->j++);
//         }
//         set->j = 0;
//         set->k = 0;
//         return (set->i++);
//     }
//     set->i = 0;
//     return (1);
// }