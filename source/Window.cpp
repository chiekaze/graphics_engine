#include <Window.h>

namespace engine
{
	Window::Window(Application* app, GraphicsSystem* graphicsSystem) : 
		Object(), 
		m_app(app),
		m_graphicsSystem(graphicsSystem)
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
		m_graphicsSystem = graphics;
	}

	Application* Window::getApplication() const
	{
		return m_app;
	}

	GraphicsSystem* Window::getGraphicsSystem() const
	{
		return m_graphicsSystem;
	}
}
