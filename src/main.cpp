#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <switch.h>
#include "Global.hpp"
#include "Wheel.hpp"

int main(int argv, char **argc)
{

    Game::Start();
    chdir("romfs:/");
    while (Game::running && appletMainLoop())
    {
        Game::PollEvents();
        Game::Update();
        Game::Render();
        SDL_Delay(WAIT); // pause for a bit every loop because vsync no worky and im too lazy to find a better solution :)
    }
}
