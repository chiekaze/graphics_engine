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

		bool update(float deltaTime);
		void render(Window* window, GraphicsSystem* graphicsSystem);

	private:
		float m_totalTime;
	};
}

#endif;

