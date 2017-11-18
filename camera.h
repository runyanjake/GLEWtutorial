 // $Id: camera.h,v 1.2 2016-05-09 16:01:56-07 - - $

#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <GLM/glm.hpp>
#include <GLM/gtx/transform.hpp> 

class Camera{
private:
	glm::mat4 m_perspective;
	glm::vec3 m_position;
	glm::vec3 m_forward;
	glm::vec3 m_up;
public:
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar){
		m_perspective = glm::perspective(fov, aspect, zNear, zFar);
		m_position = pos;
		m_forward = glm::vec3(0,0,1); //can take that in rather than hardcode
		m_up = glm::vec3(0,1,0); //can take that in also
	} 
	Camera(const Camera& m) = delete; //delete copy ctor
	Camera(Camera&& m) = delete; //delete move ctor
	Camera& operator=(const Camera& m) = delete; //delete copy opr
	Camera& operator=(Camera&& m) = delete; //delete move opr
	//virtual ~Camera(); //Default destructor ok?
	
	inline glm::mat4 GetViewProjection() const{
		return m_perspective * glm::lookAt(m_position, m_position + m_forward, m_up);
	}
};

#endif