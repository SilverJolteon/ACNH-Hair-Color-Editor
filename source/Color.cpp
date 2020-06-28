#include "Color.h"
#include "HairColor.h"
#include "EyeColor.h"

color_t convert_color(uint32_t color){
	color_t temp;
	
	// Split hex RGB into each color
	temp.red_8 = (color & 0xFF0000) >> 16;
	temp.green_8 = (color & 0x00FF00) >> 8;
	temp.blue_8 = color & 0x0000FF;
	
	// Convert 8 bit colors into 32 bit colors
	temp.red_32 = __builtin_bswap32(temp.red_8 * 0x030303 + 0x3C000000);
	temp.green_32 = __builtin_bswap32(temp.green_8 * 0x030303 + 0x3C000000);
	temp.blue_32 = __builtin_bswap32(temp.blue_8 * 0x030303 + 0x3C000000);
	
	return temp;
}

void Color::edit_hair(int color_id, uint32_t hair, uint32_t shine){
	color_t hair_color = convert_color(hair);
	color_t shine_color = convert_color(shine);	
	
	// Replace bytes
	
	for(int i = 0; i < 4; i++){
		CharaMakeHairColorParam[0x74 + (color_id * 0x60) + 3 - i] = (hair_color.red_32 >> (i * 8) & 0xFF);
		CharaMakeHairColorParam[0x74 + (color_id * 0x60) + 4 + 3 - i] = (hair_color.blue_32 >> (i * 8) & 0xFF);
		CharaMakeHairColorParam[0x74 + (color_id * 0x60) + 8 + 3 - i] = (hair_color.green_32 >> (i * 8) & 0xFF);
		
		CharaMakeHairColorParam[0x68 + (color_id * 0x60) + 3 - i] = (shine_color.blue_32 >> (i * 8) & 0xFF);
		CharaMakeHairColorParam[0x68 + (color_id * 0x60) + 4 + 3 - i] = (shine_color.green_32 >> (i * 8) & 0xFF);
		CharaMakeHairColorParam[0x68 + (color_id * 0x60) + 8 + 3 - i] = (shine_color.red_32 >> (i * 8) & 0xFF);
	}
}

void Color::edit_eye(int color_id, uint32_t eye){
	color_t eye_color = convert_color(eye);
	
	// Replace bytes
	
	for(int i = 0; i < 4; i++){
		CharaMakeEyeColorParam[0x50 + (color_id * 0x54) + 3 - i] = (eye_color.blue_32 >> (i * 8) & 0xFF);
		CharaMakeEyeColorParam[0x50 + (color_id * 0x54) + 4 + 3 - i] = (eye_color.green_32 >> (i * 8) & 0xFF);
		CharaMakeEyeColorParam[0x50 + (color_id * 0x54) + 8 + 3 - i] = (eye_color.red_32 >> (i * 8) & 0xFF);
	}
}

void Color::save_hair(){
	// Generate 'CharaMakeHairColorParam.bcsv' file
	std::ofstream hair("CharaMakeHairColorParam.bcsv", std::ios::binary);
	hair.seekp(0, hair.beg);
	hair.write((char*)CharaMakeHairColorParam, HAIRCOLOR_SIZE);
	hair.close();
}

void Color::save_eye(){
	// Generate 'CharaMakeEyeColorParam.bcsv' file
	std::ofstream eye("CharaMakeEyeColorParam.bcsv", std::ios::binary);
	eye.seekp(0, eye.beg);
	eye.write((char*)CharaMakeEyeColorParam, EYECOLOR_SIZE);
	eye.close();
}