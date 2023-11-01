#pragma once

// DO NOT CHANGE THIS ENUM
enum class ChannelOrder {
	BGR,
	BRG,
	GBR,
	GRB,
	RBG,
	RGB
};

class template <typename ColorType> Pixel {

    public:
        Pixel() : redIntensity(1), greenIntensity(1), blueIntensity(1){}
        Pixel(ColorType in0, ColorType in1, ColorType in2){}
        const ChannelOrder channel_order;
        const ColorType get_red_channel() noexcept;
        const ColorType get_green_channel();
        const ColorType get_blue_channel();

    private:
        ColorType redIntensity;
        ColorType greenIntensity;
        ColorType blueIntensity;





}
