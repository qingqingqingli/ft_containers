
### project requirement

- No need to implement `get_allocator`
- Implement `iterator system`
- Can't implement more public functions than the ones offered in the standard containers. Everything else must be private or protected.**Each public function/variable must be justified**.
- For non-member overloads, the keyword `friend` is allowed.

### standard containers

- A container is a holder object that stores a collection of other objects (its elements). They are implemented as class templates, which allows a great flexibility in the types supported as elements.
- The container manages the storage space for its elements and provides member functions to access them, either directly or through iterators.
- Containers replicate structures very commonly used in programming: dynamic arrays(`vector`), queues (`queue`), stacks(`stack`), linked_list(`list`), associative arrays(`map`).
- `stack` and `queue` are implemented as `container adaptors`. They are not full container classes, but classes that provide a specific interface `relying on an object of one of the container classes` to handle the elements. The underlying container is encapsulated in such a way that its elements are accessed by the members of the container adaptor independently of the underlying container class used.

### vector

- Vectors are sequence containers representing arrays that `can change in size`.
- Just like arrays, vectors use `contiguous storage locations` for their elements, which means that their elements can also be accessed using offsets on regular pointers to its elements, and just as efficiently as in arrays. But unlike arrays, their `size can change dynamically`, with their storage being handled automatically by the container.
- Internally, vectors use a `dynamically allocated array` to store their elements. This array may need to be reallocated in order to grow in size when new elements are inserted, which implies allocating a new array and moving all elements to it. This is a relatively expensive task in terms of processing time, and thus, vectors do not reallocate each time an element is added to the container.

### Member types

> Example of helper types for standard containers

```c++
template<typename T>
class SomeContainer {
    // ...

  public:
    // Let's provide the same helper types as most standard containers.
    typedef T                                     value_type;
    typedef std::allocator<value_type>            allocator_type;
    typedef value_type&                           reference;
    typedef const value_type&                     const_reference;
    typedef value_type*                           pointer;
    typedef const value_type*                     const_pointer;
    typedef MyIterator<value_type>                iterator;
    typedef MyConstIterator<value_type>           const_iterator;
    typedef std::reverse_iterator<iterator>       reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef size_t                                size_type;
    typedef ptrdiff_t                             difference_type;
};
```

### STD vs. STL
- In the subject, functions in the STD library is allowed but any STL library is forbidden
- `STL` stands for `Standard Template Library`. It refers to a C++ implementation of useful functionalities, including containers, algorithms and various utilities. 
- `STD` is a namespace.

### Why allocator in class template

- Class template: `template<class T, class Allocator = std::allocator<T>> class vector`;
- Default constructor: `explicit vector(const Allocator& alloc = Allocator() );`
- There always is an instance of Allocator provided as alloc parameter. By default it constructs Allocator object. Whenever you do not use invocation of vector specifying allocator parameter, you do create new Allocator object, which in default case most probably does nothing. 
- In some system you have more then one type of memory, so it might be useful to provide separate allocators. This is common in embedded systems. 
- When you create a new object, you need to tell which of the allocators instances should take care of it.
- The basic idea of allocator is to separate the steps of allocating memory and object construction. Default new combines the both. In case of vector reserve we only want to allocate the required memory. We can't construct or initialize the objects at that time since the type may not be default constructable.
- `std::allocator` is used when you want to separate allocation and do construction in two steps. It is also used when separate destruction and deallocation is done in two steps. The default allocator simply uses the operators new and delete to obtain and release memory.

### resources

- [c++ member types](https://stackoverflow.com/questions/39844582/c-member-types)
- [std::allocator() in C++ with Examples](https://www.geeksforgeeks.org/stdallocator-in-cpp-with-examples/)