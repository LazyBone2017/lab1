#include "image/pixel.h"
using namespace std;
using namespace pixel;

channel_order = ChannelOrder.BGR;
Pixel(ColorType in0, ColorType in1, ColorType in2) {
    switch (channel_order){
        case RGB: {
            redIntensity = in0;
            greenIntensity = in1;
            blueIntensity = in2;
            }
        case RBG: {
            redIntensity = in0;
            blueIntensity = in1;
            greenIntensity = in2;
        }
        case BRG: {
            blueIntensity = in0;
            redIntensity = in1;
            greenIntensity = in2;
        }
        case BGR: {
            blueIntensity = in0;
            greenIntensity = in1;
            redIntensity = in2;
            }

        case GBR: {
            
            greenIntensity = in0;
            blueIntensity = in1;
            redIntensity = in2;
            }
        case GRB: {
            greenIntensity = in0;
            redIntensity = in1;
            blueIntensity = in2;
            }
    }
}