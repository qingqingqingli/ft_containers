//
// Created by qli on 16/08/2021.
//

#ifndef FT_CONTAINERS_PAIR_H
#define FT_CONTAINERS_PAIR_H

namespace ft {

template <class T1, class T2>
struct pair {

public:
	typedef T1 first_type;
	typedef T2 second_type;

private:
	first_type 	first;
	second_type second;

public:

// default
pair();

// copy
template<class U, class V> pair (const pair<U,V>& pr);

// initialization
pair (const first_type& a, const second_type& b);

// note	- implicitly declared:

// copy
pair& operator= (const pair& pr);

};

template <class T1, class T2>
bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

template <class T1, class T2>
bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

template <class T1, class T2>
bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

template <class T1, class T2>
bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

template <class T1, class T2>
bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

template <class T1, class T2>
bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

}

#endif //FT_CONTAINERS_PAIR_H
