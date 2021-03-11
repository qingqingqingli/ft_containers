//
// Created by qli on 25/02/2021.
//

#ifndef FT_CONTAINERS_VECTOR_H
# define FT_CONTAINERS_VECTOR_H
# include <iostream>

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector {

public:
	//		existing_type							new_type_name
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

// helper function
private:
	void reallocation(size_type realloc_size)
	{
		value_type *new_array = new value_type [realloc_size];
		for (size_type i = 0; i < this->size(); i++)
			new_array[i] = this->_array[i];
		delete [] this->_array;
		this->_array = new_array;
		this->_capacity = realloc_size;
	}

	void copy_vector_value(size_type n, value_type val)
	{
		while (this->size() < n)
		{
			this->_array[this->size()] = val;
			this->_size++;
		}
	}

public:
//-> Coplien form
	explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc), _array(NULL) {}

	explicit vector (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc)
	{
		this->_array = new value_type [n];
		for (size_type i = 0; i < this->size(); i++)
			this->_array[i] = val;
	}

//	template <class InputIterator>	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

	vector& operator= (const vector& x) {
		if (this != &x)
		{
			this->_size = x._size;
			this->_capacity = x._capacity;
			this->_alloc = x._alloc;
			this->_array = new value_type [this->_size];
			for (size_type i = 0; i < this->size(); i++)
				this->_array[i] = x._array[i];
		}
		return *this;
	}

	vector (const vector& x){ *this = x; }
	~vector() { delete [] this->_array; }

//-> Iterators

	//** [iterator] begin (returns an iterator pointing to the first element in the vector)
	iterator begin();
	const_iterator begin() const;

	//** [iterator] end (return iterator to end)
	iterator end();
	const_iterator end() const;

	//** [iterator] rbegin (return a reverse iterator pointing to the last element in the vector)
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;

	//** [iterator] rend (return a reverse iterator pointing to the theoretical element preceding the first element in the vector)
	reverse_iterator rend();
	const_reverse_iterator rend() const;

//-> Capacity

	size_type size() const { return this->_size; }
	size_type max_size() const { return this->_alloc.max_size(); }
	size_type capacity() const { return this->_capacity; }

	void resize (size_type n, value_type val = value_type()) {
		if (n < this->size())
			this->_size = n;
		else if (n > this->size())
		{
			if (n > this->capacity() && n <= this->capacity() * 2)
				reallocation(this->capacity() * 2);
			else if (n > this->capacity() * 2)
				reallocation(n);
			copy_vector_value(n, val);
		}
	}

	bool empty() const {
		if (!this->size())
			return true;
		else
			return false;
	}

	void reserve (size_type n) {
		if (n > this->capacity())
			reallocation(n);
	}

//-> Element access

	reference operator[] (size_type n) {
		T& elem_ref = *(this->_array + n);
		return elem_ref;
	}

	const_reference operator[] (size_type n) const {
		const T& elem_ref = *(this->_array + n);
		return elem_ref;
	}

	reference at (size_type n) {
		if (n > this->_size - 1)
		{
			std::stringstream sstm;
			sstm << "vector::_M_range_check: __n (which is " << n << ") this->size() (which is " << this->size() << ")" << std::endl;
			std::string error_msg = sstm.str();
			throw std::out_of_range(error_msg);
		}
		reference elem_ref = *(this->_array + n);
		return elem_ref;
	}

	const_reference at (size_type n) const {
		if (n > this->_size - 1)
		{
			std::stringstream sstm;
			sstm << "vector::_M_range_check: __n (which is " << n << ") this->size() (which is " << this->size() << ")" << std::endl;
			std::string error_msg = sstm.str();
			throw std::out_of_range(error_msg);
		}
		const_reference elem_ref = *(this->_array + n);
		return elem_ref;
	}

	// to understand if this can be simplified
	reference front() {
		reference front_ref = this->_array[0];
		return front_ref;
	}

	const_reference front() const {
		const_reference front_ref = this->_array[0];
		return front_ref;
	}

	reference back() {
		reference back_ref = this->_array[this->size() - 1];
		return back_ref;
	}

	const_reference back() const {
		const_reference const_back_ref = this->_array[this->size() - 1];
		return const_back_ref;
	}

//-> Modifier

	//** [modifier] assign (assign new contents to the vector)

//	template <class InputIterator> void assign (InputIterator first, InputIterator last);

	void assign (size_type n, const value_type& val) {
		if (n <= this->capacity())
		{
			this->_size = n;
			for (size_type i = 0; i < this->size(); i++)
				this->_array[i] = val;
		}
		else
		{
			value_type *new_array = new value_type [n];
			this->_capacity = n;
			this->_size = n;
			for (size_type i = 0; i < this->size(); i++)
				new_array[i] = val;
			delete [] this->_array;
			this->_array = new_array;
		}
	}

	//** [modifier] push_back (add a new element at the end of the vector)
	void push_back (const value_type& val) {
		if (this->size() + 1 > this->capacity())
		{
			if (!this->size())
				this->_capacity = 1;
			else
				this->_capacity = this->size() * 2;
			value_type *new_array = new value_type [this->capacity()];
			size_type i = 0;
			while(i < this->size())
			{
				new_array[i] = this->_array[i];
				i++;
			}
			delete [] this->_array;
			this->_array = new_array;
		}
		this->_array[this->size()] = val;
		this->_size += 1;
	}

	//** [modifier] pop_back (removes the last element in the vector)
	void pop_back() { this->_size -= 1; }

	//** [modifier] insert (insert new elements to the vector)
//	iterator insert (iterator position, const value_type& val);

//	void insert (iterator position, size_type n, const value_type& val);

//	template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last);

	//** [modifier] erase (erase element(s) from the vector)
//	iterator erase (iterator position);
//	iterator erase (iterator first, iterator last);

	//** [modifier] swap (exchange the content of the container by the content of another container)
	void swap (vector& x) {
		value_type *array_swap = x._array;
		size_type size_swap = x._size;
		size_type capacity_swap = x._capacity;
		allocator_type alloc_swap = x._alloc;

		x._array = this->_array;
		x._size = this->_size;
		x._capacity = this->_capacity;
		x._alloc = this->_alloc;

		this->_array = array_swap;
		this->_size = size_swap;
		this->_capacity = capacity_swap;
		this->_alloc = alloc_swap;
	}

	//** [modifier] clear (remove all elements from the vector)
	void clear() { this->_size = 0; }

};
}

#endif //FT_CONTAINERS_VECTOR_H
