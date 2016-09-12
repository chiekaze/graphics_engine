// TestDemo.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <Win32Window.h>
#include <Ref.h>


//K‰ytet‰‰n engine -namespacea
using namespace engine;

//int doSomeStuff()
//{
//	int a = 0.0;
//
//	for (int i = 0; i < 10000000; ++i)
//	{
//		a *= 2;
//	}
//
//	return a;
//}

int _tmain(int argc, _TCHAR* argv[])
{
	//engine::Ref<Object> obj = new Object();
	//
	//engine::ElapsedTimer timer;
	//timer.reset();

	//int a = doSomeStuff();

	//float deltaTime = timer.getTime();

	//printf("%d, deltaTime=%2.2f\n", a, deltaTime);

	int w = 640;
	int h = 480;

	printf("Application create window (%d, %d)\n", w, h);

	engine::Ref<engine::Win32Window> window = new engine::Win32Window(w, h, L"muh wundow");

	while (window->updateMessages())
	{
		printf("Window update okay!\n");
	}

	return 0;
}



