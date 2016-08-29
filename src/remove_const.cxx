template<typename T>
struct remove_const {
    using type = T;
};

template<typename T>
struct remove_const<T const> {
    using type = T;
};

int main()
{
    const int x = 3;
    remove_const<decltype(x)>::type y = 5;
    return ++y;
}
