#ifndef game_hpp
#define game_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>

class Game
{
    public:
        Game();
        ~Game();

        void init(const char *title, int pos_x, int pos_y, int window_w, int windw_h, bool fullscreen);

        void handleEvents();
        void update();
        void render();
        void clean();

        bool running() {return is_running;}

    private:
        bool is_running;
        SDL_Window *window;
        SDL_Renderer *renderer;

};

#endif