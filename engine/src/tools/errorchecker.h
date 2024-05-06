#pragma once

#ifndef ERRORCHECKER_H
#define ERRORCHECKER_H

#include "logger.h"
#include "glad/glad.h"

// The error checker should only be available in Debug mode
#ifdef RICHARD_CONFIG_DEBUG
#define RICHARD_CHECK_GL_ERROR Richard::Tools::CheckGLError();
#else
#define RICHARD_CHECK_GL_ERROR (void)0;
#endif

namespace Richard::Tools {

	/*
	* CeckGLError() checks if an OpenGL error occurred and if it did,
	* it stops the application and logs it.
	*/
	void CheckGLError();
}

#endif