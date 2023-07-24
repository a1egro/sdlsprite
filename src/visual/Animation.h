//
// Created by alex on 25.12.22.
//

#ifndef SDLSPRITE_ANIMATION_H
#define SDLSPRITE_ANIMATION_H


#include <atomic>
#include <utility>
#include <vector>
#include <thread>

#include "Sprite.h"

class Animation : public core::Drawable, public core::Positionable {

    auto create_endless_runner()
    {
        return std::thread([this]
           {
               while (m_run) {
                   std::this_thread::sleep_for(m_pause_per_frame);

                   if (m_paused) continue;

                   auto new_val = (m_current_sprite_index + 1) % m_sprites.size();
                   m_current_sprite_index = new_val;
               }
           });
    }

    auto create_single_runner(bool close_loop)
    {
        return std::thread([this]
           {
               while (m_run && m_current_sprite_index + 1 < m_sprites.size()) {
                   std::this_thread::sleep_for(m_pause_per_frame);

                   if (m_paused) continue;

                   // no modulo needed
                   auto new_val = (m_current_sprite_index + 1);
                   m_current_sprite_index = new_val;
               }
               m_current_sprite_index = 0;
               m_run = false;
           });
    }

public:
    using sprite_vector_t = std::vector<Sprite>;

    Animation(sprite_vector_t sprites, double fps) :
            m_sprites(std::move(sprites)), m_current_sprite_index(0), m_run(false), m_paused(false), m_cleaned(true)
    {
        setFPS(fps);

        // assuming al sprites are of the same size
        assert(!m_sprites.empty());
        mBbox.w = m_sprites[0].getWidth();
        mBbox.h = m_sprites[0].getHeight();
    }

    void setFPS(double fps)
    {
        using namespace std::chrono;

        m_fps = fps;
        m_pause_per_frame = duration_cast<microseconds>(seconds(1) / fps);
        m_period = m_pause_per_frame * m_sprites.size();
    }

    auto getFPS() const
    {
        return m_fps;
    }

    void setPosition(const float &x, const float &y) override
    {
        setPosition({x, y});
    }

    void setPosition(const Vec2f &newPos) override
    {
        for (auto &frame: m_sprites) {
            frame.getTransform().setPosition(newPos);
        }
        core::Positionable::setPosition(newPos);
    }

    bool overlapsBB(const SDL_FRect &box) const override
    {
        // update mBbox just in time (don't update on every move)
        mBbox.x = getPosition().x;
        mBbox.y = getPosition().y;
        return Drawable::overlapsBB(box);
    }

    void render(const Vec2f &origin) const override
    {
        m_sprites[m_current_sprite_index].render(origin);
    }

    void start()
    {
        m_paused = false;
        if (m_run.exchange(true)) {
            return;
        }

        // maybe needs lock
        if (!m_cleaned.exchange(true)) {
            m_updater.join();
        }

        m_updater = create_endless_runner();
        m_cleaned = false;
    }

    void run_once(bool closed_loop = false)
    {
        // ignore if already running
        m_paused = false;
        if (m_run.exchange(true)) {
            return;
        }

        if (!m_cleaned.exchange(true)) {
            m_updater.join();
        }

        m_updater = create_single_runner(closed_loop);
        m_cleaned = false;
    }

    void pause()
    {
        m_paused = true;
    }

    void stop()
    {
        if (m_run.exchange(false)) {
            m_updater.join();
            m_current_sprite_index = 0;
            // TODO: lock
            m_cleaned = true;
        }
    }

    virtual ~Animation()
    {
        stop();
    }

private:
    sprite_vector_t m_sprites;
    std::atomic_size_t m_current_sprite_index;

    double m_fps;
    std::chrono::microseconds m_period;
    std::chrono::microseconds m_pause_per_frame;

    std::thread m_updater;
    std::atomic_bool m_run, m_paused, m_cleaned;
};


#endif //SDLSPRITE_ANIMATION_H
