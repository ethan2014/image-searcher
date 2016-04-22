#ifndef COLOR_HISTOGRAM_HPP
#define COLOR_HISTOGRAM_HPP

#include "image-searcher/image-searcher.hpp"

#include <png++/png.hpp>

#include <algorithm>
#include <vector>
#include <utility>

namespace is {

template<typename Pixel>
using Histogram = std::vector<std::pair<Pixel, int>>;

template <typename Pixel, typename T>
auto get_color_histogram(const png::image<Pixel>& image, const T tolerance);

template <typename Pixel, typename T>
auto similar_histograms(const Histogram<Pixel>& a, const Histogram<Pixel>& b);

}

template <typename Pixel, typename T>
auto is::get_color_histogram(const png::image<Pixel>& image, const T tolerance) {
    auto histogram = Histogram<Pixel>{};

    const auto height = image.get_height();
    const auto width = image.get_width();

    using SizeType = decltype(width);

    for (auto row = SizeType{ 0 }; row < height; row++) {
	for (auto col = SizeType{ 0 }; col < width; col++) {
	    const auto pixel = image.get_pixel(col, row);

	    const auto it = std::find_if(std::begin(histogram), std::end(histogram),
					 [&pixel, &tolerance] (const auto& p) {
					     return similar_pixels(pixel, p.first, tolerance);
					 });

	    if (it == std::end(histogram)) {
		histogram.push_back(std::make_pair(pixel, 1));
	    } else {
		it->second++;
	    }
	}
    }

    return histogram;
}

#endif
