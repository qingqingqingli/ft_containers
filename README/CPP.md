
### Iterators

- An iterator is an object that points to an element inside a container. It is a simple class that provides a bunch of arithmetic operations (such as `++`, `*`) to work with the pointers. 

### Iterator properties
- **iterator_category**: 
  - `Input iterator`: Can scan the container forward only once, can't change the value it points to (read-only);
  - `Output iterator`: Can scan the container forward only once, can't read the value it points to (write-only);
  - `Forward iterator`: Can scan the container forward multiple times, can read and write the value it points to;
  - `Bidirectional iterator`: Same as previous one but can scan the container back and forth;
  - `Random-access iterator`: Same as previous one but can access the container also non-sequentially (i.e. by jumping around);
  - They are represented by different tags, which are used to select the most efficient algorithm from the `<algorithm>` library. Wrong tags mean sub-optimal performance.
- **difference_type**: a signed integer type that can be used to identify distance between iterator steps. `std::ptrdiff_t` is a good choice.
- **value_type**: the type the iterator iterates over (such as `int`). 
- **pointer**: defines a pointer to the type iterated over (such as `int*`). 
- **reference**: defines a reference to the type iterated over (such as `int&`).

### reverse_iterator

- `reverse_iterator` is an iterator adaptor that enables backwards traversal of a range. 
- A copy of the original iterator (the `base iterator`) is kept internally and used to reflect the operations performed on the `reverse_iterator`: whenever the reverse_iterator is incremented, its base iterator is decreased, and vice versa.
- **Notice however that when an iterator is reversed, the reversed version does not point to the same element in the range, but to the one preceding it.** 

### Operator overloading member vs. non-member functions
- In random access iterator implementation, `a + n` and `n + a` have different implementations. The first one can be implemented as a member function overload, but the second one a non-member function overload. 
- `a + n`: The compiler understands it as `a.operator+(int n)`. This can be implemented as a member function overload.
```c++
	// n + a
	iterator operator+ (const int n) {
		return iterator(_ptr + n);
	}
```
- `n + a`: Integer type does not understand the iterator type and has no overload for this situation. Therefore, there needs to be a non-member function overload between an integer and an iterator type.
```c++
	// a + n
	friend iterator operator+ (int n, iterator itr) {
		return iterator(itr._ptr + n);
	}
```

### General learnings
- There is a difference between the return type being const and returning actual const pointer/ref. When I define the typedef, I am specifying the type of term (such as `const_pointer`). However, I still need to make sure in the function, I am returning an actual const pointer.

### resources
- [const correctness](https://www.cprogramming.com/tutorial/const_correctness.html)