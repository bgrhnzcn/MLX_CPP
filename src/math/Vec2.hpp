/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec2.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:34:35 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/09/08 02:15:54 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef VEC2_HPP
# define VEC2_HPP

#include <iosfwd>

namespace mlx
{
	template <typename T> class Vec2
	{
	private: // Attributes
		T x;
		T y;
	public: // Constructors and Destructor
		Vec2(void) = default;
		Vec2(const Vec2<T> &v);
		Vec2(T, T);
		~Vec2(void) = default;
	public: // Getters and Setters
		T getX(void) const;
		T getY(void) const;
		void setX(T);
		void setY(T);
		Vec2<T> operator+(const Vec2<T> &v);
		Vec2<T> operator-(const Vec2<T> &v);
		Vec2<T> operator*(const T &v);
		Vec2<T> operator/(const T &v);
		Vec2<T> &operator=(const Vec2<T> &v) = default;
		T &operator[](unsigned int index);
	public: // Static Functins
		static Vec2<T> zero(void);
		static Vec2<T> one(void);
	public: // Member Functions
		T dot(const Vec2<T> &v);
		T lenght(void);
		T dist(const Vec2<T> &v);
		Vec2<T> normalize(void);
	public: // Friend Functions
		template <typename U> friend std::ostream &operator<<(std::ostream &os, const Vec2<T> &v);
	};
}

#include "Vec2.tpp"

#endif