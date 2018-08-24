#include "application.h"
#include <iostream>
#include <glew.h>
#include <SDL.h>
#include "input/input.h"
#include "util/file_load.h"
#include "math/vec4.h"
#include "math/vec2.h"
#include "math/mat4.h"
#include "math/math.h"
#include "graphics/buffers\vertexarray.h"
#include "graphics/buffers\vertexbuffer.h"
#include "graphics/shader.h"
#include "graphics/renderers/renderer.h"
#include "graphics/buffers\indexbuffer.h"
#include "graphics/mesh.h"
#include "graphics/renderers/simple2drenderer.h"
#include "graphics/renderers/batchrenderer2d.h"
#include "graphics/staticsprite.h"
namespace lord
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

		float aspect = (float)_window.getWidth() / (float)_window.getHeight();

		Vec4 p1(0, 0, 0, 0);
		Vec4 p2(2.0f, 3.0f, 1.5, 0.5);
	
		Lerp(p1, p2, 0.5f).print();

		//GL TEST DATA

		float fov = 70.0f;
		Matrix4f perspective = Matrix4f::projection(fov, aspect, 0.1f, 200.0f);
		Matrix4f ortho = Matrix4f::ortho(-1.0f, 1.0f, (1.0f / aspect), -(1.0f / aspect), 0.0f, 200.0f);
		Matrix4f view = Matrix4f::identity();
		Matrix4f model = Matrix4f::identity();

		Renderer renderer;
		// DATA 
		//------------------------------------------------------------------
		Vec3 vertices[] = {
			Vec3(-0.5f, -0.5f, -0.5f), Vec3(-0.5f, 0.5f, -0.5f),
			Vec3(0.5f, 0.5f, -0.5f), Vec3(0.5f, -0.5f, -0.5f),

			Vec3(-0.5f, -0.5f, 0.5f), Vec3(0.5f, -0.5f, 0.5f)
		};

		Vec3 verticesB[] = {
			Vec3(0.8f, -0.2f, 0.0f), Vec3(0.7f, -0.3f, 0.0f), Vec3(0.75f, -0.4f, 0.0f),
		};
		Vec4 colors[] = {Vec4(1, 0, 1, 1), Vec4(0, 0, 1, 1), Vec4(0.5f, 0.9f, 0.65f, 1),
			Vec4(1, 0, 0, 1), Vec4(1, 0, 1, 1), Vec4(0, 0.5f, 0, 1) };

		unsigned int indices[] = { 0, 1, 2, 2, 0, 3, 3, 0, 4, 4, 3, 5 };
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
		for (unsigned int i = 0; i < 12; ++i)
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

		//-----
		
		Input& input = Input::instance();
		bool add = false;
		float z = -2.0f;
		float x = 0.0f;
		Matrix4f* projection = &ortho;

		StaticSprite sprite(Vec2(-0.5f, -0.2f), Vec2(0.2f, 0.4f), shader);
		//Renderable2D spriteB(Vec2(-0.5f, -0.2f), Vec2(0.2f, 0.4f));

		Simple2DRenderer simple2DRenderer(_window);
		BatchRenderer2D batchRenderer2D(_window);
		Renderer2D* renderer2D = &batchRenderer2D;
		
		while (running)
		{
			_window.clear();
			input.update();
			if (input.poll(KEY_T)) z += 0.01f;
			if (input.poll(KEY_G)) z -= 0.01f;
			if (input.poll(KEY_F)) x += 0.01f;
			if (input.poll(KEY_H)) x -= 0.01f;
			if (input.poll(KEY_O))
			{
				fov += 0.1f; perspective = Matrix4f::projection(fov, aspect, 0.1f, 200.0f);
				std::cout << "Fov: " << fov << std::endl;
			}
			if (input.poll(KEY_I)) 
			{ 
				fov -= 0.1f; perspective = Matrix4f::projection(fov, aspect, 0.1f, 200.0f);
				std::cout << "Fov: " << fov << std::endl;
			}

				
			view = Matrix4f::translate(Vec3(x, 0, z));
			renderer.push(&mesh);
			if (add)
			renderer.push(&meshB);
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
			shader->setUniformMat4("u_projection", *projection);
			shader->setUniformMat4("u_view", view);
			shader->setUniformMat4("u_model", model);
			renderer.render();
			batchRenderer2D.begin();
			for (int i = 0; i < 10; ++i)
			{
				Renderable2D s(Vec2(-1.0f + i * 0.1f, 0), Vec2(0.09f, 0.2f));
				batchRenderer2D.submit(&s);
			}
			shader->setUniformMat4("u_view", Matrix4f::identity());
			shader->setUniformMat4("u_projection", ortho);
		
			batchRenderer2D.end();
			batchRenderer2D.flush();
			_window.update();
		}
	}

	void Application::initEngine()
	{
		VertexBufferLayout::defaultPositionLayout.push<float>(4);
		VertexBufferLayout::defaultColorLayout.push<float>(4);
	}
}
