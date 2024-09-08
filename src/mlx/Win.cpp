/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Win.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:51:02 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/09/08 14:13:25 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C"
{
#include <mlx.h>
}

#include <string>

#include "fwd.hpp"
#include "Mlx.hpp"
#include "Win.hpp"
#include "Image.hpp"
#include "Vec2.hpp"

mlx::Win::Win(mlx::Mlx &mlx, int width, int height, const std::string &title)
	: mlx(mlx), width(width), height(height) , title(title)
{
	this->win_ptr = mlx_new_window(this->mlx.getMlxPtr(),
								   this->width,
								   this->height,
								   (char *)this->title.c_str());
	this->currMousePos = this->mlxGetMousePos();
	this->prevMousePos = this->currMousePos;
}

mlx::Win::~Win(void)
{
	mlx_destroy_window(this->mlx.getMlxPtr(), this->win_ptr);
}

mlx::Mlx &mlx::Win::getMlx(void) const
{
	return (this->mlx);
}

void *mlx::Win::getMlxPtr(void) const
{
	return (this->mlx.getMlxPtr());
}

void *mlx::Win::getWinPtr(void) const
{
	return (this->win_ptr);
}

int mlx::Win::getWidth(void) const
{
	return (this->width);
}

int mlx::Win::getHeight(void) const
{
	return (this->height);
}

mlx::Vec2<float> mlx::Win::getCurrMousePos(void) const
{
	return (this->currMousePos);
}

mlx::Vec2<float> mlx::Win::getPrevMousePos(void) const
{
	return (this->prevMousePos);
}

void mlx::Win::putImage(mlx::Image &img, int x, int y)
{
	mlx_put_image_to_window(this->mlx.getMlxPtr(), this->win_ptr, img.getImgPtr(), x, y);
}

mlx::Vec2<float> mlx::Win::mlxGetMousePos(void)
{
	int x, y;

	mlx_mouse_get_pos(this->getMlxPtr(), this->win_ptr, &x, &y);
	return (mlx::Vec2<float>(x, y));
}

void mlx::Win::mlxKeyHook(int (*func_ptr)(int keycode, void *param), void *param)
{
	EmptyParamFunc* func = reinterpret_cast<EmptyParamFunc*>(&func_ptr);
	mlx_key_hook(this->win_ptr, *func, param);
}

void mlx::Win::mlxHook(int x_event, int x_mask, int (*func_ptr)(int keycode, void *param), void *param)
{
	EmptyParamFunc* func = reinterpret_cast<EmptyParamFunc*>(&func_ptr);
	mlx_hook(this->getWinPtr(), x_event, x_mask, *func, param);
}
