#pragma once

#include <Events/Event.h>

#include <Input/Keyboard.h>
using namespace IneptEngine::Input;

namespace IneptEngine::Events {
	/**
	 * @brief Represents a keyboard event
	 */
	class KeyEvent : public Event {
	public:
		/**
		 * @brief Constructs a new KeyEvent
		 * @param type The event type
		 * @param key The key that was pressed or released
		 * @param mods The keyboard modifiers that were active when the event occurred
		 */
		KeyEvent(EventType type, const Keyboard::Key key, Keyboard::KeyModifier mods) : Event(type, static_cast<EventCategory>(EventCategory::Keyboard | EventCategory::Input)), m_key(key), m_mods(mods) {}

		/**
		* @brief Gets the key that was pressed or released
		* @return The key that was pressed or released
		*/
		const Keyboard::Key GetKey() const { return m_key; }

		/**
		 * @brief Gets the keyboard modifiers that were active when the event occurred
		 * @return The keyboard modifiers that were active when the event occurred
		 */
		Keyboard::KeyModifier GetMods() const { return m_mods; }

		/**
		 * @fn std::string ToString() const
		 * @brief Returns a string representation of the event.
		 * @return A string representation of the event.
		 *
		 * This function returns a string representation of the event, which includes the event type, the key that was pressed, released, or typed, and the modifier keys that were held.
		 */
		virtual std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyEvent: " << Keyboard::KeyToString(GetKey()) << " (" << (char)GetMods() << ") at " << GetTime();
			return ss.str();
		}
	private:
		Keyboard::Key m_key;
		Keyboard::KeyModifier m_mods;
	};

	/**
	 * @brief Represents a key pressed event
	 */
	class KeyPressedEvent : public KeyEvent {
	public:
		/**
		 * @brief Constructs a new KeyPressedEvent
		 * @param key The key that was pressed
		 * @param mods The keyboard modifiers that were active when the event occurred
		 */
		KeyPressedEvent(Keyboard::Key  key, Keyboard::KeyModifier mods) : KeyEvent(EventType::KeyPressed, key, mods) {}

		/**
		 * @fn std::string ToString() const
		 * @brief Returns a string representation of the event.
		 * @return A string representation of the event.
		 * This function returns a string representation of the event, which includes the event type, the key that was pressed, and the modifier keys that were held.
		 */
		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << Keyboard::KeyToString(GetKey()) << " (" << (char)GetMods() << ") at " << GetTime();
			return ss.str();
		}
	};

	/**
	 * @brief Represents a key released event
	 */
	class KeyReleasedEvent : public KeyEvent {
	public:
		/**
		 * @brief Constructs a new KeyReleasedEvent
		 * @param key The key that was released
		 * @param mods The keyboard modifiers that were active when the event occurred
		 */
		KeyReleasedEvent(Keyboard::Key  key, Keyboard::KeyModifier mods) : KeyEvent(EventType::KeyReleased, key, mods) {}

		/**
		 * @fn std::string ToString() const
		 * @brief Returns a string representation of the event.
		 * @return A string representation of the event.
		 * This function returns a string representation of the event, which includes the event type, the key that was released, and the modifier keys that were held.
		 */
		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << Keyboard::KeyToString(GetKey()) << " (" << (char)GetMods() << ") at " << GetTime();
			return ss.str();
		}
	};

	/**
	 * @brief Represents a key typed event
	 */
	class KeyTypedEvent : public KeyEvent {
	public:
		/**
		 * @brief Constructs a new KeyTypedEvent
		 * @param key The key that was typed
		 * @param mods The keyboard modifiers that were active when the event occurred
		 */
		KeyTypedEvent(Keyboard::Key key, Keyboard::KeyModifier mods) : KeyEvent(EventType::KeyTyped, key, mods) {}

		/**
		 * @fn std::string ToString() const
		 * @brief Returns a string representation of the event.
		 * @return A string representation of the event.
		 * This function returns a string representation of the event, which includes the event type, the key that was typed, and the modifier keys that were held.
		 */
		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyTypedEvent: " << Keyboard::KeyToString(GetKey()) << " (" << (char)GetMods() << ") at " << GetTime();
			return ss.str();
		}
	};

	/**
	 * @brief Represents a key held event
	 */
	class KeyHeldEvent : public KeyEvent {
	public:
		/**
		 * @brief Constructs a new KeyHeldEvent
		 * @param key The key that was held
		 * @param mods The keyboard modifiers that were active when the event occurred
		 * @param duration The duration that the key was held, in seconds
		 */
		KeyHeldEvent(Keyboard::Key key, Keyboard::KeyModifier mods, float duration) : KeyEvent(EventType::KeyHeld, key, mods), m_duration(duration) {}

		/**
		 * @brief Gets the duration that the key was held, in seconds
		 * @return The duration that the key was held, in seconds
		 */
		float GetDuration() const { return m_duration; }

		/**
		 * @fn std::string ToString() const
		 * @brief Returns a string representation of the event.
		 * @return A string representation of the event.
		 * This function returns a string representation of the event, which includes the event type, the key that was held, and the modifier keys that were held.
		 */
		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyHeldEvent: " << Keyboard::KeyToString(GetKey()) << " (" << (char)GetMods() << ") at " << GetTime();
			return ss.str();
		}
	private:
		float m_duration;
	};

	/**
	 * @brief Represents a key repeated event
	 */
	class KeyRepeatedEvent : public KeyEvent {
	public:
		/**
		 * @brief Constructs a new KeyRepeatedEvent
		 * @param key The key that was repeated
		 * @param mods The keyboard modifiers that were active when the event occurred
		 * @param repeatCount The number of times the key has been repeated
		 */
		KeyRepeatedEvent(Keyboard::Key key, Keyboard::KeyModifier mods, int repeatCount) : KeyEvent(EventType::KeyRepeated, key, mods), m_repeatCount(repeatCount) {}

		/**
		 * @brief Gets the number of times the key has been repeated
		 * @return The number of times the key has been repeated
		 */
		int GetRepeatCount() const { return m_repeatCount; }
		/**
		 * @fn std::string ToString() const
		 * @brief Returns a string representation of the event.
		 * @return A string representation of the event.
		 *
		 * This function returns a string representation of the event, which includes the event type, the key that was repeated, the modifier keys that were held, and the number of times the key was repeated.
		 */
		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyRepeatedEvent: " << Keyboard::KeyToString(GetKey()) << " (" << (char)GetMods() << ")"
				<< " (" << m_repeatCount << " repeats) at " << GetTime();
			return ss.str();
		}
	private:
		int m_repeatCount;
	};

} // namespace IneptEngine::Events
