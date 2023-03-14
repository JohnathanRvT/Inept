#pragma once

#include <Input/Input.h>

#include <Windowing/Windows/WindowsWindow.h>
using namespace IneptEngine::Windowing;

namespace IneptEngine::Input {
	class WindowsInput : public InputManager
	{
	public:
		WindowsInput();
		virtual ~WindowsInput() = default;
		virtual bool IsKeyPressed(Keyboard::Key key) override;
		virtual bool IsMouseButtonPressed(int button) override;
		virtual std::pair<int, int> GetMousePosition() override;
		virtual std::map<Keyboard::Key, bool> GetKeyStates() override;
		virtual std::map<int, bool> GetMouseButtonStates() override;
		virtual void RegisterKeyCallback(Keyboard::Key key, std::function<void(int)> callback) override;
		virtual void RegisterAllKeyCallback(std::function<void(Keyboard::Key)> callback) override;
		virtual void RegisterMouseButtonCallback(int button, std::function<void(int)> callback) override;
		virtual void RegisterMouseMoveCallback(std::function<void(int, int)> callback) override;
		virtual void PollEvents() override;
		static LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	private:
		void HandleWindowsMessage(WindowsWindow* window, UINT message, WPARAM wParam, LPARAM lParam);
		void SetWindow(WindowsWindow* window);

		WindowsWindow* m_Window;

		std::vector<std::function<void(Keyboard::Key)>> m_allKeyCallbacks;
		std::map<int, std::vector<std::function<void(int)>>> m_keyCallbacks;
		std::map<int, std::vector<std::function<void(int)>>> m_mouseButtonCallbacks;
		std::vector<std::function<void(int, int)>> m_mouseMoveCallbacks;

		Keyboard m_keyBoard;
	};
}