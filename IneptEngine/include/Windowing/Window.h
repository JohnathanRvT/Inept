#pragma once

#include <Input/Input.h>
using namespace IneptEngine::Input;
#include <Rendering/Renderer.h>
using namespace IneptEngine::Rendering;

#include <string>

namespace IneptEngine::Windowing
{
    /*
   The Window class is a cross-platform implementation for creating a window in C++.
   It abstracts away platform-specific code,
   allowing for the creation of a window that can be used on multiple operating systems,
   such as Windows, MacOS, Android and Linux.
   This allows for a consistent and streamlined development experience when
   creating graphical applications in C++.
   */
    class Window
    {
    public:

        // Static create function for cross platform support of WindowBase
        static Window* CreateIneptWindow(Window* parent = nullptr, int width = 800, int height = 600, const std::string title = "Inept Window");
        /*
         * @brief Constructor for the Window class.
         * @param parent A pointer to the parent window.
         * @param width The width of the window.
         * @param height The height of the window.
         * @param title The title of the window.
         */
        Window(Window* parent = nullptr, int width = 800, int height = 600, const std::string title = "Inept Window") {
        }

        /*
         * @brief Virtual destructor for the Window class.
         */
        virtual ~Window() {
            delete m_inputManager;
            delete m_renderer;
        };

        /*
         The default constructor, copy constructor,
         copy assignment operator, move constructor,
         and move assignment operator of Window have been deleted.
         This is done to prevent unwanted copying or moving of Window objects
         as it may not make sense or have unexpected behavior in certain cases.
         */
        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;
        Window(Window&&) = delete;
        Window& operator=(Window&&) = delete;

        /*
        * @brief Updates the window.
        */
        virtual void Update() = 0;

        /*
         * @brief Close the window.
         */
        virtual void Close() = 0;

        /*
         * @brief Show the window.
        */
        virtual void Show() = 0;

        /*
         * @brief Hide the window.
         */
        virtual void Hide() = 0;

        /*
         * @brief Check if the window is currently visible.
         * @return true if the window is visible, false otherwise.
         */
        virtual bool IsVisible() = 0;

        /*
         * @brief Move the window to a specific position.
         * @param x The x-coordinate of the new position.
         * @param y The y-coordinate of the new position.
         */
        virtual void Move(int x, int y) = 0;

        /*
         * @brief Resize the window to a specific size.
         * @param width The new width of the window.
         * @param height The new height of the window.
         */
        virtual void Resize(int width, int height) = 0;

        /*
         * @brief Check if the window is currently maximized.
         * @return true if the window is maximized, false otherwise.
         */
        virtual bool IsMaximized() = 0;

        /*
         * @brief Check if the window is currently minimized.
         * @return true if the window is minimized, false otherwise.
         */
        virtual bool IsMinimized() = 0;

        /*
         * @brief Minimize the window.
         */
        virtual void Minimize() = 0;

        /*
         *  @brief Maximize the window.
         */
        virtual void Maximize() = 0;

        /*
         * @brief Restore the window to its previous state (before it was minimized or maximized).
         */
        virtual void Restore() = 0;

        /*
         * @brief Show the window in full-screen mode.
         */
        virtual void ShowFullScreen() = 0;

        /*
         * @brief Exit full-screen mode and restore the window to its previous size and position.
         */
        virtual void CloseFullScreen() = 0;

        /*
         * @brief Set the full-screen state of the window.
         * @param fullscreen true to show the window in full-screen mode, false to exit full-screen mode.
         */
        virtual void SetFullscreen(bool fullscreen) = 0;

        /*
         * @brief Check if the window currently has focus.
         * @return true if the window has focus, false otherwise.
         */
        virtual bool IsFocused() = 0;

        /*
         * @brief Set the title of the window.
         * @param title The new title of the window.
         */
        virtual void SetTitle(const std::string title) = 0;

        /*
         * @brief Get the title of the window.
         * @return The title of the window.
         */
        virtual const std::string GetTitle() = 0;

        /*
         * @brief Set the position of the window.
         * @param x The x-coordinate of the new position.
         * @param y The y-coordinate of the new position.
         */
        virtual void SetPosition(int x, int y) = 0;

        /*
         * @brief Set the size of the window.
         * @param width The new width of the window.
         * @param height The new height of the window.
         */
        virtual void SetSize(int width, int height) = 0;

        /*
         * @brief Gets the width of the window.
         */
        virtual int GetWidth() = 0;

        /*
         * @brief Gets the height of the window.
         */
        virtual int GetHeight() = 0;

        /*
         * @brief Add a child window to the current window.
         * @param child A pointer to the child window.
         */
        virtual void AddChild(Window* child) = 0;

        /*
         * @brief Remove a child window from the current window.
         * @param child A pointer to the child window.
         */
        virtual void RemoveChild(Window* child) = 0;

        /*
         * @brief Remove all child windows from the current window.
         */
        virtual void RemoveAllChildren() = 0;

        /*
         * @brief Return the parent of the window if any
         */
        virtual Window* GetParentWindow() = 0;

        /*
         * @brief Sets the parent of the window
        */
        virtual void SetParentWindow(Window* parent) = 0;

        /*
         * @brief Get the input manager for the window.
         * @return A pointer to the input manager for the window.
         */
        InputManager* GetInputManager() { return m_inputManager; }

        /*
        * @brief Get the renderer for the window.
        * @return A pointer to the renderer for the window.
        */
        Renderer* GetRenderer() { return m_renderer; }

        /*
        * @brief Create the renderer for the window.
        * @return A pointer to the renderer for the window.
        */
        void CreateRenderer(RenderingAPI api) { m_renderer = Renderer::CreateRenderer(this, api); }
    protected:
        InputManager* m_inputManager;
        Window* m_parent = nullptr;
        Renderer* m_renderer = nullptr;
        virtual void Create(Window* parent = nullptr, int width = 800, int height = 600, const std::string title = "Inept Window") = 0;
    };
} // namespace IneptEngine::Windowing
