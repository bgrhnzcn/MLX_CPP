/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:15:59 by buozcan           #+#    #+#             */
/*   Updated: 2024/09/16 01:17:11 by bgrhnzcn         ###   ########.fr       */
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
	mlx::Win &win;
	//mlx::Image &img;
} t_data;

void draw_circle(mlx::Win &win, mlx::Image &img)
{
	mlx::Vec2<float> pos = win.getInput().getMousePos();
	float radius = 50;
	for (int i = pos.getX() - radius; i < pos.getX() + radius; i++)
	{
		for (int j = pos.getY() - radius; j < pos.getY() + radius; j++)
		{
			if (mlx::Vec2<float>(i, j).dist(pos) < radius)
				img.putPixel(i, j, Color::Red);
		}
	}
}

int update(void *param)
{
	t_data &data = *reinterpret_cast<t_data *>(param);

	std::cout << "Mouse Pos: " << data.win.getInput().getMousePos() << std::endl;
	std::cout << "Q is pressed: " << data.win.getInput().keyDown(mlx::KeyCode::Q) << std::endl;
	//if (data.win.getInput().keyDown(mlx::KeyCode::A))
	//	draw_circle(data.win, data.img);
	//data.win.putImage(data.img, 0, 0);
	return (0);
}

int	main(void)
{
	mlx::Mlx mlx;
	mlx::Win win = mlx::Win(mlx, 800, 600, "Hello World");
	//mlx::Image img = mlx::Image(mlx, win.getWidth(), win.getHeight());
	t_data data = {win};

	mlx.mlxLoopHook(update, &data);
	mlx.mlxLoop();
	return (EXIT_SUCCESS);
}
