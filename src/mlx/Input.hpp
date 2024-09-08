/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:11:36 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/09/08 23:59:03 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INPUT_HPP
# define INPUT_HPP

extern "C"
{
#include <X11/keysym.h>
#include <mlx.h>
}

#include <string>
#include <algorithm>
#include <map>

#include "fwd.hpp"

namespace mlx
{
	enum class KeyCode
	{
		ESC = XK_Escape,
		X = XK_x,
		Z = XK_z,
		O = XK_o,
		Q = XK_q,
		W = XK_w,
		E = XK_e,
		R = XK_r,
		A = XK_a,
		S = XK_s,
		D = XK_d,
		F = XK_f,
		P = XK_p,
		RIGHT = XK_Right,
		LEFT = XK_Left,
		UP = XK_Up,
		DOWN = XK_Down
	};

	struct KeyState
	{
		bool isPressed;
		bool isReleased;
	};
	
	class Input
	{
		public:
			std::unordered_map<KeyCode, KeyState> keys;
			Win &win;
		public:
			Input(Win &win);
			~Input(void) = default;
		public:
			Vec2<float> mlxGetMousePos(void);
			void keyDown(int xEventMask, mlx::KeyEventFunc, void *param);
			void keyUp(int xEventMask, mlx::KeyEventFunc, void *param);
			void mouseButtonDown(int xEventMask, mlx::MouseButtonEventFunc, void *param);
			void mouseButtonUp(int xEventMask, mlx::MouseButtonEventFunc, void *param);
			void mouseMove(int xEventMask, mlx::MouseMoveEventFunc, void *param);

	};
}

#endif // INPUT_HPP