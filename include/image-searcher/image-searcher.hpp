#ifndef IMAGE_SEARCHER_HPP
#define IMAGE_SEARCHER_HPP

#include <png++/png.hpp>

#include <cmath>

namespace is {

auto load_image(const std::string& filename);

template <typename T>
constexpr auto similar_pixels(const png::rgb_pixel& a, const png::rgb_pixel& b, const T tolerance) noexcept;

template <typename Stream, typename Pixel>
auto print_pixel(Stream& out, const Pixel& pixel) -> void;

}

auto is::load_image(const std::string& filename) {
    return png::image<png::rgb_pixel>{ filename };
}

template <typename T>
constexpr auto is::similar_pixels(const png::rgb_pixel& a, const png::rgb_pixel& b, const T tolerance) noexcept {
    if (std::abs(a.red - b.red) > tolerance) {
	return false;
    }

    if (std::abs(a.green - b.green) > tolerance) {
	return false;
    }

    if (std::abs(a.blue - b.blue) > tolerance) {
	return false;
    }

    return true;
}

template <typename Stream, typename Pixel>
auto is::print_pixel(Stream& out, const Pixel& pixel) -> void{
    out << "red = " << static_cast<int>(pixel.red)
	<< ", green = " << static_cast<int>(pixel.green)
	<< ", blue = " << static_cast<int>(pixel.blue);
}

#endif
