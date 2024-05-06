#pragma once

#include <utility>

namespace Richard::Input {
	class Mouse {
	public:
		/*Methods*/

		/*
		* Constructor. It creates the object Mouse.
		*/
		Mouse();

		/*
		* Destructor. It destroys the object Mouse.
		*/
		~Mouse();

		/*
		* GetPosition() returns the current x-axis and y-axis mouse position (in that order).
		*/
		static std::pair<float, float> GetPosition();

		/*
		* IsButtonPressed() returns true if the button given in the argument is being pressed.
		* It returns false otherwise.
		*/
		static bool IsButtonPressed(int buttonName);
	};
}


/*
* Mouse buttons available.
*/
const int MOUSE_BUTTON_LEFT = 1;
const int MOUSE_BUTTON_MIDDLE = 2;
const int MOUSE_BUTTON_RIGHT = 3;
const int MOUSE_BUTTON_X1 = 4;
const int MOUSE_BUTTON_X2 = 5;