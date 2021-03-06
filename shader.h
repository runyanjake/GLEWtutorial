// $Id: fileio.h,v 1.2 2016-05-09 16:01:56-07 - - $

#ifndef __SHADER_H__
#define __SHADER_H__

#include <string>
#include <vector>

#include "transform.h"
#include "camera.h"

#ifdef __APPLE__
#include <OpenGL/gl3.h> 
#include <OpenGL/gl3ext.h> 
#else
#include <GL/glew.h>
#endif

class Shader{
private:
	enum{
		TRANSFORM_U,

		NUM_UNIFORMS
	};
	static const unsigned int NUM_SHADERS = 2; //change depending on type of shading being done
	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];
public:
	Shader(const std::string& filename); //default ctor override
	Shader(const Shader& m) = delete; //delete copy ctor
	Shader(Shader&& m) = delete; //delete move ctor
	Shader& operator=(const Shader& m) = delete; //delete copy opr
	Shader& operator=(Shader&& m) = delete; //delete move opr
	virtual ~Shader(); //default dtor override


	void Bind();
	void Update(const Transform& transform, const Camera& camera);
};






#endif