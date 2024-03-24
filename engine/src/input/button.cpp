#include "button.h"

namespace Richard::Input {
	Button::Button() {
		mCurrentState = 0;
		mPreviousState = 0;
	}

	Button::~Button() {}

	void Button::Update(int state) {
		mPreviousState = mCurrentState;
		mCurrentState = state;
	}

	int Button::GetCurrentState() {
		return mCurrentState;
	}

	int Button::GetPreviousState() {
		return mPreviousState;
	}
}