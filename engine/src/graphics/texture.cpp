#include "texture.h"

#include "glad/glad.h"
#include "tools/errorchecker.h"
#include "tools/logger.h"
// This is specified by the stb documentation.
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace Richard::Graphics {
	/*Public methods*/

	Texture::Texture(string imagePath) {
		mImagePath = imagePath;
		mPixels = nullptr;

		// stbi_load returns the pixel data as a chunk of memory
		mPixels = stbi_load(mImagePath.c_str(), &mWidth, &mHeight, &mChannelsAmount, 0);
		if (!mPixels) {
			Tools::Logger::Error("Error creating texture with path " + mImagePath);
			mWidth = 0;
			mHeight = 0;
			mChannelsAmount = 0;
		}

		// Loads the texture
		LoadTexture();

	}

	Texture::~Texture()
	{
	}

	void Texture::Bind() {
		glBindTexture(GL_TEXTURE_2D, mId); RICHARD_CHECK_GL_ERROR;
	}

	void Texture::Unbind() {
		glBindTexture(GL_TEXTURE_2D, 0); RICHARD_CHECK_GL_ERROR;
	}

	uint32_t Texture::GetId() {
		return mId;
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

	int Texture::GetChannelsAmount() {
		return mChannelsAmount;
	}

	/*Private methods*/
	void Texture::LoadTexture() {
		// Bind texture
		glGenTextures(1, &mId); RICHARD_CHECK_GL_ERROR;
		Bind();

		// Load image into the texture
		GLenum dataFormat = 0;
		if (mChannelsAmount == 4) {
			dataFormat = GL_RGBA;
		}
		else if (mChannelsAmount == 3) {
			dataFormat = GL_RGB;
		}
		else if (mPixels) {
			// We print this error only if the number of channles is not 4 nor 3 and the are pixels to load.
			Tools::Logger::Error("Number of channels not supported. Richard only supports 3 or 4 channels and this texture has " + mChannelsAmount);
		}

		if (mPixels && dataFormat) {
			glTexImage2D(GL_TEXTURE_2D, 0, dataFormat, mWidth, mHeight, 0, dataFormat, GL_UNSIGNED_BYTE, mPixels); RICHARD_CHECK_GL_ERROR;
			Tools::Logger::Info("Channels loaded. Channels amount: " + mChannelsAmount);
		}
		else {
			// Something went wrong so it will render the default texture
			float pixels[] = {
				1.f, 1.f, 1.f,	0.f, 0.f, 0.f,	1.f, 1.f, 1.f,	0.f, 0.f, 0.f,
				0.f, 0.f, 0.f,	1.f, 1.f, 1.f,	0.f, 0.f, 0.f,	1.f, 1.f, 1.f,
				1.f, 1.f, 1.f,	0.f, 0.f, 0.f,	1.f, 1.f, 1.f,	0.f, 0.f, 0.f,
				0.f, 0.f, 0.f,	1.f, 1.f, 1.f,	0.f, 0.f, 0.f,	1.f, 1.f, 1.f
			};
			mWidth = 4;
			mHeight = 4;
			mChannelsAmount = 3;
			dataFormat = GL_RGB;

			glTexImage2D(GL_TEXTURE_2D, 0, dataFormat, mWidth, mHeight, 0, dataFormat, GL_FLOAT, pixels); RICHARD_CHECK_GL_ERROR;
			Tools::Logger::Warning("Could not load channels, it will load the default texture. Image path: " + mImagePath);
		}

		Unbind();
	}
}
