#ifndef ANDROID_H_
#define ANDROID_H_

#include <Window.h>

namespace engine
{
	class AndroidWindow : public Window
	{
	public:
		AndroidWindow(EGLNativeWindowType nativeWindow);
		~AndroidWindow();

		virtual EGLNativeWindowType getNativeWindow() const;

	private:
		EGLNativeWindowType m_hwnd;
	};
}

#endif