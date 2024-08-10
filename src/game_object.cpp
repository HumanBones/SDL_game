#include "game_object.hpp"
#include "texture_manager.hpp"

GameObject::GameObject(const char* texture_sheet, SDL_Renderer* ren, int x, int y)
{
    renderer = ren;
    obj_texture = TextureManager::load_texture(texture_sheet, ren);
    x_pos = x;
    y_pos = y;

}

void GameObject::update()
{

    x_pos++;
    y_pos++;

    source_rect.h = 32;
    source_rect.w = 32;
    source_rect.x = 0;
    source_rect.y = 0;

    dest_rect.x = x_pos;
    dest_rect.y = y_pos;
    dest_rect.w = source_rect.w * 2;
    dest_rect.h = source_rect.h * 2;

}

void GameObject::render()
{
    SDL_RenderCopy(renderer, obj_texture, &source_rect, &dest_rect);
}