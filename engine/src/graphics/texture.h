#pragma once

#include <string>

using namespace std;

/*
* texture_filter represents the kind of filter that can be used to render textures
* Texture coordinates do not depend on resolution but can be any floating point value,
* thus it is necessary to define which texture pixel (also known as a texel) to map the texture coordinate to.
* The filters available are:
* T_FILTER_NEAREST: selects the texel that center is closest to the texture coordinate.
* T_FILTER_LINEAR: takes an interpolated value from the texture coordinate's neighboring texels, approximating a color between the texels.
*/
enum texture_filter {
    T_FILTER_NEAREST,
    T_FILTER_LINEAR
};


/*
* texture_wrapping represents the different ways to handle an image whose coordinates
* are outside the usual range. The options are:
* T_WRAPPING_REPEAT: repeats the texture image.
* T_WRAPPING_MIRRORED_REPEAT: same as T_WRAPPING_REPEAT but mirrors the image with each repeat.
* T_WRAPPING_CLAMP_TO_EDGE: clamps the coordinates between 0 and 1. The result is that higher coordinates become clamped to the edge, resulting in a stretched edge pattern.
* GL_CLAMP_TO_BORDER: coordinates outside the range are now given a user-specified border color.
*/
enum texture_wrapping {
    T_WRAPPING_REPEAT,
    T_WRAPPING_MIRRORED_REPEAT,
    T_WRAPPING_CLAMP_TO_EDGE,
    T_WRAPPING_CLAMP_TO_BORDER
};

namespace Richard::Graphics {
    class Texture {
        public:
            /*Methods*/

            /* 
            * Constuctor. It creates a texture with the given image path.
            * If something fails during the loading process, it will render a default image.
			// The default texture is 4x4 pixel image in black and white like a chess board.
            */
            Texture(string imagePath, texture_filter filter, texture_wrapping wrapping);

            /*
            * Destructor. It frees the memory asked for the image 
            * and destroys the object Texture.
            * */
            ~Texture();

            /*
            * Bind() binds the texture
            */
            void Bind();

            /*
            * Unbind() unbinds the texture
            */
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



        private:
            /*Methods*/

            void LoadTexture(); //RODO: borrar

            /*
            * SetFilter() sets the filter that will be used to render the texture.
            * Its default value is T_FILTER_LINEAR.
            */
            void SetFilter(texture_filter filter);

            /*
            * SetWrapping() sets the wrapping options that will be used to handle
            * the out-of-range case (if it happens).
            * Its default value is T_WRAPPING_REPEAT.
            */
            void SetWrapping(texture_wrapping wrapping);


            /*Member variables*/

            /*Image path*/
            string mImagePath;

            /*Texture Id*/
            uint32_t mId;

            /*Width and Height in pixels of the image*/
            int mWidth, mHeight;

            /*Pixel data*/
           unsigned char* mPixelData;
    };
}