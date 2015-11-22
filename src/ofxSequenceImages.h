//
//  effectAnimation.h
//  SBX_Visualize0813
//
//  Created by YOKOYAMA Toru on 2015/08/14.
//
//

#ifndef __SBX_Visualize0813__effectAnimation__
#define __SBX_Visualize0813__effectAnimation__

#include "ofMain.h"

class EffectAnimation
{
public:
    EffectAnimation();
    
    void setImages(vector<ofImage> *images);
    void setFrameCount(int frameCount);
    void setAnimationInterval(float interval);
    void setDrawRect(const ofRectangle &rect);
    
    void play();
    
    bool isPlaying() const;
    
    void update();
    
    void draw();
    void draw(int x, int y, int w, int h);
    
private:
    vector<ofImage> *mImages;
    bool mPlaying;
    int mDrawIndex;
    int mFrameCount;
    float mAnimatoinStartTime;
    float mAnimatoinInterval;
    ofRectangle mDrawRect;
    
    
};

#endif /* defined(__SBX_Visualize0813__effectAnimation__) */
