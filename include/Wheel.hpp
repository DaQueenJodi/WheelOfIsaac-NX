#pragma once
#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Global.hpp"
class Wheel
{
private:
    std::vector<std::string> choices;
    SDL_Texture* img;
    double angle;
    SDL_Rect rect;
public:
    Wheel(std::vector<std::string> str_array);
    SDL_Texture* get_img();
    double get_angle();
    void render();
    ~Wheel();
    
};