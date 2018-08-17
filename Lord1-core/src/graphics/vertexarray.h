#pragma once
#include "glew.h"
#include "vertexbuffer.h"
#include "indexbuffer.h"
#include <vector>

namespace Lord1 { namespace graphics {

class VertexArray
{
	GLuint							_vao;
	std::vector<VertexBuffer*>		_vbos;
	const IndexBuffer*				_ibo;
	unsigned int					_numAttributes;
public:
	VertexArray();
	~VertexArray();
	void push(VertexBuffer* vbo);
	void setIndices(const std::vector<unsigned int>& indices);
	inline const IndexBuffer* getIndexBuffer() const { return _ibo; }
	void bind() const;
};

}}