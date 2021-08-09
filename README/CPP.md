
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
- **Notice however that when an iterator is reversed, the reversed version does not point to the same element in the range, but to the one preceding it.** This is so, in order to arrange for the past-the-end element of a range: An iterator pointing to a past-the-end element in a range, when reversed, is pointing to the last element (not past it) of the range (this would be the first element of the reversed range). And if an iterator to the first element in a range is reversed, the reversed iterator points to the element before the first element (this would be the past-the-end element of the reversed range).

### resources
- [const correctness](https://www.cprogramming.com/tutorial/const_correctness.html)