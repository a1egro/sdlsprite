//
// Created by alex on 08.03.22.
//

#ifndef SDLSPRITE_ROTATABLE_H
#define SDLSPRITE_ROTATABLE_H

namespace core {

class Rotatable {

 public:
    Rotatable() : Rotatable(0) { }

    explicit Rotatable(double &&rot) : rotation(rot) { }

    virtual void setRotation(const double &rot) { if (!m_locked) rotation = rot; }

    /**
     * Change the rotation by the given delta.
     * Does nothing if rotation is locked
     *
     * @param delta the rotation difference in radian
     */
    virtual void spin(const double &delta) { if (!m_locked) rotation += delta; }

    [[nodiscard]] double getRotation() const { return rotation; }

    /**
     * Locks the rotatable disabling it from further changing its rotation.
     */
    void lockRotation() const { m_locked = true; }

    void unlockRotation() const { m_locked = false; }

 private:
    double rotation;
    mutable bool m_locked = false;
};

}

#endif //SDLSPRITE_ROTATABLE_H
