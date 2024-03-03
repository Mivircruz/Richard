#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace Richard::Events::Periphericals {
	class Button {
	public:
		/*Methods*/

		/*
		* Constructor. It creates the object Button.
		* and initializes both the current and previous state in 0.
		*/
		Button();

		/*
		* Destructor. It destroys the object Button.
		*/
		~Button();

		/*
		* Update() updates the previous state and changes the current state 
		* with the state given.
		*/
		void Update(int state);

		/*
		* GetCurrentState() returns the current state of the button.
		* It can be 0 if it is down or 1 if it is up.
		*/
		int GetCurrentState();

		/*
		* GetPreviousState() returns the previous state of the button.
		* It can be 0 if it is down or 1 if it is up.
		*/
		int GetPreviousState();



	private:
		/*Member variables*/

		/*
		* Current and previous state of the button.
		* The int represents the state as it follows:
		* 0 = button down.
		* 1 = button up.
		*/
		int mCurrentState;
		int mPreviousState;
	};
}