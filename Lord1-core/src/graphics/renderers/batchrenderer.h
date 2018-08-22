#pragma once
#include "../mesh.h"


namespace lord { namespace graphics {

class BatchRenderer
{
public:
	void push(const Mesh* renderable);
	void render();
};

}}