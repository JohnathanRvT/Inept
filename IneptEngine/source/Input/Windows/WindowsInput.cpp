#ifdef INEPT_PLATFORM_WINDOWS
#include <IneptEngine.h>

#include <Input/Windows/WindowsInput.h>

namespace IneptEngine::Input {
    WindowsInput::WindowsInput() : m_Window(NULL)
    {}

    bool WindowsInput::IsKeyPressed(Keyboard::Key key)
    {
        short state = GetAsyncKeyState(static_cast<int>(key));
        return (state & 0x8000) != 0;
    }

    bool WindowsInput::IsMouseButtonPressed(int button)
    {
        short state = GetAsyncKeyState(static_cast<int>(button));
        return (state & 0x8000) != 0;
    }

    std::pair<int, int> WindowsInput::GetMousePosition()
    {
        POINT p;
        GetCursorPos(&p);
        ScreenToClient(m_Window->GetHandle(), &p);
        return std::make_pair(p.x, p.y);
    }

    std::map<Keyboard::Key, bool> WindowsInput::GetKeyStates()
    {
        std::map<Keyboard::Key, bool> keyStates;

        for (int i = 0; i < 256; i++)
        {
            short state = GetAsyncKeyState(i);
            bool isPressed = (state & 0x8000) != 0;
            Keyboard::Key key = static_cast<Keyboard::Key>(i);
            keyStates[key] = isPressed;
        }

        return keyStates;
    }

    std::map<int, bool> WindowsInput::GetMouseButtonStates()
    {
        std::map<int, bool> buttonStates;

        for (int i = 0; i < 3; i++)
        {
            short state = GetAsyncKeyState(i);
            bool isPressed = (state & 0x8000) != 0;
            buttonStates[i] = isPressed;
        }

        return buttonStates;
    }
    
    void WindowsInput::RegisterKeyCallback(Keyboard::Key key, std::function<void(int)> callback)
    {
        m_keyCallbacks[static_cast<int>(key)].push_back(callback);
    }

    void WindowsInput::RegisterAllKeyCallback(std::function<void(Keyboard::Key)> callback)
    {
        m_allKeyCallbacks.push_back(callback);
    }

    void WindowsInput::RegisterMouseButtonCallback(int button, std::function<void(int)> callback)
    {
        m_mouseButtonCallbacks[button].push_back(callback);
    }

    void WindowsInput::RegisterMouseMoveCallback(std::function<void(int, int)> callback)
    {
        m_mouseMoveCallbacks.push_back(callback);
    }

    LRESULT CALLBACK WindowsInput::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        WindowsWindow* pWindow = nullptr;
        if (message == WM_NCCREATE)
        {
            CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
            pWindow = static_cast<WindowsWindow*>(pCreate->lpCreateParams);
            SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWindow));
        }
        else
        {
            pWindow = reinterpret_cast<WindowsWindow*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
        }

        if (pWindow)
        {
            WindowsInput* inputmanager = dynamic_cast<WindowsInput*>(pWindow->GetInputManager());
            if (!inputmanager) {
                LOG_ERROR("Input manager is not of the correct type!");
                return 0;
            }

            inputmanager->SetWindow(pWindow);
            inputmanager->HandleWindowsMessage(pWindow, message, wParam, lParam);
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
        return 0;
    }

    void WindowsInput::HandleWindowsMessage(WindowsWindow* window, UINT message, WPARAM wParam, LPARAM lParam)
    {
        switch (message)
        {
        case WM_CHAR:
        {
            unsigned int scanCode = (lParam >> 16) & 0xFF;
            unsigned int virtualKeyCode = MapVirtualKey(scanCode, MAPVK_VSC_TO_VK);
            const Keyboard::Key keyCode = (Keyboard::Key)virtualKeyCode;
            for (auto& callback : m_allKeyCallbacks)
            {
                callback(keyCode);
            }
        break; 
        }
        case WM_KEYDOWN:
        case WM_SYSKEYDOWN:
        {
            int key = static_cast<int>(wParam);
            for (auto& callback : m_keyCallbacks[key])
            {
                callback(key);
            }
            
            break;
        }
        case WM_LBUTTONDOWN:
        case WM_MBUTTONDOWN:
        case WM_RBUTTONDOWN:
        {
            int button = 0;
            if (message == WM_LBUTTONDOWN)
            {
                button = 0;
            }
            else if (message == WM_MBUTTONDOWN)
            {
                button = 1;
            }
            else if (message == WM_RBUTTONDOWN)
            {
                button = 2;
            }
            for (auto& callback : m_mouseButtonCallbacks[button])
            {
                callback(button);
            }
            break;
        }
        case WM_MOUSEMOVE:
        {
            int x = GET_X_LPARAM(lParam);
            int y = GET_Y_LPARAM(lParam);

            for (auto& callback : m_mouseMoveCallbacks)
            {
                callback(x, y);
            }
            break;
        }
        case WM_CLOSE: {
            // Create an instance of the event to publish
            EVENT_PUBLISH_NOW(WindowCloseEvent);

            DestroyWindow(m_Window->GetHandle());
        }
        case WM_SIZE: {
            // Publish the event to the event buffer
            EVENT_PUBLISH(WindowResizeEvent,m_Window->GetWidth(),m_Window->GetHeight());
        }
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            break;
        }
    }

    void WindowsInput::PollEvents()
    {
        // Use the Windows API to check for any new input events

        // Get the next message from the queue
        MSG msg;
        if (PeekMessage(&msg, m_Window->GetHandle(), 0, 0, PM_REMOVE))
        {
            // Handle the message
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    void WindowsInput::SetWindow(WindowsWindow* window)
    {
        m_Window = window;
    }
}
#endif