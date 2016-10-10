#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <Object.h>
#include <Ref.h>
#include <vector>
#include <Shader.h>

namespace engine
{
	class Window;
	class GraphicsSystem;
	class Shader;

	class Application : public Object
	{
	public:
		Application();
		~Application();

		bool update(float deltaTime);
		void render(Window* window, GraphicsSystem* graphicsSystem);
		
	private:
		float m_totalTime;		
		std::vector<Ref<Shader>> m_shader;
	};
}

#endif;

