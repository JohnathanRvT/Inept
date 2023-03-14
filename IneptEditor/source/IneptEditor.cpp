#include "IneptEditor.h"

namespace IneptEditor {
	IneptEditorApp::IneptEditorApp(IneptEngine::Core::CommandLineArgs args):Application(args)
	{
		LOG_INFO("Inept Editor Application started at {}", __TIME__);
		IneptEngine::Events::EventBus::GetInstance().Subscribe(EventType::WindowClose, [this](Event* e) {
			//LOG_INFO("Inept Editor exit loop");
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
