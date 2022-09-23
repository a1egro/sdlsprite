//
// Created by alex on 06.03.22.
//

#include "uuid.h"

unsigned long uuid::getRng() {
    static std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
    return gen();
}