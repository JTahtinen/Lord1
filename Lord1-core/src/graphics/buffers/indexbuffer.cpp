#include "indexbuffer.h"
#include <glew.h>
#include "../../defs.h"
#include "vertexbufferlayout.h"

namespace lord { namespace graphics {

	IndexBuffer::IndexBuffer(const std::vector<unsigned int>& indices)
	{
		_count = indices.size();
		GLCALL(glGenBuffers(1, &_ibo));
		bind();
		GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, _count * getSizeOfType(GL_UNSIGNED_INT), &indices[0], GL_STATIC_DRAW));
	}

	IndexBuffer::~IndexBuffer()
	{
		GLCALL(glDeleteBuffers(1, &_ibo));
	}

	void IndexBuffer::bind() const
	{
		GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo));
	}

	void IndexBuffer::unbind() const
	{
		GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}
}}