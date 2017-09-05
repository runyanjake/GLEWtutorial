// $Id: graphics.cpp,v 1.2 2016-05-09 16:01:56-07 - - $

#include "graphics.h"

basic_window::basic_window(std::string n, int w, int h): win_width(w), win_height(h) {
	win_obj = SDL_CreateWindow(win_name.c_str(), \
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, \
		w, h, SDL_WINDOW_OPENGL);
	win_glcontext = SDL_GL_CreateContext(win_obj);
	win_name = n;
}

basic_window::~basic_window(){
	SDL_GL_DeleteContext(win_glcontext);
	SDL_DestroyWindow(win_obj);
	win_name = "";
}


void basic_window::swapbuffers(){
	SDL_GL_SwapWindow(win_obj);
}

