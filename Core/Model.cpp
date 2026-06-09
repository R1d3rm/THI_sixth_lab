#include "Model.h"
#include <opencv2/imgproc.hpp>
#include <QFile>
#include <QByteArray>
#include <QString>
#include <vector>

bool ImageModel::loadImage(const std::wstring& path) {
    QString qpath = QString::fromStdWString(path);
    QFile file(qpath);
    if (!file.open(QIODevice::ReadOnly)) return false;

    QByteArray bytes = file.readAll();
    file.close();
    if (bytes.isEmpty()) return false;

    std::vector<uchar> fileData(bytes.begin(), bytes.end());
    cv::Mat data(fileData, true);
    originalImage = cv::imdecode(data, cv::IMREAD_COLOR);
    return !originalImage.empty();
}

void ImageModel::setBrightness(int b) {
    brightness = b;
}

void ImageModel::setFilterType(FilterFactory::FilterType type) {
    filterType = type;
}

cv::Mat ImageModel::getProcessed() const {
    if (originalImage.empty()) return cv::Mat();

    cv::Mat result;
    originalImage.convertTo(result, -1, 1.0, brightness);
    
    auto filter = FilterFactory::createFilter(filterType);
    result = filter->apply(result);
    
    return result;
}

void ImageModel::reset() {
    brightness = 0;
    filterType = FilterFactory::FilterType::None;
}