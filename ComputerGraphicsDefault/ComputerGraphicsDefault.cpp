// ComputerGraphicsDefault.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <glad.h>
#ifdef __APPLE__
#include <SDL2/SDL.h>
#elif _WIN32
#include <SDL.h>
#endif

int main(int argc, char** argv)
{
		SDL_Init(SDL_INIT_VIDEO);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
		SDL_Window* window = SDL_CreateWindow("OpenGL", 0, 0, 1280, 720, SDL_WINDOW_OPENGL);
		if (window == nullptr)
		{
			std::cout << "Failed to create SDL Window" << std::endl;
			SDL_Quit();
			return -1;
		}
		SDL_GLContext context = SDL_GL_CreateContext(window);
		if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			SDL_Quit();
			return -2;
		}
		SDL_Event windowEvent;
		while (true)
		{
			if (SDL_PollEvent(&windowEvent))
			{
				if (windowEvent.type == SDL_QUIT) break;
			}
			glClearColor(0.0f, 0.0f, 0.0f, 0.3f);
			glClear(GL_COLOR_BUFFER_BIT);
			SDL_GL_SwapWindow(window);
		}
		SDL_GL_DeleteContext(context);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 0;
}
