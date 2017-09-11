// $Id: texture.cpp,v 1.2 2016-05-09 16:01:56-07 - - $

#include "texture.h"
#include "stb_image.h"


Texture::Texture(const std::string& filename){
    unsigned int width, height, numComponents;
    unsigned char* imageData = stbi_load(filename.c_str(), &width, &height, &numComponents, 4); //4 is feature of image loader

    glGenTextures(1, &m_texture);
    glBindTexture(GL_TEXTURE_2D, m_texture); //there are other textures

    glTexParameteri(TL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(TL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTextParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTextParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG _FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

    stdi_image_free();
}

Texture::~Texture(){
    glDeleteTextures(1, &m_texture);
}

void Texture::Bind(unsigned int unit){

}
