#include "vertexbufferlayout.h"
#include "../defs.h"

namespace Lord1 { namespace graphics {

	VertexBufferLayout::VertexBufferLayout()
		: _stride(0)
	{
		_elements.reserve(10);
	}

	template<>
	void VertexBufferLayout::push<float>(unsigned int count)
	{
		_elements.push_back({ GL_FLOAT, count, false });
		_stride += count * getSizeOfType(GL_FLOAT);
	}

	template<>
	void VertexBufferLayout::push<unsigned int>(unsigned int count)
	{
		_elements.push_back({ GL_UNSIGNED_INT, count, false });
		_stride += count * getSizeOfType(GL_UNSIGNED_INT);
	}

	template<>
	void VertexBufferLayout::push<int>(unsigned int count)
	{
		_elements.push_back({ GL_INT, count, false });
		_stride += count * getSizeOfType(GL_INT);
	}

	template<>
	void VertexBufferLayout::push<unsigned char>(unsigned int count)
	{
		_elements.push_back({ GL_UNSIGNED_BYTE, count, false });
		_stride += count * getSizeOfType(GL_UNSIGNED_BYTE);
	}

	const std::vector<VertexBufferElement>& VertexBufferLayout::getElements() const
	{
		return _elements;
	}
}}