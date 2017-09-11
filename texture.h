// $Id: texture.h,v 1.2 2016-05-09 16:01:56-07 - - $

#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <string>

class Texture{
private:
	
public:
	Texture(); //default ctor override
	Texture(const Texture& m) = delete; //delete copy ctor
	Texture(Texture&& m) = delete; //delete move ctor
	Texture& operator=(const Texture& m) = delete; //delete copy opr
	Texture& operator=(Texture&& m) = delete; //delete move opr
	virtual ~Texture(); //default dtor override
};






#endif