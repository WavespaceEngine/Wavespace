#ifndef VBO_H
#define VBO_H

#include<glad/glad.h>

class VBO {
public:
	GLuint ID;

	bool bound = false;

	GLsizeiptr size;
	const void* data;
	GLenum usage;

	VBO(GLsizeiptr pSize, const void* pData, GLenum pUsage = GL_STATIC_DRAW);

	void SetData(GLsizeiptr pSize, const void* pData, GLenum pUsage = GL_STATIC_DRAW);

	void Bind();

	void Unbind();

	void Close();
};

#endif