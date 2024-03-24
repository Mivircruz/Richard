#pragma once
#include "button.h"
#include <map>

namespace Richard::Input {
	class Keyboard {
	public:
		/*Methods*/

		/*
		* Constructor. It creates the object Keyboard.
		*/
		Keyboard();

		/*
		* Destructor. It destroys the object Keyboard.
		*/
		~Keyboard();

		/*
		* Initialize() initializes the keys map.
		*/
		static void Initialize();

		/*
		* Update() gets the current state of the keyboard
		* and it updates every key state.
		*/
		static void Update();

		/*
		* GetKeyCurrentState() returns the current status of the key given in the argument.
		*/
		static int GetKeyCurrentState(int keyName);


	private:
		/*Member variables*/
		/*
		* Keyboard buttons.
		*/
		static map<int, Button> mKeys;

		/*
		* Amount of keys.
		*/
		static const int mKeysAmount = 286;
	};
}

/*
* Keys  available.
* SDL supports up to 286 mouse buttons.
* Adapted from SDL - check SDL_NUM_SCANCODES for more information.
*/
const int KEYBOARD_KEY_A = 4;
const int KEYBOARD_KEY_B = 5;
const int KEYBOARD_KEY_C = 6;
const int KEYBOARD_KEY_D = 7;
const int KEYBOARD_KEY_E = 8;
const int KEYBOARD_KEY_F = 9;
const int KEYBOARD_KEY_G = 10;
const int KEYBOARD_KEY_H = 11;
const int KEYBOARD_KEY_I = 12;
const int KEYBOARD_KEY_J = 13;
const int KEYBOARD_KEY_K = 14;
const int KEYBOARD_KEY_L = 15;
const int KEYBOARD_KEY_M = 16;
const int KEYBOARD_KEY_N = 17;
const int KEYBOARD_KEY_O = 18;
const int KEYBOARD_KEY_P = 19;
const int KEYBOARD_KEY_Q = 20;
const int KEYBOARD_KEY_R = 21;
const int KEYBOARD_KEY_S = 22;
const int KEYBOARD_KEY_T = 23;
const int KEYBOARD_KEY_U = 24;
const int KEYBOARD_KEY_V = 25;
const int KEYBOARD_KEY_W = 26;
const int KEYBOARD_KEY_X = 27;
const int KEYBOARD_KEY_Y = 28;
const int KEYBOARD_KEY_Z = 29;
const int KEYBOARD_KEY_1 = 30;
const int KEYBOARD_KEY_2 = 31;
const int KEYBOARD_KEY_3 = 32;
const int KEYBOARD_KEY_4 = 33;
const int KEYBOARD_KEY_5 = 34;
const int KEYBOARD_KEY_6 = 35;
const int KEYBOARD_KEY_7 = 36;
const int KEYBOARD_KEY_8 = 37;
const int KEYBOARD_KEY_9 = 38;
const int KEYBOARD_KEY_0 = 39;
const int KEYBOARD_KEY_RETURN = 40;
const int KEYBOARD_KEY_ESCAPE = 41;
const int KEYBOARD_KEY_BACKSPACE = 42;
const int KEYBOARD_KEY_TAB = 43;
const int KEYBOARD_KEY_SPACE = 44;
const int KEYBOARD_KEY_MINUS = 45;
const int KEYBOARD_KEY_EQUALS = 46;
const int KEYBOARD_KEY_LEFTBRACKET = 47;
const int KEYBOARD_KEY_RIGHTBRACKET = 48;
const int KEYBOARD_KEY_BACKSLASH = 49;
const int KEYBOARD_KEY_NONUSHASH = 50;
const int KEYBOARD_KEY_SEMICOLON = 51;
const int KEYBOARD_KEY_APOSTROPHE = 52;
const int KEYBOARD_KEY_GRAVE = 53;
const int KEYBOARD_KEY_COMMA = 54;
const int KEYBOARD_KEY_PERIOD = 55;
const int KEYBOARD_KEY_SLASH = 56;
const int KEYBOARD_KEY_CAPSLOCK = 57;
const int KEYBOARD_KEY_F1 = 58;
const int KEYBOARD_KEY_F2 = 59;
const int KEYBOARD_KEY_F3 = 60;
const int KEYBOARD_KEY_F4 = 61;
const int KEYBOARD_KEY_F5 = 62;
const int KEYBOARD_KEY_F6 = 63;
const int KEYBOARD_KEY_F7 = 64;
const int KEYBOARD_KEY_F8 = 65;
const int KEYBOARD_KEY_F9 = 66;
const int KEYBOARD_KEY_F10 = 67;
const int KEYBOARD_KEY_F11 = 68;
const int KEYBOARD_KEY_F12 = 69;
const int KEYBOARD_KEY_PRINTSCREEN = 70;
const int KEYBOARD_KEY_SCROLLLOCK = 71;
const int KEYBOARD_KEY_PAUSE = 72;
const int KEYBOARD_KEY_INSERT = 73;
const int KEYBOARD_KEY_HOME = 74;
const int KEYBOARD_KEY_PAGEUP = 75;
const int KEYBOARD_KEY_DELETE = 76;
const int KEYBOARD_KEY_END = 77;
const int KEYBOARD_KEY_PAGEDOWN = 78;
const int KEYBOARD_KEY_RIGHT = 79;
const int KEYBOARD_KEY_LEFT = 80;
const int KEYBOARD_KEY_DOWN = 81;
const int KEYBOARD_KEY_UP = 82;
const int KEYBOARD_KEY_NUMLOCKCLEAR = 83;
const int KEYBOARD_KEY_KP_DIVIDE = 84;
const int KEYBOARD_KEY_KP_MULTIPLY = 85;
const int KEYBOARD_KEY_KP_MINUS = 86;
const int KEYBOARD_KEY_KP_PLUS = 87;
const int KEYBOARD_KEY_KP_ENTER = 88;
const int KEYBOARD_KEY_KP_1 = 89;
const int KEYBOARD_KEY_KP_2 = 90;
const int KEYBOARD_KEY_KP_3 = 91;
const int KEYBOARD_KEY_KP_4 = 92;
const int KEYBOARD_KEY_KP_5 = 93;
const int KEYBOARD_KEY_KP_6 = 94;
const int KEYBOARD_KEY_KP_7 = 95;
const int KEYBOARD_KEY_KP_8 = 96;
const int KEYBOARD_KEY_KP_9 = 97;
const int KEYBOARD_KEY_KP_0 = 98;
const int KEYBOARD_KEY_KP_PERIOD = 99;
const int KEYBOARD_KEY_NONUSBACKSLASH = 100;
const int KEYBOARD_KEY_APPLICATION = 101;
const int KEYBOARD_KEY_POWER = 102;
const int KEYBOARD_KEY_KP_EQUALS = 103;
const int KEYBOARD_KEY_F13 = 104;
const int KEYBOARD_KEY_F14 = 105;
const int KEYBOARD_KEY_F15 = 106;
const int KEYBOARD_KEY_F16 = 107;
const int KEYBOARD_KEY_F17 = 108;
const int KEYBOARD_KEY_F18 = 109;
const int KEYBOARD_KEY_F19 = 110;
const int KEYBOARD_KEY_F20 = 111;
const int KEYBOARD_KEY_F21 = 112;
const int KEYBOARD_KEY_F22 = 113;
const int KEYBOARD_KEY_F23 = 114;
const int KEYBOARD_KEY_F24 = 115;
const int KEYBOARD_KEY_EXECUTE = 116;
const int KEYBOARD_KEY_HELP = 117;
const int KEYBOARD_KEY_MENU = 118;
const int KEYBOARD_KEY_SELECT = 119;
const int KEYBOARD_KEY_STOP = 120;
const int KEYBOARD_KEY_AGAIN = 121;
const int KEYBOARD_KEY_UNDO = 122;
const int KEYBOARD_KEY_CUT = 123;
const int KEYBOARD_KEY_COPY = 124;
const int KEYBOARD_KEY_PASTE = 125;
const int KEYBOARD_KEY_FIND = 126;
const int KEYBOARD_KEY_MUTE = 127;
const int KEYBOARD_KEY_VOLUMEUP = 128;
const int KEYBOARD_KEY_VOLUMEDOWN = 129;
const int KEYBOARD_KEY_KP_COMMA = 133;
const int KEYBOARD_KEY_KP_EQUALSAS400 = 134;
const int KEYBOARD_KEY_INTERNATIONAL1 = 135;
const int KEYBOARD_KEY_INTERNATIONAL2 = 136;
const int KEYBOARD_KEY_INTERNATIONAL3 = 137;
const int KEYBOARD_KEY_INTERNATIONAL4 = 138;
const int KEYBOARD_KEY_INTERNATIONAL5 = 139;
const int KEYBOARD_KEY_INTERNATIONAL6 = 140;
const int KEYBOARD_KEY_INTERNATIONAL7 = 141;
const int KEYBOARD_KEY_INTERNATIONAL8 = 142;
const int KEYBOARD_KEY_INTERNATIONAL9 = 143;
const int KEYBOARD_KEY_LANG1 = 144;
const int KEYBOARD_KEY_LANG2 = 145;
const int KEYBOARD_KEY_LANG3 = 146;
const int KEYBOARD_KEY_LANG4 = 147;
const int KEYBOARD_KEY_LANG5 = 148;
const int KEYBOARD_KEY_LANG6 = 149;
const int KEYBOARD_KEY_LANG7 = 150;
const int KEYBOARD_KEY_LANG8 = 151;
const int KEYBOARD_KEY_LANG9 = 152;
const int KEYBOARD_KEY_ALTERASE = 153;
const int KEYBOARD_KEY_SYSREQ = 154;
const int KEYBOARD_KEY_CANCEL = 155;
const int KEYBOARD_KEY_CLEAR = 156;
const int KEYBOARD_KEY_PRIOR = 157;
const int KEYBOARD_KEY_RETURN2 = 158;
const int KEYBOARD_KEY_SEPARATOR = 159;
const int KEYBOARD_KEY_OUT = 160;
const int KEYBOARD_KEY_OPER = 161;
const int KEYBOARD_KEY_CLEARAGAIN = 162;
const int KEYBOARD_KEY_CRSEL = 163;
const int KEYBOARD_KEY_EXSEL = 164;
const int KEYBOARD_KEY_KP_00 = 176;
const int KEYBOARD_KEY_KP_000 = 177;
const int KEYBOARD_KEY_THOUSANDSSEPARATOR = 178;
const int KEYBOARD_KEY_DECIMALSEPARATOR = 179;
const int KEYBOARD_KEY_CURRENCYUNIT = 180;
const int KEYBOARD_KEY_CURRENCYSUBUNIT = 181;
const int KEYBOARD_KEY_KP_LEFTPAREN = 182;
const int KEYBOARD_KEY_KP_RIGHTPAREN = 183;
const int KEYBOARD_KEY_KP_LEFTBRACE = 184;
const int KEYBOARD_KEY_KP_RIGHTBRACE = 185;
const int KEYBOARD_KEY_KP_TAB = 186;
const int KEYBOARD_KEY_KP_BACKSPACE = 187;
const int KEYBOARD_KEY_KP_A = 188;
const int KEYBOARD_KEY_KP_B = 189;
const int KEYBOARD_KEY_KP_C = 190;
const int KEYBOARD_KEY_KP_D = 191;
const int KEYBOARD_KEY_KP_E = 192;
const int KEYBOARD_KEY_KP_F = 193;
const int KEYBOARD_KEY_KP_XOR = 194;
const int KEYBOARD_KEY_KP_POWER = 195;
const int KEYBOARD_KEY_KP_PERCENT = 196;
const int KEYBOARD_KEY_KP_LESS = 197;
const int KEYBOARD_KEY_KP_GREATER = 198;
const int KEYBOARD_KEY_KP_AMPERSAND = 199;
const int KEYBOARD_KEY_KP_DBLAMPERSAND = 200;
const int KEYBOARD_KEY_KP_VERTICALBAR = 201;
const int KEYBOARD_KEY_KP_DBLVERTICALBAR = 202;
const int KEYBOARD_KEY_KP_COLON = 203;
const int KEYBOARD_KEY_KP_HASH = 204;
const int KEYBOARD_KEY_KP_SPACE = 205;
const int KEYBOARD_KEY_KP_AT = 206;
const int KEYBOARD_KEY_KP_EXCLAM = 207;
const int KEYBOARD_KEY_KP_MEMSTORE = 208;
const int KEYBOARD_KEY_KP_MEMRECALL = 209;
const int KEYBOARD_KEY_KP_MEMCLEAR = 210;
const int KEYBOARD_KEY_KP_MEMADD = 211;
const int KEYBOARD_KEY_KP_MEMSUBTRACT = 212;
const int KEYBOARD_KEY_KP_MEMMULTIPLY = 213;
const int KEYBOARD_KEY_KP_MEMDIVIDE = 214;
const int KEYBOARD_KEY_KP_PLUSMINUS = 215;
const int KEYBOARD_KEY_KP_CLEAR = 216;
const int KEYBOARD_KEY_KP_CLEARENTRY = 217;
const int KEYBOARD_KEY_KP_BINARY = 218;
const int KEYBOARD_KEY_KP_OCTAL = 219;
const int KEYBOARD_KEY_KP_DECIMAL = 220;
const int KEYBOARD_KEY_KP_HEXADECIMAL = 221;
const int KEYBOARD_KEY_LCTRL = 224;
const int KEYBOARD_KEY_LSHIFT = 225;
const int KEYBOARD_KEY_LALT = 226;
const int KEYBOARD_KEY_LGUI = 227;
const int KEYBOARD_KEY_RCTRL = 228;
const int KEYBOARD_KEY_RSHIFT = 229;
const int KEYBOARD_KEY_RALT = 230;
const int KEYBOARD_KEY_RGUI = 231;
const int KEYBOARD_KEY_MODE = 257;
const int KEYBOARD_KEY_AUDIONEXT = 258;
const int KEYBOARD_KEY_AUDIOPREV = 259;
const int KEYBOARD_KEY_AUDIOSTOP = 260;
const int KEYBOARD_KEY_AUDIOPLAY = 261;
const int KEYBOARD_KEY_AUDIOMUTE = 262;
const int KEYBOARD_KEY_MEDIASELECT = 263;
const int KEYBOARD_KEY_WWW = 264;
const int KEYBOARD_KEY_MAIL = 265;
const int KEYBOARD_KEY_CALCULATOR = 266;
const int KEYBOARD_KEY_COMPUTER = 267;
const int KEYBOARD_KEY_AC_SEARCH = 268;
const int KEYBOARD_KEY_AC_HOME = 269;
const int KEYBOARD_KEY_AC_BACK = 270;
const int KEYBOARD_KEY_AC_FORWARD = 271;
const int KEYBOARD_KEY_AC_STOP = 272;
const int KEYBOARD_KEY_AC_REFRESH = 273;
const int KEYBOARD_KEY_AC_BOOKMARKS = 274;
const int KEYBOARD_KEY_BRIGHTNESSDOWN = 275;
const int KEYBOARD_KEY_BRIGHTNESSUP = 276;
const int KEYBOARD_KEY_DISPLAYSWITCH = 277;
const int KEYBOARD_KEY_KBDILLUMTOGGLE = 278;
const int KEYBOARD_KEY_KBDILLUMDOWN = 279;
const int KEYBOARD_KEY_KBDILLUMUP = 280;
const int KEYBOARD_KEY_EJECT = 281;
const int KEYBOARD_KEY_SLEEP = 282;
const int KEYBOARD_KEY_APP1 = 283;
const int KEYBOARD_KEY_APP2 = 284;
const int KEYBOARD_KEY_AUDIOREWIND = 285;
const int KEYBOARD_KEY_AUDIOFASTFORWARD = 286;