// $Id: shader.cpp,v 1.2 2016-05-09 16:01:56-07 - - $

#include <string>
#include <iostream> //cerr etc
#include <fstream> //ifstream
#include "shader.h"

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
static std::string LoadShader(const std::string& filename);
static GLuint CreateShader(const std::string& text, GLenum shaderType);

Shader::Shader(const std::string& filename){
    m_program = glCreateProgram();
    m_shaders[0] = CreateShader(LoadShader(filename + ".vs"), GL_VERTEX_SHADER);
    m_shaders[1] = CreateShader(LoadShader(filename + ".fs"), GL_FRAGMENT_SHADER);

    for(unsigned int i = 0; i < NUM_SHADERS; ++i){
        glAttachShader(m_program, m_shaders[i]);
    }

    glBindAttribLocation(m_program, 0, "position"); //tells what part to data to read as what var
    glBindAttribLocation(m_program, 1, "texCoord"); //see glsm files for where these should be.

    glLinkProgram(m_program); //linking like compiling code
    CheckShaderError(m_program, GL_LINK_STATUS, true, "Error: Program linking Failed: ");

    glValidateProgram(m_program); //validate 
    CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Program is invalid: ");

    m_uniforms[TRANSFORM_U] = glGetUniformLocation(m_program, "transform");
}

Shader::~Shader(){

    for(unsigned int i = 0; i < NUM_SHADERS; ++i){
        glDetachShader(m_program, m_shaders[i]);
        glDeleteShader(m_shaders[i]);
    }

    glDeleteProgram(m_program);
}

void Shader::Bind(){
    glUseProgram(m_program);
}

void Shader::Update(const Transform& transform, const Camera& camera){
    glm::mat4 model = camera.GetViewProjection() * transform.getModel();

    glUniformMatrix4fv(m_uniforms[TRANSFORM_U], 1, GL_FALSE, &model[0][0]);
}

static GLuint CreateShader(const std::string& text, GLenum shaderType){
    GLuint shader = glCreateShader(shaderType); //ERROR takes glenum param

    if(shader == 0)
        std::cerr << "Error: Shader creation failed!" << std::endl;

    const GLchar* shaderSourceStrings[1];
    GLint shaderSourceStringLengths[1];

    shaderSourceStrings[0] = text.c_str();
    shaderSourceStringLengths[0] = text.length();

    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
    glCompileShader(shader);

    CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed! : ");


    return shader;
}

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage){
	GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram){
        glGetProgramiv(shader, flag, &success);
    }else{
        glGetShaderiv(shader, flag, &success);
    }

    if(success == GL_FALSE){
        if(isProgram){
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        }else{
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);
        }

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}

static std::string LoadShader(const std::string& filename){
	std::ifstream file;
    file.open((filename).c_str());

    std::string output;
    std::string line;

    if(file.is_open()){
        while(file.good()){
            getline(file, line);
			output.append(line + "\n");
        }
    }else{
		std::cerr << "Unable to load shader: " << filename << std::endl;
    }

    return output;
}