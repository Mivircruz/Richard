#include "texture.h"

#include "glad/glad.h"
#include "tools/errorchecker.h"
#include "tools/logger.h"
// This is specified by the stb documentation.
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

namespace Richard::Graphics {
	/*Public methods*/

	Texture::Texture(string imagePath, texture_filter filter, texture_wrapping wrapping) {
		mImagePath = imagePath;
		mPixelData = nullptr;

		// Generate and bind texture
		glGenTextures(1, &mTexture); RICHARD_CHECK_GL_ERROR;
		Bind();

		// Set the texture wrapping/filtering options (on the currently bound texture object)
		SetFilter(filter);
		//SetWrapping(wrapping); ToDo: uncomment this

		// Load image
		// stbi_load returns the pixel data as a chunk of memory
		stbi_set_flip_vertically_on_load(true);
		int channelsAmount;
		mPixelData = stbi_load(mImagePath.c_str(), &mWidth, &mHeight, &channelsAmount, 0);

		// Generate texture
		if (mPixelData) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mWidth, mHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, mPixelData); RICHARD_CHECK_GL_ERROR;
			Tools::Logger::Info("Image loaded. Image path: " + mImagePath);
		}
		else {
			Tools::Logger::Error("Could not load image. Image path: " + mImagePath);
		}
		stbi_image_free(mPixelData);
	}


	Texture::~Texture() {
		//stbi_image_free(mPixelData);
	}

	void Texture::Bind() {
		glBindTexture(GL_TEXTURE_2D, mTexture); RICHARD_CHECK_GL_ERROR;
	}

	void Texture::Unbind() {
		glBindTexture(GL_TEXTURE_2D, 0); RICHARD_CHECK_GL_ERROR;
	}

	uint32_t Texture::GetId() {
		return mTexture;
	}

	string Texture::GetImagePath() {
		return mImagePath;
	}

	int Texture::GetWidth() {
		return mWidth;
	}

	int Texture::GetHeight() {
		return mHeight;
	}



	/*Private methods*/

	void Texture::SetFilter(texture_filter filter) {
		// Set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// Set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		/*switch (filter) {
		case T_FILTER_LINEAR:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); RICHARD_CHECK_GL_ERROR;
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); RICHARD_CHECK_GL_ERROR;
			break;
		case T_FILTER_NEAREST:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); RICHARD_CHECK_GL_ERROR;
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); RICHARD_CHECK_GL_ERROR;
			break;
		default:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); RICHARD_CHECK_GL_ERROR;
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); RICHARD_CHECK_GL_ERROR;
		}*/
	}

	void Texture::SetWrapping(texture_wrapping wrapping) {
		switch (wrapping) {
		case T_WRAPPING_REPEAT:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); RICHARD_CHECK_GL_ERROR;
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); RICHARD_CHECK_GL_ERROR;
			break;
		case T_WRAPPING_MIRRORED_REPEAT:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT); RICHARD_CHECK_GL_ERROR;
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT); RICHARD_CHECK_GL_ERROR;
			break;
		case T_WRAPPING_CLAMP_TO_EDGE:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER); RICHARD_CHECK_GL_ERROR;
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER); RICHARD_CHECK_GL_ERROR;
			break;
		case T_WRAPPING_CLAMP_TO_BORDER:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); RICHARD_CHECK_GL_ERROR;
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); RICHARD_CHECK_GL_ERROR;
			break;
		default:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); RICHARD_CHECK_GL_ERROR;
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); RICHARD_CHECK_GL_ERROR;
		}
	}
}
