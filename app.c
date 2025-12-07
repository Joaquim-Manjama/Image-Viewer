#include <stdio.h>
#include "SDL.h"

int main() {
    int width = 800;
    int height = 800;

    SDL_Window *pwindow = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    int running = 1;
    //Event Loop
    while (running) {
        
        SDL_Event event;
        while (SDL_PollEvent(&event)) {  // poll until all events are handled!
            // decide what to do with this event.
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        // update game state, draw the current frame
    }
}

/*  ****  TODO  **** 
 - FILL THE SCREEN WITH PIXELS.
 - INPUT THE IMAGE.
 - MAKE SIZE OF THE SCREEN THE SAME AS THE SIZE OF THE IMAGE
 - PAINT EACH PIXEL USING THE INFORMATION FROM THE IMAGE
 * */
