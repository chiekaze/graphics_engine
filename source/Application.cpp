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
		char VertexShader1[] =
			"void main()										\n"
			"{													\n"
			"	gl_Position =  vPosition;						\n"
			"}													\n";
		
		char FragmentShader1[] =		
			"void main()										\n"
			"{													\n"
			"	gl_FragColor = vec4(1, 1, 0, 0);				\n"
			"}													\n";

		char FragmentShader2[] =
			"void main()										\n"
			"{													\n"
			"	gl_FragColor = vec4(1, 0, 1, 0);				\n"
			"}													\n";

		m_shader.push_back(new Shader(VertexShader1, FragmentShader1));	
		m_shader.push_back(new Shader(VertexShader1, FragmentShader2));
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
	
		float pulse = (sinf(2.0f * m_totalTime));

		float scale = abs(cosf(2.0f * m_totalTime));
		
		graphicsSystem->clearScreen(0, 1, pulse);
		

		GLfloat square[] =
		{
			-1 * (sinf(m_totalTime)), -1 * (cosf(m_totalTime)), 0.0f,
			1 * (cosf(m_totalTime)), -1 * (sinf(m_totalTime)), 0.0f,
			1 * (sinf(m_totalTime)), 1 * (cosf(m_totalTime)), 0.0f,

			1 * (sinf(m_totalTime)), 1 * (cosf(m_totalTime)), 0.0f,
			-1 * (cosf(m_totalTime)), 1 * (sinf(m_totalTime)), 0.0f,
			-1 * (sinf(m_totalTime)), -1 * (cosf(m_totalTime)), 0.0f,
		};

		GLfloat triangle[] =
		{
			-0.5f * scale, -0.5f * scale, 0.0f,
			0.5f * scale, -0.5f * scale, 0.0f,
			0.0f, 0.5f * scale, 0.0f,
		};

		graphicsSystem->drawTriangle(m_shader[0], square, 6);
		graphicsSystem->drawTriangle(m_shader[1], triangle, 3);
		
		graphicsSystem->swapBuffers();	
	

	}
}


