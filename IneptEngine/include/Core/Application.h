#pragma once

#include <iepch.h>
#include <Windowing/Window.h>
using namespace IneptEngine::Windowing;
//#include <Scripting/Lua.h>
//using namespace IneptEngine::Scripting;


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
		LOG_INFO("Application started at {}", __TIME__);
		m_window = Window::CreateIneptWindow(nullptr, 800, 600, "Inept Window");

		m_scenewindow = Window::CreateIneptWindow(nullptr, 400, 600, "Scene Window");
		m_window->AddChild(m_scenewindow);
		m_scenewindow->CreateRenderer(RenderingAPI::OpenGL);

		m_gamewindow = Window::CreateIneptWindow(m_window, 400, 600, "Game Window");


		std::unique_ptr<Subscription> sub =	EventBus::GetInstance().Subscribe(EventCategory::Input,[](Event* e) {
			LOG_TRACE("Event : {}",e->ToString());
			});
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
		m_scenewindow->Update();
		m_gamewindow->Update();

		EVENT_PROCESS();
		return 0;
	}
private:
	IneptEngine::Windowing::Window* m_window;
	IneptEngine::Windowing::Window* m_scenewindow;
	IneptEngine::Windowing::Window* m_gamewindow;
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
