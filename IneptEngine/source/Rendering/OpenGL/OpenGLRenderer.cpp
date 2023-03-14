#include <Rendering/OpenGL/OpenGLRenderer.h>

namespace IneptEngine::Rendering {
	OpenGLRenderer::~OpenGLRenderer()
	{
	}

	void OpenGLRenderer::Render()
	{
		// Clear the screen and draw your scene
		m_context->MakeCurrent();

		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		//
		glm::mat4 viewMatrix = camera.GetViewMatrix();
		glm::mat4 projectionMatrix = camera.GetProjectionMatrix();
		//
		
		// Pass the matrices to the shader program
		square->GetShader()->SetUniform("viewMatrix", viewMatrix);
		square->GetShader()->SetUniform("projectionMatrix", projectionMatrix);

		// Draw here
		square->Render();
		//

		m_context->SwapBuffers();
	}
}