#pragma once
#include <IneptEngine.h>

namespace IneptEditor {
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
		/**
		* @fn void Run()
		* @brief Runs the EditorApp object
		* This function is the main loop of the EditorApp object, which should continue until the application is closed while calling the base Run every frame.
		*/
		int Run() override;
	protected:
		bool m_exit = false;
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
