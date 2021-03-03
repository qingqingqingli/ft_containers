//
// Created by qli on 25/02/2021.
//

#ifndef FT_CONTAINERS_VECTOR_H
#define FT_CONTAINERS_VECTOR_H

#include <iostream>

namespace ft
{

template < class T, class Alloc = std::allocator<T> >
class vector {

//nested member type
public:
	//** nested type names
	//typedef	existing_type						new_type_name
	typedef T										value_type;
	typedef Alloc									allocator_type;
	typedef T&										reference;
	typedef const T&								const_reference;
	typedef T*										pointer;
	typedef const T*								const_pointer;
	typedef std::random_access_iterator_tag			iterator;
	typedef const std::random_access_iterator_tag	const_iterator;
	typedef std::reverse_iterator<iterator>			reverse_iterator;
	typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
	typedef ptrdiff_t								difference_type;
	typedef size_t									size_type;

private:
	size_type				_size;
	size_type				_capacity;
	allocator_type		 	_alloc;
	pointer 				_array;

public:

//-> coplien form

	//** 1. default constructor: empty vector
	explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc), _array(NULL) {}

	//** 2. default constructor: vector with size and val
	explicit vector (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc)
	{
		this->_array = new value_type [n];
		size_type i = 0;
		while (i < this->size())
		{
			this->_array[i] = val;
			i++;
		}
	}

	//** 3. default constructor: vector with InputIterator
	// for later to implement the iterator
//	template <class InputIterator>	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {
//
//	}

	//** 4. copy constructor
	vector (const vector& x){
		*this = x;
	}

	//** 5. assignation operator ->update later
	vector& operator= (const vector& x) {
		if (this != &x)
		{
			this->_size = x._size;
			this->_capacity = x._capacity;
			this->_alloc = x._alloc;
			this->_array = this->_alloc.allocate(this->_size);
			size_type i = 0;
			while (i < this->_size)
			{
				this->_array[i] = x._array[i];
				i++;
			}
		}
		return *this;
	}

	//** 6. default destructor
	~vector() {
		delete [] this->_array;
	}

//-> member functions

	//** 7. assign (assign new contents to the vector)

	template <class InputIterator> void assign (InputIterator first, InputIterator last);
	void assign (size_type n, const value_type& val);

	//** 8. at (returns a reference to the element at position n in the vector)
	// the first element has  a position of 0

	reference at (size_type n) {
		if (n > this->_size - 1)
		{
			std::stringstream sstm;
			sstm << "vector::_M_range_check: __n (which is " << n << ") this->size() (which is " << this->size() << ")" << std::endl;
			std::string error_msg = sstm.str();
			throw std::out_of_range(error_msg);
		}
		else
		{
			reference elem_ref = *(this->_array + n);
			return elem_ref;
		}
	}

	const_reference at (size_type n) const {
		if (n > this->_size - 1)
		{
			std::stringstream sstm;
			sstm << "vector::_M_range_check: __n (which is " << n << ") this->size() (which is " << this->size() << ")" << std::endl;
			std::string error_msg = sstm.str();
			throw std::out_of_range(error_msg);
		}
		else
		{
			const_reference elem_ref = *(this->_array + n);
			return elem_ref;
		}
	}

	//** 9. back (returns a reference to the last element in the vector)
	reference back();
	const_reference back() const;

	//** 10. begin (returns an iterator pointing to the first element in the vector)
	iterator begin();
	const_iterator begin() const;

	//** 11. capacity (return the size of the storage space)
	size_type capacity() const {
		return this->_capacity;
	}

	//** 12. clear (remove all elements from the vector)
	void clear();

	//** 13. empty (test whether the vector is empty)
	bool empty() const;

	//** 14. end (return iterator to end)
	iterator end();
	const_iterator end() const;

	//** 15. erase (erase element(s) from the vector)
	iterator erase (iterator position);
	iterator erase (iterator first, iterator last);

	//** 16. front (return a reference to the first element)
	reference front();
	const_reference front() const;

	//** 17. insert (insert new elements to the vector)
	iterator insert (iterator position, const value_type& val);

	void insert (iterator position, size_type n, const value_type& val);

	template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last);

	//** 18. max_size (return the max number of elements)
	// to understand the difference between capacity and max_size
	size_type max_size() const;

	//** 19. operator[] (return a reference to the element at position n)
	// does not check against bounds
	reference operator[] (size_type n) {
		T& elem_ref = *(this->_array + n);
		return elem_ref;
	}

	const_reference operator[] (size_type n) const {
		const T& elem_ref = *(this->_array + n);
		return elem_ref;
	}

	//** 20. pop_back (removes the last element in the vector)
	void pop_back();

	//** 21. push_back (add a new element at the end of the vector)
	void push_back (const value_type& val) {
		if (this->size() + 1 > this->capacity())
		{
			// create new vector
			vector new_vector;
			new_vector._size = this->size();
			new_vector._capacity = this->size() * 2;
			new_vector._alloc = this->_alloc;
			new_vector._array = new_vector._alloc.allocate(new_vector._capacity);

			//  copy old value into new vector
			size_type i = 0;
			while(i < this->size())
			{
				new_vector._array[i] = this->_array[i];
				i++;
			}
			this->_alloc.deallocate(this->_array, this->capacity());
			this->_array = new_vector._array;
			*this = new_vector;
		}
		//invalid read
		this->_array[this->size()] = val;
		this->_size += 1;
	}

	//** 22. rbegin (return a reverse iterator pointing to the last element in the vector)
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;

	//** 23. rend (return a reverse iterator pointing to the theoretical element preceding the first element in the vector)
	reverse_iterator rend();
	const_reverse_iterator rend() const;

	//** 24. reverse (request that the vector capacity be at least enough to contain n elements)
	void reserve (size_type n);

	//** 25. resize (resize the container so that it contains n elements)
	void resize (size_type n, value_type val = value_type());

	//** 26. size (return the number of elements in the vector)
	size_type size() const {
		return this->_size;
	}

	//** 27. swap (exchange the content of the container by the content of another container)
	void swap (vector& x);

};
}

#endif //FT_CONTAINERS_VECTOR_H
