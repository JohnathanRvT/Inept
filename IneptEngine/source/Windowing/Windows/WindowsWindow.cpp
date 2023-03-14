#ifdef INEPT_PLATFORM_WINDOWS
#include <Windowing/Windows/WindowsWindow.h>

#include <Input/Windows/WindowsInput.h>
using namespace IneptEngine::Input;

#include <Rendering/Renderer.h>
using namespace IneptEngine::Rendering;

#include <memory>

namespace IneptEngine::Windowing
{
   WindowsWindow::WindowsWindow(Window* parent, int width, int height, const std::string title)
   {
       m_inputManager = new WindowsInput();

      // m_inputManager->RegisterMouseMoveCallback([](int x, int y) {
      //     EventBus::GetInstance().Publish(new MouseMovedEvent(x, y));
      //     });
       m_inputManager->RegisterAllKeyCallback([](Keyboard::Key key) {
           //LOG_TRACE("Key: {}",(int)key);
           EVENT_PUBLISH(KeyPressedEvent,key,Keyboard::KeyModifier::None);
           });
      // m_inputManager->RegisterMouseButtonCallback(1, [](int y) {
      //     EventBus::GetInstance().Publish(new MouseButtonPressedEvent((IneptEngine::Input::MouseButton)1, 0,0));
      //     });
       Log::Init();

       Create(parent, width, height, title);

       //m_renderer = Renderer::CreateRenderer(this, RenderingAPI::OpenGL);
       this->Show();
   }

   WindowsWindow::~WindowsWindow()
   {
       Close();
   }
 
    void WindowsWindow::Create(Window* parent, int width, int height, const std::string title)
    {
        // Use the Windows API to create a window
        WindowsInput* inputmanager = dynamic_cast<WindowsInput*>(m_inputManager);
       if (!inputmanager) {
            LOG_ERROR("Input manager is not of the correct type!");
            return;
        }
 
        WNDCLASS wc = { 0 };
        wc.lpfnWndProc = reinterpret_cast<WNDPROC>(&WindowsInput::WndProc);
        wc.hInstance = GetModuleHandle(NULL);
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wc.lpszClassName = "IneptWindow";
        RegisterClass(&wc);

        m_handle = CreateWindowEx(
            0,
            "IneptWindow",
            title.c_str(),
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            width,
            height,
            NULL,
            NULL,
            GetModuleHandle(NULL),
            this);
 
        if (m_handle == NULL) {
            LOG_ERROR("Window creation failed!");
        }
        else {
            LOG_INFO("New window [{0}] [width:{1},height:{2}] created", this->GetTitle(), width, height);
            if (parent != NULL)
                parent->AddChild(this);
        }
    }

  void WindowsWindow::Update()
  {
      m_inputManager->PollEvents();
      if (m_renderer != nullptr) {
          m_renderer->Render();
      }
  }

  void WindowsWindow::Close()
  {
      // Use the Windows API to close the window
      if (DestroyWindow(m_handle))
          LOG_INFO("Destroyed window [{0}]", this->GetTitle());
      else
          LOG_ERROR("Destroying window [{0}] failed!", this->GetTitle());
  }

   void WindowsWindow::Show()
   {
       // Use the Windows API to show the window
       ShowWindow(m_handle, SW_SHOW);
       LOG_INFO("Showing window [{0}]", this->GetTitle());
   }
 
    void WindowsWindow::Hide()
    {
        // Use the Windows API to hide the window
        ShowWindow(m_handle, SW_HIDE);
        LOG_INFO("Hiding window [{0}]", this->GetTitle());
    }
 
    bool WindowsWindow::IsVisible()
    {
        // Use the Windows API to check if the window is visible
        return IsWindowVisible(m_handle) != 0;
    }
 
    void WindowsWindow::Move(int x, int y)
    {
        // Use the Windows API to move the window
        if (SetWindowPos(m_handle, 0, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE)) {
            LOG_INFO("Moved window [{0}] to [{1},{2}]", this->GetTitle(), x, y);

            EVENT_PUBLISH(WindowMovedEvent,x, y);
        }
        else
            LOG_ERROR("Moving window [{0}] failed!", this->GetTitle());

    }
 
    void WindowsWindow::Resize(int width, int height)
    {
        // Use the Windows API to resize the window
        if (SetWindowPos(m_handle, 0, 0, 0, width, height, SWP_NOZORDER | SWP_NOMOVE)) {
            LOG_INFO("Resizing window [{0}] to [{1},{2}]", this->GetTitle(), width, height);

            EVENT_PUBLISH(WindowResizeEvent, width, height);
        }
        else
            LOG_ERROR("Resizing window [{0}] failed!", this->GetTitle());
    }
 
    bool WindowsWindow::IsMaximized()
    {
        // Use the Windows API to check if the window is maximized
        WINDOWPLACEMENT wp;
        wp.length = sizeof(wp);
        GetWindowPlacement(m_handle, &wp);
        return wp.showCmd == SW_MAXIMIZE;
    }
 
    bool WindowsWindow::IsMinimized()
    {
        // Use the Windows API to check if the window is minimized
        WINDOWPLACEMENT wp;
        wp.length = sizeof(wp);
        GetWindowPlacement(m_handle, &wp);
        return wp.showCmd == SW_MINIMIZE;
    }
 
