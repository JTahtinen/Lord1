#include "shader.h"
#include "../util/file_load.h"
#include "../defs.h"


namespace Lord1 { namespace graphics {

	Shader::Shader(GLuint id)
		: _id(id)
	{
	}

	void Shader::bind() const
	{
		GLCALL(glUseProgram(_id));
	}

	Shader* Shader::generateShader(const std::string& filename)
	{
		GLuint program = glCreateProgram();
		GLuint vs = Shader::loadShader(filename + ".vs", GL_VERTEX_SHADER);
		GLuint fs = Shader::loadShader(filename + ".fs", GL_FRAGMENT_SHADER);
		GLCALL(glAttachShader(program, vs));
		GLCALL(glAttachShader(program, fs));
		GLCALL(glLinkProgram(program));
		GLCALL(glValidateProgram(program));
		GLCALL(glDeleteShader(vs));
		GLCALL(glDeleteShader(fs));
		
		return new Shader(program);
	}

	GLint Shader::getUniformLocation(const std::string& u_name)
	{
		if (_uniformLocations.find(u_name) != _uniformLocations.end())
		{
			return _uniformLocations[u_name];
		}
		GLint location = glGetUniformLocation(_id, u_name.c_str());
		if (location == -1)
		{
			std::cout << "[ERROR] Cannot find uniform: " << u_name << std::endl;
		}
		_uniformLocations[u_name] = location;
		return location;
	}

	void Shader::setUniform1i(const std::string& u_name, int v0)
	{
		glUniform1i(getUniformLocation(u_name), v0);
	}

	void Shader::setUnifotm1f(const std::string& u_name, float v0)
	{
		glUniform1f(getUniformLocation(u_name), v0);
	}

	void Shader::setUniform2f(const std::string& u_name, float v0, float v1)
	{
		glUniform2f(getUniformLocation(u_name), v0, v1);
	}

	void Shader::setUniform3f(const std::string& u_name, float v0, float v1, float v2)
	{
		glUniform3f(getUniformLocation(u_name), v0, v2, v2);
	}

	void Shader::setUniform4f(const std::string& u_name, float v0, float v1, float v2, float v3)
	{
		glUniform4f(getUniformLocation(u_name), v0, v1, v2, v3);
	}

	void Shader::setUniformMat4(const std::string& u_name, math::Matrix4f& matrix)
	{
		glUniformMatrix4fv(getUniformLocation(u_name), 1, false, &matrix[0]);
	}

	GLuint Shader::loadShader(const std::string& filename, GLenum type)
	{
		std::string shaderfile = util::load_file(filename);
		if (shaderfile == "")
		{
			std::cerr << "[ERROR] Could not load shader: " << filename << std::endl;
			return 0;
		}

		GLuint shader = glCreateShader(type);
		const char* shaderstring = shaderfile.c_str();
		GLCALL(glShaderSource(shader, 1, &shaderstring, NULL));
		GLCALL(glCompileShader(shader));
		return shader;
	}
}}