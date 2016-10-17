#ifndef TEXTURE_H
#define TEXTURE_H

#include <Object.h>
#include <GLES2/gl2.h>

namespace engine
{
	class Texture : public Object
	{
	public:
		
		// Constructs and compiles new shader from given vertex and fragment shaders sources.
		Texture(int width, int height, int bytesPerPixel, const GLubyte* pixels);
		~Texture();

		GLuint getTextureID() const
		{
			return m_textureID;
		}
	
	private:
		GLuint m_textureID;
	};
}
#endif