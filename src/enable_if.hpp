#include "identity.hpp"

// if true, use the given type; if false, use no type at all

// primary template assumes the bool value is true
template<bool, class T=void>
struct enable_if: type_is<T> {};

// partial specialization: false value, compute nothing
template<class T>
struct enable_if<false, T> {}; // no member named type

template<bool B, class T>
using enable_if_t = typename enable_if<B, T>::type;
