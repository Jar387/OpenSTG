#include <log4c.h>
#include <openstg.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(){
    init_logger(DEBUG, NULL);
    info("starting openstg engine");
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)<0){
        error("cannot initialize sdl2");
        exit(-1);
    }

    SDL_Window* window = SDL_CreateWindow("OpenSTG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if(!window){
        error("cannot create window");
        exit(-1);
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer){
        error("cannot create renderer");
        exit(-1);
    }
    IMG_Init(IMG_INIT_PNG);
    SDL_Texture* texture = IMG_LoadTexture(renderer, "../rsrc/pl00.png");
    if(!texture){
        error("cannot load texture %s", IMG_GetError());
    }
    SDL_Event e;
    int quit = 0;
    while(!quit){
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }
        SDL_Rect srcRect;
        srcRect.x = 0; // x position in the texture
        srcRect.y = 0; // y position in the texture
        srcRect.w = 256; // width of the part of the texture
        srcRect.h = 256; // height of the part of the texture

        // Define the destination rectangle (position in the window)
        SDL_Rect dstRect;
        dstRect.x = 0; // x position in the window
        dstRect.y = 0; // y position in the window
        dstRect.w = 256; // width of the destination
        dstRect.h = 256; // height of the destination

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
        SDL_RenderPresent(renderer);
    }
    return 0;
}