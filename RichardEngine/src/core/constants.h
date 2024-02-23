/*WINDOWS MANAGER*/

/*
* window_event represents the OS events that the method HandleEvents() may receive.
* It is used to indicate those functions that call HandleEvents() which event
* was popped out and processed.
*/
enum window_event {
	EVENT_DEFAULT = 0,
	EVENT_QUIT = 1
};

/*
* window_initialize_response represents all the possible Initialize() scenarios.
* It is possible that Initialize() succeeds or that fails
* due to some internal initialization failing.
*/
enum window_initialize_response {
	W_INTIALIZE_OK = 0,
	W_INTIALIZE_SDL_WINDOW_FAIL = -1,
	W_INITIALIZE_OPENGL_CONTEXT_FAIL = -2
};

/*
* Constants realated to the window size
*/
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int WINDOW_MIN_WIDTH = 400;
const int WINDOW_MIN_HEIGHT = 200;

/*
* Constants related to the glad version downloaded
*/
const int GLAD_MAJOR_VERSION = 4;
const int GLAD_MINOR_VERSION = 6;
const int GLAD_DEPTH_SIZE = 24;