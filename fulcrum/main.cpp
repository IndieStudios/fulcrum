#include <Windows.h>

#include "engine/engine.hpp"

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prev_instance, PWSTR cmd_line, int cmd_show)
{
	if (!engine::get().initialize(800, 600, "fulcrum"))
	{
		return 1;
	}
	engine::get().run();
	return 0;
}