// $Id: mesh.h,v 1.2 2016-05-09 16:01:56-07 - - $

#ifndef __MESH_H__
#define __MESH_H__

#include <string>
#include <GLM/glm.hpp>
#include <SDL2/SDL.h>

#ifdef __APPLE__
#include <OpenGL/gl3.h> 
#include <OpenGL/gl3ext.h> 
#else
#include <GL/glew.h>
#endif

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
	void clear();
	void clear(float r, float g, float b, float a);
};

class Vertex{
private:
	glm::vec3 pos;
public:
	Vertex(const glm::vec3& p): pos(p){} //default ctor override
	// Vertex(const Vertex& m) = delete; //delete copy ctor
	// Vertex(Vertex&& m) = delete; //delete move ctor
	// Vertex& operator=(const Vertex& m) = delete; //delete copy opr
	// Vertex& operator=(Vertex&& m) = delete; //delete move opr
	~Vertex(); //default dtor override
	
};

class Mesh{
private:
	enum{
		POSITION_VB,

		NUM_BUFFERS,
	};
	GLuint m_VertexArrayObject; //may be sketch
	GLuint m_VertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawcount;
public:
	Mesh(Vertex* vertices, unsigned int numverts); //default ctor override
	Mesh(const Mesh& m) = delete; //delete copy ctor
	Mesh(Mesh&& m) = delete; //delete move ctor
	Mesh& operator=(const Mesh& m) = delete; //delete copy opr
	Mesh& operator=(Mesh&& m) = delete; //delete move opr
	~Mesh(); //default dtor override

	void draw();	
};

#endif