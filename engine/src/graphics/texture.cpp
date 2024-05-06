#include "texture.h"

#include "glad/glad.h"
#include "tools/errorchecker.h"
#include "tools/logger.h"
// This is specified by the stb documentation.
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

namespace Richard::Graphics {
	/*Public methods*/

	Texture::Texture(string imagePath, uint32_t colorFormat, uint32_t minFilter, uint32_t maxFilter, uint32_t tWrapping, uint32_t sWrapping) {
		mImagePath = imagePath;
		mPixelData = nullptr;

		// Generate and bind texture
		glGenTextures(1, &mTexture); RICHARD_CHECK_GL_ERROR;
		Bind();

		// Set the texture wrapping/filtering options (on the currently bound texture object)
		SetFilters(minFilter, maxFilter);
		SetWrapping(tWrapping, sWrapping);

		// Load image
		// stbi_load returns the pixel data as a chunk of memory
		stbi_set_flip_vertically_on_load(true);
		int channelsAmount;
		mPixelData = stbi_load(mImagePath.c_str(), &mWidth, &mHeight, &channelsAmount, 0);

		// Generate texture
		if (mPixelData) {
			glTexImage2D(GL_TEXTURE_2D, 0, colorFormat, mWidth, mHeight, 0, colorFormat, GL_UNSIGNED_BYTE, mPixelData); RICHARD_CHECK_GL_ERROR;
			glGenerateMipmap(GL_TEXTURE_2D);
			Tools::Logger::Info("Image loaded. Image path: " + mImagePath);
		}
		else {
			Tools::Logger::Error("Could not load image. Image path: " + mImagePath);
		}
		stbi_image_free(mPixelData);
	}

	Texture::Texture(string imagePath, uint32_t colorFormat) : Texture(imagePath, colorFormat, T_FILTER_LINEAR, T_FILTER_LINEAR, T_WRAPPING_REPEAT, T_WRAPPING_REPEAT) {}

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

	void Texture::SetFilters(uint32_t minFilter, uint32_t maxFilter) {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, maxFilter);
	}

	void Texture::SetWrapping(uint32_t tWrapping, uint32_t sWrapping) {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, sWrapping);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, tWrapping);
	}
}
