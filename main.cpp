/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:15:59 by buozcan           #+#    #+#             */
/*   Updated: 2024/09/08 03:39:58 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

extern "C"
{
#include <mlx.h>
}

#include "inputs.hpp"
#include "Vec3.hpp"
#include "Vec2.hpp"
#include "Mlx.hpp"
#include "Win.hpp"
#include "Image.hpp"
#include "Color.hpp"

typedef struct s_data
{
	mlx::Mlx	&mlx;
	mlx::Win	&win;
	mlx::Image	&img;
}	t_data;

int key_press_handler(int keycode, void *param)
{
	t_data *data = reinterpret_cast<t_data *>(param);
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(data->mlx.getMlxPtr(), data->win.getWinPtr());
		exit(EXIT_SUCCESS);
	}
	if (keycode == R_KEY)
	{
		data->img.fill(Color::Black);
		data->win.putImage(data->img, 0, 0);
	}
	return (0);
}

int mouse_press_handler(int keycode, void *param)
{
	t_data *data = reinterpret_cast<t_data *>(param);
	float radius = 50;
	if (keycode == 1)
	{
		mlx::Vec2<float> mousePos = data->win.mlxGetMousePos();
		std::cout << data->win.getCurrMousePos() - data->win.getPrevMousePos() << std::endl;
		std::cout << mousePos << std::endl;
		for (int x = mousePos.getX() - radius; x < mousePos.getX() + radius; x++)
			for (int y = mousePos.getY() - radius; y < mousePos.getY() + radius; y++)
				if (mousePos.dist(mlx::Vec2<float>(x, y)) < radius)
					data->img.putPixel(x, y, Color::DarkBrown);
		data->win.putImage(data->img, 0, 0);
	}
	return (0);
}

int	main(void)
{
	mlx::Mlx mlx;
	mlx::Win win = mlx::Win(mlx, 800, 600, "Hello World");
	mlx::Image img = mlx::Image(mlx, win.getWidth(), win.getHeight());
	t_data data{mlx, win, img};
	win.mlxHook(mlx::KeyPress, (1<<0), key_press_handler, &data);
	win.mlxHook(mlx::ButtonPress, (1<<2), mouse_press_handler, &data);
	mlx.mlxLoop();
	return (EXIT_SUCCESS);
}
