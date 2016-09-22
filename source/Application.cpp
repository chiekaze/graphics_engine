#include <Application.h>
#include <GraphicsSystem.h>
#include <Window.h>

#include <GLES2/gl2.h>
#include <EGL\egl.h>

#include <stdio.h>

namespace engine
{
	Application::Application() : Object(), m_totalTime(0.0f)
	{
	}

	Application::~Application()
	{
	}

	void Application::Update(/*float deltaTime*/)
	{
		printf("%s\n", __FUNCTION__);
	}

	void Application::Render(Window* window, GraphicsSystem* graphicsSystem)
	{ 
		printf("%s\n", __FUNCTION__);

		glViewport(0, 0, window->getWidth(), window->getHeight());
		
		glClearColor(1.0f, 0.0f, 0.0f, 0.0f);		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		graphicsSystem->swapBuffers();

		printf("%s\n", __FUNCTION__);
	}
}


