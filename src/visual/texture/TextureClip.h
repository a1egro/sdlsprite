//
// Created by alex on 03.03.22.
//

#ifndef TANO_TEXTURECLIP_H
#define TANO_TEXTURECLIP_H


#include <SDL2/SDL.h>
#include <string>
#include <memory>
#include "utils/Units.h"
#include "TextureBuffer.h"

namespace texture {

class TextureClip {
    std::shared_ptr<TextureBuffer> mBuff;
    SDL_Rect mClip{};
    SDL_Rect *mClipPtr;
    int w, h;

 public:
    explicit TextureClip(const std::shared_ptr<TextureBuffer> &buff, const SDL_Rect &clip = {0, 0, 0, 0});

    void renderAt(const Vec2f &pos, const double &rot = 0, const Vec2f &scaling = {1, 1}) const;

    [[nodiscard]] int getWidth() const { return w; }

    [[nodiscard]] int getHeight() const { return h; }
};

}

#endif //TANO_TEXTURECLIP_H
