#include "stdafx.h"
#include <Win32Window.h>
#include <Ref.h>
#include <OpenGLES2GraphicsSystem.h>
#include <Application.h>
#include <ElapsedTimer.h>

using namespace engine;

int _tmain(int argc, _TCHAR* argv[])
{
	int w = 640;
	int h = 480;

	//engine::Ref<engine::ElapsedTimer> timer = new engine::ElapsedTimer();

	printf("Created window (%d, %d)\n", w, h);

	engine::Ref<engine::Win32Window> window = 
		new engine::Win32Window(w, h, L"muh wundow");

	engine::Ref<engine::Application> application =
		new engine::Application();
	
	engine::Ref<engine::OpenGLES2GraphicsSystem> graphicsSystem =
		new engine::OpenGLES2GraphicsSystem(window);
	
	window->setApplication(application);
	window->setGraphics(graphicsSystem);

	//window->getApplication()->Render(window, graphicsSystem);

	while (window->updateMessages())
	{ 
		printf("Updating...\n");
	}

	printf("Application done!\n");

	return 0;
}
