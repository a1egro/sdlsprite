//
// Created by alex on 16.07.23.
//

#ifndef SDLSPRITE_TEST_CLICKABLE_H
#define SDLSPRITE_TEST_CLICKABLE_H


#include "GameObject.h"

namespace core {

/**
 * An arbitrary game object that can be clicked.
 * The implementation needs to define, whether the game object was clicked given the relative position to its center.
 * The center is defined by the position of its transform.
 * This allows clickable of any shapes.
 * Common shapes are covered by specializations like TODO: Button (rectangle) or CircularButton (circle).
 */
class Clickable : public GameObject {

 public:
    Clickable() = default;

    explicit Clickable(bool lockRot) : GameObject(lockRot) { }

    Clickable(const Vec2f &position, bool lockRot) : GameObject(position, lockRot) { }

 public:
    /**
     * Check whether the Clickable was clicked.
     * The position passed is relative to the center of the clickable, defined by the position of its transform.
     *
     * @param relativePos the position where the click happened relative to
     * @return true if the clickable was clicked, false otherwise
     */
    virtual bool isClicked(const Vec2f &relativePos) const = 0;

    /**
     * Called by the view when the clickable was actually clicked, determined by the above function.
     *
     * @param relativePos the position relative to its center, where the click happened
     */
    virtual void onClicked(const Vec2f &relativePos) = 0;

    /**
     * Get the maximal relative distance **squared** a click can be away from the center of the clickable and still possible
     * to click it.
     * This may be used for filtering multiple clickable objects before calling their individual isClicked(..)
     * implementations.
     *
     * @return the maximal relative distance from the center where a click can still happen
     */
    virtual double getMaxClickDistance2() const = 0;
};

}


#endif //SDLSPRITE_TEST_CLICKABLE_H
