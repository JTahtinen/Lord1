#pragma once
#include <glew.h>
#include <vector>

namespace lord { namespace graphics {

		struct VertexBufferElement
	{
		unsigned int				type;
		unsigned int				count;
		bool						normalized;
	};

	class VertexBufferLayout
	{
		std::vector<VertexBufferElement>	_elements;
		unsigned int						_stride;
	public:
		VertexBufferLayout();
		template <typename T>
		void push(unsigned int count);
		const std::vector<VertexBufferElement>& getElements() const;
		inline unsigned int getStride() const { return _stride; }

		static VertexBufferLayout defaultPositionLayout;
		static VertexBufferLayout defaultColorLayout;
	};

}}