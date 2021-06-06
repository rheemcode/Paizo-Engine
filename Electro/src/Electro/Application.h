#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"
#include "Layer.h"
#include "LayerStack.h"

namespace Electro
{
	class ELECTRO_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();
		
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverLay(Layer* layer);
	
	private:

		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();
}


