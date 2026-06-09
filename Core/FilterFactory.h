#pragma once
#include <memory>
#include "ImageFilter.h"

class FilterFactory {
public:
    enum class FilterType { None = 0, Grayscale = 1, Negative = 2, Sepia = 3 };
    
    static std::unique_ptr<ImageFilter> createFilter(FilterType type);
    static std::unique_ptr<ImageFilter> createFilter(int type);
};