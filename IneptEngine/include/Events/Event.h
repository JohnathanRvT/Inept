#pragma once

#include <Events/EventBus.h>

#define TIME_NOW std::chrono::system_clock::now()

namespace IneptEngine::Events {
	/**
	  @brief Enum for the different types of events
	 */
	enum class EventType {
		None = 0,
		WindowClose,
		WindowResize,
		WindowFocus,
		WindowLostFocus,
		WindowMoved,
		WindowMinimized,
		WindowRestored,
		AppTick,
		AppUpdate,
		AppRender,
		KeyPressed,
		KeyReleased,
		KeyTyped,
		KeyHeld,
		KeyRepeated,
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};

	/**
	  @brief Enum for the different categories of events
	 */
	enum EventCategory {
		None = 0,
		Application = 1 << 0,
		Window = 1 << 1,
		Input = 1 << 2,
		Keyboard = 1 << 3,
		Mouse = 1 << 4,
		MouseButton = 1 << 5,
	};

	/**
	@class Event
	@brief Base class for all events.
	This class provides a common interface for all events, including functions for getting the event type and category.
	*/
	class Event {
	public:
		/**
		  @brief Performs a bitwise OR operation between two EventCategory values and returns the result.
		 */
		EventCategory operator|(EventCategory rhs) {
			return static_cast<EventCategory>(static_cast<int>(this->GetCategory()) | static_cast<int>(rhs));
		}

		/**
		  @brief Performs a bitwise AND operation between two EventCategory values and returns the result.
		 */
		EventCategory operator&(EventCategory rhs) {
			return static_cast<EventCategory>(static_cast<int>(this->GetCategory()) & static_cast<int>(rhs));
		}

		/**
		  @brief Constructor
		  @param type The type of the event
		  @param category The category of the event
		 */
		Event(EventType type, EventCategory category) : m_type(type), m_category(category) {
			m_timestamp = TIME_NOW;
		}

		/**
		 @fn EventType GetType() const
		 @brief Gets the type of the event
		 @return The type of the event
		 */
		EventType GetType() const { return m_type; }

		/**
		  @fn EventCategory GetCategory() const
		  @brief Gets the category of the event
		  @return The category of the event
		 */
		EventCategory GetCategory() const { return m_category; }

		/**
		@fn std::string GetTime() const
		@brief Returns the timestamp of the event as a string.
		@return The timestamp of the event as a string.
		*/
		std::string GetTime() const {
			std::stringstream ss;
			using namespace std::chrono;
			zoned_time zt(current_zone(), m_timestamp);
			ss << std::format("{:%T}", zt);
			return ss.str();
		}

		/**
		@fn std::string ToString() const
		@brief Returns a string representation of the event.
		@return A string representation of the event.
		This function returns a string representation of the event, which includes the event type and category.
		*/
		virtual std::string ToString() const {
			std::stringstream ss;
			ss << "Event: " << TypeToString(m_type) << ", Category: " << CategoryToString(m_category) << " at " << GetTime();
			return ss.str();
		}

		/**
		@fn std::string TypeToString(EventType type)
		@brief Converts an event type to a string representation
		@param type The event type to convert
		@return A string representation of the event type
		*/
		static std::string TypeToString(EventType type) {
			switch (type) {
			case EventType::None:
				return "None";
			case EventType::WindowClose:
				return "WindowClose";
			case EventType::WindowResize:
				return "WindowResize";
			case EventType::WindowFocus:
				return "WindowFocus";
			case EventType::WindowLostFocus:
				return "WindowLostFocus";
			case EventType::WindowMoved:
				return "WindowMoved";
			case EventType::WindowMinimized:
				return "WindowMinimized";
			case EventType::WindowRestored:
				return "WindowRestored";
			case EventType::AppTick:
				return "AppTick";
			case EventType::AppUpdate:
				return "AppUpdate";
			case EventType::AppRender:
				return "AppRender";
			case EventType::KeyPressed:
				return "KeyPressed";
			case EventType::KeyReleased:
				return "KeyReleased";
			case EventType::KeyTyped:
				return "KeyTyped";
			case EventType::KeyHeld:
				return "KeyHeld";
			case EventType::KeyRepeated:
				return "KeyRepeated";
			case EventType::MouseButtonPressed:
				return "MouseButtonPressed";
			case EventType::MouseButtonReleased:
				return "MouseButtonReleased";
			case EventType::MouseMoved:
				return "MouseMoved";
			case EventType::MouseScrolled:
				return "MouseScrolled";
			}
			return "Unknown";
		}

		/**
		@fn std::string CategoryToString(EventCategory category)
		@brief Converts an event category to a string representation
		@param category The event category to convert
		@return A string representation of the event category
		*/
		static std::string CategoryToString(EventCategory category) {
			std::stringstream ss;

			if (category & EventCategory::Application)
				ss << "Application | ";
			if (category & EventCategory::Input)
				ss << "Input | ";
			if (category & EventCategory::Keyboard)
				ss << "Keyboard | ";
			if (category & EventCategory::Mouse)
				ss << "Mouse | ";
			if (category & EventCategory::MouseButton)
				ss << "Mouse Button | ";

			std::string result = ss.str();
			if (!result.empty())
			{
				result.pop_back(); // remove trailing ' | '
				result.pop_back();
			}

			return result;
		}

	private:
		EventType m_type;
		EventCategory m_category;
		std::chrono::system_clock::time_point m_timestamp;
	};

} // namespace IneptEngine::Events