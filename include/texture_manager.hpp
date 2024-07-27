#pragma once

#include "game.hpp"


class TextureManager
{
    public:
        static SDL_Texture* load_texture(const char* file_name, SDL_Renderer* ren);
};