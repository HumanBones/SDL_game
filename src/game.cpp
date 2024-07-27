#include "game.hpp"
#include "texture_manager.hpp"


SDL_Texture *player_texture;
SDL_Rect srcc, dest;


Game::Game()
{
}

Game::~Game()
{    
}

void Game::init(const char *title, int pos_x, int pos_y, int window_w, int window_h, bool fullscreen)
{
    int flags = 0;

    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL initialised !" << std::endl;

        window = SDL_CreateWindow(title, pos_x, pos_y, window_w, window_h, flags);
        if (window)
        {
            std::cout << "Window created" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }

        is_running = true;

        player_texture = TextureManager::load_texture("assets/player.png",renderer);

    }
    else { is_running = false;}
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        is_running = false;
        break;
    
    default:
        break;
    }

}

void Game::update()
{
    dest.h = 128;
    dest.w = 128;
    dest.x += 1;

}

void Game::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, player_texture, NULL, &dest);
    //Add stuff to render
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "All clean" << std::endl;
}