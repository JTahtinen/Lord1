#include "renderer.h"
#include <iostream>
#include <glew.h>
#include "../defs.h"

namespace Lord1 { namespace graphics {

	Renderer::Renderer()
		: _numMeshes(0)
	{			
	}

	void Renderer::push(const Mesh* mesh)
	{
		if (mesh && _numMeshes >= _meshes.size())
		{
			std::cerr << "[ERROR] Could not push mesh to renderer: mesh was nullptr!" << std::endl;
		}
		_meshes[_numMeshes++] = mesh;
	}

	void Renderer::render()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		for (unsigned int i = 0; i < _numMeshes; ++i)
		{
			auto* vao = _meshes[i]->getVertexArray();
			vao->bind();
			unsigned int indexCount = vao->getIndexBuffer()->getCount();
		
			GLCALL(glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, NULL));
		}
		_numMeshes = 0;
	}
}}