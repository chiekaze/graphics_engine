#ifndef OPENGLES2_GRAPHICS_SYSTEM_H_
#define OPENGLES2_GRAPHICS_SYSTEM_H_

#include <GraphicsSystem.h>
#include <Ref.h>

#include <GLES2/gl2.h>
#include <EGL/egl.h>

namespace engine
{
	class Window;

	class OpenGLES2GraphicsSystem : public GraphicsSystem
	{
	public:
		OpenGLES2GraphicsSystem(Window* window);
		~OpenGLES2GraphicsSystem();

		virtual void swapBuffers();

	private:
		engine::Ref<Window> m_window;
		bool m_active;

		EGLContext m_eglContext;

		EGLDisplay m_eglDisplay;
		EGLSurface m_eglSurface;	
	};
}

#endif;
