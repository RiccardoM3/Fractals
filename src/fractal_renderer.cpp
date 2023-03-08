#include "fractal_renderer.hpp"

FractalRenderer::FractalRenderer(Vector2i resolution)
    : mResolution(resolution)
    , mPixels(mResolution.x * mResolution.y * 4, 0) // 4 bytes per pixel (RGBA)
    , mMaxReal(1.5)
    , mMinReal(-1.5)
    , mMaxIm(1.5)
    , mMinIm(-1.5)
    , mZoom(1.0)
{
    mTexture.create(mResolution.x, mResolution.y);
    mTexture.update(mPixels.data());
}

void FractalRenderer::TranslateBounds(double real, double im) {
    mMaxReal += real;
    mMinReal += real;
    mMaxIm += im;
    mMinIm += im;
}

void FractalRenderer::ZoomIn() {
    mZoom *= 1.2;
}

void FractalRenderer::ZoomOut() {
    mZoom /= 1.2;
}

void FractalRenderer::Render(Fractal* fractal) {
    //TODO: can optimise 'i' out
    //TODO: parralellise
    //TODO: don't need to reset alpha every time
    //TODO: zoom multiplier seems to be incorrectly applied here. zooming towards absolute center instead of camera center. should remove the scale variable and just adjust the bounds
    int i = 0;
    const double scale = (mMaxReal - mMinReal)/mResolution.y;
    for (int y = 0; y < mResolution.y; y++) {
        for (int x = 0; x < mResolution.x; x++) {
            //compute pixel's coordinates in the complex plane within the bounds
            const double re = mZoom * (mMinReal + x*scale);
            const double im = mZoom * (mMinIm + y*scale);

            const double iterations = fractal->ComputeIterations({re, im});
            mPixels[i++] = IterationsToGradient(fractal, iterations);   //R
            mPixels[i++] = IterationsToGradient(fractal, iterations);   //G
            mPixels[i++] = IterationsToGradient(fractal, iterations);   //B
            mPixels[i++] = 255; //A
        }
    }

    mTexture.update(mPixels.data());
}

int FractalRenderer::IterationsToGradient(Fractal* fractal, int iterations) const {
    return iterations * 1.0 / fractal->GetMaxIterations() * 255;
}

const sf::Texture& FractalRenderer::GetTexture() const {
    return mTexture;
}