#pragma once

#include "ofMain.h"
#include "layer.h"
#include <vector>

class testApp : public ofBaseApp {

	public:

		void setup();
		void update();
		void draw();
        ofTexture myTexture;
        ofVideoPlayer myVideo;
        bool frameByframe;
    
        string paths[26] = {"movies/hummingbird_singlecolorkey_1.mp4", "movies/sf58_bridge.mp4",
                            "movies/chi_skyline1_blur.mp4", "movies/49th_otherside.mp4",
                            "movies/sf58_city.mp4", "movies/keyedslowfuckingbirds.mp4",
                            "movies/pancakes.mp4", "movies/bfast.mp4",
                            "movies/49th_otherside.mp4", "movies/berries.mp4",
                            "movies/powell_station.mp4", "movies/sad_girl.mp4",
                            "movies/eggs.mp4", "movies/street_lamp.mp4",
                            "movies/SLOWFUCKINGBIRDS.mp4", "movies/sf58_trolley.mp4",
                            "movies/sf58_lombard.mp4", "movies/sf_trolley.mp4",
                            "movies/sf_fog.mp4", "movies/FUCKINGBIRDS.mp4",
                            "movies/hummingbird_colorrangekey.mp4", "movies/coffee.mp4",
                            "movies/chicago2.mp4", "movies/bfast.mp4",
                            "movies/alley.mp4", "movies/49th.mp4"};
        std::vector<layer*> layers;
    
        int w, h, numLayers;
    
};