    void WindowsWindow::Minimize()
    {
        // Use the Windows API to minimize the window
        if (ShowWindow(m_handle, SW_MINIMIZE)) {
            LOG_INFO("Minimizing window [{0}]", this->GetTitle());
            EVENT_PUBLISH(WindowMinimizedEvent);
        }
        else
            LOG_ERROR("Minimizing window [{0}] failed!", this->GetTitle());
    }
 
    void WindowsWindow::Maximize()
    {
        // Use the Windows API to maximize the window
        if (ShowWindow(m_handle, SW_MAXIMIZE)) {
            LOG_INFO("Maximizing window [{0}]", this->GetTitle());

            EVENT_PUBLISH(WindowRestoredEvent);
        }
        else
            LOG_ERROR("Maximizing window [{0}] failed!", this->GetTitle());
    }
 
    void WindowsWindow::Restore()
    {
        // Use the Windows API to restore the window
        if (ShowWindow(m_handle, SW_RESTORE)) {
            LOG_INFO("Restoring window [{0}]", this->GetTitle());

            EVENT_PUBLISH(WindowRestoredEvent);
        }
        else
            LOG_ERROR("Restoring window [{0}] failed!", this->GetTitle());
    }
 
    void WindowsWindow::ShowFullScreen()
    {
        // Use the Windows API to set the window to fullscreen
        SetWindowLongPtr(m_handle, GWL_STYLE, WS_POPUP | WS_VISIBLE);
        if (SetWindowPos(m_handle, HWND_TOP, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_SHOWWINDOW)) {
            LOG_INFO("Showing window [{0}] fullscreen", this->GetTitle());

            EVENT_PUBLISH(WindowRestoredEvent);
        }
        else
            LOG_ERROR("Showing window [{0}] fullscreen failed!", this->GetTitle());
    }
 
    void WindowsWindow::CloseFullScreen()
    {
        // Use the Windows API to remove the window from fullscreen
        SetWindowLongPtr(m_handle, GWL_STYLE, WS_OVERLAPPEDWINDOW | WS_VISIBLE);
        if (SetWindowPos(m_handle, 0, 0, 0, 800, 600, SWP_SHOWWINDOW)) {
            LOG_INFO("Closing window [{0}] fullscreen", this->GetTitle());
        }
        else
            LOG_ERROR("Closing window [{0}] fullscreen failed!", this->GetTitle());
    }
 
    void WindowsWindow::SetFullscreen(bool fullscreen)
    {
        if (fullscreen)
            ShowFullScreen();
        else
            CloseFullScreen();
    }
 
    bool WindowsWindow::IsFocused()
    {
        // Use the Windows API to check if the window has focus
        return GetFocus() == m_handle;
    }
 
    void WindowsWindow::SetTitle(const std::string title)
    {
        // Use the Windows API to set the window's title
        std::string oldtitle = this->GetTitle();
        if (SetWindowText(m_handle, title.c_str()))
            LOG_INFO("Setting window [{0}] title to {1}", oldtitle, title);
        else
            LOG_ERROR("Setting window [{0}] title to {1} failed", oldtitle, title);
    }
 
 
    const std::string WindowsWindow::GetTitle()
    {
        // Use the Windows API to get the window's title

        int length = GetWindowTextLength(m_handle);
        std::vector<char> buffer(length + 1);

        if (GetWindowText(m_handle, buffer.data(), buffer.size()))
        {
            return std::string(buffer.data());
        }
        else
        {
            return "";
        }
    }
 
    void WindowsWindow::SetPosition(int x, int y)
    {
        Move(x, y);
    }
 
    void WindowsWindow::SetSize(int width, int height)
    {
        Resize(width, height);
    }
 
    int WindowsWindow::GetWidth()
    {
        RECT rect;
        GetClientRect(m_handle, &rect);
        return rect.right - rect.left;
    }
 
    int WindowsWindow::GetHeight()
    {
        RECT rect;
        GetClientRect(m_handle, &rect);
        return rect.bottom - rect.top;
    }
 
   void WindowsWindow::AddChild(Window* child)
   {
       // Use the Windows API to add a child window
       SetParent(static_cast<WindowsWindow*>(child)->m_handle, m_handle);
       child->SetParentWindow(this);
   }
 
    void WindowsWindow::RemoveChild(Window* child)
    {
        // Use the Windows API to remove a child window
        SetParent(static_cast<WindowsWindow*>(child)->m_handle, NULL);
        SetParentWindow(NULL);
    }
 
    void WindowsWindow::RemoveAllChildren()
    {
        // Use the Windows API to remove all child windows
        EnumChildWindows(
            m_handle, [](HWND hwnd, LPARAM lParam)
            {
                SetParent(hwnd, NULL);
                return TRUE; },
            0);
    }
    Window* WindowsWindow::GetParentWindow()
    {
        return m_parent;
    }
 
   void WindowsWindow::SetParentWindow(Window* parent)
   {
       m_parent = parent;
   }
} // namespace IneptEngine::Windowing
#endif INEPT_PLATFORM_WINDOWS