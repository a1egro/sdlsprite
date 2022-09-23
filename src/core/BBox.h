//
// Created by alex on 06.03.22.
//

#ifndef TANO_BBOX_H
#define TANO_BBOX_H

#include <SDL2/SDL_rect.h>

namespace core {

struct BBox {
    float x, y, w, h;

    bool intersects(const SDL_FRect& rect) const {
        auto d1x = static_cast<float>(rect.x) - (x + w);
        auto d1y = static_cast<float>(rect.y) - (y + h);
        auto d2x = x - static_cast<float>(rect.x + rect.w);
        auto d2y = y - static_cast<float>(rect.y + rect.h);

        if (d1x > 0.0 || d1y > 0.0)
            return false;

        if (d2x > 0.0 || d2y > 0.0)
            return false;

        return true;
    }
};


}

#endif //TANO_BBOX_H
