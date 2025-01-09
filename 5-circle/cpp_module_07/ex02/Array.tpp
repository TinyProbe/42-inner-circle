/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 07:24:22 by tkong             #+#    #+#             */
/*   Updated: 2023/02/18 08:45:53 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T>
Array<T>::Array() : ptr(new T[0]()), n() {}

template <class T>
Array<T>::Array(const Array &rhs) : ptr(), n() { *this = rhs; }

template <class T>
Array<T>::Array(size_t n) : ptr(new T[n]()), n(n) {}

template <class T>
Array<T>::~Array() {
	if (ptr != NULL) { delete[] ptr; }
}

template <class T>
Array<T> &Array<T>::operator=(const Array &rhs) {
	if (this == &rhs) { return *this; }
	if (ptr != NULL) { delete[] ptr; }
	n = rhs.n;
	ptr = new T[n];
	for (size_t i=0; i<n; ++i) { ptr[i] = rhs.ptr[i]; }
	return *this;
}

template <class T>
T &Array<T>::operator[](size_t idx) {
	if (idx >= n) { throw std::exception(); }
	return ptr[idx];
}

template <class T>
const T &Array<T>::operator[](size_t idx) const {
	if (idx >= n) { throw std::exception(); }
	return ptr[idx];
}

template <class T>
size_t Array<T>::size() const { return n; }
