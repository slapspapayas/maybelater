#pragma once

#include "ofMain.h"
#include "layer.h"
#include <vector>

class testApp : public ofBaseApp {

	public:

		void setup();
		void update();
		void draw();
        bool frameByframe;
    
    string paths[31] = {"movies/49th_c.mov","movies/49th_otherside_c.mov","movies/alley_c.mov",
                        "movies/berries_c.mov","movies/bfast_c.mov","movies/cake_decorating_compressed.mov",
                        "movies/chicago2_c.mov","movies/coffee_c.mov",
                        "movies/doughnuts_frying_c.mov","movies/doughnuts_on_conveyer_belt_c.mov","movies/dripping_donut_masked_c.mov",
                        "movies/eggs_c.mov","movies/FUCKINGBIRDS_c.mov","movies/hummingbird_colorrangekey_c.mov","movies/hummingbird_singlecolorkey_c.mov",
                        "movies/icing_loop_c.mov","movies/pancakes_c.mov","movies/pink_cake_compressed.mov",
                        "movies/powell_station_c.mov","movies/sad_girl_c.mov","movies/selecting_cake.mov",
                        "movies/sf58_bridge_c.mov","movies/sf58_city_c.mov","movies/sf58_lombard_c.mov",
                        "movies/sf58_trolley_c.mov","movies/sf_cityscape_e.mov","movies/sf_fog_c.mov","movies/sf_trolley_c.mov",
                        "movies/street_lamp_c.mov","movies/trimming_cake_compressed.mov","movies/turtle_chillin(sloppy_masking)_c.mov"
                        /*"movies/flowersBitch.mp4", "movies/moreBUsh.mp4", "movies/topsy_turvy.mp4", "movies/abstract_trees.mp4", "movies/wall.mp4", "movies/stripes_trees.mp4", "movies/sidewalk_grass.mp4", "movies/shadows_sidewalk.mp4", "movies/grass_light.mp4", "movies/brick_wall.mp4", "movies/80DegreeWeather.mp4", "movies/iDontUseSound.mp4"*/};
        std::vector<layer*> layers;
    vector<ofVideoPlayer> movies;
    int totalVideos = 31;
        int w, h, numLayers;
    
};

