//
// Created by qli on 16/08/2021.
//

#ifndef FT_CONTAINERS_MAKE_PAIR_H
#define FT_CONTAINERS_MAKE_PAIR_H
#include "pair.h"

namespace ft {

template <class T1, class T2>
pair<T1,T2> make_pair (T1 x, T2 y)
{
	return ( pair<T1,T2>(x , y) );
};
}

#endif //FT_CONTAINERS_MAKE_PAIR_H
