/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fwd.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:24:23 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/09/08 02:41:59 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FWD_HPP
# define FWD_HPP

namespace mlx
{
	//win
	class Mlx;
	class Win;
	class Image;
	//render
	class Color;
	//math
	template <typename T> class Vec2;
	template <typename T> class Vec3;
	template <typename T> class Vec4;
	//function types
	typedef int(*EmptyParamFunc)();
} // namespace mlx

#endif