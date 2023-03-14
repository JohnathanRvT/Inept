#pragma once

#include <Events/Event.h>
#include <Input/Mouse.h>
using namespace IneptEngine::Input;

namespace IneptEngine::Events {
/**
 * @brief Represents a mouse event
 */
class MouseEvent : public Event {
public:
	/**
	 * @brief Constructs a new MouseEvent
	 * @param type The event type
	 * @param x The x coordinate of the mouse cursor, in pixels
	 * @param y The y coordinate of the mouse cursor, in pixels
	 */
	MouseEvent(EventType type, float x, float y, EventCategory category) : Event(type, static_cast<EventCategory>(category | EventCategory::Mouse | EventCategory::Input)), m_x(x), m_y(y) {}

	/**
	 * @brief Gets the x coordinate of the mouse cursor, in pixels
	 * @return The x coordinate of the mouse cursor, in pixels
	 */
	float GetX() const { return m_x; }

	/**
	 * @brief Gets the y coordinate of the mouse cursor, in pixels
	 * @return The y coordinate of the mouse cursor, in pixels
	 */
	float GetY() const { return m_y; }
	/**
	 * @brief Returns a string representation of the event.
	 * @return A string representation of the event.
	 * This function returns a string representation of the event, which includes the event type, the mouse button that was pressed, and the time at which the event occurred.
	 */
	virtual std::string ToString() const override {
		std::stringstream ss;
		ss << "MouseEvent: " << " at (" << GetX() << ", " << GetY() << ") at " << GetTime();
		return ss.str();
	}

private:
	float m_x;
	float m_y;
};

/**
 * @brief Represents a mouse button pressed event
 */
class MouseButtonPressedEvent : public MouseEvent {
public:
	/**
	 * @brief Constructs a new MouseButtonPressedEvent
	 * @param button The mouse button that was pressed
	 * @param x The x coordinate of the mouse cursor, in pixels
	 * @param y The y coordinate of the mouse cursor, in pixels
	 */
	MouseButtonPressedEvent(IneptEngine::Input::MouseButton button, float x, float y) : MouseEvent(EventType::MouseButtonPressed, x, y, EventCategory::MouseButton), m_button(button) {}

	/**
	 * @brief Gets the mouse button that was pressed
	 * @return The mouse button that was pressed
	 */
	int GetButton() const { return (int)m_button; }

	/**
	 * @brief Returns a string representation of the event.
	 * @return A string representation of the event.
	 * This function returns a string representation of the event, which includes the event type, the mouse button that was pressed, and the time at which the event occurred.
	 */
	std::string ToString() const override {
		std::stringstream ss;
		ss << "MouseButtonPressedEvent: " << GetButton() << " at (" << GetX() << ", " << GetY() << ") at " << GetTime();
		return ss.str();
	}

private:
	IneptEngine::Input::MouseButton m_button;
};
/**
 * @brief Represents a mouse button released event
 */
class MouseButtonReleasedEvent : public MouseEvent {
public:
	/**
	 * @brief Constructs a new MouseButtonReleasedEvent
	 * @param button The mouse button that was released
	 * @param x The x coordinate of the mouse cursor, in pixels
	 * @param y The y coordinate of the mouse cursor, in pixels
	 */
	MouseButtonReleasedEvent(IneptEngine::Input::MouseButton button, float x, float y) : MouseEvent(EventType::MouseButtonReleased, x, y, EventCategory::MouseButton), m_button(button) {}

	/**
	 * @brief Gets the mouse button that was released
	 * @return The mouse button that was released
	 */
	int GetButton() const { return (int)m_button; }

	/**
	 * @brief Returns a string representation of the event.
	 * @return A string representation of the event.
	 * This function returns a string representation of the event, which includes the event type, the mouse button that was released, and the time at which the event occurred.
	 */
	std::string ToString() const override {
		std::stringstream ss;
		ss << "MouseButtonReleasedEvent: " << GetButton() << " at (" << GetX() << ", " << GetY() << ") at " << GetTime();
		return ss.str();
	}

private:
	IneptEngine::Input::MouseButton m_button;
};

/**
 * @brief Represents a mouse moved event
 */
class MouseMovedEvent : public MouseEvent {
public:
	/**
	 * @brief Constructs a new MouseMovedEvent
	 * @param x The x coordinate of the mouse cursor, in pixels
	 * @param y The y coordinate of the mouse cursor, in pixels
	 */
	MouseMovedEvent(float x, float y) : MouseEvent(EventType::MouseMoved, x, y, EventCategory::Mouse) {}

	/**
	 * @brief Returns a string representation of the event.
	 * @return A string representation of the event.
	 * This function returns a string representation of the event, which includes the event type, the coordinates of the mouse cursor, and the time at which the event occurred.
	 */
	std::string ToString() const override {
		std::stringstream ss;
		ss << "MouseMovedEvent: (" << GetX() << ", " << GetY() << ") at " << GetTime();
		return ss.str();
	}
};

/**
 * @brief Represents a mouse scrolled event
 */
class MouseScrolledEvent : public MouseEvent {
public:
	/**
	 * @brief Constructs a new MouseScrolledEvent
	 * @param xOffset The x offset of the scroll wheel, in pixels
	 * @param yOffset The y offset of the scroll wheel, in pixels
	 */
	MouseScrolledEvent(float xOffset, float yOffset) : MouseEvent(EventType::MouseScrolled, xOffset, yOffset, EventCategory::Mouse) {}

	/**
	 * @brief Gets the x offset of the scroll wheel, in pixels
	 * @return The x offset of the scroll wheel, in pixels
	 */
	float GetXOffset() const { return GetX(); }

	/**
	 * @brief Gets the y offset of the scroll wheel, in pixels
	 * @return The y offset of the scroll wheel, in pixels
	 */
	float GetYOffset() const { return GetY(); }

	/**
	 * @brief Returns a string representation of the event.
	 * @return A string representation of the event.
	 * This function returns a string representation of the event, which includes the event type, the offsets of the scroll wheel, and the time at which the event occurred.
	 */
	std::string ToString() const override {
		std::stringstream ss;
		ss << "MouseScrolledEvent: (" << GetXOffset() << ", " << GetYOffset() << ") at " << GetTime();
		return ss.str();
	}
};
} // namespace IneptEngine::Events