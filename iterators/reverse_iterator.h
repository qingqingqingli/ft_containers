//
// Created by qli on 09/08/2021.
//

#ifndef FT_CONTAINERS_REVERSE_ITERATOR_H
#define FT_CONTAINERS_REVERSE_ITERATOR_H
#include "iterator_traits.h"

namespace ft {

template <class Iterator>
class reverse_iterator {

public:
	typedef Iterator											iterator_type;
	typedef typename ft::iterator_traits<Iterator>::iterator_category 	iterator_category;
	typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
	typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
	typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
	typedef typename ft::iterator_traits<Iterator>::reference			reference;

private:
	iterator_type _base_itr;

public:

//******************************************** Constructor ********************************************

// default
reverse_iterator() : _base_itr(NULL) {}

// initialization
explicit reverse_iterator (iterator_type it) : _base_itr(it) {}

// copy
template <class Iter>
explicit reverse_iterator (const reverse_iterator<Iter>& rev_it): _base_itr(rev_it.base()) {}

//******************************************** Member functions ********************************************

// return the current iterator
iterator_type base() const { return _base_itr; }

reference operator*() const { return *(_base_itr - 1); }

reverse_iterator operator+ (difference_type n) const;

// The pre-increment version (1) returns *this.
reverse_iterator& operator++();

// The post-increment version (2) returns the value *this had before the call.
reverse_iterator operator++(int);

reverse_iterator& operator+= (difference_type n);

// An iterator pointing to the element n positions before the currently pointed one.
reverse_iterator operator- (difference_type n) const;

// The pre-decrement version (1) returns *this.
reverse_iterator& operator--();

// The post-decrement version (2) returns the value *this had before the call.
reverse_iterator  operator--(int);

// The reverse iterator itself (*this).
reverse_iterator& operator-= (difference_type n);

//  A pointer to the element pointed by the iterator.
pointer operator->() const;

// Accesses the element located n positions away from the element currently pointed to by the iterator.
reference operator[] (difference_type n) const;

};

//******************************************** Non-member function overloads ********************************************

template <class Iterator>
bool operator== (const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs);

template <class Iterator>
bool operator!= (const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs);

template <class Iterator>
bool operator<  (const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs);

template <class Iterator>
bool operator<= (const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs);

template <class Iterator>
bool operator>  (const reverse_iterator<Iterator>& lhs,
						 const reverse_iterator<Iterator>& rhs);

template <class Iterator>
bool operator>= (const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs);

template <class Iterator>
reverse_iterator<Iterator> operator+ (
				typename reverse_iterator<Iterator>::difference_type n,
				const reverse_iterator<Iterator>& rev_it);

// The number of elements between lhs and rhs.
template <class Iterator>
typename reverse_iterator<Iterator>::difference_type operator- (
				const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs);

}

#endif //FT_CONTAINERS_REVERSE_ITERATOR_H
