#pragma once

#include <Windows.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../singleton.hpp"
#include <iostream>

class engine : public singleton<engine>
{
private:
	friend class singleton<engine>;

	engine();
	~engine();

	int m_window_width = 0;
	int m_window_height = 0;
	const char* m_window_title = nullptr;

	GLFWwindow* m_window = nullptr;

public:
	bool initialize(int window_width, int window_height, const char* window_title);
	void run();
};