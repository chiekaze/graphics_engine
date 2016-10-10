#include <Application.h>
#include <GraphicsSystem.h>
#include <Window.h>
#include <stdio.h>
#include <math.h>

namespace engine
{
	Application::Application() : Object(), 
		m_totalTime(0.0f)
	{
		char VertexShader[] =
			"void main()										\n"
			"{													\n"
			"	gl_Position = vPosition;						\n"
			"}													\n";
		
		char FragmentShader[] =					
			"void main()										\n"
			"{													\n"
			"	gl_FragColor = vec4(1, 0, 1, 0);				\n"
			"}													\n";

		m_shader.push_back(new Shader(VertexShader, FragmentShader));	
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

		float puls = abs(sinf(2.0f*m_totalTime));
		
		graphicsSystem->clearScreen(0, 1, puls);
		
		GLfloat triangle1[] = 
		{
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f,
		};
		
		graphicsSystem->drawTriangle(m_shader[0], triangle1, 3);
		graphicsSystem->swapBuffers();	
	}
}


