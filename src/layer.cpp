//
//  layer.cpp
//  artVideo
//
//  Created by Alyssa Pappas on 4/30/13.
//  Copyright (c) slapspapayas. All rights reserved.
//

#include <iostream>
#include <cstdlib>

#include "layer.h"

//--------------------------------------------------------------

layer::layer(string path){
	ofBackground(255,255,255);
	ofSetVerticalSync(true);
	frameByframe = false;
    
	// rgba doesn't actually work
    myVideo.setPixelFormat(OF_PIXELS_RGBA);
    
    // set video path
    myVideo.loadMovie(path);
    myVideo.setLoopState(OF_LOOP_NONE);
    //play video so can get pixels to manipulate for each frame
    myVideo.play();
    
    w = myVideo.getWidth();
	h = myVideo.getHeight();
    a = rand() % 255 + 50; // randomly choose opacity
    threshold = rand() % 255; // randomly choose what range to key
    
    // decide where tex should be drawn
    
    int screenW = ofGetScreenWidth();
    int screenH = ofGetScreenHeight();
    
    xPos = rand() % screenW;
    yPos = rand() & screenH;
    
    // choose scale of image
    
    int random = rand() % 3;
	(w < (screenW>>1)) ? scale = 1<<random : 1>>random;
	
    myTexture.allocate(w, h, GL_RGBA);
	
	
    //unsigned char * 
    pixels = myVideo.getPixels();
    videoPixels = new unsigned char [w*h*4];
    
    
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++){
            int i = (y*w*3)+(x*3); // calc starting index for curr pixel
            int j = (y*w*4)+(x*4);
            int r = pixels[i];
            int g = pixels[i + 1];
            int b = pixels[i + 2];
            
            //if (r == 255 || g == 255 || b == 255) {
            //if (r >= 240 && g >= 240 && b >= 240) {
            //if (r >= 230 && g >= 230 && b >= 230) {
            //if (r <= threshold && g <= threshold && b <= threshold) {
            if (r == threshold || g == threshold || b == threshold) {
                //set alpha pixel to 0
                videoPixels[j+3] = 0;
            } else {
                //keep visible
                videoPixels[j+3] = a;
            }
            videoPixels[j] = r;
            videoPixels[j+1] = g;
            videoPixels[j+2] = b;
        }
    }	 
    
    
    myTexture.loadData(videoPixels, w, h, GL_RGBA);
    
}

//--------------------------------------------------------------
void layer::update(){
    
    ofBackground(255,255,255);
    
    myVideo.getIsMovieDone() ? finished = true : finished = false;
    
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++){
            int i = (y*w*3)+(x*3); // calc index for video pixel data
            int j = (y*w*4)+(x*4); // calc index for texture pixel data
            int r = pixels[i];
            int g = pixels[i + 1];
            int b = pixels[i + 2];
            //int a = pixels[i += 3];
            //if (r == 255 || g == 255 || b == 255) {
            //if (r == 0 && g == 0 && b == 0) {
            //if (r >= 200 && g >= 200 && b >= 200) {  
            if (r <= 5 && g <= 5 && b <= 5) {
            //if (r <= threshold && g <= threshold && b <= threshold) {
            //if (r == threshold || g == threshold || b == threshold) {
                //set alpha pixel to 0
                videoPixels[j+3] = 0;
            } else {
                //keep visible
                videoPixels[j+3] = a;
            }
            videoPixels[j] = g;
            videoPixels[j+1] = b;
            videoPixels[j+2] = r;
        }
    }	 
    
    myTexture.loadData(videoPixels, w, h, GL_RGBA);
}

//--------------------------------------------------------------
void layer::draw(){
    myVideo.update();
    
	// 	blending has to be enabled 
	// 	for transparency to work
	
	ofEnableAlphaBlending();
    
    myTexture.draw(xPos>>1, yPos>>1, w*scale, h*scale);
    
	ofDisableAlphaBlending();
    
    
    
    
}

//--------------------------------------------------------------

