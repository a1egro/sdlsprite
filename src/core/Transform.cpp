//
// Created by alex on 24.06.23.
//

#include "Transform.h"

components::Transform::Transform(GameObject *go, bool lockRot) : Component(go)
{
    if (lockRot) lockRotation();
}


