#include "stdafx.h"
#include <Win32Window.h>
#include <Ref.h>
#include <OpenGLES2GraphicsSystem.h>

//K‰ytet‰‰n engine -namespacea
using namespace engine;

int _tmain(int argc, _TCHAR* argv[])
{
	int w = 640;
	int h = 480;

	printf("Created window (%d, %d)\n", w, h);

	engine::Ref<engine::Win32Window> window = 
		new engine::Win32Window(w, h, L"muh wundow");

	engine::Ref<engine::OpenGLES2GraphicsSystem> graphics =
		new engine::OpenGLES2GraphicsSystem(window);

	while (window->updateMessages())
	{
		printf("Window update okay!\n");
	}

	printf("Application done!\n");

	return 0;
}
