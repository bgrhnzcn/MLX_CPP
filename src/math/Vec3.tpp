/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec3.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:44:56 by buozcan           #+#    #+#             */
/*   Updated: 2024/09/05 20:39:09 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef VEC3_CPP
# define VEC3_CPP

namespace mlx_cpp
{
	template <typename T> T Vec3<T>::getX(void)
	{
		return (this->x);
	}

	template <typename T> T Vec3<T>::getY(void)
	{
		return (this->y);
	}

	template <typename T> void Vec3<T>::setX(T x)
	{
		this->x = x;
	}

	template <typename T> void Vec3<T>::setY(T y)
	{
		this->y = y;
	}
}

#endif