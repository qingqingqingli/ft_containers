//
// Created by qli on 16/08/2021.
//

#ifndef FT_CONTAINERS_STACK_H
#define FT_CONTAINERS_STACK_H
#include <deque>

namespace ft {

template <class T, class Container = std::deque<T> >
class stack {

public:
	typedef T				value_type;
	typedef Container		container_type;
	typedef size_t 			size_type;

//************** Private attributes **************
protected:
	container_type 			_container;

//************** Public functions **************

public:
explicit stack (const container_type& ctnr = container_type()) : _container(ctnr) {}

bool empty() const { return _container.empty(); }

size_type size() const { return _container.size(); }

value_type& top() { return _container.back(); }

const value_type& top() const { return _container.back(); }

void push (const value_type& val) { _container.push_back(val); }

void pop() { _container.pop_back(); }

friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{ return lhs._container == rhs._container; }

friend bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{ return lhs._container < rhs._container; }

};

//************** Non-member function overloads **************

template <class T, class Container>
bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{ return !(lhs == rhs); }

template <class T, class Container>
bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{ return rhs < lhs; }

template <class T, class Container>
bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{ return rhs > lhs; }

template <class T, class Container>
bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{ return rhs < lhs; }
}

#endif //FT_CONTAINERS_STACK_H
