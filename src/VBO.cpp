#include<VBO.hpp>

VBO::VBO(GLsizeiptr pSize, const void* pData, GLenum pUsage) {

	size = pSize;
	data = pData;
	usage = pUsage;

	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);

	this->bound = true;
}

void VBO::SetData(GLsizeiptr pSize, const void* pData, GLenum pUsage) {
	size = pSize;
	data = pData;
	usage = pUsage;

	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
}

void VBO::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Close() {
	glDeleteBuffers(1, &ID);
}