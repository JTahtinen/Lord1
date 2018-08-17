#pragma once
#include <array>
#include "vertexarray.h"
#include "mesh.h"

namespace Lord1 { namespace graphics {

	const int MAX_RENDERABLES = 50;

		class Renderer
		{
			std::array < const Mesh*, MAX_RENDERABLES>	_meshes;
			unsigned int _numMeshes;
		public:
			Renderer();
			void push(const Mesh* mesh);
			void render();
		};

}}