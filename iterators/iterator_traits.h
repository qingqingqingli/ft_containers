//
// Created by qli on 09/08/2021.
//

#ifndef FT_CONTAINERS_ITERATOR_TRAITS_H
#define FT_CONTAINERS_ITERATOR_TRAITS_H

namespace ft {

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template< class Iterator >
class iterator_traits {
	typedef typename Iterator::value_type            value_type;
	typedef typename Iterator::difference_type       difference_type;
	typedef typename Iterator::iterator_category     iterator_category;
	typedef typename Iterator::pointer               pointer;
	typedef typename Iterator::reference             reference;
};
}

#endif //FT_CONTAINERS_ITERATOR_TRAITS_H
