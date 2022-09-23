//
// Created by alex on 27.01.22.
//

#include "BasicView.h"

void BasicView::render() const {
    SDL_FRect renderQuad {origin.x, origin.y, 0, 0 };
    renderQuad.w = static_cast<float>(screenWidth);
    renderQuad.h = static_cast<float>(screenHeight);

    for(const auto &d: drawables) {
        if (!d->getHidden() && d->intersectsBB(renderQuad)) {
            d->render(origin);
        }
    }

    SDL_RenderPresent(mRenderer);
}
