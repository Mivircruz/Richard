/*WINDOWS MANAGER*/

/*
* A WINDOW_EVENT represents the OS events that the method HandleEvents() may receive.
* It is used to indicate those functions that call HandleEvents() which event
* was popped out and processed.
*/
enum WINDOW_EVENT {
	EVENT_DEFAULT = 0,
	EVENT_QUIT = 1
};

/*
* A WINDOW_EVENT represents the OS events that the method HandleEvents() may receive.
* It is used to indicate those functions that call HandleEvents() which event
* was popped out and processed.
*/
enum WINDOW_INTIALIZE_RESPONSE {
	W_INTIALIZE_OK = 0,
	W_INTIALIZE_FAIL = -1
};