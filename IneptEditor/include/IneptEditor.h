#pragma once

#include <IneptEngine.h>
#include <Core/EntryPoint.h>
#include <Core/LayerStack.h>

#include <typeinfo>  //for 'typeid' to work  

namespace IneptEditor {

	class EditorLayer : public IneptEngine::Core::Layer
	{
	public:
		
		virtual void OnAttach() override {
			LOG_DEBUG("Attach");
		}

		virtual void OnDetach() override {
			LOG_DEBUG("Detach");
		}

		virtual void OnUpdate(float deltaTime) override {
			LOG_DEBUG("Update");
		}

		virtual void OnRender() override {
			LOG_DEBUG("Render");
		}

		virtual void OnEvent(IneptEngine::Events::Event* event) override {
			//LOG_DEBUG("{}", event->ToString());
		}
	};
	  
	/**
	 * @class The main editor application class.
	 * @brief This class derives from the IneptEngine::Core::Application class and serves as the entry point for the editor.
	 */
	class IneptEditorApp : public IneptEngine::Core::Application {
	public:
		/**
		 * @fn EditorApp()
		 * @brief Constructs a new EditorApp object
		 * This constructs a new EditorApp object with default values.
		 */
		IneptEditorApp(IneptEngine::Core::CommandLineArgs args);

		/**
		 * @fn ~EditorApp()
		 * @brief Destroys the EditorApp object
		 * This destructor cleans up any resources used by the EditorApp object.
		 */
		~IneptEditorApp();
	};
} // namespace IneptEditor

/**
 * @fn Application* CreateApplication(CommandLineArgs args)
 * @brief Creates a new IneptEditorApp object
 * @param args The command line arguments passed to the application
 * @return A pointer to the newly created IneptEditorApp object
 *
 * This function creates a new IneptEditorApp object using the provided command line arguments. It returns a pointer
 * to the newly created object implemented by the host program, i.e this Editor.
 */
IneptEngine::Core::Application* IneptEngine::Core::CreateApplication(CommandLineArgs args) {

	// Create and return a new instance of the editor application.
	return new IneptEditor::IneptEditorApp(args);
}
