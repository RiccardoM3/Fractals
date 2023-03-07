#include "fractal_renderer.hpp"

FractalRenderer::FractalRenderer(Vector2i resolution)
    : mResolution(resolution)
    , mPixels(mResolution.x * mResolution.y * 4, 0) // 4 bytes per pixel (RGBA)
    , mMaxReal(1.5)
    , mMinReal(-1.5)
    , mMaxIm(1.5)
    , mMinIm(-1.5)
{
    mTexture.create(mResolution.x, mResolution.y);
    mTexture.update(mPixels.data());
}

void FractalRenderer::SetBounds(double maxReal, double minReal, double maxIm, double minIm) {
    mMaxReal = maxReal;
    mMinReal = minReal;
    mMaxIm = maxIm;
    mMinIm = minIm;
}

void FractalRenderer::Render(Fractal& fractal) {
    int i = 0;
    const double scale = (mMaxReal - mMinReal)/mResolution.y;
    for (int y = 0; y < mResolution.y; y++) {
        for (int x = 0; x < mResolution.x; x++) {
            //compute pixel's coordinates in the complex plane within the bounds
            const double re = mMinReal + x*scale;
            const double im = mMinIm + y*scale;

            const double iterations = fractal.ComputeIterations({re, im});
            mPixels[i++] = IterationsToGradient(iterations);   //R
            mPixels[i++] = IterationsToGradient(iterations);   //G
            mPixels[i++] = IterationsToGradient(iterations);   //B
            mPixels[i++] = 255; //A
        }
    }

    mTexture.update(mPixels.data());
}

int FractalRenderer::IterationsToGradient(int iterations) const {
    return iterations * 1.0 / Fractal::MAX_ITERATIONS * 255;
}

const sf::Texture& FractalRenderer::GetTexture() const {
    return mTexture;
}