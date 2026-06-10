#include "ImageFilter.h"

cv::Mat NoFilter::apply(const cv::Mat& image) const {
    return image.clone();
}

cv::Mat GrayscaleFilter::apply(const cv::Mat& image) const {
    cv::Mat result;
    cv::cvtColor(image, result, cv::COLOR_BGR2GRAY);
    cv::cvtColor(result, result, cv::COLOR_GRAY2BGR);
    return result;
}

cv::Mat NegativeFilter::apply(const cv::Mat& image) const {
    cv::Mat result;
    cv::bitwise_not(image,image, result);
    return result;
}

cv::Mat SepiaFilter::apply(const cv::Mat& image) const {
    cv::Mat result;
    cv::Mat kernel = (cv::Mat_<float>(3, 3) <<
    0.131f, 0.534f, 0.272f,
    0.168f, 0.686f, 0.349f,
    0.189f, 0.769f, 0.393f);
    cv::transform(image, result, kernel);
    cv::convertScaleAbs(result, result);
    return result;
}