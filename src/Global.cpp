#include "Global.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <switch.h>
#include <vector>
#include <string>
#include "Wheel.hpp"

bool Game::running = false;
SDL_Renderer *Game::renderer = nullptr;
SDL_Window *Game::window = nullptr;
void Game::Update() {}

std::vector<std::string> str_arr;
Wheel *wheel = new Wheel(str_arr);

void Game::Quit()
{
    running = false;
    IMG_Quit();
    Mix_CloseAudio();
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
    romfsExit();
    delete wheel;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Game::Render()
{
    SDL_RenderClear(renderer);
    wheel->render();
    SDL_RenderPresent(renderer);
}

void Game::PollEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_JOYBUTTONDOWN:
            if (event
                    .jbutton.button == JOY_PLUS)
            {
                Quit();
            }
        default:
            continue;
        }
    }
}

void Game::Start()
{
    running = true;
    romfsInit();
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    SDL_JoystickEventState(SDL_ENABLE);
    SDL_JoystickOpen(0);

    window = SDL_CreateWindow("wheel of isaac", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}
SDL_Texture *render_text(SDL_Renderer *renderer, const char *text, TTF_Font *font, SDL_Color color, SDL_Rect *rect)

{

    SDL_Surface *surface;

    SDL_Texture *texture;

    surface = TTF_RenderText_Solid(font, text, color);

    texture = SDL_CreateTextureFromSurface(renderer, surface);

    rect->w = surface->w;

    rect->h = surface->h;

    SDL_FreeSurface(surface);

    return texture;
}
