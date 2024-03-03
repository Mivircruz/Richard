#pragma once
#include "button.h"
#include <map>
#include <string>

using namespace std;

/*
* Mouse buttons available.
* SDL supports up to 5 mouse buttons
*/
const string MOUSE_BUTTON_LEFT		= "MouseButtonLeft";
const string MOUSE_BUTTON_MIDDLE	= "MouseButtonMiddle";
const string MOUSE_BUTTON_RIGHT		= "MouseButtonRight";
const string MOUSE_BUTTON_X1		= "MouseButtonX1";
const string MOUSE_BUTTON_X2		= "MouseButtonX2";

namespace Richard::Events::Periphericals {
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
		* GetLeftButtonCurrentState() returns the current status of the left button.
		*/
		static int GetLeftButtonCurrentState();

		/*
		* GetMiddleButtonCurrentState() returns the current status of the middle button.
		*/
		static int GetMiddleButtonCurrentState();

		/*
		* GetRightButtonCurrentState() returns the current status of the right button.
		*/
		static int GetRightButtonCurrentState();

		/*
		* GetX1ButtonCurrentState() returns the current status of the X1 button.
		*/
		static int GetX1ButtonCurrentState();

		/*
		* GetX2ButtonCurrentState() returns the current status of the X2 button.
		*/
		static int GetX2ButtonCurrentState();



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
		static map<string, Button> mButtons;
	};
}