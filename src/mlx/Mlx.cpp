/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mlx.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:16:23 by buozcan           #+#    #+#             */
/*   Updated: 2024/09/08 02:42:15 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C"
{
	#include <mlx.h>
	#include <stdlib.h>
}

#include "fwd.hpp"
#include "Mlx.hpp"

mlx::Mlx::Mlx(void)
{
	this->mlx_ptr = mlx_init();
}

mlx::Mlx::~Mlx(void)
{
	free(this->mlx_ptr);
}

void *mlx::Mlx::getMlxPtr(void)
{
	return (this->mlx_ptr);
}

void mlx::Mlx::mlxLoop(void)
{
	mlx_loop(this->mlx_ptr);
}

void mlx::Mlx::mlxLoopHook(int (*funct_ptr)(void *param), void *param)
{
	EmptyParamFunc* epf = reinterpret_cast<EmptyParamFunc*>(&funct_ptr);
	mlx_loop_hook(this->mlx_ptr, *epf, param);
}
