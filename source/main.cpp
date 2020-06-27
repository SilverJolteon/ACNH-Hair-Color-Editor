#include <iostream>
#include <fstream>
#include "Color.h"

uint32_t convert(int HairColor, uint32_t hair, uint32_t shine){
	// Split hex RGB into each color
	uint8_t hair_red_8 = (hair & 0xFF0000) >> 16;
	uint8_t hair_green_8 = (hair & 0x00FF00) >> 8;
	uint8_t hair_blue_8 = hair & 0x0000FF;
	
	uint8_t shine_red_8 = (shine & 0xFF0000) >> 16;
	uint8_t shine_green_8 = (shine & 0x00FF00) >> 8;
	uint8_t shine_blue_8 = shine & 0x0000FF;
	
	// Convert 8 bit colors into 32 bit colors
	
	uint32_t hair_red_32 = __builtin_bswap32(hair_red_8 * 0x030303 + 0x3C000000);
	uint32_t hair_green_32 = __builtin_bswap32(hair_green_8 * 0x030303 + 0x3C000000);
	uint32_t hair_blue_32 = __builtin_bswap32(hair_blue_8 * 0x030303 + 0x3C000000);
	
	uint32_t shine_red_32 = __builtin_bswap32(shine_red_8 * 0x030303 + 0x3C000000);
	uint32_t shine_green_32 = __builtin_bswap32(shine_green_8 * 0x030303 + 0x3C000000);
	uint32_t shine_blue_32 = __builtin_bswap32(shine_blue_8 * 0x030303 + 0x3C000000);
	
	// Replace bytes
	
	for(int i = 0; i < 4; i++){
		CharaMakeHairColorParam[0x74 + (HairColor * 0x60) + 3 - i] = (hair_red_32 >> (i * 8) & 0xFF);
		CharaMakeHairColorParam[0x74 + (HairColor * 0x60) + 4 + 3 - i] = (hair_blue_32 >> (i * 8) & 0xFF);
		CharaMakeHairColorParam[0x74 + (HairColor * 0x60) + 8 + 3 - i] = (hair_green_32 >> (i * 8) & 0xFF);
		
		CharaMakeHairColorParam[0x68 + (HairColor * 0x60) + 3 - i] = (shine_blue_32 >> (i * 8) & 0xFF);
		CharaMakeHairColorParam[0x68 + (HairColor * 0x60) + 4 + 3 - i] = (shine_green_32 >> (i * 8) & 0xFF);
		CharaMakeHairColorParam[0x68 + (HairColor * 0x60) + 8 + 3 - i] = (shine_red_32 >> (i * 8) & 0xFF);
	}
}

void save(){
	// Generate 'CharaMakeHairColorParam.bcsv' file
	std::ofstream out("CharaMakeHairColorParam.bcsv", std::ios::binary);
	out.seekp(0, out.beg);
	out.write((char*)CharaMakeHairColorParam, COLOR_SIZE);
	out.close();
}

int main(int agrc, char** argv){
	std::cout << "---------------------------\nACNH Hair Color Editor v0.3\n     by SilverJolteon\n---------------------------" << std::endl << std::endl;
	bool finished = false;
	std::string num, hair, shine, choice;
	while(!finished){
		std::cout << "Hair Color Number: ";
		std::cin >> num;
		std::cout << "Hair Color (in hex): #";
		std::cin >> hair;
		std::cout << "Hair Shine Color (in hex): #";
		std:: cin >> shine;
		convert(std::stoi(num, 0, 10), std::stoi(hair, 0, 16), std::stoi(shine, 0, 16));
		std::cout << std::endl << "Change another? (y/n): ";
		std::cin >> choice;
		if(choice.compare("n") == 0) finished = true;
	}
	std::cout << std::endl << "Saved as CharaMakeHairColorParam.bcsv" << std::endl;
	save();
	
	return 0;
}