#include "engine.hpp"

engine::engine()
{

}

engine::~engine()
{

}

bool engine::initialize(int window_width, int window_height, const char* window_title)
{
	this->m_window_width = window_width;
	this->m_window_height = window_height;
	this->m_window_title = window_title;
	if (glfwInit() != GLFW_TRUE)
	{
		MessageBoxA(NULL, "Failed to initialize GLFW", "fulcrum engine", MB_OK | MB_ICONERROR);
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	this->m_window = glfwCreateWindow(this->m_window_width, this->m_window_height, this->m_window_title, NULL, NULL);
	glfwMakeContextCurrent(this->m_window);

	if (!this->m_window)
	{
		MessageBoxA(NULL, "Failed to create a window", "fulcrum engine", MB_OK | MB_ICONERROR);
		glfwTerminate();
		return false;
	}

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		MessageBoxA(NULL, "Failed to initialize GLAD", "fulcrum engine", MB_OK | MB_ICONERROR);
		return false;
	}

	glViewport(0, 0, this->m_window_width, this->m_window_height);

	return true;
}

void engine::run()
{
	while (!glfwWindowShouldClose(this->m_window))
	{
		glfwPollEvents();
		glClearColor(0.f, 0.f, 0.f, 0.f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(this->m_window);
	}

	glfwTerminate();
}