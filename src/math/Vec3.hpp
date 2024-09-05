/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec3.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:58:15 by buozcan           #+#    #+#             */
/*   Updated: 2024/09/05 20:37:35 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef VEC3_HPP
# define VEC3_HPP

namespace mlx_cpp
{
	template <typename T> class Vec3
	{
		private:
			T x;
			T y;

		public:
			T getX(void);
			T getY(void);
			void setX(T);
			void setY(T);
	};
}

#include "Vec3.tpp"

#endif // VEC3_HPP
