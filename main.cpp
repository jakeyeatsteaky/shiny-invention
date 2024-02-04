#include <iostream>
#include "SDL.h"
#include "SDL_opengl.h"

#include "App.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
	// Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    // Create an SDL window
    SDL_Window* window = SDL_CreateWindow("SDL OpenGL Example",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          800, 600,
                                          SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // Create an OpenGL context associated with the window.
    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        SDL_Log("OpenGL context could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Initialize OpenGL settings here (like glEnable, glClearColor, etc.)
    // For example, set the clear color to dark blue
    glClearColor(0.1f, 0.1f, 0.4f, 1.0f);

    bool running = true;
    SDL_Event event;
    while (running) {
        // Handle events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // OpenGL rendering goes here!
        // For example, draw a triangle, setup shaders, etc.

        // Swap the window buffers
        SDL_GL_SwapWindow(window);
    }

    // Clean up
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
	return 0;

}	
