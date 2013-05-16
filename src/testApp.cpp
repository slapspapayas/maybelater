#include "testApp.h"
#include "layer.h"
#include <vector>

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(255,255,255);
	ofSetVerticalSync(true);
	frameByframe = false;
    int size = 1;//rand() % totalVideos + 8;
    //int len = paths->size();
    int channels = rand() % 6;
    int p = rand() % totalVideos; // choose random video
    
    /*for(int i = 0; i < totalVideos; i++){ //preload all vids
        ofVideoPlayer vid;
        vid.setPixelFormat(OF_PIXELS_RGB);
        vid.loadMovie( paths[i] );
        vid.setLoopState(OF_LOOP_NONE);
        movies.push_back( vid );
    }*/
    
    for (int i = 0; i < size; i++) {
        //layer * newLayer = new layer(&movies[p]);
        layer * newLayer = new layer(paths[p]);
        newLayer->channels = channels;
        layers.push_back(newLayer);
        p = rand() % totalVideos;
    }
    
    numLayers = layers.size();
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    ofBackground(255,255,255);
    
    //for (int i = 0; i < numLayers; i++) {
    for(vector<layer*>::iterator it = layers.begin(); it != layers.end(); ++it){
        if ((*it)->finished) { // if video finished deallocate layer & choose new
            
            (*it)->myVideo.close();
            (*it)->myTexture.clear();
            delete (*it)->layerPixels;
            delete * it;
            layers.erase(it);
            
            layer * newLayer = new layer(paths[rand() % totalVideos]); //layer(&movies[rand() % totalVideos]);
            layers.push_back(newLayer);
        } else {
            (*it)->update();
        }
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
	// 	blending has to be enabled 
	// 	for transparency to work
	
    ofEnableAlphaBlending();
    
    //for (int i = 0; i < numLayers; i++) {
    for(vector<layer*>::iterator it = layers.begin(); it != layers.end(); ++it){
        (*it)->draw();
    }
    ofDisableAlphaBlending();
    
    


}

//--------------------------------------------------------------
