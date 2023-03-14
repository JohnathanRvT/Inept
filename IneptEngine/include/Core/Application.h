#pragma once

#include <iepch.h>
#include <IneptEngine.h>

#include <Windowing/Window.h>
using namespace IneptEngine::Windowing;

/* Currently working on implementing main features before scripting
#include <Scripting/Lua.h>
using namespace IneptEngine::Scripting;
*/
namespace IneptEngine::Core {
/**
 * @struct CommandLineArgs
 * @brief Struct for storing and accessing command line arguments
 *
 * This struct stores the number of command line arguments and an array of the arguments themselves.
 * It also provides an overloaded operator that allows accessing the arguments by index.
 */
struct CommandLineArgs {
	/**
	 * @brief The number of command line arguments
	 */
	int Count;

	/**
	 * @brief The array of command line arguments
	 */
	char** Args;

	/**
	 * @brief Overloaded operator for accessing the command line arguments by index
	 * @param index The index of the argument to access
	 * @return A pointer to the command line argument at the specified index
	 *
	 * If the index is out of bounds, this function will return a null pointer.
	 */
	const char* operator[](int index) const {
		return Args[index];
	}
};

/**
 * @class Application
 * @brief A class representing a running application in IneptEngine
 * This class serves as the base for all applications running on IneptEngine. It provides a simple
 * interface for running the application and cleaning up when the application is closed.
 */
class Application {
public:
	/**
	 * @fn Application()
	 * @brief Constructs a new Application object
	 * This constructs a new Application object with default values.
	 */
	Application(CommandLineArgs args) {
		//InitLua();

		LOG_INFO("Application started at {}", TIME_NOW);

		m_window = Window::CreateIneptWindow(nullptr, 800, 600, "Inept Window");
		m_window->CreateRenderer(RenderingAPI::OpenGL);
	}

	/**
	 * @fn ~Application()
	 * @brief Destroys the Application object
	 * This destructor cleans up any resources used by the Application object.
	 */
	virtual ~Application() {
		delete m_window;

		//CloseLua();
	}

	/**
	 * @fn void Run()
	 * @brief Runs the Application object
	 * This function is the main loop of the Application object, which should continue until the application is closed.
	 */
	virtual int Run() {
		EVENT_PUBLISH(AppUpdateEvent);

		m_window->Update();

		EVENT_PROCESS();
		return 0;
	}
private:
	IneptEngine::Windowing::Window* m_window;
};

/**
 * @fn Application* CreateApplication(CommandLineArgs args)
 * @brief Creates a new Application object
 * @param args The command line arguments passed to the application
 * @return A pointer to the newly created Application object
 * This function creates a new Application object using the provided command line arguments. It returns a pointer
 * to the newly created object implemented by the host program. (Games, Editor etc.)
 */
Application* CreateApplication(CommandLineArgs args);

} // namespace IneptEngine::Core
