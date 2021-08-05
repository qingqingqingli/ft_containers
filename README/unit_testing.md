
### Why unit testing?

- `Modularize your code`. As code's testability depends on its design, unit tests facilitate breaking it into specialized easy-to-test pieces.

- `Avoid regressions`. When you have a suite of unit tests, you can run it iteratively to ensure that everything keeps working correctly every time you add new functionality or introduce changes.

- `Document your code`. Running, debugging, or even just reading tests can give a lot of information about how the original code works, so you can use them as implicit documentation.

### Good practices 

- Creating tests for `all publicly exposed functions`, including class constructors and operators.

- Covering all code paths and checking both `trivial and edge cases`, including those with incorrect input data (`negative testing`).

- Assuring that `each test works independently` and does't prevent other tests from execution.

- Organizing tests in a way that `the order` in which you run them doesn't affect the results.

### Resources

- [CLion documentation on unit testing](https://www.jetbrains.com/help/clion/unit-testing-tutorial.html#basics)