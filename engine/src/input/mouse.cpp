#include "mouse.h"

#ifndef MOUSE_BUTTON_MASK
#define MOUSE_BUTTON_MASK(X)       (1 << ((X)-1))
#endif


namespace Richard::Input {
	// Static member creation initialization
	int Mouse::mCurrentXPosition = 0;
	int Mouse::mPreviousXPosition = 0;
	int Mouse::mCurrentYPosition = 0;
	int Mouse::mPreviousYPosition = 0;
	map<int, Button> Mouse::mButtons = {};

	Mouse::Mouse() {}

	Mouse::~Mouse() {}

	void Mouse::Initialize() {
		for (int i = MOUSE_BUTTON_LEFT; i <= mButtonAmount; i++) {
			mButtons[i] = Button();
		}
	}

	void Mouse::Shutdown() {
		mCurrentXPosition = 0;
		mPreviousXPosition = 0;
		mCurrentYPosition = 0;
		mPreviousYPosition = 0;
		mButtons.clear();
	}

	void Mouse::Update() {
		// Update the previous state
		mPreviousXPosition = mCurrentXPosition;
		mPreviousYPosition = mCurrentYPosition;

		// Update the mouse position
		//uint32_t mouseButtonsState = SDL_GetMouseState(&mCurrentXPosition, &mCurrentYPosition);

		// Update the buttons
		/*for (int i = MOUSE_BUTTON_LEFT; i <= mButtonAmount; i++) {
			mButtons.at(i).Update((mouseButtonsState & MOUSE_BUTTON_MASK(i)) ? 1 : 0);
		}*/
	}

	int Mouse::GetXCurrentPosition() {
		return mCurrentXPosition;
	}

	int Mouse::GetYCurrentPosition() {
		return mCurrentYPosition;
	}

	int Mouse::GetButtonCurrentState(int buttonName) {
		return mButtons.at(buttonName).GetCurrentState();
	}

	int Mouse::GetXPreviousPosition() {
		return mPreviousXPosition;
	}

	int Mouse::GetYPreviousPosition() {
		return mPreviousYPosition;
	}

	int Mouse::GetButtonPreviousState(int buttonName) {
		return mButtons.at(buttonName).GetPreviousState();
	}
}
