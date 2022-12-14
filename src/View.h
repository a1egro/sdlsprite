//
// Created by alex on 6/4/22.
//

#ifndef SDLSPRITE_VIEW_H
#define SDLSPRITE_VIEW_H

#include <list>
#include <memory>
#include "core/Drawable.h"

class View {
public:
    typedef core::Drawable              element;
    typedef std::shared_ptr<element>    sPointer;

protected:
    std::list<sPointer> drawables;
    mutable SDL_Renderer *mRenderer = nullptr;

    int screenWidth = 0, screenHeight = 0;
    Vec2f center, origin;

    virtual void updateOrigin() {
        origin = center - Vec2i(screenWidth / 2, screenHeight / 2).cast<float>();
    }

public:

    explicit View() = default;
    View(const View&) = delete;
    View(View&&) = delete;

    virtual ~View();

    void init(SDL_Window* window);

    void addDrawable(const sPointer& drawable);

    void removeDrawable(const sPointer& drawable);

    virtual void render() const = 0;

    void clear() {
        SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 0);
        SDL_RenderClear(mRenderer);
    }

    void resize(const int& width, const int& height);

    [[nodiscard]] SDL_Renderer* getRenderer() const { return mRenderer; }

    void setCenter(const Vec2f& newCenter);

    Vec2f getCenter() { return center; }

    Vec2f getOrigin() { return origin; }
};


#endif //SDLSPRITE_VIEW_H
