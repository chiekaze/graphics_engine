#ifndef WINDOW_H_
#define WINDOW_H_

#include <Object.h>
#include <EGL/eglplatform.h>

namespace engine
{
	class Window : public Object
	{
	public:
		Window();
		~Window();

		virtual EGLNativeDisplayType getNativeDisplay() const = 0;
		virtual EGLNativeWindowType getNativeWindow() const = 0;
	};
}

#endif;
