//
// Created by alex on 03.03.22.
//

#include "TextureClip.h"

#include <SDL2/SDL_image.h>
#include <cassert>

texture::TextureClip::TextureClip(const std::shared_ptr<TextureBuffer> &buff, const SDL_Rect &clip)
{
    assert(buff->isInit());
    mBuff = buff;

    w = buff->getWidth();
    h = buff->getHeight();

    if (!SDL_RectEmpty(&clip)) {
        w = clip.w;
        h = clip.h;
        mClip = clip;
        mClipPtr = &mClip;
    }
}

void texture::TextureClip::renderAt(const Vec2f &pos, const double &rot, const Vec2f &scaling) const
{
    auto renderer = mBuff->getRenderer();

    SDL_FRect renderQuad = {pos.x, pos.y,
                            static_cast<float>(w) * scaling.x, static_cast<float>(h) * scaling.y};
    SDL_RenderCopyExF(renderer, mBuff->getTexture(), mClipPtr, &renderQuad,
                      rot / M_PI * 180.0, nullptr, SDL_FLIP_NONE);
    // TODO: additional functionality of SDL_RenderCopyExF is currently masked
}
