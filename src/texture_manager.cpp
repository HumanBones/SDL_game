#include "texture_manager.hpp"

SDL_Texture* TextureManager::load_texture(const char* texture, SDL_Renderer * ren)
{
    SDL_Surface* temp_surface = IMG_Load(texture);
    SDL_Texture* text = SDL_CreateTextureFromSurface(ren, temp_surface);
    SDL_FreeSurface(temp_surface);

    return text;
}