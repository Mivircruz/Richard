#include "mouse.h"
#include "SDL_mouse.h"

#ifndef MOUSE_BUTTON_MASK
#define MOUSE_BUTTON_MASK(X)       (1 << ((X)-1))
#endif


namespace Richard::Events::Periphericals {
	// Static member creation initialization
	int Mouse::mCurrentXPosition = 0;
	int Mouse::mPreviousXPosition = 0;
	int Mouse::mCurrentYPosition = 0;
	int Mouse::mPreviousYPosition = 0;
	map<int, Button> Mouse::mButtons = {};

	Mouse::Mouse() {
	}

	Mouse::~Mouse() {}

	void Mouse::Initialize() {
		mButtons[MOUSE_BUTTON_LEFT]		= Button();
		mButtons[MOUSE_BUTTON_MIDDLE]	= Button();
		mButtons[MOUSE_BUTTON_RIGHT]	= Button();
		mButtons[MOUSE_BUTTON_X1]		= Button();
		mButtons[MOUSE_BUTTON_X2]		= Button();
	}

	void Mouse::Update() {
		// Update the previous state
		mPreviousXPosition = mCurrentXPosition;
		mPreviousYPosition = mCurrentYPosition;

		// Update the mouse position
		uint32_t mouseButtonsState = SDL_GetMouseState(&mCurrentXPosition, &mCurrentYPosition);

		// Update the buttons
		for (int i = 1; i < mButtonAmount+1; i++) {
			mButtons.at(i).Update((mouseButtonsState & MOUSE_BUTTON_MASK(i)) ? 1 : 0);
		}
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
}
