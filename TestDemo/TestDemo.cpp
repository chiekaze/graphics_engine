// TestDemo.cpp : Defines the entry point for the console application.
//

#include "Object.h"
#include "Ref.h"
#include "ElapsedTimer.h"
#include <iostream>
#include <Windows.h>

//Käytetään engine -namespacea
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

INT WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	INT nCmdShow
	);

LRESULT CALLBACK MyMessageHandler(
	HWND hWnd,
	UINT msg,
	WPARAM wParam,
	LPARAM lParam
	);

LRESULT CALLBACK MyMessageHandler(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		// Ikkunan alustuskoodi.
		return 0;
	case WM_PAINT:
		// Ikkunan piirtokoodi.
		return 0;
	case WM_SIZE:
		// Ikkunan koon muuttumiskoodi.
		return 0;
	case WM_COMMAND:
		// Käskyjen, kuten valikon nappien painamiseen
		// liittyvien viestien käsittelyyn liittyvä koodi.
		return 0;
	case WM_DESTROY:
		// Ikkunan tuhoamiseen liittyvä koodi:
		// Lähetetään lopetusviesti sovellukselle
		PostQuitMessage(0);
		return 0;
	}
	// Käsitellään viestit, joita me ei huolittu.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

typedef struct {
	UINT cbSize; // Tämän tietueen koko
	UINT style; // Tyyliliput
	WNDPROC lpfnWndProc; // Funktio-osoitin ikkunan sanomankäsittelijään
	int cbClsExtra; // Lisätietoa ikkunaluokasta
	int cbWndExtra; // Lisätietoa ikkunasta
	HINSTANCE hInstance; // Pääsovelluksen instanssikahva
	HICON hIcon; // Kahva käytettyyn isoon ikoniin
	HCURSOR hCursor; // Kahva käytettävään hiiren osoittimeen
	HBRUSH hbrBackground; // Kahva ikkunan taustasiveltimeen
	LPCTSTR lpszMenuName; // Valikon nimi
	LPCTSTR lpszClassName; // Ikkunaluokan nimi
	HICON hIconSm; // Kahva käytettyyn pieneen ikoniin
} WNDCLASSEX, *PWNDCLASSEX;

int main()
{
	//engine::Ref<Object> obj = new Object();
	//
	//engine::ElapsedTimer timer;
	//timer.reset();

	//int a = doSomeStuff();

	//float deltaTime = timer.getTime();

	//printf("%d, deltaTime=%2.2f\n", a, deltaTime);
	

	return 0;
}



