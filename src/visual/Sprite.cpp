//
// Created by alex on 05.03.22.
//

#include "Sprite.h"

#include <utility>

Sprite::Sprite(std::shared_ptr<texture::TextureClip> buff) : mTextClip(std::move(buff)) {
    mBbox.x = 0;
    mBbox.y = 0;
    mBbox.w = static_cast<float>(mTextClip->getWidth());
    mBbox.h = static_cast<float>(mTextClip->getHeight());
}

Sprite::Sprite(const std::shared_ptr<texture::TextureBuffer> &buff, const SDL_Rect &clip) :
        Sprite(std::make_shared<texture::TextureClip>(buff, clip)) {

}

bool Sprite::intersectsBB(const SDL_FRect &box) const {
    // update mBbox just in time (don't update on every move)
    mBbox.x = position.x;
    mBbox.y = position.y;
    return Drawable::intersectsBB(box);
}

void Sprite::render(const Vec2f &origin) const {
    mTextClip->renderAt(position - origin, rotation, mScaling);
}

void Sprite::setScale(float scale) {
    mScaling.x = scale;
    mScaling.y = scale;
}

void Sprite::setScaling(Vec2f scaling) {
    mScaling = scaling;
}

Vec2f Sprite::getScaling() const {
    return mScaling;
}
