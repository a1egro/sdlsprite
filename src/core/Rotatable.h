//
// Created by alex on 08.03.22.
//

#ifndef TANO_ROTATABLE_H
#define TANO_ROTATABLE_H

namespace core {

class Rotatable {
 protected:
    double rotation;

 public:
    Rotatable() : Rotatable(0) { }

    explicit Rotatable(double &&rot) : rotation(rot) { }

    virtual void setRotation(const double &rot) { rotation = rot; }

    [[nodiscard]] double getRotation() const { return rotation; }
};

}

#endif //TANO_ROTATABLE_H
