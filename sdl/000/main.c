/*****************************************************************************/
/*   000/main.c                                                              */
/*                                                                           */
/*   By:      knznsmn                                                        */
/*   Email:   mail@jccesar.com                                               */
/*   Created: 2026/01/12 09:37:57                                            */
/*   Updated: 2026/01/12 09:37:57                                            */
/*                                                                           */
/*   Codes for days.                                                         */
/*****************************************************************************/

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "utilities.h"

Window window = {
    .title = "Learning SDL3",
    .width = 640,
    .height = 480
};


int main(int argc, char **argv) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow(window.title, window.width, window.height, SDL_WINDOW_RESIZABLE);
    if (!win) {
        SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
        SDL_Delay(10);
    }

    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}