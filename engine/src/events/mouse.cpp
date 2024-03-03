#include "mouse.h"
#include "SDL_mouse.h"

namespace Richard::Events::Periphericals {
	// Static member creation initialization
	int Mouse::mCurrentXPosition = 0;
	int Mouse::mPreviousXPosition = 0;
	int Mouse::mCurrentYPosition = 0;
	int Mouse::mPreviousYPosition = 0;
	map<string, Button> Mouse::mButtons = {};

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
		mButtons.at(MOUSE_BUTTON_LEFT).Update((mouseButtonsState & SDL_BUTTON_LMASK) ? 1 : 0);
		mButtons.at(MOUSE_BUTTON_MIDDLE).Update((mouseButtonsState & SDL_BUTTON_MMASK) ? 1 : 0);
		mButtons.at(MOUSE_BUTTON_RIGHT).Update((mouseButtonsState & SDL_BUTTON_RMASK) ? 1 : 0);
		mButtons.at(MOUSE_BUTTON_X1).Update((mouseButtonsState & SDL_BUTTON_X1MASK) ? 1 : 0);
		mButtons.at(MOUSE_BUTTON_X2).Update((mouseButtonsState & SDL_BUTTON_X2MASK) ? 1 : 0);
	}

	int Mouse::GetXCurrentPosition() {
		return mCurrentXPosition;
	}

	int Mouse::GetYCurrentPosition() {
		return mCurrentYPosition;
	}

	int Mouse::GetButtonCurrentState(string buttonName) {
		return mButtons.at(buttonName).GetCurrentState();
	}
}
