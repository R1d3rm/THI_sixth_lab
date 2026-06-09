#pragma once
#include <opencv2/opencv.hpp>

class ImageFilter {
public:
    virtual ~ImageFilter() = default;
    virtual cv::Mat apply(const cv::Mat& image) const = 0;
};

class NoFilter : public ImageFilter {
public:
    cv::Mat apply(const cv::Mat& image) const override;
};

class GrayscaleFilter : public ImageFilter {
public:
    cv::Mat apply(const cv::Mat& image) const override;
};

class NegativeFilter : public ImageFilter {
public:
    cv::Mat apply(const cv::Mat& image) const override;
};

class SepiaFilter : public ImageFilter {
public:
    cv::Mat apply(const cv::Mat& image) const override;
};