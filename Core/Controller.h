#pragma once
#include "Model.h"

class ImageController {
private:
    ImageModel model;

public:
    ImageController() = default;
    
    bool loadImage(const std::wstring& path);
    ImageModel* getModel() { return &model; }
    const ImageModel* getModel() const { return &model; }
};