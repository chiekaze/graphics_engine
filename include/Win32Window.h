#ifndef WIN32_H_
#define WIN32_H_

#include <Window.h>
#include <Windows.h>

namespace engine
{
	class Win32Window : public Window
	{
	public:
		Win32Window(int width, int height);

		//hwnd get handles
		//bool update messages

		~Win32Window();
	private:
	};
}

#endif;

