#pragma once

#include <iepch.h>

#include <IneptEngine.h>

#include <glad/glad.h>
#include <glm.hpp>

namespace IneptEngine::Rendering {
	class OpenGLShader //: public Shader
	{
	public:
		OpenGLShader() : m_program(NULL) {}
		virtual ~OpenGLShader() { glDeleteProgram(m_program); }

		virtual void Bind(); //override;
		virtual void Unbind(); //override;

		int LoadShader(std::string vertPath, std::string fragPath);

		
		// Set a uniform value of type int
		void SetUniform(const std::string& name, int value)
		{
			GLint location = glGetUniformLocation(m_program, name.c_str());
			if (location != -1)
			{
				glUniform1i(location, value);
			}
		}

		// Set a uniform value of type float
		void SetUniform(const std::string& name, float value)
		{
			GLint location = glGetUniformLocation(m_program, name.c_str());
			if (location != -1)
			{
				glUniform1f(location, value);
			}
		}

		// Set a uniform value of type vec3
		void SetUniform(const std::string& name, const glm::vec3& value)
		{
			GLint location = glGetUniformLocation(m_program, name.c_str());
			if (location != -1)
			{
				glUniform3fv(location, 1, &value[0]);
			}
		}

		// Set a uniform value of type vec4
		void SetUniform(const std::string& name, const glm::vec4& value)
		{
			GLint location = glGetUniformLocation(m_program, name.c_str());
			if (location != -1)
			{
				glUniform4fv(location, 1, &value[0]);
			}
		}

		// Set a uniform value of type mat4
		void SetUniform(const std::string& name, const glm::mat4& value)
		{
			GLint location = glGetUniformLocation(m_program, name.c_str());
			if (location != -1)
			{
				glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
			}
		}

	private:
		GLuint m_program;
	};

	inline void OpenGLShader::Bind()
	{
		glUseProgram(m_program);
	}

	inline int OpenGLShader::LoadShader(std::string vertPath, std::string fragPath)
	{

		std::ifstream vertFile(vertPath);
		std::ifstream fragFile(fragPath);

		// Read our shaders into the appropriate buffers
		std::string vertexSource((std::istreambuf_iterator<char>(vertFile)), std::istreambuf_iterator<char>());
		std::string fragmentSource((std::istreambuf_iterator<char>(fragFile)), std::istreambuf_iterator<char>());

		vertFile.close();
		fragFile.close();

		// Create an empty vertex shader handle
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

		// Send the vertex shader source code to GL
		// Note that std::string's .c_str is NULL character terminated.
		const GLchar* source = (const GLchar*)vertexSource.c_str();
		glShaderSource(vertexShader, 1, &source, 0);

		// Compile the vertex shader
		glCompileShader(vertexShader);

		GLint isCompiled = 0;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

			// We don't need the shader anymore.
			glDeleteShader(vertexShader);

			//LOG_ERROR("Compiling vertex shader failed: {}", infoLog.data());

			return 0;
		}

		// Create an empty fragment shader handle
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		// Send the fragment shader source code to GL
		// Note that std::string's .c_str is NULL character terminated.
		source = (const GLchar*)fragmentSource.c_str();
		glShaderSource(fragmentShader, 1, &source, 0);

		// Compile the fragment shader
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

			// We don't need the shader anymore.
			glDeleteShader(fragmentShader);
			// Either of them. Don't leak shaders.
			glDeleteShader(vertexShader);

			//LOG_ERROR("Compiling fragment shader failed: {}", infoLog.data());
			return 0;
		}

		// Vertex and fragment shaders are successfully compiled.
		// Now time to link them together into a program.
		// Get a program object.
		m_program = glCreateProgram();

		// Attach our shaders to our program
		glAttachShader(m_program, vertexShader);
		glAttachShader(m_program, fragmentShader);

		// Link our program
		glLinkProgram(m_program);

		// Note the different functions here: glGetProgram* instead of glGetShader*.
		GLint isLinked = 0;
		glGetProgramiv(m_program, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(m_program, maxLength, &maxLength, &infoLog[0]);

			// We don't need the program anymore.
			glDeleteProgram(m_program);
			// Don't leak shaders either.
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			//LOG_ERROR("Linking shaders failed: {}", infoLog.data());

			return 0;
		}

		// Always detach shaders after a successful link.
		glDetachShader(m_program, vertexShader);
		glDetachShader(m_program, fragmentShader);
		return 1;
	}

	inline void OpenGLShader::Unbind()
	{
		glUseProgram(0);
	}
}