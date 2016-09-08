#ifndef OPENGLES2_GRAPHICS_SYSTEM_H_
#define OPENGLES2_GRAPHICS_SYSTEM_H_

#include <GraphicsSystem.h>

namespace engine
{
	class OpenGLES2GraphicsSystem : public GraphicsSystem
	{
	public:
		OpenGLES2GraphicsSystem();
		virtual~OpenGLES2GraphicsSystem();
	};
}
#endif;