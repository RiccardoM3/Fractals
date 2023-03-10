#include "fractal_renderer.hpp"

#include <atomic>
#include <thread>
#include <chrono>

FractalRenderer::FractalRenderer(Vector2i resolution, ctpl::thread_pool& threadPool, unsigned int numThreads)
    : mResolution(resolution)
    , mThreadPool(threadPool)
    , mNumThreads(numThreads)
    , mPixels(mResolution.x * mResolution.y * 4, 255) // 4 bytes per pixel (RGBA). Default each pixel data to 255 so we don't have to manually set the alpha later
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
    
    const double scale = (mMaxReal - mMinReal)/mResolution.y;
    const float rowsPerThread = mResolution.y/mNumThreads;
    std::atomic_int numCompleted(0);

    for (int i = 0; i < mNumThreads; i++) {
        mThreadPool.push([this, i, rowsPerThread, scale, fractal, &numCompleted](int){ 
            int currentIndex = i * rowsPerThread * mResolution.x * 4;
            for (int y = i * rowsPerThread; y < (i+1) * rowsPerThread; y++) {
                for (int x = 0; x < mResolution.x; x++) {
                    //compute pixel's coordinates in the complex plane within the bounds
                    const double re = mMinReal + x*scale;
                    const double im = mMinIm + y*scale;

                    const double iterations = fractal->ComputeIterations({re, im});
                    mPixels[currentIndex++] = IterationsToGradient(fractal, iterations);   //R
                    mPixels[currentIndex++] = IterationsToGradient(fractal, iterations);   //G
                    mPixels[currentIndex++] = IterationsToGradient(fractal, iterations);   //B
                    currentIndex++; //Pixel alphas are already initialised to 255 when the mPixels array was created
                }
            }

            //notify once complete
            numCompleted++;
        });
    }

    //wait until all threads have completed
    while (numCompleted < mNumThreads)
        std::this_thread::sleep_for(std::chrono::milliseconds(5));

    mTexture.update(mPixels.data());
}

int FractalRenderer::IterationsToGradient(Fractal* fractal, int iterations) const {
    return iterations * 255.0 / fractal->GetMaxIterations();
}

const sf::Texture& FractalRenderer::GetTexture() const {
    return mTexture;
}