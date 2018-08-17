#include "vertexarray.h"
#include <iostream>
#include "../defs.h"

namespace Lord1 { namespace graphics {

	VertexArray::VertexArray()
		: _numAttributes(0)
		, _ibo(nullptr)
	{
		GLCALL(glGenVertexArrays(1, &_vao));
		_vbos.reserve(10);
	}

	VertexArray::~VertexArray()
	{
		for (auto& vbo : _vbos)
		{
			delete vbo;
		}
		delete _ibo;
		GLCALL(glDeleteVertexArrays(1, &_vao));
	}

	void VertexArray::setIndices(const std::vector<unsigned int>& indices)
	{
		bind();
		_ibo = new IndexBuffer(indices);
	}

	void VertexArray::push(VertexBuffer* vbo)
	{
		if (!vbo)
		{
			std::cerr << "[ERROR] could not push VertexBuffer: vbo is nullptr!" << std::endl;
			return;
		}
		bind();
		vbo->bind();
		VertexBufferLayout* layout = vbo->getLayout();
		const auto& elements = layout->getElements();
		unsigned int offset = 0;
		for (const auto& element : elements)
		{
			GLCALL(glEnableVertexAttribArray(_numAttributes));
			GLCALL(glVertexAttribPointer(_numAttributes, element.count, element.type, 
				element.normalized, layout->getStride(), (const void*)offset));
			++_numAttributes;
			offset += element.count * getSizeOfType(element.type);
		}
		_vbos.push_back(vbo);
	}

	void VertexArray::bind() const
	{
		GLCALL(glBindVertexArray(_vao));
	}

}}