#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

#include <Windows.h>



namespace IneptEngine::Input {
	class Keyboard {
	public:
		enum Key {
			KEY_NONE = 0,

			KEY_ESCAPE = 0x1B,
			KEY_1 = 0x31,
			KEY_2 = 0x32,
			KEY_3 = 0x33,
			KEY_4 = 0x34,
			KEY_5 = 0x35,
			KEY_6 = 0x36,
			KEY_7 = 0x37,
			KEY_8 = 0x38,
			KEY_9 = 0x39,
			KEY_0 = 0x30,
			KEY_MINUS = 45,
			KEY_EQUALS = 61,
			KEY_BACKSPACE = 0x08,
			KEY_TAB = 0x09,
			KEY_Q = 0x51,
			KEY_W = 0x57,
			KEY_E = 0x45,
			KEY_R = 0x52,
			KEY_T = 0x54,
			KEY_Y = 0x59,
			KEY_U = 0x55,
			KEY_I = 0x49,
			KEY_O = 0x4F,
			KEY_P = 0x50,
			KEY_q = 113,
			KEY_w = 119,
			KEY_e = 101,
			KEY_r = 114,
			KEY_t = 116,
			KEY_y = 121,
			KEY_u = 117,
			KEY_i = 105,
			KEY_o = 111,
			KEY_p = 112,
			KEY_LBRACKET = 91,
			KEY_RBRACKET = 93,
			KEY_ENTER = 0x0D,
			KEY_LCTRL = 0xA2,
			KEY_A = 0x41,
			KEY_S = 0x53,
			KEY_D = 0x44,
			KEY_F = 0x46,
			KEY_G = 0x47,
			KEY_H = 0x48,
			KEY_J = 0x4A,
			KEY_K = 0x4B,
			KEY_L = 0x4C,
			KEY_a = 97,
			KEY_s = 115,
			KEY_d = 100,
			KEY_f = 102,
			KEY_g = 103,
			KEY_h = 104,
			KEY_j = 106,
			KEY_k = 107,
			KEY_l = 108,
			KEY_SEMICOLON = 59,
			KEY_COLON = 58,
			KEY_APOSTROPHE = 39,
			KEY_QUOTATION = 34,
			KEY_GRAVE = 96,
			KEY_TILDE = 126,
			KEY_LSHIFT = 0xA0,
			KEY_BACKSLASH = 92,
			KEY_PIPE = 92,
			KEY_Z = 0x5A,
			KEY_X = 0x58,
			KEY_C = 0x43,
			KEY_V = 0x56,
			KEY_B = 0x42,
			KEY_N = 0x4E,
			KEY_M = 0x4D,
			KEY_z = 122,
			KEY_x = 120,
			KEY_c = 99,
			KEY_v = 118,
			KEY_b = 98,
			KEY_n = 110,
			KEY_m = 109,
			KEY_COMMA = 44,
			KEY_LANGLEBRACKET = 60,
			KEY_RANGLEBRACKET = 62,
			KEY_PERIOD = 46,
			KEY_SLASH = 44,
			KEY_QUESTION = 47,
			KEY_RSHIFT = 0xA1,
			KEY_KP_STAR = 42,
			KEY_LALT = 0xA4,
			KEY_SPACE = 0x20,
			KEY_CAPSLOCK = 0x14,
			KEY_F1 = 0x70,
			KEY_F2 = 0x71,
			KEY_F3 = 0x72,
			KEY_F4 = 0x73,
			KEY_F5 = 0x74,
			KEY_F6 = 0x75,
			KEY_F7 = 0x76,
			KEY_F8 = 0x77,
			KEY_F9 = 0x78,
			KEY_F10 = 0x79,
			KEY_NUMLOCK = 0x90,
			KEY_SCROLL = 0x91,
			KEY_KP_7 = 0x67,
			KEY_KP_8 = 0x68,
			KEY_KP_9 = 0x69,
			KEY_KP_MINUS = 0x6D,
			KEY_KP_4 = 100,
			KEY_KP_5 = 101,
			KEY_KP_6 = 102,
			KEY_KP_PLUS = 0x4E,
			KEY_KP_1 = 97,
			KEY_KP_2 = 98,
			KEY_KP_3 = 99,
			KEY_KP_0 = 96,
			KEY_KP_DOT = 110,
			KEY_F11 = 0x57,
			KEY_F12 = 0x58,
			KEY_F13 = 0x64,
			KEY_F14 = 0x65,
			KEY_F15 = 0x66,
			KEY_KANA = 0x70,
			KEY_CONVERT = 0x79,
			KEY_NOCONVERT = 0x7B,
			KEY_YEN = 0x7D,
			KEY_KP_EQUALS = 0x8D,
			KEY_CIRCUMFLEX = 0x90,
			KEY_AT = 0x91,
			KEY_UNDERLINE = 0x93,
			KEY_KANJI = 0x94,
			KEY_STOP = 0x95,
			KEY_AX = 0x96,
			KEY_UNLABELED = 0x97,
			KEY_KP_ENTER = 0x9C,
			KEY_RCTRL = 0x9D,
			KEY_KP_COMMA = 0xB3,
			KEY_KP_SLASH = 111,
			KEY_PRINTSCREEN = 0xB7,
			KEY_RALT = 0xB8,
			KEY_PAUSE = 0xC5,
			KEY_HOME = 0xC7,
			KEY_UPARROW = 38,
			KEY_PGUP = 0xC9,
			KEY_LEFTARROW = 37,
			KEY_RIGHTARROW = 39,
			KEY_END = 0xCF,
			KEY_DOWNARROW = 40,
			KEY_PGDN = 0xD1,
			KEY_INS = 0xD2,
			KEY_DEL = 0xD3,
			KEY_LWIN = 0xDB,
			KEY_RWIN = 0xDC,
			KEY_APPS = 0xDD,
			KEY_POWER = 0xDE,
			KEY_SLEEP = 0xDF
		};
		struct KeyCode {
			Key winapi_value;
			std::string string_version;

