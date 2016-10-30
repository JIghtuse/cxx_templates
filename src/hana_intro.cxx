#include <boost/hana.hpp>
#include <cassert>
#include <iostream>
#include <string>

namespace hana = boost::hana;

struct Fish {
    std::string name;
};

struct Cat {
    std::string name;
};

struct Dog {
    std::string name;
};

struct Person {
    BOOST_HANA_DEFINE_STRUCT(
        Person,
        (std::string, name),
        (int, age));
};

auto serialize = [](std::ostream& os, auto const& object) {
    hana::for_each(hana::members(object), [&](auto member) {
        os << member << '\n';
    });
};

int main()
{
    using namespace hana::literals;

    auto animals = hana::make_tuple(
            Fish{"Nemo"},
            Cat{"Garfield"},
            Dog{"Snoopy"});

    Cat garfield = animals[1_c];

    auto names = hana::transform(animals, [](auto a) {
        return a.name;
    });

    assert(hana::reverse(names) == hana::make_tuple(
                "Snoopy",
                "Garfield",
                "Nemo"));

    auto animal_types = hana::make_tuple(
            hana::type_c<Fish*>,
            hana::type_c<Cat&>,
            hana::type_c<Dog>);

    auto no_pointers = hana::remove_if(animal_types, [](auto a) {
        return hana::traits::is_pointer(a);
    });

    static_assert(no_pointers == hana::make_tuple(
                hana::type_c<Cat&>,
                hana::type_c<Dog>));

    auto has_name = hana::is_valid([](auto&& x) -> decltype((void)x.name) {});

    static_assert(has_name(garfield), "");
    static_assert(!has_name(), "");

    Person john{"John", 30};
    serialize(std::cout, john);
}
