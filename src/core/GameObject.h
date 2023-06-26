//
// Created by alex on 24.06.23.
//

#ifndef SDLSPRITE_GAMEOBJECT_H
#define SDLSPRITE_GAMEOBJECT_H

#include "Transform.h"


class GameObject {
 public:
    GameObject() : GameObject(false) { }

    explicit GameObject(bool lock_rot) : transform(this, lock_rot) { }

    explicit GameObject(const Vec2f &position, bool lock_rot = false) : transform(this, lock_rot)
    {
        getTransform().setPosition(position);
    }

    [[nodiscard]] inline components::Transform &getTransform()
    {
        return transform;
    }

    [[nodiscard]] inline const components::Transform &getTransform() const
    {
        return transform;
    }

 private:
    components::Transform transform;
};


#endif //SDLSPRITE_GAMEOBJECT_H
