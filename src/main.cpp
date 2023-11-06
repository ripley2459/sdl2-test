#include <glad/glad.h>
#include <SDL.h>
#include <glm/glm.hpp>

SDL_Window *window;
SDL_Renderer *renderer;

void tick() {
    bool running = true;
    SDL_Event event;

    int posX = 0;
    int posY = 0;
    const SDL_Rect rect{20, 20, 100, 50};

    while (running) {
        // Close window with any input
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN) {
                running = false;
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 100, 100, 180, 255);
        SDL_RenderClear(renderer); // Clear

        if (++posX >= 800) posX = 1;
        if (++posY >= 600) posY = 1;

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawPoint(renderer, posX, posY);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderDrawRect(renderer, &rect);

        SDL_RenderPresent(renderer); // Update
        SDL_Delay(1000);
    }
}

int main(int argc, char *args[]) {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Blank Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    tick();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
