//
// Created by alex on 24.06.23.
//

#ifndef SDLSPRITE_TRANSFORM_H
#define SDLSPRITE_TRANSFORM_H

#include "Positionable.h"
#include "Movable.h"
#include "Rotatable.h"

#include "Component.h"
#include "functional"


namespace components {

class Transform : public Component, public core::Movable, public core::Rotatable {
 public:
    explicit Transform(GameObject *go, bool lockRot = false);
};

}


#endif //SDLSPRITE_TRANSFORM_H
