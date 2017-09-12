// $Id: mesh.cpp,v 1.2 2016-05-09 16:01:56-07 - - $

#include <vector>

#include "mesh.h"


basic_window::basic_window(std::string n, int w, int h): win_name(n), win_width(w), win_height(h) {
	win_obj = SDL_CreateWindow(win_name.c_str(), \
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, \
		win_width, win_height, SDL_WINDOW_OPENGL);
	win_glcontext = SDL_GL_CreateContext(win_obj);
	win_name = n;
	win_isclosed = false;
}

basic_window::~basic_window(){
	SDL_GL_DeleteContext(win_glcontext);
	SDL_DestroyWindow(win_obj);
	win_name = "";
}


void basic_window::Update(){
	SDL_GL_SwapWindow(win_obj);
	SDL_Event e;
	while(SDL_PollEvent(&e)){
		if(e.type == SDL_QUIT){
			win_isclosed = true;
		}
	}
}

bool basic_window::isclosed(){
	return win_isclosed;
}

void basic_window::clear(){
	glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}


void basic_window::clear(float r, float g, float b, float a){
	glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

//-------------------------------------------

Vertex::~Vertex(){

}

//-------------------------------------------

Mesh::Mesh(Vertex* vertices, unsigned int numverts){
	m_drawcount = numverts;
	glGenVertexArrays(1, &m_VertexArrayObject);
	glBindVertexArray(m_VertexArrayObject);

	std::vector<glm::vec3> positions;
	positions.reserve(numverts);
	std::vector<glm::vec2> texCoords;
	texCoords.reserve(numverts);

	for(unsigned int i = 0; i < numverts; ++i){
		positions.push_back(*vertices[i].GetPos());
		texCoords.push_back(*vertices[i].GetTexCoord());
	}

	glGenBuffers(NUM_BUFFERS, m_VertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, numverts*sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_VertexArrayBuffers[TEXCOORD_VB]);
	glBufferData(GL_ARRAY_BUFFER, numverts*sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0); //Vertexarr operations past this dont affect mvao.

	//glBindVertexArray(1); //Vertexarr operations past this dont affect mvao.
}

Mesh::~Mesh(){
	glDeleteVertexArrays(1, &m_VertexArrayObject);
}

void Mesh::draw(){
	glBindVertexArray(m_VertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, m_drawcount);
	glBindVertexArray(0);
}
