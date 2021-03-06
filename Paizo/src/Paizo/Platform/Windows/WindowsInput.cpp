#include "pzpch.h"
#include "Core/OS/Input.h"
#include "Core/Application.h"
#include "WindowsInput.h"
#include <GLFW/glfw3.h>

namespace Paizo
{

	Input* Input::s_Instance = new WindowsInput();

	bool Paizo::WindowsInput::IsKeyPressedImpl(KeyCode keyCode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		if (glfwGetKey(window, keyCode))
			return true;

		return false;
	}

	bool Paizo::WindowsInput::IsMouseButtonPressedImpl(MouseButton button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

		if (glfwGetMouseButton(window, button))
			return true;

		return false;
	}

	std::pair<float, float> Paizo::WindowsInput::GetMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

		double mouseX, mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);

		return { float(mouseX), float(mouseY) };
	}

	float Paizo::WindowsInput::GetMouseXImpl()
	{
		auto [mouseX, mouseY] = GetMousePositionImpl();
		return mouseX;
	}

	float Paizo::WindowsInput::GetMouseYImpl()
	{
		auto [mouseX, mouseY] = GetMousePositionImpl();
		return mouseY;
	}
}