#pragma once
#include <vector>
namespace lord { namespace graphics {

	class IndexBuffer
	{
		unsigned int		_ibo;
		unsigned int		_count;
	public:
		IndexBuffer(const std::vector<unsigned int>& indices);
		~IndexBuffer();
		void bind() const;
		inline unsigned int getCount() const { return _count; }
		inline unsigned int getIbo() const { return _ibo; }
	};

}}