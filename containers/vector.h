//
// Created by qli on 25/02/2021.
//

#ifndef FT_CONTAINERS_VECTOR_H
#define FT_CONTAINERS_VECTOR_H

namespace ft
{
class allocator {

};
template < class T>
class vector {

//nested member type
public:
	// Need to double check and adjust for different containers
	// these are nested type names
	typedef T										value_type;
	typedef allocator<value_type>					allocator_type;
	typedef value_type&								reference;
	typedef const value_type&						const_reference;
	typedef value_type*								pointer;
	typedef const value_type*						const_pointer;
	typedef ptrdiff_t								difference_type;
	typedef size_t									size_type;

	//** coplien form
public:
	explicit vector(const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0){}

	size_type capacity() const {
		return this->_capacity;
	}

	size_type size() const {
		return this->_size;
	}

private:
	size_type _size;
	size_type _capacity;

};
}




#endif //FT_CONTAINERS_VECTOR_H
