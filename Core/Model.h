#pragma once
#include <opencv2/opencv.hpp>
#include "FilterFactory.h"

class ImageModel {
private:
    cv::Mat originalImage;
    int brightness = 0;
    FilterFactory::FilterType filterType = FilterFactory::FilterType::None;

public:
    bool loadImage(const std::wstring& path);
    void setBrightness(int b);
    void setFilterType(FilterFactory::FilterType type);
    cv::Mat getProcessed() const;
    void reset();
    
    // Геттеры для UI
    const cv::Mat& getOriginal() const { return originalImage; }
    int getBrightness() const { return brightness; }
    FilterFactory::FilterType getFilterType() const { return filterType; }
};