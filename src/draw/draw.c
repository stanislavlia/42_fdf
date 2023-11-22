/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:10:37 by sliashko          #+#    #+#             */
/*   Updated: 2023/11/11 15:10:39 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//previous version with origin at top left 
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *) dst = color;
// }

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (abs(x)  < WIDTH / 2 && abs(y) < HEIGHT / 2)
	{
		dst = data->addr + ((y + HEIGHT / 2) * data->line_length + (x + WIDTH / 2) * (data->bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}


void	draw_pixel(t_env *env, int i, int j)
{
	if (env->map.rows[i].values[j].z < 2)
	{
		my_mlx_pixel_put(&env->img, env->map.rows[i].values[j].x,
			env->map.rows[i].values[j].y,
			env->map.rows[i].values[j].color);
	}
}

void	display_static_matrix(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->map.m)
	{
		j = 0;
		while (j < env->map.n)
		{
			if (j + 1 < env->map.n)
				draw_line(env->map.rows[i].values[j],
					env->map.rows[i].values[j + 1], env);
			if (i + 1 < env->map.m)
				draw_line(env->map.rows[i].values[j],
					env->map.rows[i + 1].values[j], env);
			//printf("I am drawing x = %d  y = %d\n",env->map.rows[i].values[j].x, env->map.rows[i].values[j].y );
			draw_pixel(env, i, j);
			j++;
		}
		i++;
	}
}
