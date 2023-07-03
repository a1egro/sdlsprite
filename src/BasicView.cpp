//
// Created by alex on 27.01.22.
//

#include "BasicView.h"

#define DRAW_BBOX false

void BasicView::render() const
{
    SDL_FRect renderQuad{origin.x, origin.y, 0, 0};
    renderQuad.w = static_cast<float>(screenWidth);
    renderQuad.h = static_cast<float>(screenHeight);

    for (const auto &d: m_drawables) {
        if (!d->getHidden() && d->overlapsBB(renderQuad)) {
            d->render(origin);
        }
    }

    if constexpr (DRAW_BBOX) {
        SDL_Color oColor;
        SDL_GetRenderDrawColor(m_renderer, &oColor.r, &oColor.g, &oColor.b, &oColor.a);
        SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);

        for (const auto &d: m_drawables) {
            auto bbox = d->getBBox().asSDL_FRect();
            bbox.x = bbox.x - origin.x;
            bbox.y = bbox.y - origin.y;
            SDL_RenderDrawRectF(m_renderer, &bbox);
        }

        SDL_SetRenderDrawColor(m_renderer, oColor.r, oColor.g, oColor.b, oColor.a);
    }

    SDL_RenderPresent(m_renderer);
}
