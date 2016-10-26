#pragma once

#include <algorithm>
#include <iostream>
#include <experimental/iterator>

template<typename Container>
std::ostream& print(const Container& c,
                    const char* header="",
                    const char* delim=" ",
                    const char* footer="",
                    std::ostream& out=std::cout)
{
    out << header;
    std::copy(std::begin(c),
              std::end(c),
              std::experimental::make_ostream_joiner(out, delim));
    out << footer;
    return out;
}
