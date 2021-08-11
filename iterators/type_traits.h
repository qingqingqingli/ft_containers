//
// Created by qli on 11/08/2021.
//

#ifndef FT_CONTAINERS_TYPE_TRAITS_H
#define FT_CONTAINERS_TYPE_TRAITS_H

namespace ft {

//************************ enable_if ************************
template<bool Cond, class T = void> struct enable_if {};
template<class T> struct enable_if<true, T> { typedef T type; };

//************************ is_integral ************************
template <class T> struct is_integral{ static const bool value = false; };
template <> struct is_integral<bool> { static const bool value = true; };
template <> struct is_integral<char> { static const bool value = true; };
template <> struct is_integral<char16_t> { static const bool value = true; };
template <> struct is_integral<char32_t> { static const bool value = true; };
template <> struct is_integral<wchar_t> { static const bool value = true; };
template <> struct is_integral<signed char> { static const bool value = true; };
template <> struct is_integral<short int> { static const bool value = true; };
template <> struct is_integral<int> { static const bool value = true; };
template <> struct is_integral<long int> { static const bool value = true; };
template <> struct is_integral<long long int> { static const bool value = true; };
template <> struct is_integral<unsigned char> { static const bool value = true; };
template <> struct is_integral<unsigned short int> { static const bool value = true; };
template <> struct is_integral<unsigned int> { static const bool value = true; };
template <> struct is_integral<unsigned long int> { static const bool value = true; };
template <> struct is_integral<unsigned long long int> { static const bool value = true; };

////************************ is_const ************************
//
//template <class T> struct is_const { static const bool value = false; };
//template <class T> struct is_const<const T> { static const bool value = true; };
//
////************************ is_const ************************
//
//template <bool flag, class IsTrue, class IsFalse>
//		struct choose;
//
//template <class IsTrue, class IsFalse>
//		struct choose<true, IsTrue, IsFalse> {
//			typedef IsTrue type;
//		};
//
//template <class IsTrue, class IsFalse>
//		struct choose<false, IsTrue, IsFalse> {
//			typedef IsFalse type;
//		};
}

#endif //FT_CONTAINERS_TYPE_TRAITS_H
