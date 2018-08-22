#pragma once
#include <glew.h>
#include "vertexbufferlayout.h"

namespace lord { namespace graphics {

	class VertexBuffer
	{
		GLuint					_vbo;
		VertexBufferLayout*		_layout;
	public:
		~VertexBuffer();
		void bind() const;
		inline GLuint getBuffer() const { return _vbo; }
		inline VertexBufferLayout* getLayout() const { return _layout; }
		static VertexBuffer* genVertexBuffer(const void* data, unsigned int size, VertexBufferLayout* layout);
	private:
		VertexBuffer(const void* data, unsigned int size, VertexBufferLayout* layout);
	};

}}