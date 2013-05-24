//
//  layer.h
//  artVideo
//
//  Created by Alyssa Pappas on 4/30/13
//

#ifndef artVideo_layer_h
#define artVideo_layer_h

#pragma once

#include "ofMain.h"

class layer {
    
public:
    void pixelManipulation();
    void update();
    void draw();
    
    layer(ofVideoPlayer * vid);
    
    ofTexture           myTexture;
    ofVideoPlayer   *   myVideo;
    bool                frameByframe;
    bool                finished;
    int                 w, h, a, xPos, yPos, scale, threshold, channels;
    unsigned char       * layerPixels, * pixels;
    
};


#endif
