/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec3.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:44:56 by buozcan           #+#    #+#             */
/*   Updated: 2024/09/07 17:53:02 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef VEC3_TPP
# define VEC3_TPP

#include <system_error>
#include <cmath>

#include "Vec3.hpp"

template <typename T> mlx::Vec3<T>::Vec3(const mlx::Vec3<T> &v)
{
	this->x = v.getX();
	this->y = v.getY();
	this->z = v.getZ();
}

template <typename T> mlx::Vec3<T>::Vec3(T x, T y, T z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

template <typename T> T mlx::Vec3<T>::getX(void) const
{
	return (this->x);
}

template <typename T> T mlx::Vec3<T>::getY(void) const
{
	return (this->y);
}

template <typename T> T mlx::Vec3<T>::getZ(void) const
{
	return (this->z);
}

template <typename T> void mlx::Vec3<T>::setX(T x)
{
	this->x = x;
}

template <typename T> void mlx::Vec3<T>::setY(T y)
{
	this->y = y;
}

template <typename T> void mlx::Vec3<T>::setZ(T z)
{
	this->z = z;
}

template <typename T> mlx::Vec3<T> mlx::Vec3<T>::operator+(const mlx::Vec3<T> &v)
{
	mlx::Vec3<T> res;
	res.setX(this->x + v.getX());
	res.setY(this->y + v.getY());
	res.setZ(this->z + v.getZ());
	return (res);
}

template <typename T> mlx::Vec3<T> mlx::Vec3<T>::operator-(const mlx::Vec3<T> &v)
{
	mlx::Vec3<T> res;
	res.setX(this->x - v.getX());
	res.setY(this->y - v.getY());
	res.setZ(this->z - v.getZ());
	return (res);
}

template <typename T> mlx::Vec3<T> mlx::Vec3<T>::operator*(const T &v)
{
	mlx::Vec3<T> res;
	res.setX(this->x * v);
	res.setY(this->y * v);
	res.setZ(this->z * v);
	return (res);
}

template <typename T> mlx::Vec3<T> mlx::Vec3<T>::operator/(const T &v)
{
	mlx::Vec3<T> res;
	
	if (v == 0)
		throw std::runtime_error("Division by zero");
	res.setX(this->x / v);
	res.setY(this->y / v);
	res.setZ(this->z / v);
	return (res);
}

template <typename T> T &mlx::Vec3<T>::operator[](unsigned int index)
{
	if (index > 2)
		throw std::out_of_range("mlx::Vec3: Index out of range. Please give number between 0 and 2");
	if (index == 0)
		return (this->x);
	else if (index == 1)
		return (this->y);
	else
		return (this->z);
}

template <typename T> mlx::Vec3<T> mlx::Vec3<T>::zero(void)
{
	return (mlx::Vec3<T>(0, 0, 0));
}

template <typename T> mlx::Vec3<T> mlx::Vec3<T>::one(void)
{
	return (mlx::Vec3<T>(1, 1, 1));
}

template <typename T> T mlx::Vec3<T>::dot(const mlx::Vec3<T> &v)
{
	return ((this->x * v.getX()) +
			(this->y * v.getY()) +
			(this->z * v.getZ()));
}

template <typename T> T mlx::Vec3<T>::lenght(void)
{
	return (std::sqrt(this->dot(*this)));
}

template <typename T> mlx::Vec3<T> mlx::Vec3<T>::normalize(void)
{
	T len = this->lenght();
	if (len == 0)
		throw std::runtime_error("Division by zero");
	return (*this / len);
}

template <typename T> std::ostream &operator<<(std::ostream &os, const mlx::Vec3<T> &v)
{
	os << "x: " << v.getX() << ", y: " << v.getY() << ", z: " << v.getZ();
	return (os);
}

#endif // VEC3_TPP
