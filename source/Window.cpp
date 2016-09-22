#include <Window.h>

namespace engine
{
	Window::Window()
	{

	}

	Window::Window(Application* app, GraphicsSystem* graphics) : 
		Object(), 
		m_app(app),
		m_graphics(graphics)
	{
	}

	Window::~Window()
	{
	}

	void Window::setApplication(Application* app)
	{
		m_app = app;
	}

	void Window::setGraphics(GraphicsSystem* graphics)
	{
		m_graphics = graphics;
	}

	Application* Window::getApplication() const
	{
		return m_app;
	}

	GraphicsSystem* Window::getGraphicsSystem() const
	{
		return m_graphics;
	}
}
