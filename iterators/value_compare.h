//
// Created by qli on 16/08/2021.
//

#ifndef FT_CONTAINERS_VALUE_COMPARE_H
#define FT_CONTAINERS_VALUE_COMPARE_H
#include "../containers/map.h"

namespace ft {

template <class Key, class T, class Compare, class Alloc>
class map<Key,T,Compare,Alloc>::value_compare
{
	// in C++98, it is required to inherit binary_function<value_type,value_type,bool>
	friend class map<Key, T, Compare, Alloc>;

protected:
	Compare comp;
	value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object

public:
	typedef bool result_type;
	typedef value_type first_argument_type;
	typedef value_type second_argument_type;
	bool operator() (const value_type& x, const value_type& y) const
	{
		return comp(x.first, y.first);
	}
}
}

#endif //FT_CONTAINERS_VALUE_COMPARE_H
