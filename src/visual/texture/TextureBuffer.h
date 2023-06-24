//
// Created by alex on 05.03.22.
//

#ifndef TANO_TEXTUREBUFFER_H
#define TANO_TEXTUREBUFFER_H

#include "utils/Units.h"
#include "exceptions/CreateTextureError.h"
#include "exceptions/ResourceNotFoundError.h"

#include <SDL2/SDL.h>
#include <string>

namespace texture {

class TextureBuffer {
    SDL_Texture *mTexture = nullptr;
    SDL_Renderer *mRenderer = nullptr;

    std::string mPath;

    bool mIsInit = false;
    int w = 0;
    int h = 0;

 public:
    TextureBuffer() = default;

    void init(SDL_Renderer *renderer, const std::string &path);

    [[nodiscard]] bool isInit() const { return mIsInit; }

    [[nodiscard]] int getWidth() const { return w; }

    [[nodiscard]] int getHeight() const { return h; }

    [[nodiscard]] SDL_Texture *getTexture() const { return mTexture; }

    [[nodiscard]] SDL_Renderer *getRenderer() const { return mRenderer; }

    ~TextureBuffer();
};

}

#endif //TANO_TEXTUREBUFFER_H
