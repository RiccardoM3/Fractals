#include "fractal_renderer.hpp"

FractalRenderer::FractalRenderer(Vector2i resolution)
    : mResolution(resolution)
    , mPixels(mResolution.x * mResolution.y * 4, 255) // 4 bytes per pixel (RGBA)
    , mMaxReal(1.5)
    , mMinReal(-1.5)
    , mMaxIm(1.5)
    , mMinIm(-1.5)
    , mTranslateSpeed(50)
{
    mTexture.create(mResolution.x, mResolution.y);
    mTexture.update(mPixels.data());
}

void FractalRenderer::TranslateBounds(double real, double im) {
    double realScale = (mMaxReal - mMinReal) / mResolution.x;
    double imScale = (mMaxIm - mMinIm) / mResolution.y;
    mMaxReal += mTranslateSpeed * real * realScale;
    mMinReal += mTranslateSpeed * real * realScale;
    mMaxIm += mTranslateSpeed * im * imScale;
    mMinIm += mTranslateSpeed * im * imScale;
}

void FractalRenderer::ZoomIn() {
    double realSize = mMaxReal - mMinReal;
    mMaxReal -= realSize/4.0;
    mMinReal += realSize/4.0;

    double imSize = mMaxIm - mMinIm;
    mMaxIm -= imSize/4.0;
    mMinIm += imSize/4.0;
}

void FractalRenderer::ZoomOut() {
    double realSize = mMaxReal - mMinReal;
    mMaxReal += realSize/2.0;
    mMinReal -= realSize/2.0;

    double imSize = mMaxIm - mMinIm;
    mMaxIm += imSize/2.0;
    mMinIm -= imSize/2.0;
}

void FractalRenderer::Render(Fractal* fractal) {
    //TODO: parralellise
    int i = 0;
    const double scale = (mMaxReal - mMinReal)/mResolution.y;
    for (int y = 0; y < mResolution.y; y++) {
        for (int x = 0; x < mResolution.x; x++) {
            //compute pixel's coordinates in the complex plane within the bounds
            const double re = mMinReal + x*scale;
            const double im = mMinIm + y*scale;

            const double iterations = fractal->ComputeIterations({re, im});
            mPixels[i++] = IterationsToGradient(fractal, iterations);   //R
            mPixels[i++] = IterationsToGradient(fractal, iterations);   //G
            mPixels[i++] = IterationsToGradient(fractal, iterations);   //B
            i++;
            // mPixels[i++] = 255; //Pixels are already initialised to 255 when the mPixels array was created
        }
    }

    mTexture.update(mPixels.data());
}

int FractalRenderer::IterationsToGradient(Fractal* fractal, int iterations) const {
    return iterations * 255.0 / fractal->GetMaxIterations();
}

const sf::Texture& FractalRenderer::GetTexture() const {
    return mTexture;
}