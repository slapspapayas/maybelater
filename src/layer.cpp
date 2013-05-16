//
//  layer.cpp
//  artVideo
//
//  Created by Alyssa Pappas on 4/30/13
//

#include <iostream>
#include <cstdlib>

#include "layer.h"

//--------------------------------------------------------------
void layer::pixelManipulation() {
    int i,j,r,g,b;
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++){
            i = (y*w*3)+(x*3); // calc starting index for curr pixel
            j = (y*w*4)+(x*4);
            r = pixels[i];
            g = pixels[i + 1];
            b = pixels[i + 2];
            
            //if (r == 255 || g == 255 || b == 255) {
            //if (r == 0 || g == 0 || b == 0) {
            //if (r >= 240 && g >= 240 && b >= 240) {
            //if (r >= 230 && g >= 230 && b >= 230) {
            //if (r <= threshold && g <= threshold && b <= threshold) {
            //if (r == threshold || g == threshold || b == threshold) {
            if(r <= 8 && g <= 8 && b <= 8) {
                //set alpha pixel to 0
                layerPixels[j+3] = 0;
            } else {
                //keep visible
                layerPixels[j+3] = a;
            }
            switch (channels) {
                case 0:
                    layerPixels[j] = r; //normal
                    layerPixels[j+1] = g;
                    layerPixels[j+2] = b;
                    break;
                case 1:
                    layerPixels[j] = g; //switch r & g
                    layerPixels[j+1] = r;
                    layerPixels[j+2] = b;
                    break;
                case 2:
                    layerPixels[j] = b; //switch r & b
                    layerPixels[j+1] = g;
                    layerPixels[j+2] = r;
                    break;
                case 3:
                    layerPixels[j] = r; //switch b & g
                    layerPixels[j+1] = b;
                    layerPixels[j+2] = g;
                    break;
                case 4:
                    layerPixels[j] = g; 
                    layerPixels[j+1] = b;
                    layerPixels[j+2] = r;
                    break;
                case 5:
                    layerPixels[j] = b; 
                    layerPixels[j+1] = r;
                    layerPixels[j+2] = g;
                    break;
            }
        }
    }	 
}

//--------------------------------------------------------------


layer::layer(string path){
	ofBackground(255,255,255);
	ofSetVerticalSync(true);
	frameByframe = false;
    finished = false;
    
	// rgba doesn't actually work :(
    myVideo.setPixelFormat(OF_PIXELS_RGB);
    
    // set video path
    myVideo.loadMovie(path);
    myVideo.setLoopState(OF_LOOP_NONE);
    //play video so can get pixels to manipulate for each frame
    //myVideo = vid;
    //myVideo->setPosition(0);
    myVideo.play();
    
    w = myVideo.getWidth();
	h = myVideo.getHeight();
    a = rand() % 255 + 50; // choose opacity
    threshold = rand() % 255; // choose what range to key
    
    // decide where tex should be drawn
    
    int screenW = ofGetScreenWidth();
    int screenH = ofGetScreenHeight();
    
    xPos = rand() % screenW - 200;
    yPos = rand() % screenH - 200; 
    
    // choose scale of image
    
    int random = rand() % 3;
	(w < (screenW>>1)) ? scale = 1<<random : 1>>random;
	
    myTexture.allocate(w, h, GL_RGBA);
	
    pixels = myVideo.getPixels();
    layerPixels = new unsigned char [w*h*4];
    pixelManipulation();
    
    myTexture.loadData(layerPixels, w, h, GL_RGBA);
    
}

//--------------------------------------------------------------
void layer::update(){
    
    ofBackground(255,255,255);
    
    myVideo.update();
    myVideo.getIsMovieDone() ? finished = true : finished = false;
    pixelManipulation();

    myTexture.loadData(layerPixels, w, h, GL_RGBA);
}

//--------------------------------------------------------------
void layer::draw(){
    // 	blending has to be enabled 
	// 	for transparency to work
	
	ofEnableAlphaBlending();

    myTexture.draw(xPos>>1, yPos>>1, w*scale, h*scale);
    
	ofDisableAlphaBlending();
    
    
    
    
}

//--------------------------------------------------------------

