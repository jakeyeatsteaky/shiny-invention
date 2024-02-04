#ifndef APP_HPP
#define APP_HPP

#include "SDL.h"
#include "SDL_opengl.h"



class App
{
public:
	~App();
	App();
	void Setup();
	void Input();
	void Update();
	void Render();

private:
	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	
};

#endif //end app.hpp