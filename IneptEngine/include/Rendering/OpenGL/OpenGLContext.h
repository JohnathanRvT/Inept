#pragma once

#include <Windowing/Window.h>

#ifdef INEPT_PLATFORM_WINDOWS
#define WIN32_LEAN_AND_MEAN
#include <Windowing/Windows/WindowsWindow.h>
#include <Windows.h>
#include <wingdi.h>
#elif INEPT_PLATFORM_LINUX
#include <X11/Xlib.h>
#include <GL/glx.h>
#elif INEPT_PLATFORM_MACOS
#include <OpenGL/OpenGL.h>
#endif
namespace IneptEngine::Rendering
{
	class OpenGLContext : public Context
	{
	public:
		OpenGLContext(IneptEngine::Windowing::Window* window);

		virtual void Init() override;
		virtual void SwapBuffers() override;
		virtual void MakeCurrent() override;
        // Platform-specific window handle and device context/display
    private:
#ifdef INEPT_PLATFORM_WINDOWS
        IneptEngine::Windowing::WindowsWindow* m_Window;
        void* m_DeviceContext;
        void* m_OpenGLContext;
#elif INEPT_PLATFORM_LINUX
        void* m_Display;
        void* m_Window;
        void* m_OpenGLContext;
#elif INEPT_PLATFORM_MACOS
        void* m_Window;
#endif
	};
}
