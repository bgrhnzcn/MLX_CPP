/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Image.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:02:00 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/09/08 02:24:16 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C"
{
#include <mlx.h>
}

#include <string>

#include "Mlx.hpp"
#include "Image.hpp"
#include "Win.hpp"
#include "Color.hpp"

mlx::Image::Image(mlx::Mlx &mlx, int width, int height) 
	: mlx(mlx), width(width), height(height)
{
	this->img_ptr = mlx_new_image(mlx.getMlxPtr(), width, height);
	this->data = (Color *)mlx_get_data_addr(this->img_ptr,
		&this->bpp, &this->width, &this->endian);
	this->width /= (this->bpp / 8);
}

mlx::Image::Image(mlx::Mlx &mlx, const std::string &path)
	: mlx(mlx)
{
	this->img_ptr = mlx_xpm_file_to_image(this->mlx.getMlxPtr(), 
		(char *)path.c_str(), &this->width, &this->height);
	this->data = (Color *)mlx_get_data_addr(this->img_ptr,
		&this->bpp, &this->width, &this->endian);
	this->width /= (this->bpp / 8);
}

mlx::Image::~Image(void)
{
	mlx_destroy_image(this->mlx.getMlxPtr(), this->img_ptr);
}

void *mlx::Image::getImgPtr(void)
{
	return (this->img_ptr);
}

void *mlx::Image::getMlxPtr(void)
{
	return (this->mlx.getMlxPtr());
}

void mlx::Image::putImage(mlx::Win &win, int x, int y)
{
	mlx_put_image_to_window(this->mlx.getMlxPtr(), win.getWinPtr(), this->img_ptr, x, y);
}

void mlx::Image::putPixel(int x, int y, mlx::Color color)
{
	if (x >= 0 && x < this->width && y >= 0 && y < this->height)
		this->data[y * this->width + x] = color;
}

void mlx::Image::fill(mlx::Color color)
{
	for (int i = 0; i < this->width * this->height; i++)
		this->data[i] = color;
}
