template<class T>
struct type_is {
    using type = T;
};

// apply convention via inheritance

// primary template handles types that are not volatile qualified
template<class T>
struct remove_volatile: type_is<T> {};

template<class T>
struct remove_volatile<T volatile>: type_is<T> {};

int main()
{
}
