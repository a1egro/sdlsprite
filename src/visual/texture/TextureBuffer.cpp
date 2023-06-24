//
// Created by alex on 05.03.22.
//

#include "TextureBuffer.h"

#include <SDL2/SDL_image.h>
#include <cassert>

void texture::TextureBuffer::init(SDL_Renderer *renderer, const std::string &path)
{
    assert(renderer != nullptr);
    mRenderer = renderer;
    mPath = path;

    SDL_Surface *loadedSurface;
    if ((loadedSurface = IMG_Load(mPath.c_str())) == nullptr) {
        throw ResourceNotFoundError(mPath, IMG_GetError());
    }

    // remove color cyan background
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

    mTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);
    if (mTexture == nullptr) {
        throw CreateTextureError(mPath, SDL_GetError());
    } else {
        w = loadedSurface->w;
        h = loadedSurface->h;
    }

    // loaded surface no longer required
    SDL_FreeSurface(loadedSurface);

    mIsInit = true;
}

texture::TextureBuffer::~TextureBuffer()
{
    if (mTexture != nullptr) {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
    }
}

