#pragma once
#include "renderer2d.h"
#include "../buffers/indexbuffer.h"
#include <glew.h>

#define RENDERER_MAX_SPRITES	50000
#define RENDERER_VERTEX_SIZE	sizeof(Vertex)
#define RENDERER_SPRITE_SIZE	RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE	RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE	RENDERER_MAX_SPRITES * 6


#define SHADER_POSITION_INDEX	0
#define SHADER_COLOR_INDEX		1

namespace lord { namespace graphics {

class BatchRenderer2D : public Renderer2D
{
	GLuint				_vao;
	GLuint				_vbo;
	IndexBuffer*		_ibo;
	Vertex*				_buffer;
	unsigned int		_numIndices;
public:
	BatchRenderer2D(const Window& win);
	~BatchRenderer2D();
	void begin();
	void submit(Renderable2D* renderable);
	void end();
	void flush();	
};

}}