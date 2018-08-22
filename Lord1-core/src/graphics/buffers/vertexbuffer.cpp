#include "vertexbuffer.h"
#include "vertexbufferlayout.h"
#include "../../defs.h"
#include <iostream>

namespace lord { namespace graphics {

	VertexBuffer::VertexBuffer(const void* data, unsigned int size, VertexBufferLayout* layout)
		: _layout(layout)
	{
		GLCALL(glGenBuffers(1, &_vbo));
		bind();
		GLCALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
	}

	VertexBuffer::~VertexBuffer()
	{
		GLCALL(glDeleteBuffers(1, &_vbo));
	}

	void VertexBuffer::bind() const
	{
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, _vbo));
	}

	VertexBuffer* VertexBuffer::genVertexBuffer(const void* data, unsigned int size, VertexBufferLayout* layout)
	{
		if (!data || !layout)
		{
			std::cerr << "[ERROR] Could not create Vertex buffer: invalid data!" << std::endl;
			return nullptr;
		}
		return new VertexBuffer(data, size, layout);
	}

}}