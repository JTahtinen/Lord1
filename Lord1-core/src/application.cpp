#include "application.h"
#include <SDL.h>
#include "input\input.h"
#include <iostream>
#include <glew.h>
#include "util\file_load.h"
#include "graphics\vertexarray.h"
#include "graphics\vertexbuffer.h"
#include "graphics\shader.h"
#include "graphics\renderer.h"
#include "graphics\indexbuffer.h"
#include "graphics\mesh.h"
#include "math\vec4.h"
#include "math\vec2.h"
#include "math\mat4.h"
#include "math\math.h"

namespace Lord1
{
	Application::Application(const char* title)
		: _window(1920, 1080, title)
	{
		Application::initEngine();
	}

	Application::~Application()
	{
	}

	void Application::run()
	{
		using namespace input;
		using namespace math;
		bool running = true;

		Vec4 p1(0, 0, 0, 0);
		Vec4 p2(2.0f, 3.0f, 1.5, 0.5);
	
		Lerp(p1, p2, 0.5f).print();

		//GL TEST DATA

		float fov = 70.0f;
		Matrix4f perspective = Matrix4f::perspective(TO_RADIANS(fov), TO_RADIANS(fov / 16.0f * 9.0f), 0.1f, 200.0f);
		Matrix4f ortho = Matrix4f::ortho(-1.0f, 1.0f, 1.0f, -1.0f, 200.0f, 0.1f);
		Matrix4f translation = Matrix4f::translation(Vec4(0, 0, -1.0f, 0));

		Renderer renderer;
		// DATA 
		//------------------------------------------------------------------
		Vec4 vertices[] = {
			Vec4(-0.5f, -0.5f, -2.0f, 1.0f), Vec4(0.0f, 0.5f, -2.0f, 1.0f), Vec4(0.5f, -0.5f,  -2.0f, 1.0f),
			Vec4(-0.2f, 0.8f,  -2.3f, 1.0f), Vec4(0.0f, 0.8f, -2.6f, 1.0f), Vec4(-0.9f, -0.9f, -3.0f, 1.0f)
		};

		Vec4 verticesB[] = {
			Vec4(0.8f, -0.2f, 0.0f, 1.0f), Vec4(0.7f, -0.3f, 0.0f, 1.0f), Vec4(0.75f, -0.4f, 0.0f, 1.0f),
		};
		Vec4 colors[] = {Vec4(1, 0, 1, 1), Vec4(0, 0, 1, 1), Vec4(0.5f, 0.9f, 0.65f, 1),
			Vec4(1, 0, 0, 1), Vec4(1, 0, 1, 1), Vec4(0, 0.5f, 0, 1) };

		unsigned int indices[] = { 0, 1, 2, 3, 4, 5 };
		unsigned int indicesB[] = { 0, 1, 2 };
		// ----------------------------------------------

		//IndexBuffer iboB(indicesB, 3);
	//	IndexBuffer ibo(indices, 6);

		std::vector<Vertex> vertexList;

		for (unsigned int i = 0; i < 6; ++i)
		{
			vertexList.emplace_back(Vertex(vertices[i], colors[i]));
		}


		std::vector<Vertex> vertexListB;
		for (unsigned int i = 0; i < 3; ++i)
		{
			vertexListB.emplace_back(Vertex(verticesB[i], colors[i]));
		}

		std::vector<unsigned int> indexList;
		for (unsigned int i = 0; i < 6; ++i)
		{
			indexList.push_back(indices[i]);
		}

		std::vector<unsigned int> indexListB;
		for (unsigned int i = 0; i < 3; ++i)
		{
			indexListB.push_back(indicesB[i]);
		}

		Mesh mesh(vertexList, indexList);
		Mesh meshB(vertexListB, indexListB);

		Shader* shader = Shader::generateShader("res/shaders/basic");
		shader->bind();
		shader->setUniformMat4("u_mvp", translation * perspective);

	/*	
		glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			GLchar error[1024] = { 0 };
			std::cout << "could not compile vertexshader!" << std::endl;
			glGetProgramInfoLog(vertexshader, sizeof(error), NULL, error);
			std::cerr << error << std::endl;
		}
		glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			std::cout << "could not compile fragmentshader!" << std::endl;
		}	
*/
		//-----
		
		Input& input = Input::instance();
		bool add = false;
		float z = -1.0f;
		float x = 0.0f;
		Matrix4f* projection = &ortho;
		while (running)
		{
			translation = Matrix4f::translation(Vec4(x, 0, z, 0.0f));
			shader->setUniformMat4("u_mvp", *projection * translation);
			renderer.push(&mesh);
			if (add)
			renderer.push(&meshB);
			input.update();
			if (input.poll(KEY_T)) z += 0.01f;
			if (input.poll(KEY_G)) z -= 0.01f;
			if (input.poll(KEY_F)) x += 0.01f;
			if (input.poll(KEY_H)) x -= 0.01f;
			if (input.poll(KEY_O))
			{
				fov += 0.01f; perspective = Matrix4f::perspective(TO_RADIANS(fov), TO_RADIANS(fov), 0.1f, 200.0f); 
				std::cout << "Fov: " << fov << std::endl;
			}
			if (input.poll(KEY_I)) 
			{ 
				fov -= 0.01f; perspective = Matrix4f::perspective(TO_RADIANS(fov), TO_RADIANS(fov), 0.1f, 200.0f); 
				std::cout << "Fov: " << fov << std::endl;
			}
			if (input.poll(KEY_M, KEYSTATE_TYPED))
			{
				if (projection == &ortho)
				{
					projection = &perspective;
				}
				else
				{
					projection = &ortho;
				}
			}
			if (input.poll(KEY_ESCAPE))	running = false;
			if (input.poll(KEY_A, KEYSTATE_TYPED)) add = !add;
			renderer.render();
			_window.update();
		}
	}

	void Application::initEngine()
	{
		Mesh::default2DLayout.push<float>(4);
		Mesh::defaultColorLayout.push<float>(4);
	}
}
