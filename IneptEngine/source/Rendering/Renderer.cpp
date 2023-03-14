#include <Rendering/Renderer.h>
#include <Rendering/OpenGL/OpenGLRenderer.h>

namespace IneptEngine::Rendering {
	Renderer* Renderer::CreateRenderer(IneptEngine::Windowing::Window* window,RenderingAPI api) {
		if (api == RenderingAPI::OpenGL)
		{
			return new OpenGLRenderer(window);
		} else
		return nullptr;
	}
}