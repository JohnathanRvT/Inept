#include <Windowing/Window.h>

#ifdef INEPT_PLATFORM_WINDOWS
#include <Windowing/Windows/WindowsWindow.h> 
#endif

namespace IneptEngine::Windowing {
    Window* Window::CreateIneptWindow(Window* parent, int width, int height, const std::string title)
    {
#ifdef INEPT_PLATFORM_WINDOWS
        return new WindowsWindow(parent, width, height, title);
#else
        return nullptr;
#endif
    }
}