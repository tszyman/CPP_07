/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tszymans <tszymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:28:24 by tszymans          #+#    #+#             */
/*   Updated: 2026/03/10 20:18:07 by tszymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
	private:
		T* 				_data;
		unsigned int	_size;
	public:
		Array() : _data(NULL), _size(0) {}
		Array(unsigned int n) : _data(new T[n]()), _size(n) {} // () at the end is a C++98 trick that ensures value-initialization (setting integers to 0, for example)
		Array(const Array& src) : _data(NULL), _size(n) {
			*this = src;
		}
		Array& operator=(const Array& rhs) {
			if(*this!=&rhs){
				//1. Delete old memory
				delete [] _data;
				//4. Update _size
				_size = other._size;
				if (_size > 0) {
					//2. Allocate new memory based on other._size
					_data = new T[_size]();
					//3. Copy element from other._data to new _data
					for (unsigned int i = 0; i < _size; i++){
						_data[i] = other._data[i];
					}
				} else {
					_data = NULL;
				}
			}
			return *this;
		}
		~Array() {
			if(_data)
				delete[] _data;
		}

		unsigned int size();
};

#endif
