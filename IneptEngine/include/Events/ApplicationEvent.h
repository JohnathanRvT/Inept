#pragma once

#include <Events/Event.h>

namespace IneptEngine::Events {
	/**
	 * @class AppTickEvent
	 * @brief Represents an application tick event.
	 * This event is triggered at a fixed time interval, typically used for physics updates.
	 */
	class AppTickEvent : public Event {
	public:
		/**
		 * @brief Constructor
		 */
		AppTickEvent() : Event(EventType::AppTick, EventCategory::Application) {}

		/**
		 * @fn std::string ToString() const
		 * @brief Returns a string representation of the event.
		 * @return A string representation of the event.
		 * This function returns a string representation of the event, including the time that the event was triggered.
		 */
		std::string ToString() const override {
			std::stringstream ss;
			ss << "AppTickEvent: " << GetTime();
			return ss.str();
		}
	};

	/**
	 * @class AppUpdateEvent
	 * @brief Represents an application update event.
	 * This event is triggered once per frame and is typically used for updating game logic.
	 */
	class AppUpdateEvent : public Event {
	public:
		/**
		 * @brief Constructor
		 */
		AppUpdateEvent() : Event(EventType::AppUpdate, EventCategory::Application) {}

		/**
		 * @fn std::string ToString() const
		 * @brief Returns a string representation of the event.
		 * @return A string representation of the event.
		 * This function returns a string representation of the event, including the time that the event was triggered.
		 */
		std::string ToString() const override {
			std::stringstream ss;
			ss << "AppUpdateEvent: " << GetTime();
			return ss.str();
		}
	};

	/**
	 * @class AppRenderEvent
	 * @brief Represents an application render event.
	 * This event is triggered once per frame and is typically used for rendering graphics.
	 */
	class AppRenderEvent : public Event {
	public:
		/**
		 * @brief Constructor
		 */
		AppRenderEvent() : Event(EventType::AppRender, EventCategory::Application) {}

		/**
		 * @fn std::string ToString() const
		 * @brief Returns a string representation of the event.
		 * @return A string representation of the event.
		 * This function returns a string representation of the event, including the time that the event was triggered.
		 */
		std::string ToString() const override {
			std::stringstream ss;
			ss << "AppRenderEvent: " << GetTime();
			return ss.str();
		}
	};
} // namespace IneptEngine::Events