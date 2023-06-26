//
// Created by alex on 24.06.23.
//

#ifndef SDLSPRITE_COMPONENT_H
#define SDLSPRITE_COMPONENT_H


class GameObject;

namespace components {

class Component {
 public:
    explicit Component(GameObject *go) : m_go(go) { }

    auto &getGameObject()
    {
        return *m_go;
    }

 private:
    GameObject *m_go;
};

}


#endif //SDLSPRITE_COMPONENT_H
