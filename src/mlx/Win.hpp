/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Win.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:58:55 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/09/08 03:04:47 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WIN_HPP
# define WIN_HPP

#include <iosfwd>

#include "fwd.hpp"
#include "Vec2.hpp"

namespace mlx
{
	class Image;

	class Win
	{
		private:
			void *win_ptr;
			Mlx &mlx;
			int width;
			int height;
			const std::string &title;
			Vec2<float> prevMousePos;
			Vec2<float> currMousePos;
		public:
			Win(Mlx &mlx, int width, int height, const std::string &title);
			~Win(void);
			Mlx &getMlx(void) const;
			void *getMlxPtr(void) const;
			void *getWinPtr(void) const;
			int getWidth(void) const;
			int getHeight(void) const;
			Vec2<float> getCurrMousePos(void) const;
			Vec2<float> getPrevMousePos(void) const;
		public:
			void putImage(Image &img, int x, int y);
		public:
			Vec2<float> mlxGetMousePos(void);
			void mlxKeyHook(int (*func_ptr)(int keycode, void *param),
				void *param);
			void mlxHook(int x_event, int x_mask, int (*funct)(int keycode,
				void *param), void *param);
	};
}

#endif