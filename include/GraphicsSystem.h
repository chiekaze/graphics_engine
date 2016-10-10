#ifndef GRAPHICS_SYSTEM_H_
#define GRAPHICS_SYSTEM_H_

#include <Object.h>

namespace engine
{
	class Shader;
	class Window;

	class GraphicsSystem : public Object
	{
	public:
		GraphicsSystem();
		~GraphicsSystem();

		virtual void clearScreen(float red, float green, float blue) = 0;
		virtual void drawTriangle(Shader* shader, float vertices[], int numvertices) = 0;

		virtual void swapBuffers() = 0;
	};
}

#endif;