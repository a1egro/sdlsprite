cmake_minimum_required(VERSION 3.16)
project(sdlsprite)

set(CMAKE_CXX_STANDARD 17)

# TODO:
set(SDL_SPRITE_INCLUDEDIR ../src)
#   auto-copy include files to include
#   install packages

add_library(sdlsprite STATIC
        src/visual/shapes/Line.cpp
        src/visual/shapes/Rectangle.cpp
        src/visual/shapes/Circle.cpp
        src/visual/texture/TextureBuffer.cpp
        src/visual/texture/TextureClip.cpp
        src/visual/Sprite.cpp
        src/utils/maths.cpp
        src/utils/uuid.cpp
        src/WindowManager.cpp
        src/BasicView.cpp
        src/Window.cpp
        src/View.cpp
        src/core/Transform.cpp
        src/core/GameObject.cpp
        src/core/Positionable.cpp
        src/visual/Animation.cpp
    )

target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image pthread)
