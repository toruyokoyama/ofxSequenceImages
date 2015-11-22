#include "ofApp.h"

const int FrameCount = 50;


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ImageAnimation.resize(FrameCount);
    for (int i = 0; i < FrameCount; i++) {
        char fileName[32];
        sprintf(fileName, "imgs/%02d.png", i+1);
        
        ofImage &image = ImageAnimation[i];
        image.loadImage(fileName);
    }
    
}

//--------------------------------------------------------------
void ofApp::updateEffectAnimations()
{
    for (int i = (int)effectAnimations.size() - 1; i >= 0; --i) {
        EffectAnimation *anim = effectAnimations.at(i);
        anim->update();
        if (!anim->isPlaying()) {
            effectAnimations.erase(effectAnimations.begin() + i);
            delete anim;
        }
    }
}


//--------------------------------------------------------------
void ofApp::update(){
    updateEffectAnimations();
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (size_t i = 0; i < effectAnimations.size(); ++i) {
        effectAnimations.at(i)->draw();
    }
}

//--------------------------------------------------------------
void ofApp::apendEffectAnimation(vector<ofImage> *images, const ofRectangle &drawRect)
{
    EffectAnimation *anim = new EffectAnimation();
    anim->setImages(images);
    anim->setFrameCount(60);
    anim->setAnimationInterval(1.0f / 30 * 1.0f);
    anim->setDrawRect(drawRect);
    anim->play();
    effectAnimations.push_back(anim);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        apendEffectAnimation(&ImageAnimation,ofRectangle(ofRandom(0,ofGetWidth()-250),ofRandom(0,ofGetHeight()-250),500,500));
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
