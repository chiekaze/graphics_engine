#include <Application.h>
#include <GraphicsSystem.h>
#include <Window.h>
#include <stdio.h>

#include <GLES2/gl2.h>

namespace engine
{
	Application::Application() : Object(), 
		m_totalTime(0.0f)
	{
	}

	Application::~Application()
	{
	}

	bool Application::update(float deltaTime)
	{
		printf("%s\n", __FUNCTION__);
		m_totalTime += deltaTime;

	
		return true;
	}

	void Application::render(Window* window, GraphicsSystem* graphicsSystem)
	{ 
		printf("%s\n", __FUNCTION__);

		glViewport(0, 0, window->getWidth(), window->getHeight());
		glClearColor(0, 0, 1, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		graphicsSystem->swapBuffers();	
	}
}


