//
// Created by alex on 24.06.23.
//

#ifndef SDLSPRITE_TIMEDEPENDENT_H
#define SDLSPRITE_TIMEDEPENDENT_H


class TimeDependent {
 public:
    virtual void update(float deltaT) = 0;
};


#endif //SDLSPRITE_TIMEDEPENDENT_H
