/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 22:21:33 by ecarlier          #+#    #+#             */
/*   Updated: 2024/10/12 22:41:51 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/*Creates an empty array*/
template <typename T>
Array<T>::Array(): _array(NULL), _size(0) { }

/*Creates an array of n elements initialized by default*/
template <typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n) { }


template <typename T>
Array<T>::Array(const Array &array)
{
	_size = array._size;
	if (_size == 0)
		_array = NULL;
	else
	{
		_array = new T[_size];
 		for (unsigned int i = 0; i < array._size; i++)
			_array[i] = array._array[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] (this->_array);
}

template<typename T>
unsigned int  Array<T>::size()
{
	return (this->_size);
}

template<typename T>
T &Array<T>::operator[](unsigned int n)
{
	if (n < 0 || n >= this->_size)
		throw Array::indexOutOFBound();
	return (_array[n]);
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &src)
{
	if (this != &src)
	{
		delete [] this->_array;
		this->_size = src._size;
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = src._array[i];
	}
	return (*this);
}


template<typename T>
const char* Array<T>::indexOutOFBound::what() const throw()
{
	return ("Throwing exception : index out of bound\n");
}
