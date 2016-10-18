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
		~Window();

		//virtual EGLNativeDisplayType getNativeDisplay() const = 0;
		virtual EGLNativeWindowType getNativeWindow() const = 0;
	
		void setSize(int w, int h);
		virtual int getWidth() const /*= 0*/;
		virtual int getHeight() const /*= 0*/;

		void setApplication(Application* application);
		void setGraphicsSystem(GraphicsSystem* graphicsSystem);

		Application* getApplication() const;
		GraphicsSystem* getGraphicsSystem() const;

	private:
		int m_width;
		int m_height;

		Application* m_application;
		GraphicsSystem* m_graphicsSystem;
	};
}

#endif
