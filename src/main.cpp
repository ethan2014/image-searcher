#include <iostream>

#include <png++/png.hpp>

auto fun() {
    return std::string{ "hello" };
}

auto main() -> int {
    std::cout << fun() << std::endl;
}
