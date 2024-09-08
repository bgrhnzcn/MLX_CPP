/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mlx.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:16:20 by buozcan           #+#    #+#             */
/*   Updated: 2024/09/08 02:38:20 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MLX_HPP
# define MLX_HPP

#include <iosfwd>

namespace mlx
{
	class Mlx
	{
		private:
			void *mlx_ptr;
		public:
			Mlx(void);
			~Mlx(void);
			void *getMlxPtr(void);
		public:
			void mlxLoop(void);
			void mlxLoopHook(int (*funct_ptr)(void *param), void *param);
	};
}

#endif