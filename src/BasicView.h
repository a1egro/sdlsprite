//
// Created by alex on 27.01.22.
//

#ifndef TANO_VIEW_H
#define TANO_VIEW_H

#include <cstdlib>
#include <SDL2/SDL.h>
#include <list>
#include <memory>

#include "View.h"

class BasicView : public View {
 public:
    BasicView() = default;

    void render() const override;
};


#endif //TANO_VIEW_H
