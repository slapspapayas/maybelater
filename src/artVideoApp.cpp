#include "artVideoApp.h"
#include "layer.h"
#include <vector>

//--------------------------------------------------------------
void artVideoApp::setup(){
	ofBackground(255,255,255);
	ofSetVerticalSync(true);
	frameByframe = false;
    int size = rand() % totalVideos + 8;
    int channels = rand() % 6;
    int p = rand() % totalVideos; // choose random video
    
    for(int i = 0; i < totalVideos; i++){ //preload all vids
        ofVideoPlayer vid;
        vid.setPixelFormat(OF_PIXELS_RGB);
        vid.loadMovie( paths[i] );
        vid.setLoopState(OF_LOOP_NONE);
        movies.push_back( vid );
    }
    
    for (int i = 0; i < size; i++) {
        layer * newLayer = new layer(&movies[p]);
        newLayer->channels = channels;//color_channels[i];
        layers.push_back(newLayer);
        p = rand() % totalVideos;
    }
    
    numLayers = layers.size();
    ofEnableAlphaBlending();

}

//--------------------------------------------------------------
void artVideoApp::update(){
    
    ofBackground(255,255,255);
    
    for(vector<layer*>::iterator it = layers.begin(); it != layers.end(); ++it){
        if ((*it)->finished) { // if video finished deallocate layer & choose new
            (*it)->myVideo->stop(); // stop vid
            (*it)->myTexture.clear();
            delete[] (*it)->layerPixels;
            delete * it;
            layers.erase(it);
            layer * newLayer = new layer(&movies[rand() % totalVideos]); 
            layers.push_back(newLayer);
        } else {
            (*it)->update();
        }
    }
    
}

//--------------------------------------------------------------
void artVideoApp::draw(){
    
	// 	blending has to be enabled 
	// 	for transparency to work
	
    glColor4f(1,1,1,1);
    for(vector<layer*>::iterator it = layers.begin(); it != layers.end(); ++it){
        (*it)->draw();
    }
    glColor4f(0,0,0,1);
    //ofDrawBitmapString(ofToString(ofGetFrameRate()),10,10);

}

//--------------------------------------------------------------
