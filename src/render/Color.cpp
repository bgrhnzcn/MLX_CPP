/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:08:33 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/09/07 17:02:08 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"

mlx::Color::Color(unsigned int value)
	: value(value)
{
	;
}

mlx::Color::Color(unsigned char alpha, unsigned char red,
	unsigned char green, unsigned char blue)
{
	this->alpha = alpha;
	this->red = red;
	this->green = green;
	this->blue = blue;
}
