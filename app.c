#include <stdio.h>
#include "SDL.h"

int main() {

    // Initialize Window Variables
    int width;
    int height;

    // Read Image Details
    FILE* pfile = fopen("image.ppm", "r");
    int lineSize = 1000;
    char* string = (char *) malloc(lineSize * sizeof(char));

    // Get the dimensions of the image
    for (int i = 0; i < 4; i++){
        fgets(string, lineSize, pfile);
        if (i == 2) {
            sscanf(string, "%d %d", &width, &height);
        }
    }

    free(string);

    // Calculating the size of the lines
    lineSize = (width * 3) + 1;
    char line[lineSize];

    // Create Window 
    SDL_Window* pwindow = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    // Surface
    SDL_Surface* psurface = NULL;
    psurface = SDL_GetWindowSurface(pwindow);

    // Pixel
    SDL_Rect pixel;
    pixel.w = 1;
    pixel.h = 1;

    // Color
    Uint32 color = 0;
    Uint8 red, green, blue;

    // Draw Picture
    for (int y = 0; y < height; y++) {
        fgets(line, lineSize, pfile);
        for (int x = 0; x < width; x++) {
            int count = x * 3;
            red = (int) line[count];
            green = (int) line[count + 1];
            blue = (int) line[count + 2];
            color = SDL_MapRGB(psurface->format, red, green, blue);
            pixel.x = x;
            pixel.y = y;
            SDL_FillRect(psurface, &pixel, color);
        }
    }

    // Update Window
    SDL_UpdateWindowSurface(pwindow);

    fclose(pfile);
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
 - PAINT EACH PIXEL USING THE INFORMATION FROM THE IMAGE
 * */
