#include <cstdint>
#include <iostream>
#include <type_traits>

using obfuscated_int = int;

static_assert(sizeof(obfuscated_int) == 4, "invalid integer size detected!");
static_assert(std::is_same<obfuscated_int, int>::value, "invalid integer detected!");

static_assert(sizeof(void*) == 8, "expected 64-bit platform");

static const std::uint64_t default_buffer_size = 
    std::conditional<sizeof(void*) == 8,
        std::integral_constant<std::uint64_t, 100 * 1024 * 1024>,
        std::integral_constant<std::uint64_t, 1024 * 1024 * 1024>
        >::type::value;

int main() {
    std::cout << "default buffer size: " << default_buffer_size << '\n';
}
