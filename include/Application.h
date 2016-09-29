#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <Object.h>

#include <GLES2/gl2.h>
#include <EGL/egl.h>

namespace engine
{
	class Window;
	class GraphicsSystem;

	class Application : public Object
	{
	public:
		Application();
		~Application();

		bool update(float deltaTime);
		void render(Window* window, GraphicsSystem* graphicsSystem);
		
	private:
		float m_totalTime;		
		GLuint programObject;
	};
}

#endif;

