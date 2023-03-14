#pragma once

#include <Events/Event.h>

namespace IneptEngine::Events {
/**
* @brief Represents a window event
 */
class WindowEvent : public Event {
public:
	/**
	* @brief Constructor
	 * @param type The type of the window event
	 */
	WindowEvent(EventType type) : Event(type, EventCategory::Window) {}

	/**
* @fn std::string ToString() const
* @brief Returns a string representation of the event
* @return A string representation of the event
* This function returns a string representation of the event, including the event type and the time at which the event occurred.
*/
	virtual std::string ToString() const override {
		std::stringstream ss;
		ss << "WindowEvent: " << GetTime();
		return ss.str();
	}
};

/**
* @class WindowCloseEvent
* @brief Represents a window close event.
* This event is triggered when the user attempts to close the window.
*/
class WindowCloseEvent : public WindowEvent {
public:
	/**
	 * @brief Constructor
	 * @param window The window that this event is for
	 */
	WindowCloseEvent() : WindowEvent(EventType::WindowClose) {}

	/**
	 * @fn std::string ToString() const
	 * @brief Returns a string representation of the event
	 * @return A string representation of the event
	 * This function returns a string representation of the event, including the event type and the time at which the event occurred.
	 */
	std::string ToString() const override {
		std::stringstream ss;
		ss << "WindowCloseEvent: " << GetTime();
		return ss.str();
	}
};

/**
* @class WindowResizeEvent
* @brief Represents a window resize event.
* This event is triggered when the user resizes the window. It includes the new width and height of the window.
*/
class WindowResizeEvent : public WindowEvent {
public:
	/**
	 * @brief Constructor
	 * @param window The window that this event is for
	 * @param width The new width of the window
	 * @param height The new height of the window
	 */
	WindowResizeEvent(int width, int height) : WindowEvent(EventType::WindowResize), m_width(width), m_height(height) {}

	/**
	 * @fn int GetWidth() const
	 * @brief Gets the new width of the window
	 * @return The new width of the window
	 */
	int GetWidth() const { return m_width; }

	/**
	 * @fn int GetHeight() const
	 * @brief Gets the new height of the window
	 * @return The new height of the window
	 */
	int GetHeight() const { return m_height; }

	/**
	*@fn std::string ToString() const
	*@brief Returns a string representation of the event.
	*@return A string representation of the event.
	*This function returns a string representation of the event, including the time that the event occurred and the new width and height of the window.
	*/
	std::string ToString() const override {
		std::stringstream ss;
		ss << "WindowResizeEvent: " << m_width << ", " << m_height << " at " << GetTime();
		return ss.str();
	}

private:
	int m_width;
	int m_height;
};

/**
* @class WindowFocusEvent
* @brief Represents a window focus event.
* This event is triggered when the window gains focus.
*/
class WindowFocusEvent : public WindowEvent {
public:
	/**
	 * @brief Constructor
	 * @param window The window that this event is for
	 */
	WindowFocusEvent() : WindowEvent(EventType::WindowFocus) {}

	/**
	* @fn std::string ToString() const
	* @brief Returns a string representation of the event.
	* @return A string representation of the event.
	* This function returns a string representation of the event, including the time that the event occurred.
	*/
	std::string ToString() const override {
		std::stringstream ss;
		ss << "WindowFocusEvent: " << GetTime();
		return ss.str();
	}
};

/**
* @class WindowLostFocusEvent
* @brief Represents a window lost focus event.
* This event is triggered when the window loses focus.
*/
class WindowLostFocusEvent : public WindowEvent {
public:
	/**
	 * @brief Constructor
	 * @param window The window that this event is for
	 */
	WindowLostFocusEvent() : WindowEvent(EventType::WindowLostFocus) {}

	/**
	 * @fn std::string ToString() const
	 * @brief Returns a string representation of the event.
	 * @return A string representation of the event.
	 * This function returns a string representation of the event, including the time that the event occurred.
	 */
	std::string ToString() const override {
		std::stringstream ss;
		ss << "WindowLostFocusEvent: " << GetTime();
		return ss.str();
	}
};

/**
* @class WindowMovedEvent
* @brief Represents a window moved event.
* This event is triggered when the user moves the window. It includes the new x and y position of the window.
*/
class WindowMovedEvent : public WindowEvent {
public:
	/**
	 * @brief Constructor
	 * @param window The window that this event is for
	 * @param x The new x position of the window
	 * @param y The new y position of the window
	 */
	WindowMovedEvent(int x, int y) : WindowEvent(EventType::WindowMoved), m_x(x), m_y(y) {}

	/**
	 * @fn int GetX() const
	 * @brief Gets the new x position of the window
	 * @return The new x position of the window
	 */
	int GetX() const { return m_x; }

	/**
	 * @fn int GetY() const
	 * @brief Gets the new y position of the window
	 * @return The new y position of the window
	 */
	int GetY() const { return m_y; }

	/**
	* @fn std::string ToString() const
	* @brief Returns a string representation of the event.
	* @return A string representation of the event.
	* This function returns a string representation of the event, including the time that the event occurred and the new x and y position of the window.
	*/
	std::string ToString() const override {
		std::stringstream ss;
		ss << "WindowMovedEvent: " << m_x << ", " << m_y << " at " << GetTime();
		return ss.str();
	}

private:
	int m_x;
	int m_y;
};

/**
* @class WindowMinimizedEvent
* @brief Represents a window minimize event.
* This event is triggered when the window is minimized.
*/
class WindowMinimizedEvent : public WindowEvent {
public:
	/**
	 * @brief Constructor
	 * @param window The window that this event is for
	 */
	WindowMinimizedEvent() : WindowEvent(EventType::WindowMinimized) {}

	/**
	 * @fn std::string ToString() const
	 * @brief Returns a string representation of the event.
	 * @return A string representation of the event.
	 * This function returns a string representation of the event, including the time that the event occurred.
	 */
	std::string ToString() const override {
		std::stringstream ss;
		ss << "WindowMinimizedEvent: " << GetTime();
		return ss.str();
	}
};
/**
* @class WindowRestoredEvent
* @brief Represents a window restore event.
* This event is triggered when the window is restored.
*/
class WindowRestoredEvent : public WindowEvent {
public:
	/**
	 * @brief Constructor
	 * @param window The window that this event is for
	 */
	WindowRestoredEvent() : WindowEvent(EventType::WindowRestored) {}

	/**
	 * @fn std::string ToString() const
	 * @brief Returns a string representation of the event.
	 * @return A string representation of the event.
	 * This function returns a string representation of the event, including the time that the event occurred.
	 */
	std::string ToString() const override {
		std::stringstream ss;
		ss << "WindowRestoredEvent: " << GetTime();
		return ss.str();
	}
};
} // namespace IneptEngine::Events