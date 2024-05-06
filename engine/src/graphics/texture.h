#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

using namespace std;

/* Color formats */
const uint32_t T_COLOR_RGB = 0x1907;
const uint32_t T_COLOR_RGBA = 0x1908;

/* Filter options */
/*
* A (2D) texture can be looked at as a function t(u, v), whose output is a "color" value.
* An actual texture image is not a smooth function; it is a discrete function. 
* The purpose of filtering is to create a continuous function t by inventing values in-between the discrete texels. 
* This allows the client to declare that u and v are floating-point values, 
* alongside the normalization of the texture coordinates, so that they're on the range [0, 1] rather than being based on the texture's size.
*/

// Produces a smoother pattern where the individual pixels are less visible,
// which results in a more realistic output
// It uses the GL_LINEAR option.
const uint32_t T_FILTER_LINEAR = 0x2601;

// Results in blocked patterns where we can clearly see the pixels that form the texture.
// It uses the GL_NEAREST option.
const uint32_t T_FILTER_NEAREST = 0x2600;



/* Wrapping options*/
/*
* The wrapping options let you set the behaviour when we specify coordinates outside the texture coordinates,
* which usually range from (0,0) to (1,1)
*/

// Repeats the texture image.
// It uses the GL_REPEAT option.
const uint32_t T_WRAPPING_REPEAT = 0x2901;

//  Same as GL_REPEAT but mirrors the image with each repeat.
// It uses the GL_MIRRORED_REPEAT option.
const uint32_t T_WRAPPING_MIRRORED_REPEAT = 0x8370;

//  Clamps the coordinates between 0 and 1. 
// The result is that higher coordinates become clamped to the edge, resulting in a stretched edge pattern.
// It uses the GL_CLAMP_TO_EDGE option.
const uint32_t T_WRAPPING_CLAMP_TO_EDGE = 0X812F;

// Coordinates outside the range are now given a user - specified border color.
// It uses the GL_CLAMP_TO_BORDER option.
const uint32_t T_WRAPPING_CLAMP_TO_BORDER = 0X812D;



namespace Richard::Graphics {
    class Texture {
    public:
        /*Methods*/

        /*
        * Constuctor. It takes the following arguments:
        * imagePath: the path to the image to be rendered.
        * minFilter: filter of the texture minifying function, which is used whenever the pixel being textured maps to an area greater than one texture element. 
        * maxFilter: filter of the texture magnification function, which is used when the pixel being textured maps to an area less than or equal to one texture element.
        * tWrapping: wrap parameter for texture coordinate t.
        * sWrapping: wrap parameter for texture coordinate s.
        */
        Texture(string imagePath, uint32_t colorFormat, uint32_t minFilter, uint32_t maxFilter, uint32_t tWrapping, uint32_t sWrapping);


        /*
        * Constructor. It takes the path of the image to be rendered as argument.
        * The filter is T_FILTER_LINEAR and the wrapping is T_WRAPPING_REPEAT.
        */
        Texture(string imagePath, uint32_t colorFormat);

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
        * SetFilter() sets the filters options that will be used to render the texture.
        */
        void SetFilters(uint32_t minFilter, uint32_t maxFilter);

        /*
        * SetWrapping() sets the wrapping options that will be used to render the texture.
        */
        void SetWrapping(uint32_t tWrapping, uint32_t sWrapping);


        /*Member variables*/

        /*Image path*/
        string mImagePath;

        /*Texture Id*/
        uint32_t mTexture;

        /*Width and Height in pixels of the image*/
        int mWidth, mHeight;
    };
}

#endif