/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:04:10 by tkong             #+#    #+#             */
/*   Updated: 2023/02/18 23:04:10 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T>
MutantStack<T>::MutantStack() : std::stack<T, container_type >() {}
template <class T>
MutantStack<T>::MutantStack(const MutantStack &rhs) : std::stack<T, container_type >(rhs) {}
template <class T>
MutantStack<T>::~MutantStack() {}
template <class T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &rhs) {
	if (this == &rhs) { return *this; }
	dynamic_cast<std::stack<T, std::vector<T> > &>(*this) = dynamic_cast<const std::stack<T, std::vector<T> > &>(rhs);
	return *this;
}
template <class T>
MutantStack<T>::operator std::stack<T>() const {
	return std::stack<T>(std::deque<T>(this->c.begin(), this->c.end()));
}

template <class T>
typename MutantStack<T>::iterator               MutantStack<T>::begin()         {return this->c.begin();}
template <class T>
typename MutantStack<T>::const_iterator         MutantStack<T>::begin()   const {return this->c.begin();}
template <class T>
typename MutantStack<T>::iterator               MutantStack<T>::end()           {return this->c.end();}
template <class T>
typename MutantStack<T>::const_iterator         MutantStack<T>::end()     const {return this->c.end();}
template <class T>
typename MutantStack<T>::reverse_iterator       MutantStack<T>::rbegin()        {return this->c.reverse_iterator(this->c.end());}
template <class T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin()  const {return this->c.const_reverse_iterator(this->c.end());}
template <class T>
typename MutantStack<T>::reverse_iterator       MutantStack<T>::rend()          {return this->c.reverse_iterator(this->c.begin());}
template <class T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend()    const {return this->c.const_reverse_iterator(this->c.begin());}
template <class T>
typename MutantStack<T>::const_iterator         MutantStack<T>::cbegin()  const {return this->c.begin();}
template <class T>
typename MutantStack<T>::const_iterator         MutantStack<T>::cend()    const {return this->c.end();}
template <class T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin() const {return this->c.rbegin();}
template <class T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend()   const {return this->c.rend();}
