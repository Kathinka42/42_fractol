/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:02:21 by kczichow          #+#    #+#             */
/*   Updated: 2022/12/16 15:18:07 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int is_valid(char *s, t_var *var)
{
	var->i = 0;

	while (s[var->i] != '\0')
	{
		if ((s[var->i] == 43 || s[var->i] == 45)
			&& (!(s[var->i + 1] == 46 
			|| (s[var->i + 1] >= 48 && s[var->i + 1] <= 57))))
			return (0);
		if (!((s[var->i] >= 48 && s[var->i] <= 57)
				|| s[var->i] == 43 || s[var->i] == 45 || s[var->i] == 46))
			return (0);
		var->i++;
	}
	return (1);
}

int	check_input(int argc, char **argv, t_var *var)
{
	if(argc < 2 || argc == 3 || argc > 4)
		return (-1);
	if (argc == 2 && !ft_strcmp("Mandelbrot", argv[1]))
		return (-1);
	if (argc == 4 && !(is_valid(argv[2], var) && is_valid(argv[3], var)
		&& (!ft_strcmp(argv[1], "Julia"))))
		return (-1);
	return (0);
}
