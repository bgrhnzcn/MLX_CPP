/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:58:41 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/09/08 02:10:26 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef COLOR_HPP
# define COLOR_HPP

extern "C"
{
#include <endian.h>
}

namespace mlx
{
	class Color
	{
		public:
		#if __BYTE_ORDER == __ORDER_BIG_ENDIAN__
			union
			{
				struct { unsigned char alpha, red, green, blue; };
				unsigned int value;
			};
		#else
			union
			{
				struct { unsigned char blue, green, red, alpha; };
				unsigned int value;
			};
		#endif
		public:
			Color(void) = default;
			Color(unsigned int value);
			Color(unsigned char alpha, unsigned char red, unsigned char green, unsigned char blue);
			~Color() = default;
	};
}

namespace Color
{
	static const inline mlx::Color Red = mlx::Color(255, 255, 0, 0);
	static const inline mlx::Color Green = mlx::Color(255, 0, 255, 0);
	static const inline mlx::Color Blue = mlx::Color(255, 0, 0, 255);
	static const inline mlx::Color Black = mlx::Color(255, 0, 0, 0);
	static const inline mlx::Color White = mlx::Color(255, 255, 255, 255);
	static const inline mlx::Color Yellow = mlx::Color(255, 255, 255, 0);
	static const inline mlx::Color Cyan = mlx::Color(255, 0, 255, 255);
	static const inline mlx::Color Magenta = mlx::Color(255, 255, 0, 255);
	static const inline mlx::Color Grey = mlx::Color(255, 128, 128, 128);
	static const inline mlx::Color Orange = mlx::Color(255, 255, 165, 0);
	static const inline mlx::Color Pink = mlx::Color(255, 255, 192, 203);
	static const inline mlx::Color Purple = mlx::Color(255, 128, 0, 128);
	static const inline mlx::Color Brown = mlx::Color(255, 165, 42, 42);
	static const inline mlx::Color LightBlue = mlx::Color(255, 173, 216, 230);
	static const inline mlx::Color LightGreen = mlx::Color(255, 144, 238, 144);
	static const inline mlx::Color LightPink = mlx::Color(255, 255, 182, 193);
	static const inline mlx::Color LightYellow = mlx::Color(255, 255, 255, 224);
	static const inline mlx::Color LightCyan = mlx::Color(255, 224, 255, 255);
	static const inline mlx::Color LightGrey = mlx::Color(255, 211, 211, 211);
	static const inline mlx::Color LightOrange = mlx::Color(255, 255, 160, 122);
	static const inline mlx::Color LightPurple = mlx::Color(255, 218, 112, 214);
	static const inline mlx::Color LightBrown = mlx::Color(255, 210, 105, 30);
	static const inline mlx::Color DarkBlue = mlx::Color(255, 0, 0, 139);
	static const inline mlx::Color DarkGreen = mlx::Color(255, 0, 100, 0);
	static const inline mlx::Color DarkRed = mlx::Color(255, 139, 0, 0);
	static const inline mlx::Color DarkCyan = mlx::Color(255, 0, 139, 139);
	static const inline mlx::Color DarkMagenta = mlx::Color(255, 139, 0, 139);
	static const inline mlx::Color DarkYellow = mlx::Color(255, 139, 139, 0);
	static const inline mlx::Color DarkGrey = mlx::Color(255, 169, 169, 169);
	static const inline mlx::Color DarkOrange = mlx::Color(255, 255, 140, 0);
	static const inline mlx::Color DarkPink = mlx::Color(255, 255, 105, 180);
	static const inline mlx::Color DarkPurple = mlx::Color(255, 153, 50, 204);
	static const inline mlx::Color DarkBrown = mlx::Color(255, 101, 67, 33);
}

#endif // COLOR_HPP
