#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#define WAIT 25

#define JOY_A 0
#define JOY_B 1
#define JOY_X 2
#define JOY_Y 3
#define JOY_PLUS 10
#define JOY_MINUS 11
#define JOY_LEFT 12
#define JOY_UP 13
#define JOY_RIGHT 14
#define JOY_DOWN 15

#define SCREEN_W 1280
#define SCREEN_H 720

struct Game
{
    static SDL_Renderer* renderer;
    static SDL_Window* window;
    static bool running;
    static void Update();
    static void PollEvents();
    static void Start();
    static void Render();
    static void Quit();

};



SDL_Texture * render_text(SDL_Renderer *renderer, const char* text, TTF_Font *font, SDL_Color color, SDL_Rect *rect);