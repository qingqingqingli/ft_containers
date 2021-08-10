//
// Created by qli on 09/08/2021.
//

#ifndef FT_CONTAINERS_ITERATOR_TRAITS_H
#define FT_CONTAINERS_ITERATOR_TRAITS_H

namespace ft {

template< class Iterator >
class iterator_traits {

public:
	typedef typename Iterator::value_type            value_type;
	typedef typename Iterator::difference_type       difference_type;
	typedef typename Iterator::iterator_category     iterator_category;
	typedef typename Iterator::pointer               pointer;
	typedef typename Iterator::reference             reference;
};

template <class T>
class iterator_traits<T*>
{

};

template <class T>
class iterator_traits<const T*>
{

};
}

#endif //FT_CONTAINERS_ITERATOR_TRAITS_H
