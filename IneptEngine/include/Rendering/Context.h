#pragma once

namespace IneptEngine::Windowing {
	class Window;
}

namespace IneptEngine::Rendering
{
	class Context
	{
	public:
		Context(Windowing::Window* window) : m_window(window) {}
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
		virtual void MakeCurrent() = 0;

	private:
		Windowing::Window* m_window;
	};
}
