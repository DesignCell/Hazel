#include "hzpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>


namespace Hazel {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_windowHandle(windowHandle)
	{
		HZ_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_windowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HZ_CORE_ASSERT(status, "Failed to initialize Glad!");

		#if 0
			HZ_CORE_INFO("OpenGL Info:");
			HZ_CORE_INFO("	Vendor: {0}", glGetString(GL_VENDOR));
			HZ_CORE_INFO("	Renderer: {0}", glGetString(GL_RENDERER));
			HZ_CORE_INFO("	Version: {0}", glGetString(GL_VERSION));
		#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		
		glfwSwapBuffers(m_windowHandle);
	}
}