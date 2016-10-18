#ifndef SHADER_H_
#define SHADER_H_

#include <Object.h>
#include <GLES2/gl2.h>

namespace engine
{
	class Shader : public Object
	{
	public:
		Shader(const char* const vShaderStr, const char* const fShaderStr);
		~Shader();

		void UseShader();
		GLuint getUniformLocation(const char* const uniformName);

	private:
		GLuint m_programObject;
		GLuint loadShader(GLenum type, const char* shaderSrc);
	};
}

#endif

