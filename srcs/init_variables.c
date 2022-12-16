/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:43:44 by kczichow          #+#    #+#             */
/*   Updated: 2022/12/16 14:52:27 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "fractol.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>

/* INIT_VARIABLES
* ----------------
* Initializes all variables in the variables structure;
*/

void init_variables(t_var *var)
{
	var->settype	=	0;
	var->i			=	0;
	var->j			= 	0;
	var->iter		=	0;
	var->min		=	0;
	var->max		=	0;
	var->x			=	0;
	var->y			=	0;
	var->zx			=	0;
	var->zx2		=	0;
	var->zy2		=	0;
}