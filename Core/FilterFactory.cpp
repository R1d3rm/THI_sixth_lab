#include "FilterFactory.h"

std::unique_ptr<ImageFilter> FilterFactory::createFilter(FilterType type) {
    switch (type) {
        case FilterType::Grayscale:
            return std::make_unique<GrayscaleFilter>();
        case FilterType::Negative:
            return std::make_unique<NegativeFilter>();
        case FilterType::Sepia:
            return std::make_unique<SepiaFilter>();
        case FilterType::None:
        default:
            return std::make_unique<NoFilter>();
    }
}

std::unique_ptr<ImageFilter> FilterFactory::createFilter(int type) {
    return createFilter(static_cast<FilterType>(type));
}