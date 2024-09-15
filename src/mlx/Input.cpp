/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:06:31 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/09/16 01:37:49 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C"
{
#include <mlx.h>
}

#include "fwd.hpp"
#include "Vec2.hpp"
#include "Win.hpp"
#include "Input.hpp"

int setKeyPress(int keycode, void *param)
{
	mlx::Input* input = reinterpret_cast<mlx::Input*>(param);
	std::cout << "Pressed Keycode: " << keycode << std::endl;
	input->setKey((mlx::KeyCode)keycode, true);
	return (0);
}

int setKeyRelease(int keycode, void *param)
{
	mlx::Input* input = reinterpret_cast<mlx::Input*>(param);
	std::cout << "Released Keycode: " << keycode << std::endl;
	input->setKey(static_cast<mlx::KeyCode>(keycode), false);
	return (0);
}

void mlx::Input::setKey(KeyCode key, bool state)
{
	if (this->keyStates.find(key) == this->keyStates.end())
		this->keyStates.insert({key, state});
	else
		this->keyStates[key] = state;
}

mlx::Input::Input(mlx::Win *win)
	: win(win)
{
	int (**f)() = reinterpret_cast<int (**)()>(&::setKeyPress);
	mlx_hook(this->win->getWinPtr(), mlx::MLXEvent::KeyPress, (1L << 0), *f, this);
	//mlx::EmptyEventFunc* keyPress = (mlx::EmptyEventFunc*)(&::setKeyPress);
	//mlx_hook(this->win->getWinPtr(), mlx::MLXEvent::KeyPress, (1L << 0), *keyPress, this);
	mlx::EmptyEventFunc* KeyRelease = (mlx::EmptyEventFunc*)(&::setKeyRelease);
	mlx_hook(this->win->getWinPtr(), mlx::MLXEvent::KeyRelease, (1L << 1), *KeyRelease, this);
}

mlx::Vec2<float> mlx::Input::getMousePos(void)
{
	int x;
	int y;

	mlx_mouse_get_pos(this->win->getMlxPtr(), this->win->getWinPtr(), &x, &y);
	return (mlx::Vec2<float>(x, y));
}

bool mlx::Input::keyDown(mlx::KeyCode key)
{
	if (this->keyStates.find(key) == this->keyStates.end())
		return (false);
	return (this->keyStates[key]);
}
