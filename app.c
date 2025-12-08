#include <stdio.h>
#include "SDL.h"

int main() {

    // Create Window 
    int width = 800;
    int height = 800;

    SDL_Window *pwindow = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    // Surface
    SDL_Surface *psurface = NULL;
    psurface = SDL_GetWindowSurface(pwindow);

    // Pixel
    SDL_Rect pixel;
    pixel.x = 100;
    pixel.y = 100;
    pixel.w = 2;
    pixel.h = 2;

    // Draw Rect
    SDL_FillRect(psurface, &pixel, 0xFF0000);

    // Update Window
    SDL_UpdateWindowSurface(pwindow);

    int running = 1;
    // Event Loop
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

    SDL_FreeSurface(psurface);
    SDL_DestroyWindow(pwindow);
    SDL_Quit();
    return EXIT_SUCCESS;
}

/*  ****  TODO  **** 
 - FILL THE SCREEN WITH PIXELS.
 - INPUT THE IMAGE.
 - MAKE SIZE OF THE SCREEN THE SAME AS THE SIZE OF THE IMAGE
 - PAINT EACH PIXEL USING THE INFORMATION FROM THE IMAGE
 * */
