#include "IneptEditor.h"

#include <Logging/Log.h>

#include <Events/EventBus.h>

namespace IneptEditor {
	IneptEditorApp::IneptEditorApp(IneptEngine::Core::CommandLineArgs args) :Application(args)
	{
		LOG_INFO("Inept Editor Application started at {}", __TIME__);
		PushLayer(new EditorLayer());
	}

	IneptEditorApp::~IneptEditorApp()
	{

	}
} // namespace IneptEditor
