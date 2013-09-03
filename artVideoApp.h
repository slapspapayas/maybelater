#pragma once

#include "ofMain.h"
#include "layer.h"
#include <vector>

class artVideoApp : public ofBaseApp {

	public:

		void setup();
		void update();
		void draw();
        bool frameByframe;
    
    string paths[38] = {"movies/49th_c.mov",
        "movies/49th_otherside_c.mov",
        "movies/alley_c.mov",
        "movies/berries_c.mov",
        "movies/bfast_c.mov",
        "movies/cake_decorating_compressed.mov",
        "movies/cheers_c.mov",
        "movies/chicago2_c.mov",
        "movies/coffee_c.mov",
        "movies/doughnuts_frying_c.mov",
        "movies/doughnuts_on_conveyer_belt_c.mov",
        "movies/dripping_donut_masked_c.mov",
        "movies/eggs_c.mov",
        "movies/flag_c.mov",
        "movies/BIRDS_c.mov",
        "movies/house_c.mov",
        "movies/hummingbird_colorrangekey_c.mov",
        "movies/hummingbird_singlecolorkey_c.mov",
        "movies/icing_loop_c.mov",
        "movies/obama_screen_c.mov",
        "movies/obamaaa_c.mov",
        "movies/pancakes_c.mov",
        "movies/pink_cake_compressed.mov",
        "movies/powell_station_c.mov",
        "movies/rolling_rock_c.mov",
        "movies/sad_girl_c.mov",
        "movies/selecting_cake.mov",
        "movies/sf58_bridge_c.mov",
        "movies/sf58_city_c.mov",
        "movies/sf58_lombard_c.mov",
        "movies/sf58_trolley_c.mov",
        "movies/sf_cityscape_e.mov",
        "movies/sf_fog_c.mov",
        "movies/sf_trolley_c.mov",
        "movies/street_lamp_c.mov",
        "movies/trimming_cake_compressed.mov",
        "movies/turtle_chillin(sloppy_masking)_c.mov",
        "movies/turtle_in_grass_c.mov"
    };
    
    int color_channels[38] = {0,1,2,3,4,5,0,1,2,3,4,5,0,1,2,3,4,5,0,1,2,3,4,5,0,1,2,3,4,5,0,1,2,3,4,5,0,1};
    std::vector<layer*> layers;
    vector<ofVideoPlayer> movies;
    int totalVideos = 38;
    int w, h, numLayers;
    
};

