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
		char texturedVertexShader1[] =
			"attribute vec4 vPosition;    \n"
			"attribute vec2 vTexCoord;    \n"
			"varying vec2 texCoord;       \n"
			"void main()                  \n"
			"{                            \n"
			"   gl_Position = vPosition;  \n"
			"   texCoord = vTexCoord;     \n"
			"}                            \n";
		
		char texturedFragmentShader1[] =
			"precision mediump float;                         \n"
			"uniform sampler2D texture;                       \n"
			"varying vec2 texCoord;                           \n"
			"void main()                                      \n"
			"{                                                \n"
			"  gl_FragColor = texture2D(texture, texCoord);   \n"
			"}                                                \n";

		char texturedFragmentShader2[] =
			"precision mediump float;                         \n"
			"uniform sampler2D texture;                       \n"
			"varying vec2 texCoord;                           \n"
			"void main()                                      \n"
			"{                                                \n"
			"  gl_FragColor = texture2D(texture, texCoord);   \n"
			"}                                                \n";

		//char FragmentShader2[] =
		//	"void main()										\n"
		//	"{													\n"
		//	"	gl_FragColor = vec4(1, 0, 1, 0);				\n"
		//	"}													\n";

		m_shader.push_back(new Shader(texturedVertexShader1, texturedFragmentShader1));
		m_shader.push_back(new Shader(texturedVertexShader1, texturedFragmentShader2));

		GLubyte pixels1[4 * 3] =
		{
			255, 0, 0,	 // Red
			0, 255, 0,	 // Green
			0, 0, 255,	 // Blue
			255, 255, 0  // Yellow
		};

		GLubyte pixels2[4 * 3] =
		{
			128, 0, 0,	 // Red
			0, 128, 0,	 // Green
			0, 0, 128,	 // Blue
			128, 128, 0  // Yellow
		};
		
		m_texture.push_back(new Texture(2, 2, 3, pixels1));	
		m_texture.push_back(new Texture(2, 2, 3, pixels2));
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
	
		float pulse = abs(sinf(3.0f*  m_totalTime));

		float scale = (sinf(2.0f * m_totalTime));
		
		graphicsSystem->clearScreen(0.25f, 0.0f, 0.25f * pulse);
		
		//float size = 1.0f;
		//float dx = -0.5f;
		//float dy = -0.5f;
		//float depth = 0.0f;
		
		GLfloat square[] = 
		{
			-1* sin(m_totalTime), -1* cos(m_totalTime), 0.0f,
			1* cos(m_totalTime), -1* sin(m_totalTime), 0.0f,
			1* sin(m_totalTime), 1* cos(m_totalTime), 0.0f,

			1* sin(m_totalTime), 1* cos(m_totalTime), 0.0f,
			-1* cos(m_totalTime), 1* sin(m_totalTime), 0.0f,
			-1* sin(m_totalTime), -1* cos(m_totalTime), 0.0f,
		};
		
		// Texture coordinates, whose origin (0,0) is top-left -corner.
		GLfloat textCoords1[] = 
		{
			0, 0,
			0, 1,
			1, 1,
			1, 1,
			1, 0,
			0, 0,
		};

		GLfloat triangle[] =
		{
			-0.5, -0.5, 0,
			0.5, -0.5, 0,
			0, 0.5, 0,
		};

		GLfloat textCoords2[] =
		{
			1, 0,
			1, 1,
			0, 1,
			0, 0,

		};

		graphicsSystem->drawTriangle(m_shader[0], m_texture[0], textCoords1, square, 6);
		graphicsSystem->drawTriangle(m_shader[1], m_texture[1], textCoords2, triangle, 3);

		graphicsSystem->swapBuffers();	
	

	}
}


