#pragma once

#include <string>

using namespace std;

namespace Richard::Graphics {
    class Texture {
        public:
            /*Methods*/

            /* 
            * Constuctor. It creates a texture with the given image path.
            * If something fails during the loading process, it will render a default image.
			// The default texture is 4x4 pixel image in black and white like a chess board.
            */
            Texture(string imagePath);

            /*
            * Destructor. It frees the memory asked for the image 
            * and destroys the object Texture.
            * */
            ~Texture();

            void Bind();

            void Unbind();

            /*
            * GetId() returns the texture Id.
            */
            uint32_t GetId();

            /*
            * GetImagePath() returns the image path.
            */
            string GetImagePath();

            /*
            * GetWidth() returns the width in pixels of the image.
            */
            int GetWidth();

            /*
            * GetHeight() returns the height in pixels of the image.
            */
            int GetHeight();

            /*
           * GetChannelsAmount() returns the amount of channels.
           */
            int GetChannelsAmount();


        private:
            /*Methods*/

            void LoadTexture();

            /*Member variables*/

            /*Image path*/
            string mImagePath;

            /*Texture Id*/
            uint32_t mId;

            /*Width and Height in pixels of the image*/
            int mWidth, mHeight;

            /* Number of channels. 
            * It could be 3 for a RGB texture or 4 for a RGBA texture.
            */
           int mChannelsAmount;

           unsigned char* mPixels;
    };
}