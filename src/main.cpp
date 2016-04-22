#include "image-searcher/image-searcher.hpp"
#include "image-searcher/color-histogram.hpp"

#include <iostream>

auto main() -> int {
    const auto img = is::load_image("images/test.png");
    const auto histogram = is::get_color_histogram(img, 10);

    const auto size = img.get_width() * img.get_height();

    std::cout << "histrogram colors: " << std::endl;

    for (const auto& pixel : histogram) {
	is::print_pixel(std::cout, pixel.first);
	std::cout << ", count = " << pixel.second
		  << ", percentage = " << ((double)pixel.second / size * 100) << std::endl;
    }
}
