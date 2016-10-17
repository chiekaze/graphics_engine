#include <OpenGLES2GraphicsSystem.h>
#include <Win32Window.h>
#include <Shader.h>
#include <Texture.h>

namespace engine
{
	OpenGLES2GraphicsSystem::OpenGLES2GraphicsSystem(Window* window) : GraphicsSystem(), 
		m_window(window), 
		m_active(false)
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

		// Make the context current
		if (!eglMakeCurrent(m_eglDisplay, m_eglSurface, m_eglSurface, m_eglContext))
		{
			return;
		}

		m_active = true;
		
		//int n = eglGetError();
		//if (n != EGL_SUCCESS)
		//{
		//	assert(0);
		//}

		//int num = glGetError();
	}

	OpenGLES2GraphicsSystem::~OpenGLES2GraphicsSystem()
	{
	}

	void OpenGLES2GraphicsSystem::clearScreen(float red, float green, float blue)
	{
		glViewport(0, 0, m_window->getWidth(), m_window->getHeight());
		glClearColor(red, green, blue, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLES2GraphicsSystem::drawTriangle(Shader* shader, Texture* texture, float textureCoords[], float vertices[], int numvertices)
	{
		shader->UseShader();

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices);
		glEnableVertexAttribArray(0);

		// Set texture coordinates
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, textureCoords);
		glEnableVertexAttribArray(1);
		
		// Bind texture
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture->getTextureID());
		
		// Set the sampler texture unit to 0
		glUniform1i(shader->getUniformLocation("texture"), 0);

		glDrawArrays(GL_TRIANGLES, 0, numvertices);
	}

	void OpenGLES2GraphicsSystem::swapBuffers()
	{
		eglSwapBuffers(m_eglDisplay, m_eglSurface);
	}
}
