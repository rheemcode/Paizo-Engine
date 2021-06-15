#pragma once

#include "Core/OS/Window.h"

#include <GLFW/glfw3.h>

namespace Electro
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;
		void SwapBuffers() override;

		inline unsigned int GetWidth() const override { return m_Data.Width;  }
		inline unsigned int GetHeight() const override { return m_Data.Height;  }

		// Window Attributes
		inline void SetEventCallbackFn(const EventCallbackFn& callback) override { m_Data.EventCallback = callback;  }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		virtual void* GetNativeWindow() const  override { return m_Window; }

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;

	};

}