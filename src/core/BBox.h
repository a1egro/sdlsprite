//
// Created by alex on 06.03.22.
//

#ifndef TANO_BBOX_H
#define TANO_BBOX_H

#include <SDL2/SDL_rect.h>

namespace core {

struct BBox {
    float x, y, w, h;

    [[nodiscard]] bool overlaps(const SDL_FRect& rect) const {
        if (rect.w == 0 || rect.h == 0 || w == 0 || h == 0)
            return false;

        if (x > (rect.x + rect.w) || rect.x > (x + w))
            return false;

        if (y > (rect.y + rect.h) || rect.y > (y + h))
            return false;

        return true;
    }

    [[nodiscard]] SDL_FRect asSDL_FRect() const {
        return { x, y, w, h};
    }
};


}

#endif //TANO_BBOX_H
