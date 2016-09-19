#ifndef WINDOW_H_
#define WINDOW_H_

#include <Object.h>
#include <EGL/eglplatform.h>

namespace engine
{
	class Application;
	class GraphicsSystem;

	class Window : public Object
	{
	public:
		Window();
		Window(Application* app, GraphicsSystem* graphicsSystem);
		~Window();

		virtual EGLNativeDisplayType getNativeDisplay() const = 0;
		virtual EGLNativeWindowType getNativeWindow() const = 0;
	
		virtual int getWidth() = 0;
		virtual int getHeight() = 0;

		void setApplication(Application* app);
		void setGraphics(GraphicsSystem* graphicsSystem);

		Application* getApplication() const;
		GraphicsSystem* getGraphicsSystem() const;

	private:
		Application* m_app;
		GraphicsSystem* m_graphicsSystem;
	};
}

#endif;
