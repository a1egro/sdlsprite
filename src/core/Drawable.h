//
// Created by alex on 05.03.22.
//

#ifndef TANO_DRAWABLE_H
#define TANO_DRAWABLE_H

#include <SDL2/SDL_render.h>
#include <cassert>

#include "utils/Units.h"
#include "utils/uuid.h"
#include "BBox.h"

#define UNPACK_COL(col) col.r, col.g, col.b, col.a

namespace core {

class Drawable {
    ulong mUuid;
 protected:
    SDL_Renderer *mRenderer = nullptr;
    mutable BBox mBbox;
    bool mHidden = false;

 public:
    Drawable() : mUuid(uuid::getRng()) { }

    virtual void setRenderer(SDL_Renderer *renderer)
    {
        mRenderer = renderer;
    }

    [[nodiscard]] SDL_Renderer *getRenderer() const { return mRenderer; }

    virtual bool overlapsBB(const SDL_FRect &box) const { return mBbox.overlaps(box); };

    bool operator==(const Drawable &o) const
    {
        return mUuid == o.mUuid;
    }

    bool operator!=(const Drawable &o) const
    {
        return !operator==(o);
    }

    const auto &getBBox() const { return mBbox; }

    virtual void render(const Vec2f &origin) const = 0;

    void hide() { mHidden = true; }

    void show() { mHidden = false; }

    bool getHidden() const { return mHidden; }
};

}

#endif //TANO_DRAWABLE_H
