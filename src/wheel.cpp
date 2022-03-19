#include "Wheel.hpp"

Wheel::Wheel(std::vector<std::string> str_array) {
    angle = 0;
    auto temp_img = IMG_Load("wheel.png");
    img = SDL_CreateTextureFromSurface(Game::renderer, temp_img);
    SDL_FreeSurface(temp_img);
    choices = str_array;
    rect.y = 1280/2;
    rect.x = 720/2;
    rect.h = 474;
    rect.w = 474;
    
}
void Wheel::render() {
    SDL_Rect srcrect;
    srcrect.x = 0;
    srcrect.y = 0;
    srcrect.w = 32;
    srcrect.h = 32;
    SDL_RenderCopyEx(Game::renderer, img, &srcrect, &rect, angle, NULL, SDL_FLIP_NONE);
}

Wheel::~Wheel() {
    SDL_DestroyTexture(img);
}