/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Win.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:58:55 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/09/16 01:18:02 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WIN_HPP
# define WIN_HPP

#include <iosfwd>

#include "fwd.hpp"
#include "Input.hpp"
#include "Vec2.hpp"

namespace mlx
{
	class Image;

	class Win
	{
		private:
			void *win_ptr;
			Mlx &mlx;
			Input *input;
			int width;
			int height;
			const std::string &title;
		public:
			Win(Mlx &mlx, int width, int height, const std::string &title);
			~Win(void);
			Mlx &getMlx(void) const;
			void *getMlxPtr(void) const;
			void *getWinPtr(void) const;
			Input &getInput(void);
			int getWidth(void) const;
			int getHeight(void) const;
		public:
			void putImage(Image &img, int x, int y);
			void keyHook(KeyEventFunc func_ptr, void *param);
	};
}

#endif