			KeyCode(Key value, std::string str) :string_version(str), winapi_value(value) {

			}
		};
		enum class KeyModifier {
			None = 0,
			Left_Shift = 340,
			Left_Control = 341,
			Left_Alt = 342,
			Left_Super = 343,
			Right_Shift = 344,
			Right_Control = 345,
			Right_Alt = 346,
			Right_Super = 347,
		};

		Keyboard() {
			// Initialize key state map to all false
			for (int i = 0; i < 512; i++) {
				m_keyState.push_back(false);
			}
		}

		bool IsKeyPressed(Key key);

		bool IsKeyModifierPressed(KeyModifier modifier) const;

		bool IsKeyReleased(Key key);

		bool IsKeyRepeated(Key key);

		std::vector<Key> GetPressedKeys();

		std::vector<bool> GetKeyStates();

		std::vector<KeyModifier> GetPressedModifierKeys();

		void SetKeyState(Key key, bool isPressed);

		void SetKeyModifierState(KeyModifier modifier, bool isPressed);

		void HandleKeyEvent(int platformKeyCode, bool isPressed);

		int KeyToPlatformValue(Key key);

		static std::string KeyToString(Key key) {
			for (const auto& pair : keynames) {
				if (pair.first == key) {
					return pair.second;
				}
			}
			return "Invalid key";
		};

		std::unordered_map<int, Key> keyMap = {
			{VK_ESCAPE , Key::KEY_ESCAPE },
		};
		std::unordered_map<int, KeyModifier> keyModifierMap = {
			{VK_SHIFT, KeyModifier::Left_Shift},
			{VK_CONTROL, KeyModifier::Left_Control},
			{VK_MENU, KeyModifier::Left_Alt},
			{VK_LWIN, KeyModifier::Left_Super},
			{VK_RSHIFT, KeyModifier::Right_Shift},
			{VK_RCONTROL, KeyModifier::Right_Control},
			{VK_RMENU, KeyModifier::Right_Alt},
			{VK_RWIN, KeyModifier::Right_Super},
		};

	private:
		std::vector<bool> m_keyState;
#define NAMEKEY( code, strId ) { code, strId }
#define NAMEKEY2( code ) { KEY_##code, #code }

#define ALIASKEY( alias, code ) { KEY_##code, alias, "" }

