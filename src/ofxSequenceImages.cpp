//
//  effectAnimation.cpp
//  SBX_Visualize0813
//
//  Created by YOKOYAMA Toru on 2015/08/14.
//
//

#include "ofxSequenceImages.h"

EffectAnimation::EffectAnimation()
: mImages(NULL)
, mPlaying(false)
, mDrawIndex(0)
, mFrameCount(30)
, mAnimatoinStartTime(0)
, mAnimatoinInterval(1.0f / 30)
{
}

void EffectAnimation::setImages(vector<ofImage> *images)
{
    mImages = images;
}

void EffectAnimation::setFrameCount(int frameCount)
{
    mFrameCount = frameCount;
}

void EffectAnimation::setAnimationInterval(float interval)
{
    mAnimatoinInterval = interval;
}

void EffectAnimation::setDrawRect(const ofRectangle &rect)
{
    mDrawRect = rect;
}

void EffectAnimation::play()
{
    mPlaying = true;
    mDrawIndex = 0;
    mAnimatoinStartTime = ofGetElapsedTimef();
}

bool EffectAnimation::isPlaying() const
{
    return mPlaying;
}

void EffectAnimation::update()
{
    if (mImages == NULL) {
        return;
    }
    
    if (!mPlaying) {
        return;
    }
    
    float now = ofGetElapsedTimef();
    float time = now - mAnimatoinStartTime;
    
    mDrawIndex = time / mAnimatoinInterval;
    
    if (mDrawIndex >= mImages->size()) {
        mPlaying = false;
    }
}


void EffectAnimation::draw()
{
    draw(mDrawRect.position.x, mDrawRect.position.y, mDrawRect.width, mDrawRect.height);
}

void EffectAnimation::draw(int x, int y, int w, int h)
{
    if (mImages == NULL) {
        return;
    }
    
    if (!mPlaying) {
        return;
    }
    
    mImages->at(mDrawIndex).draw(x, y, w, h);
}

