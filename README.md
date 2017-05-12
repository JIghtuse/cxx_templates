# Template Metaprogramming

## Materials

* [Modern Template Metaprogramming: A Compendium (youtube)](https://www.youtube.com/watch?v=Am2is2QCvxY)
* [Practical C++ Metaprogramming](http://www.oreilly.com/programming/free/practical-c-plus-plus-metaprogramming.csp)
* [C++ Templates - The Complete Guide](http://www.josuttis.com/tmplbook/)

## Templates

### Function templates

Function template can be seen as a family of functions, where some elements are parameterized.
Types of these elements are deduced when function is called. Such substitution are called
instantiation. Automatic type conversion does not happen on instantiation.

### Class templates

As functions, classes can be parameterized by one or more types. Common usage is container
classes. Class template can be specialized for particular argument. It is possible to
specialize only some parameters of class template and set default template arguments.

### Non-type template parameters

For function and class templates, template parameters can be ordinary values. Using this
technique, we can provide user ability to parameterize code with a value instead of a type.
