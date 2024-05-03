#pragma once

#include <string>

using namespace std;

namespace Richard::Graphics {
    class Texture {
    public:
        /*Methods*/

        /*
        * Constuctor. It creates a texture with the given image path.
        */
        Texture(string imagePath);

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

        /*
        * SetFilter() sets the filters/wrapping options that will be used to render the texture.
        * Their values are GL_LINEAR and GL_REPEAT.
        */
        void SetFilters();


        /*Member variables*/

        /*Image path*/
        string mImagePath;

        /*Texture Id*/
        uint32_t mTexture;

        /*Width and Height in pixels of the image*/
        int mWidth, mHeight;

        /*Pixel data*/
        unsigned char* mPixelData;
    };
}