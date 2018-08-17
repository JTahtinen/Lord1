#pragma once
#include <glew.h>
#include <string>
#include <unordered_map>
#include "../math/mat4.h"
namespace Lord1 { namespace graphics {

	class Shader
	{
		GLuint		_id;
		std::unordered_map<std::string, int>	_uniformLocations;
	public:
		void bind() const;
		static Shader* generateShader(const std::string& filename);
		GLint getUniformLocation(const std::string& u_name);
		void setUniform1i(const std::string& u_name, int v0);
		void setUnifotm1f(const std::string& u_name, float v0);
		void setUniform2f(const std::string& u_name, float v0, float v1);
		void setUniform3f(const std::string& u_name, float v0, float v1, float v2);
		void setUniform4f(const std::string& u_name, float v0, float v1, float v2, float v3);
		void setUniformMat4(const std::string& u_name, math::Matrix4f& matrix) ;
	private:
		Shader(GLuint id);
		static GLuint loadShader(const std::string& filename, GLenum type);
	};

}}