		// names not in this list can either be lowercase ascii, or '0xnn' hex sequences
		inline static const std::unordered_map<Key, std::string> keynames =
		{
			NAMEKEY(KEY_ESCAPE, "Escape"),
			NAMEKEY2(1),
			NAMEKEY2(2),
			NAMEKEY2(3),
			NAMEKEY2(4),
			NAMEKEY2(5),
			NAMEKEY2(6),
			NAMEKEY2(7),
			NAMEKEY2(8),
			NAMEKEY2(9),
			NAMEKEY2(0),
			NAMEKEY(KEY_MINUS, "-"),
			NAMEKEY(KEY_EQUALS, "="),
			NAMEKEY(KEY_BACKSPACE, "Backspace"),
			NAMEKEY(KEY_TAB, "Tab"),
			NAMEKEY2(Q),
			NAMEKEY2(W),
			NAMEKEY2(E),
			NAMEKEY2(R),
			NAMEKEY2(T),
			NAMEKEY2(Y),
			NAMEKEY2(U),
			NAMEKEY2(I),
			NAMEKEY2(O),
			NAMEKEY2(P),
			NAMEKEY2(q),
			NAMEKEY2(w),
			NAMEKEY2(e),
			NAMEKEY2(r),
			NAMEKEY2(t),
			NAMEKEY2(y),
			NAMEKEY2(u),
			NAMEKEY2(i),
			NAMEKEY2(o),
			NAMEKEY2(p),
			NAMEKEY(KEY_LBRACKET, "["),
			NAMEKEY(KEY_RBRACKET, "]"),
			NAMEKEY(KEY_ENTER, "Enter"),
			NAMEKEY(KEY_LCTRL, "Left Control"),
			NAMEKEY2(A),
			NAMEKEY2(S),
			NAMEKEY2(D),
			NAMEKEY2(F),
			NAMEKEY2(G),
			NAMEKEY2(H),
			NAMEKEY2(J),
			NAMEKEY2(K),
			NAMEKEY2(L),
			NAMEKEY2(a),
			NAMEKEY2(s),
			NAMEKEY2(d),
			NAMEKEY2(f),
			NAMEKEY2(g),
			NAMEKEY2(h),
			NAMEKEY2(j),
			NAMEKEY2(k),
			NAMEKEY2(l),
			NAMEKEY(KEY_SEMICOLON, ";"),
			NAMEKEY(KEY_APOSTROPHE, "'"),
			NAMEKEY(KEY_QUOTATION, "\""),
			NAMEKEY(KEY_GRAVE, "`"),
			NAMEKEY(KEY_TILDE, "~"),
			NAMEKEY(KEY_LSHIFT, "Left Shift"),
			NAMEKEY(KEY_BACKSLASH, "\\"),
			NAMEKEY(KEY_PIPE, "|"),
			NAMEKEY2(Z),
			NAMEKEY2(X),
			NAMEKEY2(C),
			NAMEKEY2(V),
			NAMEKEY2(B),
			NAMEKEY2(N),
			NAMEKEY2(M),
			NAMEKEY(KEY_COMMA, ","),
			NAMEKEY(KEY_LANGLEBRACKET, "<"),
			NAMEKEY(KEY_RANGLEBRACKET, ">"),
			NAMEKEY(KEY_PERIOD, "."),
			NAMEKEY(KEY_SLASH, "/"),
			NAMEKEY(KEY_QUESTION, "?"),
			NAMEKEY(KEY_RSHIFT, "Right Shift"),
			NAMEKEY(KEY_KP_STAR, "KeyPad Asterix"),
			NAMEKEY(KEY_LALT, "Left Alt"),
			NAMEKEY(KEY_SPACE, "Space"),
			NAMEKEY(KEY_CAPSLOCK, "Caps Lock"),
			NAMEKEY(KEY_F1, "F1"),
			NAMEKEY(KEY_F2, "F2"),
			NAMEKEY(KEY_F3, "F3"),
			NAMEKEY(KEY_F4, "F4"),
			NAMEKEY(KEY_F5, "F5"),
			NAMEKEY(KEY_F6, "F6"),
			NAMEKEY(KEY_F7, "F7"),
			NAMEKEY(KEY_F8, "F8"),
			NAMEKEY(KEY_F9, "F9"),
			NAMEKEY(KEY_F10, "F10"),
			NAMEKEY(KEY_NUMLOCK, "Num Lock"),
			NAMEKEY(KEY_SCROLL, "Scroll Lock"),
			NAMEKEY(KEY_KP_7, "KeyPad 7"),
			NAMEKEY(KEY_KP_8, "KeyPad 8"),
			NAMEKEY(KEY_KP_9, "KeyPad 9"),
			NAMEKEY(KEY_KP_MINUS, "KeyPad Minus"),
			NAMEKEY(KEY_KP_4, "KeyPad 4"),
			NAMEKEY(KEY_KP_5, "KeyPad 5"),
			NAMEKEY(KEY_KP_6, "KeyPad 6"),
			NAMEKEY(KEY_KP_PLUS, "KeyPad Plus"),
			NAMEKEY(KEY_KP_1, "KeyPad 1"),
			NAMEKEY(KEY_KP_2, "KeyPad 2"),
			NAMEKEY(KEY_KP_3, "KeyPad 3"),
			NAMEKEY(KEY_KP_0, "KeyPad 0"),
			NAMEKEY(KEY_KP_DOT, "KeyPad Dot"),
			NAMEKEY(KEY_F11, "F11"),
			NAMEKEY(KEY_F12, "F12"),
			NAMEKEY2(F13),
			NAMEKEY2(F14),
			NAMEKEY2(F15),
			NAMEKEY2(KANA),
			NAMEKEY2(CONVERT),
			NAMEKEY2(NOCONVERT),
			NAMEKEY2(YEN),
			NAMEKEY(KEY_KP_EQUALS, "KeyPad Equals"),
			NAMEKEY2(CIRCUMFLEX),
			NAMEKEY(KEY_AT, "@"),
			NAMEKEY(KEY_COLON, ":"),
			NAMEKEY(KEY_UNDERLINE, "_"),
			NAMEKEY2(KANJI),
			NAMEKEY2(STOP),
			NAMEKEY2(AX),
			NAMEKEY2(UNLABELED),
			NAMEKEY(KEY_KP_ENTER, "KeyPad Enter"),
			NAMEKEY(KEY_RCTRL, "Right Control"),
			NAMEKEY(KEY_KP_COMMA, ","),
			NAMEKEY(KEY_KP_SLASH, "KeyPad /"),
			NAMEKEY(KEY_PRINTSCREEN, "Print Screen"),
			NAMEKEY(KEY_RALT, "Right Alt"),
			NAMEKEY(KEY_PAUSE, "Pause"),
			NAMEKEY(KEY_HOME, "Home"),
			NAMEKEY(KEY_UPARROW, "Up Arrow"),
			NAMEKEY(KEY_PGUP, "Page Up"),
			NAMEKEY(KEY_LEFTARROW, "Left Arrow"),
			NAMEKEY(KEY_RIGHTARROW, "Right Arrow"),
			NAMEKEY(KEY_END, "#End"),
			NAMEKEY(KEY_DOWNARROW, "Down Arrow"),
			NAMEKEY(KEY_PGDN, "Page Down"),
			NAMEKEY(KEY_INS, "Insert"),
			NAMEKEY(KEY_DEL, "Delete"),
			NAMEKEY(KEY_LWIN, "Left Windows"),
			NAMEKEY(KEY_RWIN, "Right Windows"),
			NAMEKEY(KEY_APPS, "Apps Key"),
			NAMEKEY2(POWER),
			NAMEKEY2(SLEEP),
			//ALIASKEY("ALT", LALT),
			//ALIASKEY("RIGHTALT", RALT),
			//ALIASKEY("CTRL", LCTRL),
			//ALIASKEY("SHIFT", LSHIFT),
			//ALIASKEY("MENU", APPS),
			//ALIASKEY("COMMAND", LALT),
			//
			//ALIASKEY("KP_HOME", KP_7),
			//ALIASKEY("KP_UPARROW", KP_8),
			//ALIASKEY("KP_PGUP", KP_9),
			//ALIASKEY("KP_LEFTARROW", KP_4),
			//ALIASKEY("KP_RIGHTARROW", KP_6),
			//ALIASKEY("KP_END", KP_1),
			//ALIASKEY("KP_DOWNARROW", KP_2),
			//ALIASKEY("KP_PGDN", KP_3),
			//ALIASKEY("KP_INS", KP_0),
			//ALIASKEY("KP_DEL", KP_DOT),
			//ALIASKEY("KP_NUMLOCK", NUMLOCK),
			//
			//ALIASKEY("-", MINUS),
			//ALIASKEY("=", EQUALS),
			//ALIASKEY("[", LBRACKET),
			//ALIASKEY("]", RBRACKET),
			//ALIASKEY("\\", BACKSLASH),
			//ALIASKEY("/", SLASH),
			//ALIASKEY(",", COMMA),
			//ALIASKEY(".", PERIOD),

			//{ KEY_NONE, NULL }//, NULL }
		};

	//	//	MouseButton btnCodes[10] = {
		//		// --

	//	//		NAMEKEY(MOUSE1, "Mouse Button 1"),
		//		NAMEKEY(MOUSE2, "Mouse Button 2"),
		//		NAMEKEY(MOUSE3, "Mouse Button 3"),
		//		NAMEKEY(MOUSE4, "Mouse Button 4"),
		//		NAMEKEY(MOUSE5, "Mouse Button 5"),
		//		NAMEKEY(MOUSE6, "Mouse Button 6"),
		//		NAMEKEY(MOUSE7, "Mouse Button 7"),
		//		NAMEKEY(MOUSE8, "Mouse Button 8"),

	//	//		NAMEKEY(MWHEELDOWN, "Mouse Wheel Down"),
		//		NAMEKEY(MWHEELUP, "Mouse Wheel Up"),
		//	};
	   // };
	};
}