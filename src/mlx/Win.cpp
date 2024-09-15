/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Win.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:51:02 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/09/16 01:20:02 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

extern "C"
{
#include <mlx.h>
}

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
	this->input = new mlx::Input(this);
}

mlx::Win::~Win(void)
{
	free(this->input);
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

mlx::Input &mlx::Win::getInput(void)
{
	return (*this->input);
}

int mlx::Win::getWidth(void) const
{
	return (this->width);
}

int mlx::Win::getHeight(void) const
{
	return (this->height);
}

void mlx::Win::putImage(mlx::Image &img, int x, int y)
{
	mlx_put_image_to_window(this->mlx.getMlxPtr(), this->win_ptr, img.getImgPtr(), x, y);
}
