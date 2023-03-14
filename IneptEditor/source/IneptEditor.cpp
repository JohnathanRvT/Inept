#include "IneptEditor.h"

#include <Logging/Log.h>

#include <Events/EventBus.h>

namespace IneptEditor {
	IneptEditorApp::IneptEditorApp(IneptEngine::Core::CommandLineArgs args) :Application(args)
	{
		LOG_INFO("Inept Editor Application started at {}", __TIME__);
		EVENT_SUBSCRIBE(WindowClose, [this](IneptEngine::Events::Event* e) {
			LOG_INFO("Inept Editor exit loop");
			m_exit = true;
			});
	}

	int IneptEditorApp::Run() {
		while (!m_exit)
		{
			IneptEngine::Core::Application::Run();
		}
		return 1;
	}

	IneptEditorApp::~IneptEditorApp()
	{

	}
} // namespace IneptEditor
