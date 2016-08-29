#include "identity.hpp"

// primary template: bool is true
template<bool, class T, class>
struct IF : type_is<T> {};

// partial specialization: bool is false
template<class T, class F>
struct IF<false, T, F> : type_is<F> {};

template<bool B, class T, class F>
using IF_t = typename IF<B, T, F>::type;

class B1 {
};
class B2 {
};

struct F {
    void operator()()
    {
    }
};
struct G {
    void operator()()
    {
    }
};

int main()
{
    // self-configuring code
    int const q = 1; // user's configuration parameter

    IF_t<(q < 0), int, unsigned> k; // k declared to have 1 of these 2 integer types
    IF_t<(q < 0), F, G>{}(); // instantiate and call 1 of these 2 function objects
    class D : public IF_t<(q < 0), B1, B2> {}; // inherit from 1 of these 2 base classes
}
