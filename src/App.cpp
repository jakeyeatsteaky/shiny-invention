#include "App.hpp"

App::App()
{

}

App::~App()
{
    SDL_GL_DeleteContext(m_glContext);
    SDL_DestroyWindow(m_window);
    SDL_Quit();

    delete m_window;
}

void App::Setup()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    m_window = SDL_CreateWindow("SDL OpenGL Example",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        800, 600,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    if (!m_window) {
        SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(m_window);
    if (!glContext) {
        SDL_Log("OpenGL context could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return;
    }

    glClearColor(0.1f, 0.1f, 0.4f, 1.0f);
}

void App::Input()
{
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
        SDL_GL_SwapWindow(m_window);
    }
}