#include "fractal_renderer.hpp"

FractalRenderer::FractalRenderer(Vector2i resolution)
    : mResolution(resolution)
    , mPixels(mResolution.x * mResolution.y * 4, 0) // 4 bytes per pixel (RGBA)
{
    mTexture.create(mResolution.x, mResolution.y);
    mTexture.update(mPixels.data());
}

void FractalRenderer::SetBounds(Vector2d topLeft, Vector2d bottomRight) {
    
}

void FractalRenderer::Render(Fractal& fractal) {
    int i = 0;
    for (int y = 0; y < mResolution.y; y++) {
        for (int x = 0; x < mResolution.x; x++) {
            //compute pixel's coordinates
            const double px = x;
            const double py = y;

            const double iterations = fractal.ComputeIterations({px, py});
            mPixels[i++] = std::rand()*255;   //R
            mPixels[i++] = std::rand()*255;   //G
            mPixels[i++] = std::rand()*255;   //B
            mPixels[i++] = 255; //A
        }
    }

    mTexture.update(mPixels.data());
}

const sf::Texture& FractalRenderer::GetTexture() const {
    return mTexture;
}