//
// Created by alex on 6/4/22.
//

#ifndef SDLSPRITE_VIEW_H
#define SDLSPRITE_VIEW_H

#include <list>
#include <memory>
#include "core/Drawable.h"
#include "core/Clickable.h"

class View {
 public:
    typedef core::Drawable drawable;
    typedef std::shared_ptr<drawable> sp_drawable;
    typedef core::Clickable clickable;
    typedef std::shared_ptr<clickable> sp_clickable;

 protected:
    std::list<sp_drawable> m_drawables;
    std::list<sp_clickable> m_clickable;
    mutable SDL_Renderer *m_renderer = nullptr;

    int screenWidth = 0, screenHeight = 0;
    Vec2f center = {0, 0};
    Vec2f origin;

    virtual void updateOrigin()
    {
        origin = center - Vec2i(screenWidth / 2, screenHeight / 2).cast<float>();
    }

 public:

    explicit View() = default;

    View(const View &) = delete;

    View(View &&) = delete;

    virtual ~View();

    void init(SDL_Window *window);

    void addDrawable(const sp_drawable &drawable);

    void addClickable(const sp_clickable &clickable);

    void removeDrawable(const sp_drawable &drawable);

    void removeClickable(const sp_clickable  &clickable);

    void processClick(const Vec2f& position);

    virtual void render() const = 0;

    void clear()
    {
        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
        SDL_RenderClear(m_renderer);
    }

    void resize(const int &width, const int &height);

    [[nodiscard]] SDL_Renderer *getRenderer() const { return m_renderer; }

    void setCenter(const Vec2f &newCenter);

    Vec2f getCenter() const { return center; }

    Vec2f getOrigin() const { return origin; }

    Vec2i getDimensions() const { return {screenWidth, screenHeight}; }
};


#endif //SDLSPRITE_VIEW_H
