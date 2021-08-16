//
// Created by qli on 16/08/2021.
//

#ifndef FT_CONTAINERS_PAIR_H
#define FT_CONTAINERS_PAIR_H

namespace ft {

template <class T1, class T2>
struct pair {

	typedef T1 first_type;
	typedef T2 second_type;

	first_type 	first;
	second_type second;

	// default
	pair(): first(), second() {}

	// copy
	template<class U, class V> pair (const pair<U,V>& pr): first(pr.first), second(pr.second) {}

	// initialization
	pair (const first_type& a, const second_type& b): first(a), second(b) {}

	// note	- implicitly declared;

	// copy
	pair& operator= (const pair& pr) {
		first = pr.first;
		second = pr.second;
		return *this;
	}

};

template <class T1, class T2>
bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first == rhs.first && lhs.second == rhs.second; }

template <class T1, class T2>
bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs == rhs)}

template <class T1, class T2>
bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first < rhs.first ||
(!(rhs.second < lhs.first) && lhs.second < rhs.second)}

template <class T1, class T2>
bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return rhs < lhs; }

template <class T1, class T2>
bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return rhs > lhs; }

template <class T1, class T2>
bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return rhs < lhs; }

}

#endif //FT_CONTAINERS_PAIR_H
