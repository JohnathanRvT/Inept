#pragma once

#include <iepch.h>
#include <Input/Keyboard.h>

namespace IneptEngine::Input {
        bool Keyboard::IsKeyPressed(Keyboard::Key key) {
            if (key == Keyboard::Key::KEY_NONE) {
                return false;
            }
            int keyIndex = static_cast<int>(key);
            return keyIndex >= 0 && keyIndex < 512 && m_keyState[keyIndex];
        }

        bool Keyboard::IsKeyModifierPressed(Keyboard::KeyModifier modifier) const {
            int modifierIndex = static_cast<int>(modifier);

            return modifierIndex >= 0 && modifierIndex < 512 && m_keyState[modifierIndex];
        }

        bool Keyboard::IsKeyReleased(Keyboard::Key key) {
            if (key == Keyboard::Key::KEY_NONE) {
                return false;
            }
            int keyIndex = static_cast<int>(key);
            auto keyState = m_keyState[keyIndex];
            return (keyState == 0 || keyState == 2);
        }

        bool Keyboard::IsKeyRepeated(Keyboard::Key key) {
            if (key == Keyboard::Key::KEY_NONE) {
                return false;
            }
            int keyIndex = static_cast<int>(key);
            auto keyState = m_keyState[keyIndex];
            return (keyState == 2);
        }

        std::vector<Keyboard::Key> Keyboard::GetPressedKeys() {
            std::vector<Keyboard::Key> pressedKeys;
            for (int i = 0; i < 349; ++i) {
                Key key = static_cast<Key>(i);
                if (IsKeyPressed(key)) {
                    pressedKeys.push_back(key);
                }
            }
            return pressedKeys;
        }

        std::vector<bool> Keyboard::GetKeyStates() {
            return m_keyState;
        }

        std::vector<Keyboard::KeyModifier> Keyboard::GetPressedModifierKeys() {
            std::vector<KeyModifier> pressedKeys;
            for (int i = 0; i < 349; ++i) {
                KeyModifier key = static_cast<KeyModifier>(i);
                if (IsKeyModifierPressed(key)) {
                    pressedKeys.push_back(key);
                }
            }
            return pressedKeys;
        }

        void Keyboard::SetKeyState(Keyboard::Key key, bool isPressed) {
            int keyIndex = static_cast<int>(key);
            if (keyIndex >= 0 && keyIndex < 512) {
                m_keyState[keyIndex] = isPressed;
            }
            if (isPressed) 
            {
                LOG_ERROR("{} : {}", (int)key, isPressed);
                EVENT_PUBLISH(KeyPressedEvent,key, GetPressedModifierKeys()[0]);
            }
            else 
            {
                EVENT_PUBLISH(KeyReleasedEvent,key, GetPressedModifierKeys()[0]);
            }           
        }

        void Keyboard::SetKeyModifierState(KeyModifier modifier, bool isPressed) {
            int modifierIndex = static_cast<int>(modifier);
            if (modifierIndex >= 0 && modifierIndex < 512) {
                m_keyState[modifierIndex] = isPressed;
            }
        }

        void Keyboard::HandleKeyEvent(int platformKeyCode, bool isPressed) {

            LOG_ERROR("{} : {}", platformKeyCode, isPressed);
            auto keyIter = keyMap.find(platformKeyCode);
            if (keyIter != keyMap.end()) {
                // The platform key code was found in the map
                Key key = keyIter->second;
                // Handle the key event using the Key enum value
                SetKeyState(key, isPressed);
            }
            else {
                // The platform key code was not found in the keymap
                auto keyIter = keyModifierMap.find(platformKeyCode);
                if (keyIter != keyModifierMap.end()) {
                    // The platform key code was found in the map
                    KeyModifier key = keyIter->second;
                    // Handle the key event using the Key enum value
                    SetKeyModifierState(key, isPressed);
                } else {
                    // The platform key code was not found in any keymap
                }
            }
        }

        int Keyboard::KeyToPlatformValue(Key key) {
            //for (const auto& pair : keyMap) {
            //    if (pair.second == key) {
            //        return pair.first;
            //    }
            //}
            //return -1; // Invalid key
            return (int)key;
        }
}