// $Id: texture.h,v 1.2 2016-05-09 16:01:56-07 - - $

#ifndef __TEXTURE_H__
#define __TEXTURE_H__

//NOTE: All textures loaded from hard disk using stbimage. other implementations out there.

#include <string>

#ifdef __APPLE__
#include <OpenGL/gl3.h> 
#include <OpenGL/gl3ext.h> 
#else
#include <GL/glew.h>
#endif

class Texture{
private:
	GLuint m_texture;
public:
	Texture(const std::string& filename); //default ctor override
	Texture(const Texture& m) = delete; //delete copy ctor
	Texture(Texture&& m) = delete; //delete move ctor
	Texture& operator=(const Texture& m) = delete; //delete copy opr
	Texture& operator=(Texture&& m) = delete; //delete move opr
	virtual ~Texture(); //default dtor override

	void Bind(unsigned int unit); //1-31
};






#endif