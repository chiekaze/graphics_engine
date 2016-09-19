#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <Object.h>


namespace engine
{
	class Window;
	class GraphicsSystem;

	class Application : public Object
	{
	public:
		Application();
		~Application();

		void Update(float deltaTime);
		void Render(Window* window, GraphicsSystem* graphicsSystem);

	private:
		float m_totalTime;
	};
}

#endif;

