/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec2.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:43:31 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/09/08 02:17:21 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef VEC2_TPP
# define VEC2_TPP

#include <system_error>
#include <iostream>
#include <cmath>

#include "Vec2.hpp"

template <typename T> mlx::Vec2<T>::Vec2(const mlx::Vec2<T> &v)
{
	this->x = v.getX();
	this->y = v.getY();
}

template <typename T> mlx::Vec2<T>::Vec2(T x, T y)
{
	this->x = x;
	this->y = y;
}

template <typename T> T mlx::Vec2<T>::getX(void) const
{
	return (this->x);
}

template <typename T> T mlx::Vec2<T>::getY(void) const
{
	return (this->y);
}

template <typename T> void mlx::Vec2<T>::setX(T x)
{
	this->x = x;
}

template <typename T> void mlx::Vec2<T>::setY(T y)
{
	this->y = y;
}

template <typename T> mlx::Vec2<T> mlx::Vec2<T>::operator+(const mlx::Vec2<T> &v)
{
	mlx::Vec2<T> res;
	res.setX(this->x + v.getX());
	res.setY(this->y + v.getY());
	return (res);
}

template <typename T> mlx::Vec2<T> mlx::Vec2<T>::operator-(const mlx::Vec2<T> &v)
{
	mlx::Vec2<T> res;
	res.setX(this->x - v.getX());
	res.setY(this->y - v.getY());
	return (res);
}

template <typename T> mlx::Vec2<T> mlx::Vec2<T>::operator*(const T &v)
{
	mlx::Vec2<T> res;
	res.setX(this->x * v);
	res.setY(this->y * v);
	return (res);
}

template <typename T> mlx::Vec2<T> mlx::Vec2<T>::operator/(const T &v)
{
	mlx::Vec2<T> res;
	
	if (v == 0)
		throw std::runtime_error("Division by zero");
	res.setX(this->x / v);
	res.setY(this->y / v);
	return (res);
}

template <typename T> T &mlx::Vec2<T>::operator[](unsigned int index)
{
	if (index > 1)
		throw std::out_of_range("mlx::Vec2: Index out of range. Please give number between 0 and 2");
	if (index == 0)
		return (this->x);
	else
		return (this->y);
}

template <typename T> mlx::Vec2<T> mlx::Vec2<T>::zero(void)
{
	return (mlx::Vec2<T>(0, 0));
}

template <typename T> mlx::Vec2<T> mlx::Vec2<T>::one(void)
{
	return (mlx::Vec2<T>(1, 1));
}

template <typename T> T mlx::Vec2<T>::dot(const mlx::Vec2<T> &v)
{
	return ((this->x * v.getX()) + (this->y * v.getY()));
}

template <typename T> T mlx::Vec2<T>::lenght(void)
{
	return (std::sqrt(this->dot(*this)));
}

template <typename T> T mlx::Vec2<T>::dist(const mlx::Vec2<T> &v)
{
	return ((*this - v).lenght());
}

template <typename T> mlx::Vec2<T> mlx::Vec2<T>::normalize(void)
{
	T len = this->lenght();
	if (len == 0)
		throw std::runtime_error("Division by zero");
	return (*this / len);
}

template <typename T> std::ostream &operator<<(std::ostream &os, const mlx::Vec2<T> &v)
{
	os << "x: " << v.getX() << ", y: " << v.getY();
	return (os);
}

#endif
