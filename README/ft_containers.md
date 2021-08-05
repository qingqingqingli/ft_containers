##General learnings

### STL allocator vs operator new
- For general programming, you should use `new` and `delete`. However, if you are writing a library, you should use `std::allocator`. `std::allocator` gives users the control over what gets allocated from where. 

### Resources
- [C++ STL allocator vs operator new](https://stackoverflow.com/questions/5628059/c-stl-allocator-vs-operator-new)

