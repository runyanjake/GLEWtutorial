// $Id: graphics.h,v 1.2 2016-05-09 16:01:56-07 - - $

#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <string>
#include <GL/glew.h>
#include <SDL2/SDL.h>

#include "extern.h"

class basic_window{
private:
	std::string win_name; //empty string if anything other than filename.
	SDL_Window* win_obj;
	SDL_GLContext win_glcontext;
	int win_width, win_height;
	bool win_isclosed;
public:
	basic_window(std::string n, int w, int h); //default ctor override
	basic_window(const basic_window& win) = delete; //delete copy ctor
	basic_window(basic_window&& win) = delete; //delete move ctor
	basic_window& operator=(const basic_window& win) = delete; //delete copy opr
	basic_window& operator=(basic_window&& win) = delete; //delete move opr
	~basic_window(); //default dtor override

	void swapbuffers(); //like glut swapbuffers
	bool isclosed();
};

#endif