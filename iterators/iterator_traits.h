//
// Created by qli on 09/08/2021.
//

#ifndef FT_CONTAINERS_ITERATOR_TRAITS_H
#define FT_CONTAINERS_ITERATOR_TRAITS_H

namespace ft {

template< class Iterator >
class iterator_traits {

public:
	typedef typename Iterator::difference_type       difference_type;
	typedef typename Iterator::value_type            value_type;
	typedef typename Iterator::pointer               pointer;
	typedef typename Iterator::reference             reference;
	typedef typename Iterator::iterator_category     iterator_category;
};

template <class T>
class iterator_traits<T*>
{
public:
	typedef std::ptrdiff_t							difference_type;
	typedef T										value_type;
	typedef T*										pointer;
	typedef T&										reference;
	typedef std::random_access_iterator_tag			iterator_category;
};

template <class T>
class iterator_traits<const T*>
{
	typedef std::ptrdiff_t							difference_type;
	typedef T										value_type;
	typedef const T*								pointer;
	typedef const T&								reference;
	typedef std::random_access_iterator_tag			iterator_category;
};
}

#endif //FT_CONTAINERS_ITERATOR_TRAITS_H
