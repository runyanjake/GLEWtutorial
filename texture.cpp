// $Id: texture.cpp,v 1.2 2016-05-09 16:01:56-07 - - $

#include <cassert>
#include <iostream>

#include "texture.h"
#include "stb_image.h"


Texture::Texture(const std::string& filename){
    int width, height, numComponents; //changed from unsigned
    unsigned char* imageData = stbi_load(filename.c_str(), &width, &height, &numComponents, 4); //4 is feature of image loader

    if(imageData == NULL){
        std::cerr << "Texture loading failed for texture " << filename << std::endl;
    }

    glGenTextures(1, &m_texture);
    glBindTexture(GL_TEXTURE_2D, m_texture); //there are other textures

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

    stbi_image_free(imageData);
}

Texture::~Texture(){
    glDeleteTextures(1, &m_texture);
}

void Texture::Bind(unsigned int unit){ //which texture we want
    assert(unit >= 0 && unit <= 31);

    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, m_texture);
}
