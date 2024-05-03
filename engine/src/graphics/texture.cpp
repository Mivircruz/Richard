#include "texture.h"

#include "glad/glad.h"
#include "tools/errorchecker.h"
#include "tools/logger.h"
// This is specified by the stb documentation.
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

namespace Richard::Graphics {
	/*Public methods*/

	Texture::Texture(string imagePath) {
		mImagePath = imagePath;
		mPixelData = nullptr;

		// Generate and bind texture
		glGenTextures(1, &mTexture); RICHARD_CHECK_GL_ERROR;
		Bind();

		// Set the texture wrapping/filtering options (on the currently bound texture object)
		SetFilters();

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
		Unbind();
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

	void Texture::SetFilters() {
		// Set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// Set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
}
