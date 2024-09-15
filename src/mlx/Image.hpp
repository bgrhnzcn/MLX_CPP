/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Image.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:52:28 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/09/16 01:09:48 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef IMAGE_HPP
# define IMAGE_HPP

#include <iosfwd>

#include "fwd.hpp"

namespace mlx
{
	class Image
	{
		private:
			Mlx &mlx;
			void *img_ptr;
			Color *data;
			int width;
			int height;
			int bpp;
			int endian;
		public:
			Image(Mlx &mlx, int width, int height);
			Image(Mlx &mlx, const std::string &path);
			~Image(void);
			void *getImgPtr(void);
			void *getMlxPtr(void);
		public:
			void putImage(Win &img, int x, int y);
			void putPixel(int x, int y, Color color);
			void fill(Color color);
	};
}

#endif
