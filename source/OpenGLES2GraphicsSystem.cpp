#include <OpenGLES2GraphicsSystem.h>
#include <Win32Window.h>

namespace engine
{
	OpenGLES2GraphicsSystem::OpenGLES2GraphicsSystem(Window* window) : 
		GraphicsSystem(), m_window(window), m_active(false)
	{
		assert(m_window != 0);

		EGLint attribList[] = {
			EGL_RED_SIZE, 8,
			EGL_GREEN_SIZE, 8,
			EGL_BLUE_SIZE, 8,
			EGL_ALPHA_SIZE, 8,
			EGL_DEPTH_SIZE, 16,
			EGL_STENCIL_SIZE, EGL_DONT_CARE,
			EGL_SAMPLE_BUFFERS, 0,
			EGL_NONE
		};

		EGLint numConfigs;
		EGLint majorVersion;
		EGLint minorVersion;
		EGLConfig config;
		
		EGLint contextAtrribs[] = {
			EGL_CONTEXT_CLIENT_VERSION, 2, 
			EGL_NONE, 
			EGL_NONE 
		};

		m_eglDisplay = eglGetDisplay(window->getNativeDisplay());	
		if (m_eglDisplay == EGL_NO_DISPLAY)
		{
			return;
		}

		if (!eglInitialize(m_eglDisplay, &majorVersion, &minorVersion))
		{
			return;
		}

		if (!eglGetConfigs(m_eglDisplay, NULL, 0, &numConfigs))
		{
			return;
		}

		if (!eglChooseConfig(m_eglDisplay, attribList, &config, 1, &numConfigs))
		{
			return;
		}

		m_eglSurface = eglCreateWindowSurface(m_eglDisplay, config, window->getNativeWindow(), NULL);
		if (m_eglSurface == EGL_NO_SURFACE)
		{
			return;
		}

		m_eglContext = eglCreateContext(m_eglDisplay, config, EGL_NO_CONTEXT, contextAtrribs);
		if (m_eglContext == EGL_NO_CONTEXT)
		{
			return;
		}

		m_active = true;
	}

	OpenGLES2GraphicsSystem::~OpenGLES2GraphicsSystem()
	{
	}
}
