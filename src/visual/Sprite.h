//
// Created by alex on 05.03.22.
//

#ifndef GEXX_GAMEOBJECT_H
#define GEXX_GAMEOBJECT_H

#include "core/Movable.h"
#include "core/Rotatable.h"
#include "core/Drawable.h"
#include "visual/texture/TextureClip.h"
#include "core/Transform.h"
#include "core/GameObject.h"

class Sprite : public core::Drawable, public GameObject {
    std::shared_ptr<texture::TextureClip> mTextClip;
    Vec2f mScaling{1, 1};

 public:
    explicit Sprite(std::shared_ptr<texture::TextureClip> buff);

    explicit Sprite(const std::shared_ptr<texture::TextureBuffer> &buff, const SDL_Rect &clip = {0, 0, 0, 0});

    bool overlapsBB(const SDL_FRect &box) const override;

    void render(const Vec2f &origin) const override;

    [[nodiscard]] float getWidth() const { return mTextClip->getWidth() * mScaling.x; }

    [[nodiscard]] float getHeight() const { return mTextClip->getHeight() * mScaling.y; }

    [[nodiscard]] Vec2f getCenter() const;

    void setScale(float scale);

    void setScaling(Vec2f scaling);

    Vec2f getScaling() const;

    const std::shared_ptr<texture::TextureClip> &getTextureClip() const;
};

#endif //GEXX_GAMEOBJECT_H
