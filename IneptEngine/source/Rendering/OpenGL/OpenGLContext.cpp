#include "Rendering/OpenGL/OpenGLContext.h"
#include <Logging/Log.h>

#include <glad/glad.h>

namespace IneptEngine::Rendering
{
    OpenGLContext::OpenGLContext(IneptEngine::Windowing::Window* window) : Context(window) {
        // Create platform-specific window handle and device context/display
#ifdef INEPT_PLATFORM_WINDOWS
        m_Window = static_cast<IneptEngine::Windowing::WindowsWindow*>(window);
        m_DeviceContext = GetDC(m_Window->GetHandle());
        PIXELFORMATDESCRIPTOR pfd;
        ZeroMemory(&pfd, sizeof(pfd));
        pfd.nSize = sizeof(pfd);
        pfd.nVersion = 1;
        pfd.dwFlags = PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 32;
        pfd.cDepthBits = 24;
        pfd.cStencilBits = 8;
        int pixelFormat = ChoosePixelFormat(static_cast<HDC>(m_DeviceContext), &pfd);
        if (pixelFormat == 0)
        {
            LOG_ERROR("Failed to choose a pixel format");
        }

        if (!SetPixelFormat(static_cast<HDC>(m_DeviceContext), pixelFormat, &pfd))
        {
            LOG_ERROR("Failed to set the pixel format");
        }

        m_OpenGLContext = wglCreateContext(static_cast<HDC>(m_DeviceContext));
        if (m_OpenGLContext == nullptr)
        {
            LOG_ERROR("Failed to create a rendering context");
        }

        if (!wglMakeCurrent(static_cast<HDC>(m_DeviceContext), static_cast<HGLRC>(m_OpenGLContext)))
        {
            LOG_ERROR("Failed to make the rendering context current");
        }

#elif INEPT_PLATFORM_LINUX
    // Linux-specific implementation details
#elif INEPT_PLATFORM_MACOS
    // MacOS-specific implementation details
#endif
    }

    void OpenGLContext::Init() {
        // Initialize GLAD
        if (!gladLoadGL())
        {
            LOG_ERROR("Failed to initialize Glad");
        }
    }

    void OpenGLContext::MakeCurrent() {
        if (!wglMakeCurrent(static_cast<HDC>(m_DeviceContext), static_cast<HGLRC>(m_OpenGLContext)))
        {
            LOG_ERROR("Failed to make the rendering context current");
        }
    }

    void OpenGLContext::SwapBuffers() {
        // Swap buffers for double buffering
#ifdef INEPT_PLATFORM_WINDOWS
        ::SwapBuffers(static_cast<HDC>(m_DeviceContext));
#elif INEPT_PLATFORM_LINUX
        glXSwapBuffers(static_cast<Display*>(m_Display), static_cast<Window>(m_Window));
#elif INEPT_PLATFORM_MACOS
        [[NSOpenGLContext currentContext]flushBuffer];
#endif
    }
}
