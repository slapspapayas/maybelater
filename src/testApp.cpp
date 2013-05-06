#include "testApp.h"
#include "layer.h"
#include <vector>

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(255,255,255);
	ofSetVerticalSync(true);
	frameByframe = false;
    int size = rand() % 26 + 10;
    int len = paths->size();
    int p = rand() % 26; // choose random video
    for (int i = 0; i < size; i++) {
        
        layer * newLayer = new layer(paths[p]);
        layers.push_back(newLayer);
        p = rand() % 26;
    }
    
    numLayers = layers.size();
}

//--------------------------------------------------------------
void testApp::update(){
    
    ofBackground(255,255,255);
    
    //int len = layers.size();
    for (int i = 0; i < numLayers; i++) {
        if (layers[i]->finished) {
            layers[i]->myVideo.close();
            layers[i]->myVideo.closeMovie();
            delete layers[i];
            
            layer * newLayer = new layer(paths[rand() % 26]);
            layers.erase (layers.begin()+i);
            layers.push_back(newLayer);
            //layers[i] = newLayer;
        } else {
            layers[i]->update();
        }
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
	// 	blending has to be enabled 
	// 	for transparency to work
	
    ofEnableAlphaBlending();
    
    //int len = layers.size();
    for (int i = 0; i < numLayers; i++) {
        layers[i]->draw();
    }

    ofDisableAlphaBlending();
    
    


}

//--------------------------------------------------------------
