#pragma once
#include "Context.h"

namespace IneptEngine::Rendering {
    enum RenderingAPI {
        OpenGL,
    };

    class Renderer {
    public:
        Renderer(IneptEngine::Windowing::Window* window) : m_window(window) {}
        virtual ~Renderer() = default;

        virtual void Render() = 0;

        virtual IneptEngine::Windowing::Window* GetWindow() { return m_window; }
        virtual bool VSyncEnabled() { return m_vsyncEnabled; }
        virtual void SetVSync(bool enabled) { m_vsyncEnabled = enabled; }

        static Renderer* CreateRenderer(IneptEngine::Windowing::Window* window, RenderingAPI api);

    protected:
        Context* m_context;
        IneptEngine::Windowing::Window* m_window;
        bool m_vsyncEnabled = true;
    };
}
