/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooked_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:45:25 by sliashko          #+#    #+#             */
/*   Updated: 2023/11/23 14:45:27 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setup_environment(t_env *env_ptr)
{
	env_ptr->mlx = mlx_init();
	env_ptr->mlx_window = mlx_new_window(env_ptr->mlx, WIDTH,
			HEIGHT, "FDF project");
	env_ptr->img.img = mlx_new_image(env_ptr->mlx, WIDTH, HEIGHT);
	env_ptr->img.addr = mlx_get_data_addr(env_ptr->img.img,
			&env_ptr->img.bits_per_pixel,
			&env_ptr->img.line_length,
			&env_ptr->img.endian);
}
