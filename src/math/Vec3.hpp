/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec3.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:58:15 by buozcan           #+#    #+#             */
/*   Updated: 2024/09/07 19:47:43 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef VEC3_HPP
# define VEC3_HPP

#include <iosfwd>

namespace mlx
{
	template <typename T> class Vec3
	{
	private: // Attributes
		T x;
		T y;
		T z;
	public: // Constructors and Destructor
		Vec3(void) = default;
		Vec3(const Vec3<T> &v);
		Vec3(T, T, T);
		~Vec3(void) = default;
	public: // Getters and Setters
		T getX(void) const;
		T getY(void) const;
		T getZ(void) const;
		void setX(T);
		void setY(T);
		void setZ(T);
		Vec3<T> operator+(const Vec3<T> &v);
		Vec3<T> operator-(const Vec3<T> &v);
		Vec3<T> operator*(const T &v);
		Vec3<T> operator/(const T &v);
		Vec3<T> &operator=(const Vec3<T> &v) = default;
		T &operator[](unsigned int index);
	public: // Static Functins
		static Vec3<T> zero(void);
		static Vec3<T> one(void);
	public: // Member Functions
		T dot(const Vec3<T> &v);
		T lenght(void);
		Vec3<T> normalize(void);
	public: // Friend Functions
		template <typename U> friend std::ostream &operator<<(std::ostream &os, const Vec3<T> &v);
	};
}

#include "Vec3.tpp"

#endif // VEC3_HPP
