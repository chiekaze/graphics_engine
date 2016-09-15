#ifndef WIN32_H_
#define WIN32_H_

#include <Window.h>
#include <windows.h>
#include <string>

namespace engine
{
	class Win32Window : public Window
	{
	public:
		Win32Window(int width, int height, const std::wstring& title);
		~Win32Window();

		virtual EGLNativeDisplayType getNativeDisplay() const
		{
			return GetDC(getNativeWindow());
		}

		virtual EGLNativeWindowType getNativeWindow() const
		{
			return m_hwnd;
		}

		bool updateMessages();

	private:
		HWND m_hwnd;
		bool m_active;
	};
}

#endif;
