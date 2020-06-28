#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>
#include <fstream>

struct color_t{
	uint8_t red_8;
	uint8_t green_8;
	uint8_t blue_8;
	
	uint32_t red_32;
	uint32_t green_32;
	uint32_t blue_32;
};

namespace Color{
	void edit_hair(int color_id, uint32_t hair, uint32_t shine);
	void edit_eye(int color_id, uint32_t eye);
	void save_hair();
	void save_eye();
}

#endif