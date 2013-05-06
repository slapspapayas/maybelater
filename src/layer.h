//
//  layer.h
//  artVideo
//
//  Created by Alyssa Pappas on 4/30/13.
//  Copyright (c) 2013 The University of Chicago. All rights reserved.
//

#ifndef artVideo_layer_h
#define artVideo_layer_h

#pragma once

#include "ofMain.h"

class layer {
    
public:
    //methods
    void update();
    void draw();
    
    //constructor
    layer(string path);
    
    //vars
    ofTexture           myTexture;
    ofVideoPlayer       myVideo;
    bool                frameByframe;
    bool                finished;
    int 			w, h, a, xPos, yPos, scale, threshold;
    unsigned char * videoPixels;
    unsigned char * pixels;
    
};


#endif
