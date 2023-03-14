#pragma once

#include <Rendering/Renderer.h>
#include <Rendering/OpenGl/OpenGLContext.h>

#include <glad/glad.h>
#include <Rendering/Square.h>
#include "OpenGLCamera.h"

namespace IneptEngine::Rendering {
    class OpenGLRenderer : public Renderer
    {
    public:
        OpenGLRenderer(IneptEngine::Windowing::Window* window) : Renderer(window) {
            m_context = new OpenGLContext(window);
            m_context->Init();

			//OpenGL+GPU Info
			char Vendor[256];
			char Renderer[256];
			char Version[256];
			std::snprintf(Vendor, sizeof(Vendor), "%s", glGetString(GL_VENDOR));
			std::snprintf(Renderer, sizeof(Renderer), "%s", glGetString(GL_RENDERER));
			std::snprintf(Version, sizeof(Version), "OpenGL Version: %s", glGetString(GL_VERSION));
			LOG_TRACE("OpenGL Info:\n        GPU: {0} {1}\n        {2}", Vendor, Renderer, Version);

			//
			square = new Square({ 0,0 }, 1.0f);
			square->Bind();
			//

			std::unique_ptr<Subscription> sub =	EventBus::GetInstance().Subscribe(EventType::KeyPressed,[this](Event* e) {
				OnKeyPressed(e);
			});

			std::unique_ptr<Subscription> resizeSub = EventBus::GetInstance().Subscribe(EventType::WindowResize, [this](Event* e) {
				OnWindowResize(e);
			});
			camera = OpenGLCamera();
			camera.SetPosition({ 0.0f, 0.0f, 5.0f });
			camera.SetFOV(45.0f);
			camera.SetAspectRatio(4.0f / 3.0f);
			camera.SetNearPlane(0.1f);
			camera.SetFarPlane(100.0f);
			//
			glm::mat4 viewMatrix = camera.GetViewMatrix();
			glm::mat4 projectionMatrix = camera.GetProjectionMatrix();
			//
			
			// Pass the matrices to the shader program
			square->GetShader()->SetUniform("viewMatrix", viewMatrix);
			square->GetShader()->SetUniform("projectionMatrix", projectionMatrix);

			// Draw your scene
			// ...

        }

		void OnWindowResize(Event* e) {
			WindowResizeEvent* resizeEvent = static_cast<WindowResizeEvent*>(e);
			if (resizeEvent->GetWidth() != 0 && resizeEvent->GetHeight() != 0) {

				glViewport(0, 0, resizeEvent->GetWidth(), resizeEvent->GetHeight());
				camera.SetAspectRatio(static_cast<float>(resizeEvent->GetWidth()) / static_cast<float>(resizeEvent->GetHeight()));
				LOG_DEBUG("Aspect Ratio: {}", static_cast<float>(resizeEvent->GetWidth()) / static_cast<float>(resizeEvent->GetHeight()));
				LOG_DEBUG("Width,Height: {},{}",resizeEvent->GetWidth() , resizeEvent->GetHeight());
			}
		}

		void OnKeyPressed(Event* e) {
				KeyPressedEvent* keyevent = static_cast<KeyPressedEvent*>(e);
				if (keyevent->GetKey() == Keyboard::Key::KEY_W)
				{
					camera.MoveUp(1.0f);
				} 
				else if (keyevent->GetKey() == Keyboard::Key::KEY_S)
				{
					camera.MoveDown(1.0f);
				}
				else if (keyevent->GetKey() == Keyboard::Key::KEY_A)
				{
					camera.MoveLeft(1.0f);
				}
				else if (keyevent->GetKey() == Keyboard::Key::KEY_D)
				{
					camera.MoveRight(1.0f);
				}
				else if (keyevent->GetKey() == Keyboard::Key::KEY_Q)
				{
					camera.MoveForward(1.0f);
				}
				else if (keyevent->GetKey() == Keyboard::Key::KEY_E)
				{
					camera.MoveBackward(1.0f);
				}
				else if (keyevent->GetKey() == Keyboard::Key::KEY_R)
				{
					camera.Rotate(0, 1);
				}
				else if (keyevent->GetKey() == Keyboard::Key::KEY_F)
				{
					camera.Rotate(0, -1);
				}
				else if (keyevent->GetKey() == Keyboard::Key::KEY_Z)
				{
					camera.Rotate(1, 0);
				}
				else if (keyevent->GetKey() == Keyboard::Key::KEY_C)
				{
					camera.Rotate(-1, 0);
				}
				//LOG_DEBUG("{}",keyevent->ToString());
		}
        virtual ~OpenGLRenderer();

        virtual void Render() override;
	private:
		OpenGLCamera camera;
		Square* square;
    };
}
