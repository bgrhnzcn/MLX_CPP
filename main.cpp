/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:15:59 by buozcan           #+#    #+#             */
/*   Updated: 2024/09/05 20:39:11 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/math/Vec3.hpp"
#include <iostream>

int	main(void)
{
	mlx_cpp::Vec3<int> vec3;
	vec3.setX(2);
	vec3.setY(5);
	std::cout << "x: " << vec3.getX() << ", y: " << vec3.getY() << std::endl;
	return (EXIT_SUCCESS);
}
