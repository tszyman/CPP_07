/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tszymans <tszymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:28:08 by tszymans          #+#    #+#             */
/*   Updated: 2026/03/10 19:28:09 by tszymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void iter(T *array, std::size_t length, F func){
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}
template <typename T, typename F>
void iter(const T *array, std::size_t length, F func){
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

#endif
