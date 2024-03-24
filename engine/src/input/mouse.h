#pragma once
#include "button.h"
#include <map>

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
		* Initialize() initializes the button map.
		*/
		static void Initialize();

		/*
		* Update() gets the current state and position of the mouse
		* and it updates both the position and every button.
		*/
		static void Update();

		/*
		* GetXCurrentPosition() returns the current x-axis mouse position.
		*/
		static int GetXCurrentPosition();

		/*
		* GetYCurrentPosition() returns the current y-axis mouse position.
		*/
		static int GetYCurrentPosition();

		/*
		* GetButtonCurrentState() returns the current status of the button given in the argument.
		*/
		static int GetButtonCurrentState(int buttonName);



	private:
		/*Member variables*/

		/*
		* Current and previous position of the mouse in the x-axis position
		*/
		static int mCurrentXPosition, mPreviousXPosition;

		/*
		* Current and previous position of the mouse in the y-axis position
		*/
		static int mCurrentYPosition, mPreviousYPosition;

		/*
		* Mouse buttons.
		*/
		static map<int, Button> mButtons;

		/*
		* Amount of mouse buttons.
		*/
		static const int mButtonAmount = 5;
	};
}


/*
* Mouse buttons available.
* SDL supports up to 5 mouse buttons.
* Adapted from SDL - check SDL_MouseButtonEvent for more information.
*/
const int MOUSE_BUTTON_LEFT = 1;
const int MOUSE_BUTTON_MIDDLE = 2;
const int MOUSE_BUTTON_RIGHT = 3;
const int MOUSE_BUTTON_X1 = 4;
const int MOUSE_BUTTON_X2 = 5;